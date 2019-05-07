
import javaobj
import math
import sys

if len(sys.argv) < 3:
    print "Usage: python " + sys.argv[0] + " <modelFile> <destinationFile> [-opts]"
    print "\nOptions:\n\t-fxp:  use fixed point Q21.10 representation in all calculations\n"
    exit(0)

#######################################################################################################
# HANDLING FIXED POINT OPTION

useFxp = ('-fxp' in sys.argv)
        
#######################################################################################################
# OPENING MODEL FILE

try: file = open(sys.argv[2], "w")
except:
    print "Error: destination file invalid"
    exit()

try: modelFile = open(sys.argv[1])
except:
    print "Error: model file invalid"
    exit()

marshaller = javaobj.JavaObjectUnmarshaller(modelFile)
obj = marshaller.readObject()

#######################################################################################################

# Convert a float point number to its fixed point representation
# returns a string that has this representation in hexidecimal.
def toFxp(x):
    if math.isnan(x):
        return "INF_POS"
    return "(FixedNum)0x%.8x" % (int(round(x * (1 << 10))) & 0xFFFFFFFF)

#######################################################################################################

classesNumbers = vars(vars(vars(vars(obj)\
                ['m_classAttribute'])['m_AttributeInfo'])\
                ['m_Hashtable'])['annotations'][1:]
m_numClasses = vars(vars(vars(vars(obj)\
                ['m_classAttribute'])['m_AttributeInfo'])\
                ['m_Values'])['size']
m_classIndex = vars(obj)['m_classIndex']

#######################################################################################################
# Recover attribute names
inputs = []
try:
    atts = vars(vars(vars(vars(vars(obj)\
            ['m_Filter'])['m_InputRelAtts'])\
            ['m_Data'])['m_NamesToAttributeIndices'])\
            ['annotations'][1:]
    inputs = ['' for _ in range(len(atts)/2 - 1)]
    for i in range(len(atts)):
        if i % 2 == 0 or atts[i-1] == 'class' or atts[i-1] == 'label':
            continue
        index = vars(atts[i])['value']
        inputs[index - (1 if index > m_classIndex else 0)] = atts[i-1]
except:
    print "Error: can't recover attribute names"
    print "Make sure class atribute is named \'class\' or \'label\' in training dataset."
    exit(0)

#######################################################################################################
# Recover class names
outputs = []
className = "class"
for i in classesNumbers:
    if 'String' in str(type(i)):
        className = str(i)
    else:
        outputs.append((vars(i)['value'], className))
outputs.sort()

#######################################################################################################

minArray = vars(vars(obj)['m_Filter'])['m_MinArray']
maxArray = vars(vars(obj)['m_Filter'])['m_MaxArray']
m_KernelIsLinear = vars(obj)['m_KernelIsLinear']
m_classifiers = vars(obj)['m_classifiers']

# Recover SVM classifiers
new_classifiers = [[] for _ in m_classifiers]
for i in range(len(m_classifiers)):
    for j in range(len(m_classifiers[i])):
        if "None" in str(type(m_classifiers[i][j])):
            continue
        new_classifiers[j].append(m_classifiers[i][j])

#######################################################################################################

funcs = "\n"
decls = "\n"
inits = "\n"
defs = "\n"
incls = "\n"

################################ FUNCTIONS ################################

### SVMOutput function
linearSVMOutput = ("FixedNum" if useFxp else "float") +\
                  " SVMOutput(int i, int j){\n\
\t" + ("FixedNum" if useFxp else "float") + " result = " +\
("(FixedNum)0" if useFxp else "0.0") + ";\n\
\tfor (int p1 = 0; p1 < m_sparseWeights[i][j][0]; p1++){\n\
\t\tint p2 = m_sparseIndices[i][j][p1];\n\
\t\tif (p2 != CLASS_INDEX){\n\
\t\t\tresult " + ("= fxp_sum(result, fxp_mul(instance[p2], m_sparseWeights[i][j][p1+1]));"\
                  if useFxp else "+= instance[p2] * m_sparseWeights[i][j][p1+1];") + "\n\
\t\t}\n\
\t}\n\
\tresult " + ("= fxp_diff(result, m_b[i][j]);" \
              if useFxp else "-= m_b[i][j];") + "\n\
\treturn result;\n\
}\n"

if m_KernelIsLinear:
    funcs += linearSVMOutput
else:
    print "Error: Kernel is not linear"
    exit(0)

### classify function
funcs += "\n/* Function classify description:\n\
 * Instance array must be initializated, with \
appropriated attributes, before calling this function\n"

for i,j in outputs:
    funcs += " * Output number " + str(i) +\
             " means that the instance was classified as " + j + "\n"
    
funcs += " */\n"
funcs += "int classify(){\n\
\tfor (int i = 0; i <= INPUT_SIZE; i++){\n\
\t\tif (" + "maxArray[i] == minArray[i]" +\
             " || minArray[i] == " +\
             ("INF_POS" if useFxp else "NAN") + "){\n\
\t\t\tinstance[i] = " + ("(FixedNum)" if useFxp else "") + "0;\n\
\t\t}\n\
\t\telse{\n\
\t\t\tinstance[i] = " +\
("fxp_div(fxp_diff(instance[i], minArray[i]), " +\
 "fxp_diff(maxArray[i], minArray[i])" + ");" if useFxp\
 else "(instance[i] - minArray[i]) / (maxArray[i] - minArray[i]);") + "\n\
\t\t}\n\
\t}\n\
\tint result[NUM_CLASSES] = {0};\n\
\tfor (int i = 1; i < NUM_CLASSES; i++){\n\
\t\tfor (int j = 0; j < i; j++){\n\
\t\t\t" + ("FixedNum" if useFxp else "float") + " output = SVMOutput(i, j);\n\
\t\t\tif (output > 0){\n\
\t\t\t\tresult[i]++;\n\
\t\t\t}\n\
\t\t\telse{\n\
\t\t\t\tresult[j]++;\n\
\t\t\t}\n\
\t\t}\n\
\t}\n\
\tint indMax = 0;\n\
\tfor (int i = 1; i < NUM_CLASSES; i++){\n\
\t\tif (result[i] > result[indMax]){\n\
\t\t\tindMax = i;\n\
\t\t}\n\
\t}\n\
\treturn indMax;\n\
}\n"

################################ DECLARATIONS ################################

### print sorted attributes
decls += "/* Instance array must be global\n\
 * Attributes MUST be sorted in instance array in the following order:\n"
for i in inputs:
    decls += " * " + i + "\n"
decls += " */\n" + ("FixedNum" if useFxp else "float") + " instance[INPUT_SIZE+1];\n"

sizeMinArray = len(minArray)
sizeMaxArray = len(maxArray)
rangeArray = []
            
if useFxp:
    minArray = [toFxp(_i) for _i in minArray]
    maxArray = [toFxp(_i) for _i in maxArray]
    rangeArray = [toFxp(_i) for _i in rangeArray]

minArray = (str(minArray).replace('\'','') if useFxp else str(minArray).upper())
maxArray = str(maxArray).replace('\'','')
rangeArray = str(rangeArray).replace('\'','')

### print minArray
decls += "const " + ("FixedNum" if useFxp else "float") +\
         " minArray[" + str(sizeMinArray) + "] = " +\
         minArray.replace('[','{').replace(']','}') + ";\n"

### print maxArray
decls += "const " + ("FixedNum" if useFxp else "float") +\
         " maxArray[" + str(sizeMaxArray) + "] = " +\
         maxArray.replace('[','{').replace(']','}') + ";\n"

decls += "\n"

decls += "\nconst " + ("FixedNum" if useFxp else "float") +\
         " **m_sparseWeights[" + str(len(new_classifiers)) + "];\n"

inits += "void initConnections(){\n"

### initialize m_sparseWeights array
for i in range(len(new_classifiers)):
    if len(new_classifiers[i]) == 0:
        inits += "\n\tm_sparseWeights[" + str(i) + "] = NULL;\n\n"
        continue
    
    decls += "\nconst " + ("FixedNum" if useFxp else "float") +\
             " *tmp0_sparseWeights" + str(i) +\
             "[" + str(len(new_classifiers[i])) + "];\n"
    
    for j in range(len(new_classifiers[i])):
        arraySize = len(vars(new_classifiers[i][j])['m_sparseWeights'])
        array = [arraySize] + vars(new_classifiers[i][j])['m_sparseWeights']
        
        if useFxp:
            array = [toFxp(_i) for _i in array]
            array[0] = array[0].replace(')', ')(') + ' >> FIXED_FBITS)'
            
        decls += "const " + ("FixedNum" if useFxp else "float") +\
                 " tmp1_sparseWeights" + str(i) + "_" + str(j) +\
                 "[" + str(arraySize+1) + "] = " +\
                 str(array).replace(']','}').replace('[','{').replace('\'','') +\
                 ";\n"
        
        inits += "\ttmp0_sparseWeights" + str(i) +\
                 "[" + str(j) + "] = tmp1_sparseWeights" +\
                 str(i) + "_" + str(j) + ";\n"
        
    inits += "\tm_sparseWeights[" + str(i) +\
             "] = tmp0_sparseWeights" + str(i) + ";\n\n"


decls += "\nconst int **m_sparseIndices[" + str(len(new_classifiers)) + "];\n"

### initialize m_sparseIndices array
for i in range(len(new_classifiers)):
    if len(new_classifiers[i]) == 0:
        inits += "\n\tm_sparseIndices[" + str(i) + "] = NULL;\n\n"
        continue
    
    decls += "\nconst int *tmp0_sparseIndices" + str(i) +\
             "[" + str(len(new_classifiers[i])) + "];\n"
    
    for j in range(len(new_classifiers[i])):
        arraySize = len(vars(new_classifiers[i][j])['m_sparseIndices'])
        array = vars(new_classifiers[i][j])['m_sparseIndices']
        
        decls += "const int tmp1_sparseIndices" + str(i) +\
                 "_" + str(j) + "[" + str(arraySize) + "] = " +\
                 str(array).replace(']','}').replace('[','{') + ";\n"
        
        inits += "\ttmp0_sparseIndices" + str(i) + "[" +\
                 str(j) + "] = tmp1_sparseIndices" +\
                 str(i) + "_" + str(j) + ";\n"
        
    inits += "\tm_sparseIndices[" + str(i) +\
             "] = tmp0_sparseIndices" + str(i) + ";\n\n"

decls += "\nconst " + ("FixedNum" if useFxp else "float") +\
         " *m_b[" + str(len(new_classifiers)) + "];\n"

### initialize m_b array
for i in range(len(new_classifiers)):
    if len(new_classifiers[i]) == 0:
        inits += "\n\tm_b[" + str(i) + "] = NULL;\n"
        continue
    
    m_b_i = []
    
    for j in range(len(new_classifiers[i])):
        m_b_i.append(vars(new_classifiers[i][j])['m_b'])
        
    if useFxp:
        m_b_i = [toFxp(_i) for _i in m_b_i]
        
    decls += "const " + ("FixedNum" if useFxp else "float") +\
             " tmp_m_b" + str(i) + "[" + str(len(m_b_i)) + "] = " +\
             str(m_b_i).replace(']','}').replace('[','{').replace('\'','') +\
             ";\n"
    
    inits += "\tm_b[" + str(i) + "] = tmp_m_b" + str(i) + ";\n"

inits += "}\n"

################################ DEFINES ################################

defs += "#define INPUT_SIZE " + str(len(inputs)) + "\n"
defs += "#define NUM_CLASSES " + str(m_numClasses) + "\n"
defs += "#define CLASS_INDEX " + str(m_classIndex) + "\n"

################################ INCLUDES ################################

incls += "#include <Arduino.h>\n"\
         + (("#define TOTAL_BITS " + str(32) +\
             "\n#define FIXED_FBITS " + str(10) +\
             "\n#define SIGNED" +\
             "\n#include \"FixedNum.h\"\n") if useFxp else "")

file.write(incls)
file.write(defs)
file.write(decls)
file.write(funcs)
file.write(inits)

file.close()

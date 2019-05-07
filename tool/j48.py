
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
    return "(FixedNum)0x%.8x" % (int(round(x * (1 << 10))) & 0xFFFFFFFF)

#######################################################################################################

m_useLaplace = vars(obj)['m_useLaplace']

# Recover index for class attribute
try:
    m_classIndex = vars(vars(vars(obj)['m_root'])['m_train'])['m_ClassIndex']
except:
    print "Error: can't recover class index"
    exit(0)

#######################################################################################################
# Recover attribute names
attributes = []
try:
    inputs = vars(vars(vars(vars(obj)['m_root'])['m_train'])['m_NamesToAttributeIndices'])['annotations'][1:]
    attributes = ['' for _ in range((len(inputs)/2) - 1)]
    for i in range(len(inputs)):
        if i % 2 == 0 or inputs[i-1] == 'class' or inputs[i-1] == 'label':
            continue
        index = vars(inputs[i])['value']
        attributes[index - (1 if index > m_classIndex else 0)] = inputs[i-1]
except:
    print "Error: can't recover attribute names"
    print "Make sure class atribute is named \'class\' or \'label\' in training dataset."
    exit(0)

#######################################################################################################
# Recover class names
classes = []
try:
    outputs = vars(vars(vars(vars(vars(vars(vars(obj)['m_root'])['m_train'])['m_Attributes'])['annotations'][1:][m_classIndex])['m_AttributeInfo'])['m_Hashtable'])['annotations'][1:]
    classes = ['' for _ in range(len(outputs)/2)]
    for i in range(len(outputs)):
        if i % 2 == 0:
            continue
        classes[vars(outputs[i])['value']] = outputs[i-1]
except:
    print "Error: can't recover class names"
    exit(0)

#######################################################################################################
m_numClasses = len(classes)

tree = []
m_isLeaf = []
m_attIndex = []
m_splitPoint = []
m_totaL = []
m_perClass = []
m_perBag = []
m_perClassPerBag = []

# Returns length of the tree
def dfsLenTree(obj):
    if vars(obj)['m_isLeaf']:
        return 1
    return sum([dfsLenTree(_i) for _i in vars(obj)['m_sons']]) + 1

# Recovers the structure of the tree
def dfs(obj):
    i = vars(obj)['m_id']
    
    if vars(obj)['m_isLeaf']:
        m_isLeaf[i] = True
        #return i
        
    m_perClass[i] = vars(vars(vars(obj)['m_localModel'])['m_distribution'])['m_perClass']
    m_perBag[i] = vars(vars(vars(obj)['m_localModel'])['m_distribution'])['m_perBag']
    m_perClassPerBag[i] = vars(vars(vars(obj)['m_localModel'])['m_distribution'])['m_perClassPerBag']
    m_isEmpty[i] = vars(obj)['m_isEmpty']
    m_totaL[i] = vars(vars(vars(obj)['m_localModel'])['m_distribution'])['totaL']
    
    if 'm_attIndex' in vars(vars(obj)['m_localModel']):
        m_attIndex[i] = vars(vars(obj)['m_localModel'])['m_attIndex']
    if 'm_splitPoint' in vars(vars(obj)['m_localModel']):
        m_splitPoint[i] = vars(vars(obj)['m_localModel'])['m_splitPoint']
    if type(vars(obj)['m_sons']) != type(None):
        tree[i] = [dfs(_i) for _i in vars(obj)['m_sons']]
        
    return i
    
lenTree = dfsLenTree(vars(obj)['m_root'])

tree = [[] for _ in range(lenTree)]
m_isLeaf = [False for _ in range(lenTree)]
m_attIndex = [-1 for _ in range(lenTree)]
m_splitPoint = [-1 for _ in range(lenTree)]
m_isEmpty = [False for _ in range(lenTree)]
m_totaL = [0 for _ in range(lenTree)]
m_perClass = [[] for _ in range(lenTree)]
m_perBag = [[] for _ in range(lenTree)]
m_perClassPerBag = [[] for _ in range(lenTree)]

m_root = dfs(vars(obj)['m_root'])

# Save the indexes for empty nodes
emptyIndex = [i for i in range(len(m_isEmpty)) if m_isEmpty[i]]

for i in range(len(m_attIndex)):
    if m_isEmpty[i]:
        m_attIndex[i] = -2

#######################################################################################################
# Write the classifier file

funcs = "\n"
decls = "\n"
inits = "\n"
defs = "\n"
incls = "\n"

################################ FUNCTIONS ################################

### getProbs function
funcs += "\n" + ("FixedNum" if useFxp else "float") + \
         " getProbs(int i, int classIndex, " + \
         ("FixedNum" if useFxp else "float") + \
         " weight){\n\
\tif (m_attIndex[i] == -1){\n\
\t\treturn " + ("fxp_mul(weight, classProb1[i][classIndex])" if useFxp\
                else "weight * classProb1[i][classIndex])") + ";\n"

funcs += "\t}\n\
\tint treeIndex = (instance[m_attIndex[i]] <= m_splitPoint[i] ? 0 : 1);\n"
if True in m_isEmpty:   
    funcs += "\tif (m_attIndex[i] == -2){\n\
\t\treturn " + ("fxp_mul(weight, classProb2[i][classIndex][treeIndex])" \
                if useFxp\
                else "weight * classProb2[i][classIndex][treeIndex]") +\
                     ";\n\
\t}\n"

funcs += "\treturn getProbs(tree[i][treeIndex], classIndex, weight);\n\
}\n"

### classify function
funcs += "\n/* Function classify description:\n\
 * Instance array must be initializated, with appropriated attributes, before calling this function\n"

for i in range(len(classes)):
    funcs += " * Output number " +\
             str(i) +\
             " means that the instance was classified as " +\
             classes[i] +\
             "\n"
    
funcs += " */\n"
funcs += "int classify(){\n\
\t" + ("FixedNum" if useFxp else "float") +\
" doubles[NUM_CLASSES];\n\
\tfor (int i = 0; i < NUM_CLASSES; i++){\n\
\t\tdoubles[i] = getProbs(M_ROOT, i, " +\
(toFxp(1) if useFxp else "1") +\
");\n\
\t}\n\
\tint indMax = 0;\n\
\tfor (int i = 1; i < NUM_CLASSES; i++){\n\
\t\tif (doubles[i] > doubles[indMax]){\n\
\t\t\tindMax = i;\n\
\t\t}\n\
\t}\n\
\treturn indMax;\n\
}\n"

################################ DECLARATIONS ################################

### print sorted attributes
decls += "/* Instance array must be global\n \
* Attributes MUST be sorted in instance array in the following order:\n"
for i in attributes:
    decls += " * " +\
             i +\
             "\n"

### instance array
decls += " */\n" +\
         ("FixedNum" if useFxp else "float") +\
         " instance[INPUT_SIZE+1];\n"

### m_attIndex array
decls += "\nint m_attIndex[LEN_TREE] = {" +\
         str(m_attIndex).replace(']','').replace('[','') +\
         "};\n"

### m_splitPoint array
decls += "\n" +\
        ("FixedNum" if useFxp else "float") +\
        " m_splitPoint[LEN_TREE] = {" +\
        str([toFxp(_i)\
        for _i in m_splitPoint]\
        if useFxp\
        else \
        m_splitPoint).replace(']','').replace('[','').replace('\'','') +\
        "};\n"

inits += "void initConnections(){\n"

decls += "\nconst int *tree[LEN_TREE];\n"

### initialize tree array
for i in range(len(tree)):
    if len(tree[i]) == 0:
        continue
    decls += "int tree_" +\
             str(i) +\
             "[" +\
             str(len(tree[i])) +\
             "] = {" +\
             str(tree[i]).replace('[','').replace(']','') +\
             "};\n"
    
    inits += "\ttree[" +\
             str(i) +\
             "] = tree_" +\
             str(i) +\
             ";\n"

decls += "\n" + ("FixedNum" if useFxp else "float") + " *classProb1[LEN_TREE];\n"
inits += "\n"

### initialize classProb1 array
for i in range(len(m_perClass)):
    if len(m_perClass[i]) == 0 or not m_isLeaf[i]:
        continue

    # Pre-calculate the class probability
    for _i in range(len(m_perClass[i])):
        if m_useLaplace:
            m_perClass[i][_i] = (m_perClass[i][_i] + 1.0) /\
                                float(m_totaL[i] + m_numClasses)
        else:
            if m_totaL[i] != 0:
                m_perClass[i][_i] = m_perClass[i][_i] /\
                                    float(m_totaL[i])
            else:
                m_perClass[i][_i] = 0.0
        
    decls += ("FixedNum" if useFxp else "float") +\
             " classProb1_" +\
             str(i) +\
             "[" +\
             str(len(m_perClass[i])) +\
             "] = {" +\
             str([toFxp(_i)\
                  for _i in m_perClass[i]]\
                 if useFxp\
                 else\
                 m_perClass[i]).replace('[','').replace(']','').replace('\'','') +\
                 "};\n"
    
    inits += "\tclassProb1[" +\
             str(i) +\
             "] = classProb1_" +\
             str(i) +\
             ";\n"


if True in m_isEmpty:
    decls += "\n" +\
             ("FixedNum" if useFxp else "float") +\
             " **classProb2[LEN_TREE];\n"
    inits += "\n"

    ### initialize classProb2 array
    for i in range(len(m_perClassPerBag)):
        if len(m_perClassPerBag[i]) == 0 or not m_isEmpty[i]:
            continue

        decls += ("FixedNum" if useFxp else "float") +\
                 " *classProb2_" +\
                 str(i) +\
                 "[" +\
                 str(len(m_perClassPerBag[i])) +\
                 "];\n"

        for j in range(len(m_perClassPerBag[i])):
            if len(m_perClassPerBag[i][j]) == 0:
                continue

            for _i in range(len(m_perClassPerBag[i][j])):
                if m_perBag[i][j] > 0:
                    if m_useLaplace:
                        m_perClassPerBag[i][j][_i] = (m_perClassPerBag[i][j][_i] + 1.0) /\
                                                     float(m_perBag[i][j] + m_numClasses)
                    else:
                        m_perClassPerBag[i][j][_i] = m_perClassPerBag[i][j][_i] /\
                                                     float(m_perBag[i][j])
                else:
                    m_perClassPerBag[i][j][_i] = classProb1[i][_i]
            decls += ("FixedNum" if useFxp else "float") +\
                    " classProb2_" + str(i) + "_" +\
                    str(j) +\
                    "[" + str(len(m_perClassPerBag[i][j])) +\
                    "] = {" +\
                    str([toFxp(_i) \
                    for _i in m_perClassPerBag[i][j]] \
                    if useFxp \
                    else \
                    m_perClassPerBag[i][j]).replace('[','').replace(']','').replace('\'','') +\
                    "};\n"

            inits += "\tclassProb2_" +\
                     str(i) +\
                     "[" +\
                     str(j) +\
                     "] = classProb2_" +\
                     str(i) +\
                     "_" +\
                     str(j) +\
                     ";\n"
        
        inits += "\tclassProb2[" +\
                 str(i) +\
                 "] = classProb2_" +\
                 str(i) +\
                 ";\n"

inits += "}\n"

################################ DEFINES ################################

defs += "#define M_ROOT " + str(m_root) + "\n"
defs += "#define NUM_CLASSES " + str(m_numClasses) + "\n"
defs += "#define CLASS_INDEX " + str(m_classIndex) + "\n"
defs += "#define LEN_TREE " + str(lenTree) + "\n"
defs += "#define INPUT_SIZE " + str(len(attributes)) + "\n"

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

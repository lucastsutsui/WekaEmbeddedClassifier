Implementations for the tool to convert WEKA trained classifiers into code to run in low-cost embedded systems.

JavaObj library must be installed <https://pypi.org/project/javaobj-py3/>

### Usage: 
```
    python j48.py <modelFile> <destinationFile> [-opts]
    python logistic.py <modelFile> <destinationFile> [-opts]
    python mlp.py <modelFile> <destinationFile> [-opts]
    python svmLinear.py <modelFile> <destinationFile> [-opts]
```
    
*modelFile* is the WEKA trained classification model

*destinationFile* is the file that will be produced containing the classifier

```
Options:	
		-fxp:  use fixed point Q21.10 representation in all operations
```

If fixed-point representation is used, *FixedNum.h* must be included in the same folder of the classifier file.

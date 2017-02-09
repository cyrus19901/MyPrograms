import csv
import sys
import math
import sys

rootDirectory = "./HW3data/data_sets"
trainingSetFile = "/training_set.csv"
validationSetFile = "/validation_set.csv"
testSetFile = "/test_set.csv"

features = []
classIndex = -1

trainingSet = []
validationSet = []
testSet = []

treeRoot = None

confusionMatrix = [[0, 0], [0, 0]]

class Node:
    def __init__(self):
        self.element = 'root'
        self.label = -1
        self.decisionFeature = -1
        self.decisionFeatureIndex = -1
        self.trueChild = None
        self.falseChild = None
        self.isPruned = False
        self.majorityClass = -1

def getMajorityLabel(dataSet):
    trueCount = 0
    falseCount = 0

    for loop in range(len(dataSet)):
        trueCount += dataSet[loop][classIndex]
    falseCount = len(dataSet) - trueCount

    if trueCount >= falseCount:
        return 1
    else:
        return 0

def calculateInformationGain(inputData, featureIndex):
    totalInput = len(inputData)

    numberOfTrue = 0
    numberOfFalse = 0

    trueSet = []
    falseSet = []

    for loop in range(totalInput):
        if inputData[loop][featureIndex] == 1:
            numberOfTrue +=1
            trueSet.append(inputData[loop])
        if inputData[loop][featureIndex] == 0:
            numberOfFalse += 1
            falseSet.append(inputData[loop])
    
    classEntropy = calculateEntropy(inputData)
    trueEntropy = (float(numberOfTrue) / float(totalInput)) * calculateEntropy(trueSet)
    falseEntropy = (float(numberOfFalse) / float(totalInput)) * calculateEntropy(falseSet)
    informationGain = classEntropy - trueEntropy - falseEntropy

    return informationGain

def calculateEntropyTerm(probability):
    if probability == 0:
        return 0
    else:
        return float(-probability*math.log(probability,2))

def calculateEntropy(dataSet):
    totalInput = len(dataSet)

    if totalInput == 0:
        return 0

    trueCount = 0
    falseCount = 0

    for loop in range(len(dataSet)):
        trueCount += dataSet[loop][classIndex]
    falseCount = len(dataSet) - trueCount

    trueEntropy = calculateEntropyTerm(float(trueCount)/float(totalInput))
    falseEntropy = calculateEntropyTerm(float(falseCount)/float(totalInput))
    # print (trueEntropy + falseEntropy)
    return (trueEntropy + falseEntropy)

def getBestAttribute(dataSet):
    informationGain = []
    for loop in range(len(features)):
        informationGain.append(calculateInformationGain(dataSet, loop))
        # print features[loop] + " " + `calculateInformationGain(dataSet, loop)`
    featureIndex = informationGain.index( max(informationGain) )
    featureLabel = features[featureIndex]
    return featureLabel, featureIndex

def generateDecisionTree(dataSet):
    #foo()
    #Create a Root node for the tree
    root = Node()

    allPositive = True
    allNegative = True

    for loop in range(len(dataSet)):
        if dataSet[loop][classIndex] == 0:
            allPositive = False
        elif dataSet[loop][classIndex] == 1:
            allNegative = False
        if not allPositive and not allNegative:
            break
        
    #If all Examples are positive, Return the single-node tree Root, with label = +
    if allPositive:
        root.element ='leaf'
        root.label = 1
        return root
    
    #If all Examples are positive, Return the single-node tree Root, with label = -
    if allNegative:
        root.element ='leaf'
        root.label = 0
        return root

    #If Attributes is empty, Return the single-node tree Root, with label = most common value of Target attribute in Examples
    bestAttr, bestAttrIndex = getBestAttribute(dataSet)
    root.element = 'root'
    root.decisionFeature = bestAttr
    root.decisionFeatureIndex = bestAttrIndex
    root.majorityClass = getMajorityLabel(dataSet)

    trueDataSet = []
    falseDataSet = []
    for loop in range(len(dataSet)):
        if dataSet[loop][bestAttrIndex] == 1:
            trueDataSet.append(dataSet[loop])
        else:
            falseDataSet.append(dataSet[loop])

    if ( ( allNegative == False) and (allPositive == False) and ( (len(trueDataSet) == 0 and len(falseDataSet) > 0) or (len(trueDataSet) > 0 and len(falseDataSet) == 0) ) ):
        root.element = 'leaf'
        root.label = 0;
        return root;

    if trueDataSet:
        root.element = 'root'
        root.trueChild = generateDecisionTree(trueDataSet)

    if falseDataSet:
        root.element = 'root'
        root.falseChild = generateDecisionTree(falseDataSet)

    return root

def getAnswer(root, dataSet):
    if root == None:
        return -1

    if root.element == 'leaf':
        if root.label == 0:
            return 0
        elif root.label == 1:
            return 1

    if root.isPruned == True:
        return root.majorityClass
    
    attrIndex = root.decisionFeatureIndex
    if dataSet[attrIndex] == 1:
        return getAnswer(root.trueChild, dataSet)
    if dataSet[attrIndex] == 0:
        return getAnswer(root.falseChild, dataSet)

def getAccuracy(dataSet):
    wrong = 0
    total = len(dataSet)
    for loop in range(len(dataSet)):
        prediction = getAnswer(treeRoot, dataSet[loop])
        actual = dataSet[loop][len(dataSet[loop]) - 1]
        confusionMatrix[actual][prediction] += 1
        if(prediction != actual):
            wrong += 1

    return (1 - float(wrong)/float(total))*100

def getBfsQueue(treeRoot):
    queue = []
    queue.append(treeRoot)
    currentIndex = 0
    while currentIndex < len(queue):
        root = queue[currentIndex]
        if root == None:
            continue
        if root.element == 'root':
            if not root.trueChild == None:
                queue.append(root.trueChild)
            if not root.falseChild == None:
                queue.append(root.falseChild)
        currentIndex += 1
    return queue

def prune(currentRoot, dataSet):
    queue = getBfsQueue(treeRoot)
    currentIndex = len(queue) - 1
    pruneCount = 0
    while currentIndex != -1:
        outputWithoutPrune = getAccuracy(dataSet)
        queue[currentIndex].isPruned = True
        outputWithPrune = getAccuracy(dataSet)
        queue[currentIndex].isPruned = False

        if outputWithoutPrune < outputWithPrune:
            pruneCount += 1
            queue[currentIndex].isPruned = True

        currentIndex -= 1
    return pruneCount

def getFeatures(fileName):
    with open(fileName, 'r') as f:
        reader = csv.reader(f)
        attributes = next(reader)
        features = attributes
    f.close()
    return features

def readFile(fileName):
    header = []
    dataSet = []
    with open(fileName, 'r') as f:
        reader = csv.reader(f)
        attributes = next(reader)
        features = attributes
        for row in reader:
            results = [int(i) for i in row]
            dataSet.append(results)
    f.close()
    return dataSet

def printTree(root, indent):
    if root == None:
        return

    if root.element == 'leaf':
        if root.label == 0:
            print indent + "Value 0"
        elif root.label == 1:
            print indent + "Value 1"
        return

    print indent + root.decisionFeature 
    if not root.trueChild == None:
        print indent + root.decisionFeature + " == 1"
        printTree(root.trueChild, indent + " ")
    if not root.falseChild == None:
        print indent + root.decisionFeature + " == 0"
        printTree(root.falseChild, indent + " ")

def resetConfusionMatrix():
    confusionMatrix[0][0] = 0;
    confusionMatrix[0][1] = 0;
    confusionMatrix[1][0] = 0;
    confusionMatrix[1][1] = 0;

def printConfusionMatrix():
    print "Confusion Matrix"
    print "0 " + `confusionMatrix[0][0]` + " " + `confusionMatrix[0][1]`
    print "1 " + `confusionMatrix[1][0]` + " " + `confusionMatrix[1][1]`

for loop in range(2):
    print "---------------------------------------";
    print "Training set " + `loop + 1`
    print "---------------------------------------";
    features = getFeatures(rootDirectory + `loop+1` + trainingSetFile)
    classIndex = features.index('Class')
    features = features[:-1]

    trainingSet = readFile(rootDirectory + `loop+1` + trainingSetFile);
    validationSet = readFile(rootDirectory + `loop+1` + validationSetFile);
    testingSet = readFile(rootDirectory + `loop+1` + testSetFile);

    print "Training..."
    treeRoot = generateDecisionTree(trainingSet)

    # printTree(treeRoot, "")
    print 
    print "Before Pruning"
    trainingAccuracy = getAccuracy(trainingSet)
    validationAccuracy = getAccuracy(validationSet)
    resetConfusionMatrix()
    testingAccuracy = getAccuracy(testingSet)
    print "Training Accuracy: " + `trainingAccuracy`
    print "Validation Accuracy: " + `validationAccuracy`
    print "Testing Accuracy: " + `testingAccuracy`
    printConfusionMatrix()

    print 
    print "Pruning using Validation Data..."
    print
    pruneCount = prune(treeRoot, validationSet)
    trainingAccuracy = getAccuracy(trainingSet)
    validationAccuracy = getAccuracy(validationSet)
    resetConfusionMatrix()
    testingAccuracy = getAccuracy(testingSet)
    print "Count of Pruned Nodes: " + `pruneCount`
    print "Training Accuracy: " + `trainingAccuracy`
    print "Validation Accuracy: " + `validationAccuracy`
    print "Testing Accuracy: " + `testingAccuracy`
    printConfusionMatrix()
    print
    print
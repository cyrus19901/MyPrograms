import csv
import sys
import math
import sys
# Need to change the path for data_sets2 for executing the following for the other dataset.

trainingData = "data_sets2/training_set.csv" 
validationData = "data_sets2/validation_set.csv"
testData = "data_sets2/test_set.csv"
confusionMatrix = [
    [0, 0],
    [0, 0]
]
features = []
classIndex = -1
trainingSet = []
validationSet = []
testSet = []
treeRoot = None

class node:
    def __init__(self):
	  self.element = 'root'
	  self.label = 1
	  self.decisionFeature = 1
	  self.decisionFeatureIndex = 1
	  self.trueChild = None
	  self.falseChild = None
	  self.isPruned = False
	  self.majorityClass = 1

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

def calculateInformationGain(inputData, featureIndex):
    totalInput = len(inputData)

    totalTrue = 0
    totalFalse = 0

    trueSet = []
    falseSet = []

    for loop in range(totalInput):
	  if inputData[loop][featureIndex] == 1:
		totalTrue +=1
		trueSet.append(inputData[loop])
	  if inputData[loop][featureIndex] == 0:
		totalFalse += 1
		falseSet.append(inputData[loop])
    
    classEntropy = entropy(inputData)
    trueEntropy = (float(totalTrue) / float(totalInput)) * entropy(trueSet)
    falseEntropy = (float(totalFalse) / float(totalInput)) * entropy(falseSet)
    informationGain = classEntropy - trueEntropy - falseEntropy

    return informationGain

def entropy(dataSet):
    totalInput = len(dataSet)

    if totalInput == 0:
	  return 0

    trueCount = 0
    falseCount = 0

    for loop in range(len(dataSet)):
	  trueCount += dataSet[loop][classIndex]
    falseCount = len(dataSet) - trueCount
    trueprobability = float(trueCount)/float(totalInput)
    if (trueprobability == 0):
	  trueEntropy =0
    else :
	  trueEntropy= float(-trueprobability*math.log(trueprobability,2))
    falseprobability= float(falseCount)/float(totalInput)
    if (falseprobability == 0):
	  falseEntropy =0
    else :
	  falseEntropy= float(-falseprobability*math.log(falseprobability,2))
    return (trueEntropy + falseEntropy)

def decisionTree(dataSet):
    root = node()
    allPositive = True
    allNegative = True
    for loop in range(len(dataSet)):
	  if dataSet[loop][classIndex] == 0:
		allPositive = False
	  elif dataSet[loop][classIndex] == 1:
		allNegative = False
	  if not allPositive and not allNegative:
		break
    if allPositive:
	  root.element ='leaf'
	  root.label = 1
	  return root
    if allNegative:
	  root.element ='leaf'
	  root.label = 0
	  return root

    informationGain = []
    for loop2 in range(len(features)):
	  informationGain.append(calculateInformationGain(dataSet, loop2))
    featureIndex = informationGain.index( max(informationGain) )
    featureLabel = features[featureIndex]
    bestAttr = featureLabel
    bestAttrIndex = featureIndex
    root.element = 'root'
    root.decisionFeature = bestAttr
    root.decisionFeatureIndex = bestAttrIndex
    trueCount = 0
    falseCount = 0
    for loop1 in range(len(dataSet)):
	  trueCount += dataSet[loop1][classIndex]
    falseCount = len(dataSet) - trueCount
    if trueCount >= falseCount:
	  root.majorityClass=1
    else:
	  root.majorityClass=0
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
	  root.trueChild = decisionTree(trueDataSet)

    if falseDataSet:
	  root.element = 'root'
	  root.falseChild = decisionTree(falseDataSet)

    return root

def checkValue(root, dataSet):
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
	  return checkValue(root.trueChild, dataSet)
    if dataSet[attrIndex] == 0:
	  return checkValue(root.falseChild, dataSet)

def accuracy(dataSet):
    wrong = 0
    prediction =0 
    total = len(dataSet)
    for loop in range(len(dataSet)):
	  prediction = checkValue(treeRoot, dataSet[loop])
	  actual = dataSet[loop][len(dataSet[loop]) - 1]
	  confusionMatrix[actual][prediction] += 1
	  if(prediction != actual):
		wrong += 1

    return (1 - float(wrong)/float(total))*100

def prune(currentRoot, dataSet):
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
    currentIndex = len(queue) - 1
    while currentIndex != -1:
	  outputWithoutPrune = accuracy(dataSet)
	  queue[currentIndex].isPruned = True
	  outputWithPrune = accuracy(dataSet)
	  queue[currentIndex].isPruned = False
	  if outputWithoutPrune < outputWithPrune:
		queue[currentIndex].isPruned = True
	  currentIndex -= 1

def resetConfusionMatrix():
    confusionMatrix[0][0] = 0;
    confusionMatrix[0][1] = 0;
    confusionMatrix[1][0] = 0;
    confusionMatrix[1][1] = 0;

def printConfusionMatrix():
    print "Confusion Matrix"
    print "0 " + `confusionMatrix[0][0]` + " " + `confusionMatrix[0][1]`
    print "1 " + `confusionMatrix[1][0]` + " " + `confusionMatrix[1][1]`


with open(trainingData, 'r') as f:
	  reader = csv.reader(f)
	  attributes = next(reader)
	  featuresfile = attributes
f.close()
features = featuresfile
classIndex = features.index('Class')
features = features[:-1]

trainingSet = readFile(trainingData);
validationSet = readFile(validationData);
testingSet = readFile(testData);

treeRoot = decisionTree(trainingSet)

print "Accuracy before pruning"
trainingAccuracy = accuracy(trainingSet)
validationAccuracy = accuracy(validationSet)
resetConfusionMatrix()
testingAccuracy = accuracy(testingSet)
print "Training Accuracy"
print trainingAccuracy 
print "Validation Accuracy" 
print validationAccuracy
print "Testing Accuracy"
print testingAccuracy
printConfusionMatrix()
pruneCount = prune(treeRoot, validationSet)
trainingAccuracy = accuracy(trainingSet)
validationAccuracy = accuracy(validationSet)
resetConfusionMatrix()
testingAccuracy = accuracy(testingSet)
print "Accuracy after pruning"
print "Training Accuracy"
print trainingAccuracy 
print "Validation Accuracy" 
print validationAccuracy
print "Testing Accuracy"
print testingAccuracy
printConfusionMatrix()
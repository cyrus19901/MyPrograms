#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include <vector>

#include <math.h>

using namespace std;

struct Node {
    string element;
    int label;
    string decisionFeature;
    int decisionFeatureIndex;
    Node* trueChild;
    Node* falseChild;
    bool isPruned;
    int majorityClass;
};

float trainingAccuracy,testingAccuracy,validationAccuracy;
string trainingmodelFile = "data_sets2/training_set.csv";
string validationmodelFile = "data_sets2/validation_set.csv";
string testmodelFile = "data_sets2/test_set.csv";

vector<string> feature;
int labels = 1;

vector< vector<int> > trainingmodel;
vector< vector<int> > validationmodel;
vector< vector<int> > testingmodel;
vector< vector<int> > confustionMatrix;

Node* treeRoot;

Node* newNode() {
    Node *newNode = new Node();
    newNode->element = "root";
    newNode->label = -1;
    newNode->decisionFeature = "";
    newNode->decisionFeatureIndex = -1;
    newNode->trueChild = NULL;
    newNode->falseChild = NULL;
    newNode->isPruned = false;
    newNode->majorityClass = -1;
    return newNode;
}

void defaultConfustionMatrix(){
	vector<int> isfalse;
	isfalse.push_back(0);
	isfalse.push_back(0);
	vector<int> istrue;
	istrue.push_back(0);
	istrue.push_back(0);
	confustionMatrix.clear();
	confustionMatrix.push_back(isfalse);
	confustionMatrix.push_back(istrue);
}
void printmatrix(){
	cout << confustionMatrix[0][0] << "\t" << confustionMatrix[0][1] << endl;
	cout << confustionMatrix[1][0] << "\t" << confustionMatrix[1][1] << endl;
}

void printVector(vector<string> printThis) {
    for(int loop = 0; loop < printThis.size(); loop++){
        cout << printThis[loop] << " ";
    }
    cout << endl;
}

void printVector(vector<int> printThis) {
    for(int loop = 0; loop < printThis.size(); loop++){
        cout << printThis[loop] << " ";
    }
    cout << endl;
}

void printVector(vector<float> printThis) {
    for(int loop = 0; loop < printThis.size(); loop++){
        cout << printThis[loop] << " ";
    }
    cout << endl;
}

void printVector(vector< vector<int> > printThis) {
    for(int loop = 0; loop < printThis.size(); loop++){
        printVector(printThis[loop]);
    }
}

vector<string> calculatefeatures(string fileName) {
    vector<string> feature;
    
    ifstream infile(fileName);
    string line = "";
    getline(infile, line);
    stringstream strstr(line);
    string word = "";
    while (getline(strstr,word, ',')) {
        feature.push_back(word);
    }
    return feature;
}

vector< vector<int> > readFile(string fileName) {
    vector< vector<int> > dataSet;
    
    ifstream infile(fileName);
    string line = "";
    getline(infile, line);
    while (getline(infile, line)){
        stringstream strstr(line);
        string word = "";
        vector<int> dataSetLine;
        while (getline(strstr,word, ',')) {
            dataSetLine.push_back(stoi(word));
        }
        dataSet.push_back(dataSetLine);
    }
    return dataSet;
}

int calculateindex(vector<string> feature) {
    vector<string>::iterator it = find (feature.begin(), feature.end(), "Class");
    return (int)distance(feature.begin(), it);
}

int getMajorityLabel(vector< vector<int> > dataSet) {
    int trueCount = 0;
    int falseCount = 0;
    for( int loop = 0; loop < dataSet.size(); loop++) {
        trueCount += dataSet[loop][labels];
    }
    
    falseCount = (int)dataSet.size() - trueCount;
    
    if(trueCount >= falseCount) {
        return 1;
    } else {
        return 0;
    }
}

float entropyTerm(float probability) {
    if(probability == 0) {
        return 0;
    }
    
    float logValue = (float)log2(probability);
    
    return -1.0 * logValue * probability;
}

float entropy(vector< vector<int> > dataSet) {
    int totalInput = (int)dataSet.size();
    int trueCount = 0;
    int falseCount = 0;
    
    if(totalInput == 0) {
        return 0;
    }
    for( int loop = 0; loop < totalInput; loop++) {
        trueCount += dataSet[loop][labels];
    }
    falseCount = totalInput - trueCount;
    
    float trueEntropy = entropyTerm( (float)trueCount / (float)totalInput );
    float falseEntropy = entropyTerm( (float)falseCount / (float)totalInput );
    return (trueEntropy + falseEntropy);
}

float informationGain(vector< vector<int> > inputData, int featureIndex) {
    int totalInput = (int)inputData.size();
    
    int numberOfTrue = 0;
    int numberOfFalse = 0;
    
    vector< vector<int> > trueSet;
    vector< vector<int> > falseSet;
    
    for( int loop = 0; loop < totalInput; loop++) {
        if(inputData[loop][featureIndex] == 1) {
            numberOfTrue++;
            trueSet.push_back(inputData[loop]);
        }
        if(inputData[loop][featureIndex] == 0) {
            numberOfFalse++;
            falseSet.push_back(inputData[loop]);
        }
    }
    
    float classEntropy = entropy(inputData);
    float trueEntropy = ((float)numberOfTrue / (float)totalInput) * entropy(trueSet);
    float falseEntropy = ((float)numberOfFalse / (float)totalInput) * entropy(falseSet);
    float informationGain = classEntropy - trueEntropy - falseEntropy;
    
    return informationGain;
}


int getBestAttributeIndex(vector< vector<int> > dataSet) {
    vector<float> informationGain;
    float maxGain = -1;
    int maxGainIndex = -1;
    for( int loop = 0; loop < feature.size(); loop++) {
        float currentGain = informationGain(dataSet, loop);
        informationGain.push_back(currentGain);
        if(currentGain > maxGain) {
            maxGain = currentGain;
            maxGainIndex = loop;
        }
    }
    return maxGainIndex;
}

Node* generateDecisionTree(vector< vector<int> > dataSet) {
    Node* root = newNode();
    
    bool allPositive = true;
    bool allNegative = true;
    
    for( int loop = 0; loop < dataSet.size(); loop++) {
        if(dataSet[loop][labels] == 0){
            allPositive = false;
        } else if(dataSet[loop][labels] == 1) {
            allNegative = false;
        }
        if(!allPositive && !allNegative){
            break;
        }
    }
    
    if(allPositive) {
        root->element = "leaf";
        root->label = 1;
        return root;
    }
    if(allNegative) {
        root->element = "leaf";
        root->label = 0;
        return root;
    }
    
    int bestAttrIndex = getBestAttributeIndex(dataSet);
    string bestAttr = feature[bestAttrIndex];
    
    root->element = "root";
    root->decisionFeature = bestAttr;
    root->decisionFeatureIndex = bestAttrIndex;
    root->majorityClass = getMajorityLabel(dataSet);
    
    vector< vector<int> > trueDataSet;
    vector< vector<int> > falseDataSet;
    
    for( int loop = 0; loop < dataSet.size(); loop++) {
        if(dataSet[loop][bestAttrIndex] == 1) {
            trueDataSet.push_back(dataSet[loop]);
        } else {
            falseDataSet.push_back(dataSet[loop]);
        }
    }

    if(!allNegative && !allPositive && ((trueDataSet.size() == 0 && falseDataSet.size() > 0) || (trueDataSet.size() > 0 && falseDataSet.size() == 0))) {
        root->element = "leaf";
        root->label = 0;
        return root;
    }
    
    if(trueDataSet.size() > 0) {
        root->element = "root";
        root->trueChild = (Node *)(generateDecisionTree(trueDataSet));
    }
    
    if(falseDataSet.size() > 0) {
        root->element = "root";
        root->falseChild = (Node *)generateDecisionTree(falseDataSet);
    }
    
    return root;
}

int getAnswer(Node* root, vector<int> dataSet) {
    if(root == NULL) {
        return -1;
    }
    
    if(root->element == "leaf"){
        if(root->label == 0 || root->label == 1) {
            return root->label;
        }
    }
    
    if(root->isPruned) {
        return root->majorityClass;
    }
    
    int attrIndex = root->decisionFeatureIndex;
    if(dataSet[attrIndex] == 1) {
        return getAnswer(root->trueChild, dataSet);
    }
    if(dataSet[attrIndex] == 0) {
        return getAnswer(root->falseChild, dataSet);
    }
    return -1;
}

float accuracy(vector< vector<int> > dataSet, bool updateMatrix = false) {
    int correct = 0;
    int total = (int)dataSet.size();
    for( int loop = 0; loop < dataSet.size(); loop++) {
        int prediction = getAnswer(treeRoot, dataSet[loop]);
        int answer = dataSet[loop][labels];
        
        if(updateMatrix==true) {
            confustionMatrix[answer][prediction]++;
        }
        
        if( prediction == answer ) {
            correct += 1;
        }
    }
    return ( (float)correct / (float)total ) * 100;
}

vector<Node*> getBfsQueue(Node* treeRoot) {
    vector<Node*> queue;
    queue.push_back(treeRoot);
    int currentIndex = 0;
    int queueSize = 1;
    while(currentIndex < queueSize) {
        Node* root = queue[currentIndex];
        if(root == NULL) {
            continue;
        }
        if(root->element == "root") {
            if(root->trueChild) {
                queue.push_back(root->trueChild);
                queueSize++;
            }
            if(root->falseChild) {
                queue.push_back(root->falseChild);
                queueSize++;
            }
        }
        currentIndex++;
    }
    return queue;
}

int prunetree(Node* currentRoot, vector< vector<int> > dataSet) {
    vector<Node*> queue = getBfsQueue(treeRoot);
    int currentIndex = (int)queue.size() - 1;
    int prunetreeCount = 0;
    while(currentIndex != -1) {
        float outputWithoutPrune = accuracy(dataSet);
        queue[currentIndex]->isPruned = true;
        float outputWithPrune = accuracy(dataSet);
        queue[currentIndex]->isPruned = false;
        
        if(outputWithoutPrune < outputWithPrune) {
            prunetreeCount++;
            queue[currentIndex]->isPruned = true;
        }
        currentIndex--;
    }
    return prunetreeCount;
}

int main(int argc, const char * argv[]) {
    feature = calculatefeatures(trainingmodelFile);
    labels = calculateindex(feature);
    feature.erase(feature.end() - 1);
    trainingmodel = readFile(trainingmodelFile);
    validationmodel = readFile(validationmodelFile);
    testingmodel = readFile(testmodelFile);
    treeRoot = generateDecisionTree(trainingmodel);
    cout << "Before Pruning" << endl;
    defaultConfustionMatrix();
    trainingAccuracy = accuracy(trainingmodel);
    validationAccuracy = accuracy(validationmodel);
    testingAccuracy = accuracy(testingmodel,true);
	cout << "Training Accuracy " << trainingAccuracy << "Validation Accuracy " << validationAccuracy << "Testing Accuracy " << testingAccuracy << endl;
    printmatrix();
    
    defaultConfustionMatrix();
    cout << endl;
    cout << "After Pruning" << endl;
    int prunetreeCount = prunetree(treeRoot, validationmodel);
    cout << "Pruned " << prunetreeCount << " nodes" << endl;
    trainingAccuracy = accuracy(trainingmodel);
    validationAccuracy = accuracy(validationmodel);
    testingAccuracy = accuracy(testingmodel);
    cout << "Training Accuracy " << trainingAccuracy << "Validation Accuracy " << validationAccuracy << "Testing Accuracy " << testingAccuracy << endl;
    printmatrix();
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * NewNode (int data){
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->data= data;
	temp->left=NULL;
	temp->right=NULL;
	return temp; 
}

void inorder(struct node* root, vector<int>&value){
	if (root==NULL)
		return;
	inorder(root->left, value);
	cout << root->data <<"\t";
	value.push_back(root->data);
	inorder(root->right,value);
}
void checkpairsum(vector<int> value,int begin, int target){
	int sum =0;
	for (int i=begin; i <value.size(); i ++){
		sum = value[begin]+value[i];
		if (sum==target){
			cout << "the pairs are"<< value[begin] <<"\t" << value[i];
			cout <<"sum is "<<sum;
		}
	}
	if (begin<value.size())
		checkpairsum(value, begin+1, target);
}
void isPairPresent(struct node * root, int target){
	vector<int> value;
	if (root==NULL)
		return;
	inorder(root,value);
	checkpairsum(value,0,target);
}
int main(){
	struct node * root= NewNode(15);
 	root->left = NewNode(10);
    root->right = NewNode(20);
    root->left->left = NewNode(8);
    root->left->right = NewNode(12);
    root->right->left = NewNode(16);
    root->right->right = NewNode(25);
    int target = 33;
    isPairPresent(root, target);
}
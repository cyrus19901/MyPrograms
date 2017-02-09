#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * newnode (int data){
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->data= data;
	temp->left=NULL;
	temp->right=NULL;
	return temp; 
}
void printpath(vector<int>&path){
	for (int i=0; i <path.size(); i ++){
		cout << path[i]<< "->" <<"\t";
	}
	path.clear();

}
void addPath(struct node * root, vector<int> path){
	if (root==NULL)
		return;
	path.push_back(root->data);
	if (root->left==NULL && root->right==NULL){
		printpath(path);
	}
	else{
		addPath(root->left, path);
		addPath(root->right,path);
	}
}
void rooToLeaf(struct node * root){
	vector<int> path;
	addPath(root, path);
}
int main(){
	struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
    rooToLeaf(root);
}
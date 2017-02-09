#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right; 
};

struct node * newNode (int data){
	struct node * temp = (struct node *)malloc (sizeof(node));
	temp->data= data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorder(struct node * root){
	if (root != NULL){
		inorder(root->left);
		cout << root->data <<"\t";
		inorder(root->right);
	}
}
void preorder(struct node * root){
	if (root != NULL){
		cout << root->data <<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node * root){
	if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data <<"\t";
	}
}
int depthoftree(struct node * root){
	if (root == NULL)
		return 0;
	else{
		int ldepth = depthoftree(root->left);
		int rdepth = depthoftree(root->right);
		if (ldepth >rdepth)
			return (ldepth+1);
		else 
			return (rdepth+1);
	}
}
int main (){
	struct node * root = newNode(10);
	root->left = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(4);
	root->right = newNode(70);
	root->right->left = newNode(6);
	root->right->right = newNode(10);
	inorder(root);
	cout <<endl;
	preorder(root);
	cout <<endl;
	postorder(root);
	int depth = depthoftree(root);
	cout << "the depth is = " << depth <<endl ;
	return  0;
}
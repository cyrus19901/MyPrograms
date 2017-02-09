#include <iostream>
#include <vector>
using namespace std;


struct node{
	int data;
	struct node * left;
	struct node * right;
};

struct node * newnode(int data){
	struct node * node = (struct node*)malloc(sizeof(node));
	node->data = data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void inorder(struct node * root){
	if (root != NULL){
		inorder(root->left);
		cout<< root->data<<"\n"<<endl;
		inorder(root->right);
	}
}

int isBST(struct node* root){
	if (root==NULL)
		return true;
	if (root->left != NULL && root->left->data > root->data)
		return false;
	if (root->right !=NULL && root->right->data < root->data)
		return false;
	if (! isBST(root->left) || ! isBST(root->right))
		return false;
	else return true;
}
int main(){
	struct node * root = newnode(4);
	root->left= newnode(2);
	root->right= newnode(5);
	root->left->left= newnode(1);
	root->left->right= newnode(3);
	//inorder(root);
	bool output = isBST(root);
	cout <<output;
	if (output==1)
		cout <<"it is a BST"<<endl;
	else 
		cout <<"it is not a BST"<<endl;
	return 0;
}
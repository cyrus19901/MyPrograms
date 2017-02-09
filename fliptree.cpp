#include <iostream>
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
	return  temp;
}

struct node * fliptree(struct node *root){
	if (root==NULL)
		return root;
	if ((root->left == NULL) && (root->right ==NULL))
		return root;
	struct node * flipnode = fliptree(root->left);
	root->left->left= root->right;
	root->left->right= root;
	root->left=NULL;
	root->right=NULL;
	cout << flipnode <<"\t";


}
int inorder(struct node * root){
	if (root==NULL)
		return 0;
	cout << root->data<<"\t";
	inorder(root->left);
	inorder(root->right);
}
int main(){
	struct node * root = newnode(10);
	root->left = newnode(5);
	root->left->left = newnode(1);
	root->left->right = newnode(6);
	root->right = newnode(15);
	inorder(root);
	cout <<endl;
	// cout << fliptree(root);
	inorder(root);
	return 0;
}
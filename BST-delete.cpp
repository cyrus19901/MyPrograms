#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <vector>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node *newnode (int key){
	struct node * newnode = (struct node*)malloc(sizeof(struct node));
	newnode -> data = key;
	newnode ->left =NULL;
	newnode ->right =NULL;
	return newnode;
}

void inorder(struct node * root){
	if (root != NULL){
		inorder(root->left);
		cout << root->data <<endl << "\n";
		inorder(root->right);
	}
}
struct node* insert (struct node *node , int data){
	if (node == NULL ){
		return newnode(data);
	}
	if (data < node ->data){
		node->left = insert(node->left , data);
	}
	if (data > node ->data){
		node->right = insert(node->right , data);
	}
	return node ;
}

struct node* minvalue(struct node *node , int data){
	struct node * current = node;
	 while (current->left != NULL){
	 	current= current->left;
	 } 
	 return current;
}

struct node * deletenode(struct node * node , int data){
	if (node ==NULL){
		return node;
	}
	else if (data < node->data){
		node->left = deletenode(node->left, data);
	}
	else if (data > node->data){
		node->right = deletenode(node->right, data);
	}
	else 
	{
		if (node->left ==NULL){
			struct node * temp = node->right;
			free(node);
			return temp;
		}
		if (node->right ==NULL){
			struct node * temp = node->left;
			free(node);
			return temp;
		}
	}
	return node;
}
int main (){
	struct node *root = NULL;
	root= insert(root, 50);
	root= insert(root, 60);
	root= insert(root, 80);
	root= insert(root, 20);
	root= insert(root, 30);
	root= insert(root, 100);
	root= insert(root, 10);
	cout << "inorder traversal" <<endl << "\n";
	inorder(root);
	root = deletenode(root,50);
	inorder(root);
	root = deletenode(root,80);
	inorder(root);
	root = deletenode(root,30);
	inorder(root);
	return 0;
	
}
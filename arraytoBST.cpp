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

struct node * insert(struct node* node,int data){
	if (node==NULL)
		return newnode(data);
	if (data < node->data)
		node->left = insert(node->left, data);
	if (data> node->data)
		node->right = insert(node->right, data);
	return node;
}

int main (){
	int arr[7]= {7,6,5,4,3,2,1};
	struct node *root = NULL;
	for (int i=0 ; i <7 ; i++){
		root= insert(root, arr[i]);
	}
	cout << "inorder traversal" <<endl << "\n";
	inorder(root);
	return 0;
	
}
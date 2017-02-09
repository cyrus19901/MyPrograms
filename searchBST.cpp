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

void search(struct node * node , int data){
	if (node==NULL)
		cout <<"node does not exist"<<endl;
	else if (data == node->data){
		//cout << node->data;
		cout << "node exists"<<endl;
	}
	else if (data < node->data){
		search(node->left, data);
	}
	else if (data > node->data){
		search(node->right, data);
	}
	else
		cout <<"node does not exist"<<endl;
	//return false;
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
	int searchdata = 101;
	struct node *root = NULL;
	root= insert(root, 50);
	root= insert(root, 60);
	root= insert(root, 80);
	root= insert(root, 20);
	root= insert(root, 30);
	root= insert(root, 100);
	root= insert(root, 10);
	cout << "inorder traversal" <<endl << "\n";
	search(root, searchdata);
	//cout <<output;
	// if (output==true)
	// 	cout <<"node exists"<<endl;
	// else
	// 	cout <<"node does not exist"<<endl;
	inorder(root);
	return 0;
	
}
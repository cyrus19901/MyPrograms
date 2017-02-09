#include <iostream>
#include <vector>
#include <map>
using namespace std;
//initialize a struct node
struct node {
	int data;
	node * right;
	node * left;
};

//create a new node with some value 
struct node * newnode (int key){
	struct node * newnode = (struct node *)malloc(sizeof(node));
	newnode -> data = key;
	newnode -> right =NULL;
	newnode -> left  =NULL;
	return newnode;
}

void inorder(struct node * root){
	if (root != NULL){
		inorder(root->left);
		cout << root->data <<endl;
		inorder(root->right);
	}
}

struct node * insert(struct node * node , int key){
	if (node == NULL){
		return newnode(key);
	}
	if (key < node->data){
		node->left = insert (node->left, key);
	}
	else if (key > node->data){
		node-> right = insert(node->right , key);
	}
	return node;
}

int main(){
	node * root = NULL;
	root = insert (root,50);
	insert (root,30);
	insert (root,20);
	insert (root,40);
	insert (root,70);
	insert (root,60);
	insert (root,80);
	inorder(root);
	return 0;
} 
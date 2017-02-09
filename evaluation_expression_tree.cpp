#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>  
using namespace std;

struct node {
	string str;
	struct node * left;
	struct node * right;
};

struct node * newnode (string str){
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->str = str;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int evaluate(struct node * root){
	if (root==NULL)
		return 0;
	if (!root->left && !root->right){
		return stoi(root->str);
	}
	int eval_left = evaluate(root->left);
	int eval_right = evaluate(root->right);
	if (root->str == "+")
		return eval_right +eval_left;
	if (root->str == "-")
		return eval_left -eval_right;
	if (root->str == "*")
		return eval_right  * eval_left;
	if (root->str == "/")
		return eval_right  / eval_left;
}
void inorder(struct node * root){
	if (root==NULL)
		return;
	cout << root->str << "\t";
	inorder(root->left);
	inorder(root->right);
}
int main(){
	struct node * root = newnode("+");
	root->left = newnode("*");
	root->right = newnode("-");
	root->left->left = newnode("5");
	root->left->right = newnode("4");
	root->right->left = newnode("100");
	root->right->right = newnode("20");
	// inorder(root);
	int result = evaluate(root);
	cout <<result;
	return 0;
}
#include <iostream>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
	struct node * nextRight;
};

struct node * newnode(int data){
	struct node * newnode = (struct node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->left= NULL;
	newnode->right= NULL;
	newnode->nextRight= NULL;
	return newnode;
}
void connectothers(struct node * p){
	if (!p)
		return;
	if (p->left)
		p->left->nextRight= p->right;
	if (p->right)
		p->right->nextRight= (p->nextRight)? p->nextRight->left : NULL;
	connectothers(p->left);
	connectothers(p->right);
}

void connect(struct node * p ){
	p->nextRight = NULL;
	connectothers(p);
}
void print(struct node * root){
	if (root != NULL){
		print(root->left);
		cout << root->data <<endl << "\t";
		print(root->right);

	}
}

int main(){
	struct node * root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	print(root);
	connect(root);
}
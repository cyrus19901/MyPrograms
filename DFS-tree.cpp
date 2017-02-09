#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
};

void preOrder(struct Node * root){
	if (root==NULL)
		return;
	cout << root->data <<"\t";
	preOrder(root->left);
	preOrder(root->right);

}

void inOrder(struct Node * root){
	if (root==NULL)
		return;
	inOrder(root->left);
	cout << root->data <<"\t";
	inOrder(root->right);
	
}
void postOrder(struct Node * root){
	if (root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data <<"\t";
}
struct Node * newNode(int data){
	struct  Node * new_node = (struct Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right= NULL;
	return new_node;
}

int main(){
	struct Node * root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	preOrder(root);
	cout <<endl;
	inOrder(root);
	cout <<endl;
	postOrder(root);
	return 0;

}
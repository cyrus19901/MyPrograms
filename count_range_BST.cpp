#include <iostream>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node *right ;
};

struct node * newNode(int data){
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->data = data;
	temp->left =NULL;
	temp->right =NULL;
	return temp;
}
int inorder(struct node * root){
	if (!root)
		return -1;
	inorder(root->left);
	cout << root->data<<"\t";
	inorder(root->right);
	return 0;
}
int getcount(struct node * root, int l, int h){
	if (root == NULL)
		return 0;
	if (root->data==l && root->data == h)
		return 1;	
	if (root->data >= l && root->data <= h)
		return (1 + getcount(root->left,l,h)+getcount(root->right,l,h));
}
int main(){
	struct node * root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(50);
	root->left->left = newNode(1);
	root->right->right = newNode(100);
	root->right->left = newNode(40);
	inorder(root);
	int l = 5;
	int h = 45;
	int result = getcount(root,l,h);
	cout << "count is :" << result <<endl;
	return 0;
}
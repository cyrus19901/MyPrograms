#include <iostream>
#include <stack>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * newNode (int data){
	struct node * temp = (struct node *)malloc (sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * RemoveHalfNodes(struct node * root){
	if (root==NULL)
		return NULL;
	root->left=RemoveHalfNodes(root->left);
	root->right=RemoveHalfNodes(root->right);
	if (root->left == NULL && root->right ==NULL){
		return root;
	}
	if (root->left ==NULL){
		struct node * new_node = root->right;
		free(root);
		return new_node;
	}
	if (root->right ==NULL){
		struct node * new_node = root->left;
		free(root);
		return new_node;
	}
	return root;
}

void printInoder(struct node * root){
	if (root==NULL)
		return ;
	printInoder(root->left);
	cout << root->data;
	printInoder(root->right);
}
int main(void)
{
    struct node* NewRoot=NULL;
    struct node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
 
    printf("Inorder traversal of given tree \n");
    printInoder(root);
 
    NewRoot = RemoveHalfNodes(root);
 
    printf("\nInorder traversal of the modified tree \n");
    printInoder(NewRoot);
    return 0;
}
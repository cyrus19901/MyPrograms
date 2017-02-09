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
bool checkleaf(struct node * root){
	if (root==NULL)
		return false;
	if (root->left == NULL && root->right == NULL)
		return true;
	else 
		return false;

}
int leftLeavesSum(struct node * root , int &sum){
	if (root == NULL)
		return 0;
	if (checkleaf(root->left)){
		sum = sum +(root->left->data);
	}
	leftLeavesSum(root->left,sum);
	leftLeavesSum(root->right,sum);
	return sum;
}

void printInoder(struct node * root){
	if (root==NULL)
		return ;
	printInoder(root->left);
	cout << root->data << "\t";
	printInoder(root->right);
}
int main()
{
    struct node *root         = newNode(20);
    root->left                = newNode(9);
    root->right               = newNode(49);
    root->right->left         = newNode(23);
    root->right->right        = newNode(52);
    root->right->right->left  = newNode(50);
    root->left->left          = newNode(5);
    root->left->right         = newNode(12);
    root->left->right->right  = newNode(15);
    printInoder(root);
    int sum;
    cout << "Sum of left leaves is ";
	leftLeavesSum(root, sum);
	cout <<sum<<endl;
    return 0;
}
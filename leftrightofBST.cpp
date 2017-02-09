#include <iostream>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * newnode(int data){
	struct node * temp = (struct node *)malloc (sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->left = NULL;
	return temp;
}

int height(struct node * root){
	int lheight,rheight=0;
	if (root==NULL)
		return 0;
	if ((root->left) && (root->right)){
		lheight = height(root->left);
		rheight = height(root->right);
	}
	if (lheight > rheight)
		return (lheight+1);
	else
		return (rheight+1);
}

int leftright(struct node * root)
{	int count=1;
	int h = height(root);
	if (root == NULL)
		return 0;
	if (root->left != NULL && root->right != NULL ){
		cout << root->data << "\t";
		leftright(root->left);
		leftright(root->right);
		count ++;
	} 


	//cout <<root->data<<"\t";
	// if (root->left==NULL && count >=2){
	// 	count++;
	// }
	// if (root->right==NULL && count>=2){

	// 	count++;
	// }
}


int main(){
	struct node * root = newnode(15);
	root->left=newnode(10);
	root->left->left=newnode(8);
	root->left->right=newnode(12);
	root->right = newnode(20);
	root->right->left=newnode(16);
	root->right->right=newnode(25);
	leftright(root);
	return 0;
}
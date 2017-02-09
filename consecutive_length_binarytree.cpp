#include <iostream>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * newnode (int data){
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->data= data;
	temp->left=NULL;
	temp->right=NULL;
	return  temp;
}

int inorder(struct node * root){
	if (root==NULL)
		return 0;
	cout << root->data<<"\t";
	inorder(root->left);
	inorder(root->right);
}
int consecutive_pathlength(struct node * root,int lenght){
	if (root==NULL)
		return 0;
	if ((root->left) || (root->right)){
		if (abs(root->left->data - root->data == 1) || abs(root->right->data - root->data == 1)){
			lenght ++;
			consecutive_pathlength(root->left,lenght);
			consecutive_pathlength(root->right,lenght);
		}
		return lenght; 
	}
	
}
int main(){
	struct node * root = newnode(10);
	root->left = newnode(11);
	root->right = newnode(9);
	root->left->left = newnode(13);
	root->left->right = newnode(12);
	root->right->left = newnode(13);
	root->right->right = newnode(8);
	inorder(root);
	cout <<endl;
	cout <<"length"<<"\t"<<consecutive_pathlength(root,1)<<endl;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node * newnode (int value){
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->data=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int printtree(struct node * root){
	if (root==NULL)
		return 0;
	cout << root->data << "\t";
	printtree(root->left);
	printtree(root->right);
}
void printroute(int path[],int pathlenght){
	for (int i=0; i <pathlenght;i++){
		cout << path[i] <<"\t"<<endl;
	}
}
void printPath(struct node * root , int path[], int pathlenght){
	if (root==NULL)
		return;
	path[pathlenght]=root->data;
	pathlenght++;

	if (root->left==NULL && root->right ==NULL){
		printroute(path,pathlenght);
		cout << endl;
	}
	else{
		printPath(root->left,path,pathlenght);
		printPath(root->right,path,pathlenght);
	}
}
void roottoleaf(struct node * root){
	int path[1000];
	int pathlenght=0;
	printPath(root,path,pathlenght);
}

int main(){
	struct node * root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	root->left->right = newnode(5);
	root->right->left = newnode(2);
	roottoleaf(root);
	//printtree(root);
}	
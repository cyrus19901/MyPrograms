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
int height(struct node * root){
	if (root==NULL)
		return 0;
	int lheight=height(root->left);
	int rheight=height(root->right);
	if (lheight>rheight)
		return (lheight+1);
	else
		return (rheight+1);
}
void printLevelOrder(struct node * root, int h){
	if (root==NULL)
		return;
	if (h==1)
		cout << root->data <<"\t";
	else{
		printLevelOrder(root->left,h-1);
		printLevelOrder(root->right,h-1);
	}


}
void levelOrder(struct node * root){
	int h=0;
	h = height(root);
	cout <<"the height of the tree is : "<< h <<endl;
	for (int i=h; i >=1; i --){
		printLevelOrder(root,i);
	}
}

int main(){
	struct node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);
	levelOrder(root);
	return 0;
}
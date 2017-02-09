#include <iostream>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * newNode (int data){
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->data= data;
	temp->left=NULL;
	temp->right=NULL;
	return  temp;
}

void inorder(struct node * root){
	if (root==NULL)
		return;
	cout << root->data << "\t";
	inorder(root->left);
	inorder(root->right);
}
int distanceDownX(struct node * root, struct node * x){
	int lDistance=0;
	int rDistance=0;

	if (root==NULL)
		return false;
	if (x->left!=NULL){
		lDistance = distanceDownX(root,x->left);
	}
	if (x->right!=NULL){
		rDistance = distanceDownX(root,x->right);
	}
	return (max(lDistance+1,rDistance+1));
	
}
int distanceDownRoot (struct node *root, struct node *x){
	int lDistance=0;
	int rDistance=0;
	if (root==NULL)
		return 0;
	if (root != x && root !=NULL){
		lDistance = distanceDownRoot(root->left, x);
	}
	if (root != x && root !=NULL){
		rDistance = distanceDownRoot(root->right, x);
	}
	return (max(lDistance+1,rDistance+1));
}
int minimumDistance(struct node * root,struct node *x){
	if (root==NULL)
		return false;
	int minValDownX;
	int minValRoot;
	minValDownX=distanceDownX(root,x);
	minValRoot= distanceDownRoot(root,x);
	return min(minValDownX,minValRoot);
}
int main(){
	struct node * root  = newNode(1);
    root->left  = newNode(12);
    root->right = newNode(13);
    root->right->left   = newNode(14);
    root->right->right  = newNode(15);
    root->right->left->left   = newNode(21);
    root->right->left->right  = newNode(22);
    root->right->right->left  = newNode(23);
    root->right->right->right = newNode(24);
 
    root->right->left->left->left  = newNode(1);
    root->right->left->left->right = newNode(2);
    root->right->left->right->left  = newNode(3);
    root->right->left->right->right = newNode(4);
    root->right->right->left->left  = newNode(5);
    root->right->right->left->right = newNode(6);
    root->right->right->right->left = newNode(7);
    root->right->right->right->right = newNode(8); 
    struct node *x = root->right;
    inorder(root);
    cout <<endl;
    cout << "the minimum distance is  " << minimumDistance(root, x) << endl;
    return 0;
}
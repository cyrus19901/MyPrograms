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
	else{
		int lheight = height(root->left);
		int rheight = height(root->right);
		if (lheight > rheight)
			return (lheight+1);
		else
			return (rheight+1);
	}
}
int printGivenLevel(struct node * root1,struct node * root2, int h){
	
	if (root1==NULL && root2==NULL)
		return 0;
	if (root1->data != root2->data)
		return 0;
	else if (h>1){
		printGivenLevel(root1->left,root2->left, h-1);
		printGivenLevel(root1->right,root2->right, h-1);
	}
	else 
		return 1;
}
// void levelOrder(struct node * root){
// 	int h = height(root);
// 	if (root==NULL)
// 		return;
// 	for (int i=1; i <=h; i++){
// 		printGivenLevel(root,i);
// 	}
// }

void comparetowtrees(struct node * root1, struct node * root2){
	int result;
	int h1 = height(root1);
	int h2 = height(root2);
	if (root1 == NULL && root2 == NULL)
		return;
	if (h1 == h2){
		for (int i =0;i <h1; i++){
			result= printGivenLevel(root1,root2,i);
	} 
	}
	if (result ==1)
		cout << "the trees are equal" <<endl;
	else 
		cout << "not equal" <<endl; 

}

int main(){
	struct node *root1 = newnode(1);
    root1->left        = newnode(2);
    root1->right       = newnode(3);
    root1->left->left  = newnode(4);
    root1->left->right = newnode(5);
	// levelOrder(root1);
	cout <<endl;

	struct node *root2 = newnode(1);
    root2->left        = newnode(2);
    root2->right       = newnode(3);
    root2->left->left  = newnode(4);
    root2->left->right = newnode(5);
	// levelOrder(root2);

	comparetowtrees(root1,root2);
	return 0;
}
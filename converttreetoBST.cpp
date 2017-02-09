#include <iostream>
#include <vector>
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
void preorder(struct node * root){
	if (root == NULL)
		return;
	preorder(root->left);	
	preorder(root->right);
}
void storevalue(struct node * root, vector<struct node *> &nodes){
	if (root==NULL)
		return;
	storevalue(root->left, nodes);
	nodes.push_back(root);
	storevalue(root->right, nodes);
}
struct node * arrangeinBST(vector <struct node *> &nodes, int start , int end){

	if (start > end)
		return NULL;
	int mid = (start+end)/2;
	struct node * root = nodes[mid];
	root->left = arrangeinBST(nodes, start, mid-1);
	root->right = arrangeinBST(nodes, mid+1, end);
	return root;

}
struct node * convertBST(struct node * root){
	vector < struct node * > nodes;
	storevalue(root, nodes); 
	int size = nodes.size();
	cout <<size;
	return arrangeinBST(nodes,0, size-1);
}

int main(){
	struct node * root = newnode(10);
	root->left = newnode(8);
    root->left->left = newnode(7);
    root->left->left->left = newnode(6);
    root->left->left->left->left = newnode(5);
	root= convertBST(root);
	preorder(root);
	return 0;
}
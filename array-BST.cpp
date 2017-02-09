#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
};

struct Node * newNode(int data){
	struct  Node * new_node = (struct Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right= NULL;
	return new_node;
}

struct Node * convertBST(int arr[], int start , int end){

	if (start > end)
		return 0;
	int mid = (start + end )/2;
	struct Node * root =  newNode(arr[mid]);
	root->left = convertBST(arr,start, mid-1);
	root->right = convertBST(arr,mid+1, end);
	return root;
}

void preOrder(struct Node * root){
	if (root==NULL)
		return;
	cout << root->data <<"\t";
	preOrder(root->left);
	preOrder(root->right);

}

int main(){

	int arr[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	struct Node * node  = convertBST(arr,0, size-1);
	preOrder(node);
	return 0;
}
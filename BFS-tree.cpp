#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
};

void BST(struct Node * root){
	if (root == NULL)
		return;
	queue <struct Node * > q;
	q.push(root);
	while (q.empty() == false){
		struct Node * node = q.front();
		cout << node->data <<"\t";
		q.pop();
		if (node->left !=NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
	}

}
struct Node * newNode(int data){
	struct  Node * new_node = (struct Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right= NULL;
	return new_node;
}

int main(){
	struct Node * root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	BST(root);
	//printnode(root);
	return 0;

}
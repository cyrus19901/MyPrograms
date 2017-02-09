#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct node * newnode (int data){
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->data= data;
	temp->left= NULL;
	temp->right= NULL;
	return temp;
}

void diagonalutil(struct node * root, int d, map<int,vector<int> > &diagonalprint){

	if (root==NULL)
		return;
	diagonalprint[d].push_back(root->data);
	diagonalutil(root->right, d, diagonalprint);
	diagonalutil(root->left, d+1, diagonalprint);
}
int diagonalprint(struct node * root){
	map <int,vector<int> > diagonalprint;
	diagonalutil(root, 0, diagonalprint);
		for (auto it = diagonalprint.begin();
         it != diagonalprint.end(); ++it)
    		{
        	for (auto itr = it->second.begin();
             	itr != it->second.end(); ++itr)
        		cout << *itr  << ' ';
			
			cout << '\n';
    	}
	
}
int main (){
	struct node * root = newnode(8);
    root->left = newnode(3);
    root->right = newnode(10);
    root->left->left = newnode(1);
    root->left->right = newnode(6);
    root->right->right = newnode(14);
    root->right->right->left = newnode(13);
    root->left->right->left = newnode(4);
    root->left->right->right = newnode(7);
    diagonalprint(root);
    return 0;
}
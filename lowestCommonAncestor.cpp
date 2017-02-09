#include <iostream>
#include <vector>
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
	return temp; 
}
bool findPathLenght(struct node * root, vector<int>&pathlength,int n){
	if (root==NULL)
		return false;
	pathlength.push_back(root->data);
	if (root->data==n)
		return true;
	if (root->left && findPathLenght(root->left,pathlength,n)||(root->right && findPathLenght(root->right,pathlength,n)))
	{
		return true;
	}
	pathlength.pop_back();
	return false;
}
	
void LCA (struct node * root, int n , int m){

	vector<int>pathLenght1;
	vector<int>pathLenght2;
	findPathLenght(root,pathLenght1,n);
	findPathLenght(root,pathLenght2,m);

	for (int i=0; i <pathLenght2.size(); i ++){
		cout << pathLenght1[i]<<"\t";
	}
	
	if ((pathLenght1.size() == 0 )|| (pathLenght2.size() == 0)){
		cout <<"LCA not present";
	}
	for (int i=0; i < pathLenght1.size()&& i < pathLenght2.size(); i++){
		if (pathLenght1[i] != pathLenght2[i])
			cout <<"LCA :"<<"\t" <<pathLenght1[i-1]<<endl;
	}
}
int main(){
	struct node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    LCA(root ,4,5);
}
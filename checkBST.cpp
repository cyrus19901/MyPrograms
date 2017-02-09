#include <iostream>
using namespace std;

struct node {
  int data;
  struct node * left;
  struct node *right;
};

struct node * newNode(int data){
  struct node * temp= (struct node *)malloc(sizeof(node));
  temp->data= data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

void isBST(struct node * root){
  if (root==NULL)
    return;
  if(root->left && root->left->data > root->data)
    cout <<"its not a BST";
  if(root->right && root->right->data < root->data)
    cout <<"its not a BST";
  else 
    cout <<"its a BST" <<endl;
  isBST(root->left);
  isBST(root->right);
}
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
  isBST(root);
  return 0;
}  
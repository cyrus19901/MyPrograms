#include <iostream>
#include <stdlib.h>
using namespace std;

struct Stacknode{
	int data;
	struct Stacknode * next;
};

struct Stacknode * newnode(int data){
	struct Stacknode * stackNode = (struct Stacknode *)malloc(sizeof(Stacknode));
	stackNode -> data = data;
	stackNode -> next = NULL;
	return stackNode;
}

// int isEmpty(Stacknode * root){
// 	return ! root;
// }

void push(struct Stacknode ** root, int data){
	struct Stacknode * stackNode = newnode(data);
	stackNode ->next = *root;
	*root = stackNode;
	cout << "the data has been pushed" <<"\t"<<data<<endl; 
}

int pop(struct Stacknode ** root){
	if (root ==NULL){
		return false;
	}
	struct Stacknode * temp = *root;
	*root= (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int main(){
	struct Stacknode * root = NULL;
	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	cout << "no popping from top"<<"\t"<<pop(&root)<<endl;

	return 0;
}
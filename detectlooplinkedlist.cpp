#include <iostream>
#include <vector>
using namespace std;


struct node {
	int data;
	struct node * next;
};

struct node * newNode(int value){
	struct node * newnode = (struct node *)malloc(sizeof(node));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
} 
int detectloop(struct node * list){
	struct node * slow = list;
	struct node * fast = list;
	while (slow && fast && fast->next){
		slow=list->next;
		fast=list->next->next;
		if (slow == fast){
			cout <<"there is a loop";
		}
	}
	return 0;
}
void print(struct node * head){
	while (head != NULL){
		cout << head->data;
		head = head->next;
	}
}
int main(){
	struct node * head = newNode (20);
	head->next = newNode(10);
	head->next->next = newNode(30);
	head->next->next->next = newNode(5);
	head->next->next->next->next = newNode(60);

	// looped node
	head->next->next->next->next->next= head->next->next;
	print(head);
	//detectloop(head);
}
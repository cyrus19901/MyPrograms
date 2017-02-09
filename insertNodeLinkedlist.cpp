/* Program to insert in a sorted list */
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
 void insert(struct node** head_ref, struct node** new_node){
 	if (head_ref==NULL || (*head_ref)->data >= new_node->data){
 		new_node->next= *head_ref;
 		*head_ref = new_node;
 	}
 }

struct node* newNode(int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
    new_node->next =  NULL;
 
    return new_node;
}

int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    struct node* new_node = newNode(5);
    insert(&head, new_node);
    // new_node = newNode(10);
    // sortedInsert(&head, new_node);
    // new_node = newNode(7);
    // sortedInsert(&head, new_node);
    // new_node = newNode(3);
    // sortedInsert(&head, new_node);
    // new_node = newNode(1);
    // sortedInsert(&head, new_node);
    // new_node = newNode(9);
    // sortedInsert(&head, new_node);
    // printf("\n Created Linked List\n");
    // printList(head);
 
    return 0;
}
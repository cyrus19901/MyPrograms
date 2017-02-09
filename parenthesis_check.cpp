#include <iostream>
#include <stdlib.h>
using namespace std;

// Structure of a stack node

struct snode{
	char data;
	struct snode *next;
};

//function to push an item in the stack
void push (struct snode ** top_ref, int new_data);

//function to push an item in the stack
int pop (struct snode ** top_ref);
//check if the char1 and char2 are the same
bool isMatching(char character1 , char character2){
	if (character1== '(' && character2 == ')')
		return 1;
	else if (character1== '[' && character2 == ']')
		return 1;
	else if (character1== '{' && character2 == '}')
		return 1;
	else 
		return 0;
}

//check if the expression is balanced

bool isBalances(char exp[]){
	int i=0;
	struct snode * stack = NULL;

	while (exp[i]){
		if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{' )
			push(&stack , exp[i]); 
		if (exp[i]==')' || exp[i]==']' || exp[i]=='}' ){
			if (stack == NULL)
				return 0;
			else if (!isMatching(pop(&stack), exp[i]))
				return 0;
		}
		i++;
	}
	if (stack == NULL)
		return 1;
	else 
		return 0;
}

int main(){
	char exp[100]="{()}[][";
	if (isBalances(exp))
		cout << "its balanced " <<endl;
	else 
		cout << "its not balanced " <<endl;
	return 0;

}

void push(struct snode ** top_ref, int new_data){
	struct snode * new_node = (struct snode *)malloc(sizeof(snode));

	if (new_node == NULL){
		cout <<"Stck overfolow " <<endl;
	}

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref)	   = (new_node);
 }

 int pop(struct snode ** top_ref){
 	char res;
 	struct snode *top;
 	if (*top_ref == NULL){
 		cout <<"Stack overflow" <<endl;
 	}
 	else{
 		top = *top_ref;
 		res = top->data;
 		*top_ref =  top->next;
 		free(top);
 		return res;
 	}
 }

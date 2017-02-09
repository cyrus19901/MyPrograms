#include <iostream>
#include <stack>
using namespace std;

struct node {
	char data;
	struct node * left;
	struct node * right;
};

struct node * newNode (char data){
	struct node * temp = (struct node *)malloc (sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
bool isOperand(char postfix){
	if (postfix == '+' ||postfix == '-' ||postfix == '*' ||postfix == '+' ||postfix == '/')
		return true;
	else 
		return false;
}
struct node * constructTree(char postfix[]){
	struct node * t;
	struct node * t1;
	struct node * t2;
	stack<struct node *> str;

	for (int i =0 ;i <strlen(postfix); i ++){
		if (!isOperand(postfix[i])){
			t=newNode(postfix[i]);
			str.push(t);
		}
		else{
			t = newNode(postfix[i]);
			t1 = str.top();
			str.pop();
			t2 = str.top();
			str.pop();

			t->right= t1;
			t->left= t2;
			str.push(t);
		}

	}
	t= str.top();
	str.pop();
	return t;

}

void inorder(struct node * r){
	if (r==NULL)
		return ;
	inorder(r->left);
	cout << r->data;
	inorder(r->right);
}
int main(){
	char postfix[] = "ab+ef*g*-";
	struct node * r = constructTree(postfix);
	cout << "infix expression is \n" <<endl;
	inorder(r);
	cout <<endl;
	return 0;
}
#include <iostream>
#include <string>
#include <stack>
using namespace std;


int maxparenthesis(string str){
	int lenght = str.size();
	stack<int> stk;
	//stk.push(-1);
	for (int i=0 ; i <lenght ; i++){
		if (str[i]=='(')
			stk.push(i);
		else
			stk.pop();
	}
	if (stk.empty()){
		cout << "the string are balanced";
		cout <<"size : "<< lenght/2;	
	}
	else 
		cout <<"the strings not balanced";
	return 0;
}
int main(){
	string str = "(())()";
	maxparenthesis(str);
	return 0;
}
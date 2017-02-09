#include <iostream>
#include <string>
#include <stack>
using namespace std;

void checkcomplete(string str){
	stack<int> st1;
	for (int i=0 ;i <str.size(); i ++){
			if (str[i]=='<' ||str[i]=='(' ||str[i]=='{' ||str[i]=='['){
				st1.push(str[i]);
			}
			else{
				char temp = st1.top();
				cout << temp <<"\t";
				st1.pop();
			}

	}
	if (st1.size()==0){
		cout << st1.size();
		cout <<"string valid";
	}
	else {
		cout << st1.size();
		cout <<"string not valid";
	}
}
int main(){
string str="<({()})[]>";
checkcomplete(str); 
}
#include <iostream>
using namespace std;

int palindrome(string str){
	string str2;
	int count=0;
	for (int i = str.size()-1; i > 0; i--){
		if (str[i] == str[i-1]){
			count =0;
		}
		else {
		str2= str2+str[i];
		count++;
		}
	}
	str = str2+str;
	cout << "palindrome :"<<"\t"<<str <<endl; 
	cout << "number of chracters :"<<"\t"<<count <<endl; 
	return 0;
}
int main(){
	string str = "aa";
	palindrome(str);
	return 0;
}
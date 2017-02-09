#include <iostream>
#include <regex>
using namespace std;

int removespace(string str1, int lenght){
	int count=0;
	for (int i=0 ; i <lenght; i++){
		if (str1[i]==' ' && str1[i+1] == ' '){
			count ++;
			str1[i+1] = '\0';
		}
	}
	cout << str1;
}
int main(){
	string str1 ="I  live  on  earth";
	int lenght = str1.size();
	removespace ( str1, lenght);
}
#include <iostream>
#include <string>
using namespace std;


int remove(string str1){
	for (int i=0; i <str1.size(); i++){
		if ((str1[i] =='a' && str1[i+1] == 'c')){
			str1[i] ='\0';
			str1[i+1]= '\0';
		}
		if (str1[i] == 'b')
			str1[i] = '\0';
	}
	cout << str1;
	return 0;
}
int main(){
	string str1 = "aababc";
	remove(str1);
	return 0;
}
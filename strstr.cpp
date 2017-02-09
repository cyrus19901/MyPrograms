#include <iostream>
#include <string>
using namespace std;

int pattern(string str1, string str2){
	string newstring= "";

	for (int i=0 ;i<10;i++){
		int k=0;
		while(i<i+1 && i <10){
			if (str2[k]== str1[i]){
				cout << k;
				cout << str2[k] << "\t" << str1[i]<<endl;
				newstring += str1[i];
			}
			i=i+3;
			k++;
		}
		
	}
	cout << newstring;
	if (newstring == str2){
			cout << "the string exists";
		}
	return 0;
}

int main (){
	string str1= "hihowareyou";
	string teststr ="how";
	pattern(str1,teststr);
	return 0;
}
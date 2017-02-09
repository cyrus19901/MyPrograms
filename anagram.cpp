#include <iostream>
#include <string>
#include <stdio.h>
using namespace std ;

int isanagram(string str1, string str2){

	if (sizeof(str1)!= sizeof(str2)){
		return false;
	}
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	cout << str1 << endl;
	cout << str2 << endl;
	if (str1 == str2)
	{
		return true;
	}

	
}


int main (){
	string str1 = "geeksquiz";
	string str2 = "zuiqkeegs";
	bool istrue =isanagram(str1,str2);
	if (istrue == 1){
		cout << str1 <<"\t" << "and" << str2 <<"\t" << "are anagrams"<<endl;
	}
	else {
		cout << str1 << "\t"<< "and" << str2 <<"\t"<< "are not anagrams"<<endl;
	}
	
	return 0;
}

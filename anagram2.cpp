#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std ;

int checkanagram(string str1, string str2){
	if (str1.size() != str2.size()){
		return 0;
	}
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	if (str1 == str2)
	{
		return true;
	}
}
int findanagram(string arr[], int size){

	for (int i=0 ; i <size; i++ ){
		for (int j=i+1; j<size; j++){
			bool check = checkanagram(arr[i], arr[j]);
			if (check ==1 ){
				cout << arr[i] <<"\t" << "and" << "\t"<< arr[j] <<"\t" << "are anagrams"<<endl;
			}
		}
	}
	
}


int main (){
	string arr[] = {"geeksquiz", "geeksforgeeks", "abcd", 
                    "forgeeksgeeks", "zuiqkeegs"};
    int size = sizeof(arr)/sizeof(arr[0]);
    findanagram(arr, size);
	return 0;
}

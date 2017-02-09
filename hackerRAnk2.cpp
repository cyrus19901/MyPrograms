#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int indexreturn(string str){
	int len = str.length();
	int count=0;
	for (int i=0; i <len; i++){
		cout <<str[i] <<endl;
		if (islower(str[i]) && (i ==len-1)){
			return i;
		}
	}
	cout <<count;
}
int main(){
	string str ="ABba";
	int result = indexreturn(str);
	cout << "reslt is : "<<"\t" << result <<endl;
	return 0;
}
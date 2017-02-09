#include <iostream>
#include <string>
#include <regex>
using namespace std;

int checkip(string str){
    regex e("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
    return regex_match(str, e);
}

    
int main()
{   
    string str1 = "222.555.111.111";
    int result= checkip(str1);
    if (result == 1){
    	cout << "its a valid ip"<<endl;
    }
    else{
    	cout <<"its not valid"<<endl;
    }
    return 0;
}
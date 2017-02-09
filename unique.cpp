#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int checkpattern(string str2, string str1){
    //sort(str1.begin(),str1.end()),str1.end();
    str1.erase(unique(str1.begin(),str1.end()),str1.end());
    str2.erase(unique(str2.begin(),str2.end()),str2.end());
    int size1=str1.size();
    int size2=str2.size();
    if (size1 != size2){
        return false;
    }
    else {
        return true;
    }

}
int main(){
    string str1 = "foo";
    string str[] = {"abb","abc","xyz","xyy"};
    int size = sizeof(str)/sizeof(str[0]);
    for (int i=0 ; i < size ; i++){
        bool check = checkpattern(str[i],str1);
        if (check==1){
            cout << str[i]<<endl;
        } 
    }
}
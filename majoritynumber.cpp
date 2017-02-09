#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int majority(int arr[], int size){
	int counttotal=0;
	int cnt=0;
	for (int i=0; i <size;i++){
		cnt = count(arr,arr+size,arr[i]);
		if (cnt> counttotal){
			counttotal= cnt;
		}
	}
	cout<<"the maximum count is "<< "\t"<<counttotal<<endl;
	return 0;
}


int main (){
	int size1=5;
	int arr1[]= {3,1,3,3,2};
	majority(arr1,size1);
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int watertrap(int arr[], int size){
	int maxleft= arr[0];
	int sum=0;
	int collected=0;
	for (int i=1; i <size; i++){
		if (arr[i]<maxleft){
			collected= maxleft-arr[i];
			sum= sum+collected;
		}
	}
	cout << "water collected "<<"\t"<<sum<<endl;
	return 0;
}


int main (){
	int size1=4;
	int arr1[]= {7,4,0,9};

	watertrap(arr1,size1);
	return 0;
}
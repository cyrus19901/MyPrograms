#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int duplicates(int arr[], int size){
	for (int i=0; i < size ; i++){
		if (arr[abs(arr[i])]>0){
			arr[abs(arr[i])] = - arr[abs(arr[i])] ;
		}
		else 
			cout << "repeated elements" << abs(arr[i]) <<endl;
	}
}
int main (){
	int arr[] = {1,2,3,4,4,8,6,6};
	int size= sizeof(arr)/sizeof (arr[0]);
	int result = duplicates(arr,size);
	//cout << "the pivot element : " <<result <<endl;
	return 0;
}
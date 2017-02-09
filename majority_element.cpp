#include <iostream>
#define ASCII_SIZE 256
using namespace std;


int majority(int *arr, int size){
	int count[ASCII_SIZE];
	for (int i=0; i <size;i++){
		count[arr[i]]++;
	}
	int max=-1;
	int result;

	for (int i=0; i <size ; i++){
		if (max < count[arr[i]]){
			max = count[arr[i]];
			result = arr[i];
		}
	}
	return result;
}
int main(){
	int arr[]={1,2,3,3,4,5,6,3,2,5,7,8,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	int result = majority(arr,size);
	cout << "the result is " << result <<endl;
 	return 0;
}
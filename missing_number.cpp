#include <iostream>
using namespace std;


int missingnumber(int arr[10],int size){
	for (int i=0; i <size; i++){
		if ((arr[i+1] - arr[i]) !=1 && arr[i] < arr[i+1])
			cout << i+1 <<endl;
	}
	return 0;
}
int main (){
	int arr[10]= {0,1,2,4,5,6,7,8,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	missingnumber(arr,size);
	return 0;
}
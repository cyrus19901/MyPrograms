#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int pivot (int arr[], int size){
	int Lsum=0;
	int Rsum=0;
	for (int i=0; i <size; i++){
		Rsum = Rsum+arr[i];
	}
	for (int i=0; i <size;i++){
		Rsum = Rsum - arr[i];
		if (Lsum == Rsum)
			return i;
		else
			Lsum= Lsum + arr[i];
	}
	return -1;
}

int main (){
	int arr[] = {1,2,3,4,10,6};
	int size= sizeof(arr)/sizeof (arr[0]);
	int result = pivot(arr,size);
	cout << "the pivot element : " <<result <<endl;
	return 0;
}
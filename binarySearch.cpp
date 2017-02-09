#include <iostream>
using namespace std;


int binarysearch(int arr[],int begin, int end, int search){
	int mid;
	while (begin <= end){
		mid = (begin+end-1/2);	
	//cout << mid <<endl;
	if (arr[mid]==search)
		return mid;
	if (arr[mid]> search)
		binarysearch(arr,begin,mid-1,search);
	if (arr[mid] < arr[search])
		binarysearch(arr,mid+1,end,search);
	return -1;
	}
}

int sortarray(int arr[], int size, int search){
	sort(arr,arr+size);
	for (int i =0 ; i <size ; i++){
		cout << arr[i] <<"\t" <<endl;
	}
	int result = binarysearch(arr,0,size-1, search);
	if (result == -1)
		cout << "the value not found"<<endl;
	else
		cout << "the value found"<<endl;
	return 0;
}
int main(){
	int arr[]= {10,20,50,48,67,90,100};
	int size = sizeof(arr)/sizeof(arr[0]);
	int search = 100;
	sortarray(arr, size, search);
	return 0;
}
#include <iostream>
using namespace std;

int findpivot(int arr[],int begin, int end){
	if (begin > end)
		return -1;
	if (begin==end)
		return begin;
	int mid = (begin+end)/2;
	if (arr[mid]>arr[mid+1] && mid<end)
		return mid;
	if (arr[mid] < arr[mid-1] && mid>begin)
		return mid-1;
	if (arr[begin] >arr[mid])
		return findpivot(arr,begin,mid-1);
	else
		return findpivot(arr,mid+1,end);
}
int binarySearch(int arr[], int begin, int end, int key){
	if (begin>end)
		return -1;
	int mid= (begin+end)/2;
	if (key== arr[mid])
		return mid;
	if (key > arr[mid])
		return binarySearch(arr, mid+1, end,key); 
	return binarySearch(arr,begin,mid-1,key);
}

int pivotedBinarySearch(int arr[], int size, int key){
	int k= findpivot(arr,0,size-1);
	if (k == -1)
		return binarySearch(arr, 0,size-1,key);
	if (arr[k]== key)
		return k;
	if (arr[0] <= key)
		return binarySearch(arr,0,k-1,key);
	return binarySearch(arr,k+1,size-1,key);
}
int main()
{
   // Let us search 3 in below array
   int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr)/sizeof(arr[0]);
   int key = 3;
   int result = pivotedBinarySearch(arr, n, key);
   cout <<result;
   return 0;
}
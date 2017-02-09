#include <iostream>
using namespace std;


void printKMax(int arr[], int begin, int end, int n){
	int max =0;
	for (int i=begin;i <end; i++){
		if (arr[i]>max)
			max=arr[i];
	}	
	cout << max << "\t";
	if (begin < n-3)
	printKMax(arr,begin+1,end+1,n);
}
int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, 0 , k, n);
    return 0;
}
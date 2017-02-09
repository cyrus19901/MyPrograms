#include <iostream>
#include <vector>
#include <list>
using namespace std;

int leftshift(int arr[],int n,int size){
	list<int>myvector;
	int a = 0;
	for (int i=0; i <n ; i++){
			myvector.push_back(arr[i]);
		}
	for ( int j = 0 ;j <size; j++){
		arr[j]= arr[j+n];
		if (j >= size-n){
			arr[j]=myvector.front();
			myvector.pop_front();
		}
	}
	for (int a=0 ; a<size; a++){
		cout << arr[a] << "\t";
	}
	return 0;

}
int main (){
	int arr[]={1,2,4,5,7,8,9};
	int n = 2;
	int size = sizeof(arr)/sizeof(arr[0]);
	leftshift(arr,n,size);
	return 0;
}
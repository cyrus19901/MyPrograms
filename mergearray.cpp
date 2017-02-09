#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int mergearray(int arr1[],int arr2[],int size1,int size2){
	
	int newsize=size1+size2;
	int newarr[newsize];
	for (int i=0 ; i<size1 ;i++){
		newarr[i]= arr1[i];
		newarr[i+size1]= arr2[i];
	}
	sort(newarr,newarr+newsize,greater<int>());
	for (int i=0 ; i<newsize; i++){
		cout << newarr[i]<<"\t";
	}
	
	return 0;
}
int main (){
	int size1=4;
	int size2=5;
	int arr1[]= {7,5,3,1};
	int arr2[]= {9,8,6,2,0};
	mergearray(arr1,arr2,size1,size2);
	return 0;
}
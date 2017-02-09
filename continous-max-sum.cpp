#include <iostream>
#include <string>
using namespace std;

int continousum(int arr[],int size){
	int sum=arr[0];
	for (int i=1 ; i <size; i++){
		if (abs(arr[i+1]- arr[i])==1){
			if(arr[i+1] > arr[i]){
				sum=sum+arr[i];
				cout <<sum <<endl;
			}
		}
	}
	cout <<"the sum is " <<"\t" <<sum <<endl;
	return 0;
}
int main (){
	int size=4;
	int arr[]= {-1,-2,-3,-4};
	continousum(arr,size);
}
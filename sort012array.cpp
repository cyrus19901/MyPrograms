#include <iostream>
#include <vector>
using namespace std;


int sort012(int arr[],int size){
	sort(arr,arr+size);
	for (int i=0; i <size ;i++){
		cout << arr[i]<<endl;
	}
	return 0;
}
int main(){
	int arr[]={0,1,2,2,0,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	sort012(arr,size);
	return 0;
}
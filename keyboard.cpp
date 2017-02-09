#include <iostream>
#include <string>

using namespace std;

int circular(int arr[], int size){
	int distance =0;
	int gas =0;
	int remain =0 ;
	int counter=1;
	for (int i=0 ; i <size ; i=i+2){
		gas = arr[i];
		distance = arr[i+1];
		if (gas > distance){
			gas = gas +remain;
			remain = gas- distance;
			cout <<"remain" << "\t" <<remain <<endl;
			cout <<"total gas" << "\t" <<gas<<endl; 
			counter ++;
		}
		if (counter==4){
			cout << "its possible"<<endl;
		}
	}
}
int main(){
	int no_pumps=4;
	int arr[]={14,6,6,5,7,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	if (size%2 !=0){
		cout <<"wrong input";
		return false;
	}
	else 
		circular(arr,size);
}
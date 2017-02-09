#include <iostream>
using namespace std;

void subsum(int arr[], int size, int sum){
	int count = 0;
	for (int i=0; i <size; i++){
		for (int j=i; j <size; j++){
			if (count == sum){
				cout << "starting position " << i+1<<endl;
				cout << "ending position " << j<<endl; 
			}
			else{
				count= count+ arr[j];
				// cout << count <<"\t";	
			}
			
		}
		count = 0;
	}
}
int main(){
	int arr[]={1,2,3,7,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int sum = 12;
	subsum(arr, size, sum);
	// cout << "starting position" << result;
	return 0;
}
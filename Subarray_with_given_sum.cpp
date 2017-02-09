#include <iostream>
using namespace std;

int findsubarray(int arr[], int size, int sum){

	for (int i=0; i <size; i++){
		int current_sum = arr[i];
		for (int j=i+1; j<size;j++){
			if (current_sum > sum)
				break;
			if (current_sum == sum)
				cout <<"the sum found between" << i <<"and "<< j-1;
			current_sum = current_sum +arr[j];
		}
	}
	return 0;
}



int main(){
	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
	int size = sizeof(arr)/sizeof(arr[0]);
	int sum= 23;
	findsubarray(arr,size,sum);
	return 0;
}
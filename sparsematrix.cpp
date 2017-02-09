#include <iostream>
using namespace std;
#define R 3
#define C 3

void set(int row, int column, int value, int arr[R][C]){
	arr[row][column]=value;
	cout <<"the value has been set: "<<arr[row][column] <<endl;
}
int sum(int row, int column, int arr[R][C]){
	int sum =0;
	for (int i =0 ; i <row; i++){
		if (i==row){
			for (int k=0; k<=column; k++){
				sum= sum+ arr[i][k];
			}
		}
		else {
			for (int j = 0 ; j<=C ; j++){
				sum = sum + arr[i][j];
			}
		}
	}

	cout <<"sum: " <<sum <<endl; 
}

int main(){
	int arr[R][C]= {{1,0,0},{3,0,0},{0,0,5}};
	int value =10;
	int r=1;
	int c=2;
	set(r,c,value,arr);
	sum(r,c,arr);
	return 0;
}
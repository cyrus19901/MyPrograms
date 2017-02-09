#include <iostream>
#include <string>
using namespace std;

#define R 4
#define C 4

int maxrectangle(int arr[R][C]){
	int counter=0;
	int area =0 ;
	//cout << R << "\t" <<C;
	for (int i=0 ; i <R; i++){
		for (int j=0;j <C;j++){
			if (arr[i][j]==1){
				counter++;
			}
			else{
				counter=0;
			}
		}
		//cout << counter <<endl;
		if (counter == C){
			area = area + counter;
			counter =0 ;
		}
		else {
			counter =0;
		}
	}
	cout << "Area is : " <<"\t" <<area <<endl;
}

int main(){
	// int row =4;
	// int col=4;
	int arr[R][C]= {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
	maxrectangle(arr);
	return 0;
}
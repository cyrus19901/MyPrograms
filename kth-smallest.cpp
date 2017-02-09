#include <iostream>
#include <string>
using namespace std;
// #define R=4;
// #define C=4;

int kthminimum(int arr[4][4], int k){
	int smallest = arr[0][0];
for (int k=0 ;k< 3; K++){
	for (int i=0 ; i <4 ;i ++){
		for (int j=0 ; j<4 ;j++){
			if (arr[i][j] < smallest){
				smallest = arr[i][j];
			}
		}
	}
	cout <<"smallest"<<smallest <<"\n"<<endl;
	cout <<endl;
}
	
	// for (int i=0 ; i <4 ;i ++){
	// 	for (int j=0 ; j<4 ;j++){
	// 		cout <<arr[i][j]<<"\n";
	// 	}
	// }
	return 0;
}
int main(){
	int a[4][4]={{16,28,60,64},{22,41,63,91},{27,50,87,93},{36,78,87,94}};
	int k =3;
	kthminimum(a,k);
	return 0;
}
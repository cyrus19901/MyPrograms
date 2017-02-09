#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define S 4

int ksmallest(int arr[S][S], int k){
	int smallest = arr[0][0];
	// int size = sizeof(arr)/sizeof(arr[0]);
	// cout <<size;
	int counter=0;
	for (int i=0; i <S;i++){
		for (int j=0; j <S;j++){
			sort(arr[i],arr[i]+S) ;
			if (arr[i][j]>smallest && counter <= k){
				counter ++ ;
				smallest = arr[i][j];
				cout << smallest <<endl;
			}
			
				// /smallest= arr[i+1][i];
			// if (arr[i][j] > smallest && counter <=k){
			// 	counter++;
			// 	smallest = min(arr[i][j],arr[j][i]);
			// }
			// cout << arr[i][j]<<"\t";
		}
		cout <<endl;
	}
	cout << "Kth-smallest element is " << "\t" << smallest <<endl;
	return 0;
}
int main(){
	int arr[S][S] ={{16,28,60,64},{22,41,63,91},{27,50,87,93},{36,78,87,94}};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout <<size << endl;
	int k =3;
	ksmallest(arr, k);
	return 0;
}
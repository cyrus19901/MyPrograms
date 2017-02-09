#include <iostream>
using namespace std;
#define R 3
#define C 6

void spiralMarix(int m , int n , int arr[R][C]){
	int k=0;	//starting row index
				//ending row index m
	int l=0;	//starting column index
				//ending column index n
 
	while (k <m && l<n){
		for (int i=l; i <n; i++){
			cout << arr[k][i] <<"\t";
		}
		k++;

		for (int i =k; i <m; i ++){
			cout << arr[i][n-1]<<"\t";
		}
		n--;
		if (k <m){
		for (int i =n-1 ; i >=l ;i --){
			cout << arr[m-1][i]<<"\t";
		}
		m--;
		}
		if (l<n){
			for (int i =m-1; i>=k;i--){
			cout << arr[i][l]<<"\t";
		}
		l++;

		}

	}
}
int main (){
	int arr[R][C] = 	{{1,2,3,4,5,6},
        				{7,  8,  9,  10, 11, 12},
        				{13, 14, 15, 16, 17, 18}};
    spiralMarix(R,C ,arr);
    return 0;
}
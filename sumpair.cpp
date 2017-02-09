#include <iostream>
using namespace std;

int sumpair(int a[], int b[], int c, int size_a,int size_b){
	for (int i=0; i < size_a; i++){
		for (int j=0 ; j< size_b; j++){
			// cout << a[i] << "\t" <<b[j] <<endl;
			if (a[i]+b[j] <=c ){
				cout << a[i] << "\t" <<b[j] <<endl;
			}
			else 
				return 0;
		}
	}
}
int main(){
	int a[]={1,2,3,4,5};
	int b[]={0,1,2,3,4};
	int size_a = sizeof(a)/sizeof(a[0]);
	int size_b = sizeof(b)/sizeof(b[0]);
	int c = 5;
	sumpair(a,b,c,size_a,size_b);
	return 0;
}
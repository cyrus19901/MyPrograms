#include <iostream>
#include <string>
#include <vector>
using namespace std;

int subsequent(int arr[], int n){
	vector <int> myvector ;
	// int min =arr[0];
	int count=0;
	// myvector.push_back(min);
	for (int i=0 ; i<n ; i++){
		if (arr[i+1] > arr[i] && count <=3){
			myvector.push_back(arr[i+1]);
			count ++;
		}
	}
	if (myvector.size() ==3 )
		return true;
	else 
		return false;
}
int main(){
	int n = 5;
	int arr[]={1,2,1,1,3};
	bool result = subsequent(arr,n);
	cout << result<<endl;
	return 0;
}
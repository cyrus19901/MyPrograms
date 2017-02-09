#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxchain(int arr[], int pairs){
	vector <int> myvector;
	int marker= arr[1];
	int counter =0;
	for (int i =0 ; i < pairs*2 ; i=i+2){
		if (arr[i+1] >= marker) {
			counter ++;
			cout<<counter<<endl;
			marker = arr[i+1];
			cout << "Marker" << marker <<endl;
		}
		else {
			myvector.push_back(counter);
			counter=1;
			marker=arr[i+1];
			cout << "Marker" << marker <<endl;
		}

	}
	cout <<myvector.size();
	//auto max =max_element(begin(myvector),end(myvector));
	//cout << *max;
	return 0;
}
int main (){
	int pairs= 5;
	int arr[]={5,24,39,60,15,28,27,40,50,90};
	maxchain(arr, pairs);
	return 0;
}
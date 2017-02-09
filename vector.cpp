#include <iostream>
#include <vector>
using namespace std;
//function declaration
//pass them always by reference
void fillvector(vector<int>&);
void printvector(vector <int>&);
void reverse (vector<int>&);


int main(){
	vector <int> myvector ;
	fillvector(myvector);
	printvector(myvector);
	reverse(myvector);
	return 0;
}
void fillvector(vector<int>& newmyvector){
	cout <<"Type in a list of numbers from 0-100"<<endl;
	int input;
	cin >>input;
	while (input != -1){
		newmyvector.push_back(input);
		cin >> input;
	}
}

void printvector(vector<int>& newmyvector){
	cout <<"vectors";
	for (unsigned int i =0 ; i <newmyvector.size();i++){
		cout << newmyvector[i]<<endl;
	}
}
void reverse(vector<int>& newmyvector){
	cout << "reverse vectors";
	for(int i = newmyvector.size()-1 ; i>=0 ;i--){
		cout << newmyvector[i]<<endl;
	}
}
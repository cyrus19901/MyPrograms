#include <iostream>
#include <string>
using namespace std;

int numberOfGates(int arrival[6],int departure[6], int flight){
	int count =0;
	for (int i=0; i <flight; i++){
		if (departure[i]>arrival[i+1]){
			count ++;
		}
	}
	return count;
}
int main(){
	int flights =6;
	int arrival[6] 	= {900,940,950,1100,1500,1800};
	int departure[6]	= {910,1200,1120,1130,1900,2000};
	int gates = numberOfGates(arrival,departure, flights);
	cout << "number of gates required are "<<"\t" << gates<<endl;
	return 0;
}
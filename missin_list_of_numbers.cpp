#include <iostream>
using namespace std;

int missinglist(int arr[],int size){
	int start= arr[0];
	cout <<start<<endl;
	int end= arr[size-1];
	cout <<end<<endl;
	int s=0;
	int t=0;

	for (int i=start ; i <end ; i++){
		if (arr[i+1]- arr[i] != 1 && end >= start){
			s=arr[i+1];
			cout <<s <<endl;
		}
		// if (arr[i+1]- arr[i] == 1 && end >= start){
		// 	t= i;
		// }
		// cout <<"range :"<<s <<"\t" <<t <<endl;  
	} 
}

int main(){
	int arr[]={0,1,2,50,52,75};
	int size= sizeof(arr)/sizeof(arr[0]);
	missinglist(arr,size);
	return 0;
}
#include <iostream>
#include <math.h>
using namespace std;


void floorofelement(int arr[],int size,int k){
	int pos=0;
	for (int i=0 ;i <size ; i ++){
		if (arr[i] <= k)
			pos=i;
	}
	cout << "output is: " <<pos <<endl;
}
int main()
{
    int arr[] = {1,2,8,10,11,12,19};
    int size =sizeof(arr)/sizeof(arr[0]);
    int k=5;
    floorofelement(arr,size,k);
    return 0;
}

#include <iostream>
using namespace std;

void flipbit(int arr[], int size){
	int maxcount=0;
	int pos ;
	int count_number=0;
	for (int i=0; i <size; i ++){
		int count=1;
		if (arr[i]==arr[i+1])
			count++;
		if (count>maxcount){
			maxcount=count;
			pos =i;
		}
	}
	for (int i=pos; i <pos+maxcount; i ++){
		if (arr[i] == 0){
			count_number++;
			arr[i] = 1;
		}

		if (arr[i] == 1)
			count_number++;
	}
	cout << "subarray count" <<maxcount <<endl;
	cout << "pos" <<pos <<endl;
	cout <<"number of 1's" << count_number <<endl;
}
int main()
{
    int arr[] = {0, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    flipbit(arr, n);
    return 0;
}
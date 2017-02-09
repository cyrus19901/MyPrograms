#include <iostream>
using namespace std;

int maxSubArraySum(int arr[], int l){
	int current_max= arr[0];
	int max_so_far= arr[0];

	for (int i=0; i <l; i ++){
		current_max= current_max+arr[i];
		current_max= max(current_max,arr[i]);
		max_so_far= max(current_max,max_so_far);
	}
	return max_so_far;

}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}



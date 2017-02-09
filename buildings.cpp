#include <iostream>
#include <string>

using namespace std;


int sunlight(int arr[],int n){
    int first = arr[0];
    //cout << first;
    int count=1;
    for (int i=1 ;i < n ;i++){
        if (arr[i] > first){
            count ++;
            first = arr[i];
        }
    }
    cout << "number of buildings" << "\t"<< count <<endl;
    return 0;
}
int main()
{   
    int number =7;
    int arr[]= {3,4,1,0,6,2,3};
    sunlight (arr, number);
    return 0;
}
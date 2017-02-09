#include <iostream>
using namespace std;


void swap(int *a , int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int max){
    int pivot = arr[max];
    int x = (low-1);
    for (int i=low ; i <=max-1; i++){
        if (arr[i]<= pivot){
            x++;
            swap(&arr[x], &arr[i]);  
        }

    }
    swap(&arr[x+1], &arr[max]);
    return (x+1);
}

void printarray(int arr[], int size){
    for (int i=0 ; i <size; i++){
        cout << arr[i]<<"\t";

    }
}
void quicksort(int arr[],int low, int max){
    if (low < max){

        int result = partition(arr,low,max);

        quicksort(arr, low, result-1);
        quicksort(arr, result+1, max);
    }
}

int main(){
    int arr[] ={2,1,5,7,3,4,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    printarray(arr, size);
    return 0;
}
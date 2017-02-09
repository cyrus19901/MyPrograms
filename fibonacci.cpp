#include <iostream>
using namespace std;


int fibonacci(int n){
	if (n <=1)
		return n;
	for (int i=0; i <=n; i++){
		return (fibonacci(n-1) + fibonacci(n-2));
	}
}
int main(){
	int n =9;
	cout << fibonacci(n);
	return 0;
}
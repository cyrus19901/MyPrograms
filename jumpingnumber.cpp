#include <iostream>
#include <math.h>
using namespace std;

int jumping(int n){

	for (int i=0 ; i <=n ; i++){
		if (i <=9){
			cout << i << "\t";
		}
		//cout << (abs(n/10)-(n%10))	;
		else if (abs((i/10)- (i%10)) ==1){
			cout << i<< "\t";
		}
		
		// if ((abs(n/10)-(n%10)) ==1) {
		// 	cout << n<<"\t";;
		// }
	}
	return  0;

}
int main(){
	int n =50;
	jumping(n);
	return 0;
}
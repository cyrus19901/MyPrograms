#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int intersect(int x[],int y[],int radius[],int size){
	float distance =0;
	int counter =0;
	for (int i=0; i<size-1;i++){
		for (int j=0; j< size-1 ; j++){
		distance =sqrt(pow((x[j]-x[i]),2) + pow((y[j]-y[i]),2));
		cout <<distance<<"\t"<<endl;
		int radius_min = abs(radius[j]-radius[i]);
		int radius_max = abs(radius[j]+radius[i]);
		if ((radius_min <= distance )&& (distance < radius_max)){
			counter ++ ;
		}
		}
	}
	return counter;
}
int main (){
	int x[] = {1,3,4,6,7,9};
	int y[] = {-1,5,9,0,-4,-1};
	int radius[] = {10,30,20,40,12,1};
	int size= sizeof(x)/sizeof (x[0]);
	int result = intersect(x,y,radius,size);
	cout << "number of triangle that intersect : " <<result << endl; 
	return 0;
}
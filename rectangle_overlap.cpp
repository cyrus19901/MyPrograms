#include <iostream>
using namespace std;

struct point{
	int x;
	int y;
};

int overlap(point l1,point l2,point r1,point r2){
	if (l1.x > r2.x || l2.x > r1.x)
		return false;
	if (l1.y < r2.y || l2.y < r1.y)
		return false;
	else 
		return true;
}
int main (){
	point l1 = {0, 10};
	point r1 = {10, 0};
    point l2 = {5, 5};
    point r2 = {15, 0};
    bool result = overlap(l1,l2,r1,r2);
    cout <<result <<"\t";
    return 0; 

}
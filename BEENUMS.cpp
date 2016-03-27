#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
	long long int num,tmp,n;
	cin>>num;
	while(num != -1) {
		if(num == 1){
			cout<<"Y"<<endl;
		} else {
			n = (-3 + sqrt(9 + 12*(num-1)))/6;
			if((3*n*n + 3*n + 1) == num) {
				cout<<"Y"<<endl;
			} else {	
				cout<<"N"<<endl;
			}
		}
		cin>>num;
	}
	return 0;
}

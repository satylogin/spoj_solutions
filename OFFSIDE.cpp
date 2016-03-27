#include <iostream>

using namespace std;

int main()
{
	int a,d;
	cin>>a>>d;

	while ((a != 0) || (d != 0)) {
		int i,j,index = 0;
		int b[a],c[d];
		for (i = 0 ; i < a ; i++) {
			cin>>b[i];
		}
		for (i = 0 ; i < d ; i++) {
			cin>>c[i];
		}
		int min_b,min_d1,min_d2;
		min_b = b[0];
		//getting minimum distance of attacker
		for (i = 1 ; i < a ; i++) {
			if (b[i] < min_b) {
				min_b = b[i];
			}
		}
		min_d1 = c[0];
		//getting defender 1
		for (i = 1 ; i < d ; i++) {
			if (c[i] < min_d1) {
				min_d1 = c[i];
				index = i;
			}
		}
		//getting defender 2
		min_d2 = 99999;
		for (i = 0 ; i < d ; i++) {
			if((i != index) && (c[i] < min_d2)) {
				min_d2 = c[i];
			}
		}
		if (min_b > min_d2) {
			cout<<"N"<<endl;
		} else if ((min_d1 == min_d2) && (min_b == min_d1)) {
			cout<<"N"<<endl;
		} else if (min_b == min_d2) {
			cout<<"N"<<endl;
		} else {
			cout<<"Y"<<endl;
		}
		cin>>a>>d;
	}

	return 0;
}

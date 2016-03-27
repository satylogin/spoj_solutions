#include <iostream>

using namespace std;

int main()
{
	int t, ng, nm, max1, max2, f1, f2, i;
	cin>>t;

	for ( ; t; t--) {
		cin>>ng>>nm;
		int g[ng], m[nm];
		for (i = 0; i < ng; i++) {
			cin>>g[i];
		}
		for (i = 0; i < nm; i++) {
			cin>>m[i];
		}
		max1 = 0; f1 = 0; max2 = 0; f2 = 0;
		for (i = 0; i < ng; i++) {
			if (g[i] > max1) {
				max1 = g[i];
				f1 = 1;
			} else if (max1 == g[i]) {
				f1++;
			}
		}
		for (i = 0; i < nm; i++) {
			if (m[i] > max2) {
				max2 = m[i];
				f2 = 1;
			} else if (max2 == m[i]) {
				f2++;
			}
		}
		if (max1 > max2) {
			cout<<"Godzilla"<<endl;
		} else if (max2 > max1) {
			cout<<"MechaGodzilla"<<endl;
		} else {
			if (f1 >= f2) {
				cout<<"Godzilla"<<endl;
			} else {
				cout<<"MechaGodzilla"<<endl;
			}
		}
	}

	return 0;
}

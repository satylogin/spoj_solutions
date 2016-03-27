#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{	
	int t,n,m,i,j,min,tmp;
	cin>>t;

	while (t--) {
		cin>>n;
		int arr1[n];
		for (i = 0; i < n; i++) {
			cin>>arr1[i];
		}
		cin>>m;
		int arr2[m];
		for (i = 0; i < m; i++) {
			cin>>arr2[i];
		}
		min = 10000001;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				tmp = arr1[i] - arr2[j];
				if (tmp < 0) tmp = -tmp;
				if (tmp < min) min = tmp;
			}
		}
		cout<<min<<endl;
	}

	return 0;
}

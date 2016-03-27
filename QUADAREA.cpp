#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
	int t; cin>>t;

	while (t--) {
		long double a,b,c,d;
		cin>>a>>b>>c>>d;
		long double s = (a + b + c + d) / 2;
		printf("%.2Lf\n",sqrt((s-a)*(s-b)*(s-c)*(s-d)));
	}

	return 0;
}

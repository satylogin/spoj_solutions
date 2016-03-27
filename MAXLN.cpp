#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>

#define CONST 0.25 //addition factor to 4*r*r

using namespace std;

int main()
{
	int t,i;
	cin>>t;
	for (i = 0; i < t; i++ ) {
		double radius,ans;
		cin>>radius;
		ans = ( 4 * radius * radius ) + CONST;
		printf("Case %d: %.2lf\n",i+1,ans);
	}
	return 0;
}

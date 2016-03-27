#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
	int num;
	cin>>num;
	while (num != 0) {
		double ans = (num * num) / (6.28318530718) ;
		printf("%.2lf\n",floor(ans*100 + 0.50)/100.0);
		cin>>num;
	}
	return 0;
}

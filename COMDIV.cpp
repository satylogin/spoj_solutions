#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int main()
{
	int t; scanf("%d",&t);

	for (int j = 0; j < t; j++)  {
		int a, b;
		scanf("%d%d",&a,&b);
		int x = gcd(a, b);
		int count = 0;
		for (int i = 1; i <= sqrt(x); i++) {
			if (x % i == 0) {
				count = count + 2;
				if(i == x / i)
					count = count - 1;
			}
		}
		printf("%d\n",count);
	}

	return 0;
}

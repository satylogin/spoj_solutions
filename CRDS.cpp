#include <iostream>
#include <stdio.h>

using namespace std;
#define MOD 1000007

int main()
{
	int t; scanf("%d",&t);
	
	while (t--) {
		long long int n, ans;
		scanf("%lld",&n);
		ans = (n * (4 + (n - 1) * 3)) / 2;
		printf("%lld\n",ans%MOD);
	}

	return 0;
}

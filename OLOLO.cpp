#include <stdio.h>

int main()
{
	int t,i; scanf("%d",&t);
	long long int x=0,num[t];
	for(i=0;i<t;i++){
		scanf("%lld",&num[i]);
		x = x ^ num[i];
	}
	printf("%lld\n",x);
	return 0;
}

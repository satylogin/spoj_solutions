#include <stdio.h>
#include <bitset>

using namespace std;

long long int a[500001];
bitset <100000000> num;

void set()
{
	int i;
	for (i = 1; i <= 500000; i++) {
		a[i] = a[i-1] - i;
		if (a[i] > 0 && num[a[i]] == 0) {
			num[a[i]] = 1;		
		} else {
			a[i] = a[i-1] + i;
			num[a[i]] = 1;
		}
	}
}	

int main()
{
	set();
	int num;
	scanf("%d", &num);
	while (num != -1) {
		printf("%lld\n",a[num]);
		scanf("%d", &num);
	}
	return 0;
}

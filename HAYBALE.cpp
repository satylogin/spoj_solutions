#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int arr[1000010];

int main()
{
	int n, k, i, j, q, a, b;
	
	scanf("%d %d", &n, &q);

	while (q--) {
		scanf("%d %d", &a, &b);
		arr[a] += 1;
		arr[b+1] -= 1;
	}

	for (i = 1; i <= n; ++i) {
		arr[i] += arr[i-1];
	}

	sort(arr+1, arr+1+n);

	printf("%d\n", arr[(n+1) / 2]);

	return 0;
}

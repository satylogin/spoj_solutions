#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int ans[10001][10001], pil[10001], assis[10001], n;

int get_ans(int i, int cur)
{
	if (ans[i][cur]) {
		return ans[i][cur];
	}

	if (i == n) {
		if (cur == 0) {
			return 0;
		} else {
			return MOD;
		}
	}	

	if (cur > n-i) {
		return (ans[i][n] = MOD);
	}

	if (cur == 0) {
		return ans[i][cur] = assis[i] + get_ans(i+1, cur+1);
	} else {
		return ans[i][cur] = min(assis[i] + get_ans(i+1, cur+1),
				pil[i] + get_ans(i+1, cur-1));
	}
}

int main()
{
	//memset(ans, -1, sizeof(ans));
	
	int i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d %d", &pil[i], &assis[i]);
	}

	printf("%d\n", get_ans(0, 0));

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int n, ans[300][300], arr[300];
char str[300];

int get_ans(int i, int len, int score)
{
	if (i >= n && score > 0) return len;
	else if (i > n) return 0;
	if (ans[i][len] != -1) return ans[i][len];

	int x, y;
	x = get_ans(i+1, len+1, score+arr[i]);
	if (score > 0) {
		y = len + get_ans(i+1, 1, arr[i]);
	} else {
		y = get_ans(i+1, 1, arr[i]);
	}

	//cout << "i =  " << i << " len = " << len << " x = " << x << " y = " << y << endl;;
	return (ans[i][len] = max(x, y));
}

int main()
{
	int t, m, i, j, k, x, y;
	scan(t);
	while (t--) {
		scan(n);
		scanf("%s", str);
		for (i = 0; str[i]; ++i) {
			if (str[i] == '1') arr[i] = 1;
			else arr[i] = -1;
		}
		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= n; ++j) {
				ans[i][j] = -1;
			}
		}
		x = get_ans(1, 1, arr[0]);
		printf("%d\n", x);
		//for(i=0;i<=n;++i){for(j=0;j<=n;++j){if(ans[i][j]>=0)cout<<ans[i][j]<<" ";else cout<<"*"<<" ";}cout << endl;}
	}

	return 0;
}

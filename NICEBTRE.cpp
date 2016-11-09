#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

char str[100000];
int m, i;

void dfs(int dep)
{
	if (str[i] == 'l') {
		m = max(m, dep);
		return;
	}

	i++;
	dfs(dep+1);
	i++;
	dfs(dep+1);
}

int main()
{
	int t, j;
	scan(t);

	while (t--) {
		scanf("%s", str);
		m = 0;
		i = 0;
		dfs(0);
		printf("%d\n", m);
	}

	return 0;
}

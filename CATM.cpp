#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int m1, m2, c11, c12, c21, c22, n, m;	

bool check()
{
	int d, x, y;
	d = m2 - 1;
	x = abs(c11 - m1) + abs(c12 - 1);
	y = abs(c21 - m1) + abs(c22 - 1);
	if (d < x && d < y) {
		return true;
	}

	d = m - m2;
	x = abs(c11 - m1) + abs(c12 - m);
	y = abs(c21 - m1) + abs(c22 - m);
	if (d < x && d < y) {
		return true;
	}

	d = m1 - 1;
	x = abs(c11 - 1) + abs(c12 - m2);
	y = abs(c21 - 1) + abs(c22 - m2);
	if (d < x && d < y) {
		return true;
	}

	d = n - m1;
	x = abs(c11 - n) + abs(c12 - m2);
	y = abs(c21 - n) + abs(c22 - m2);
	if (d < x && d < y) {
		return true;
	}

	return false;
}

int main()
{
	int i, j, k, x, t, y;

	scanf("%d %d %d", &n, &m, &t);

	while (t--) {
		scanf("%d %d %d %d %d %d", &m1, &m2, &c11, &c12, &c21, &c22);
		if (check()) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int arr[100000];
char str[1000000];

int main()
{
	int i, j, k, a, ans, b, c, x, y, z, t;
	scan(t);
	gets(str);
	while (t--) {
		gets(str);
		x = 0;
		j = 0;
		for (i = 0; str[i]; ++i) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				x++;
			} else {
				if (x > 0) {
					arr[j++] = x;
					x = 0;
				}
			}
		}
		if (x > 0) arr[j++] = x;	
		ans = z = 1;
		for (i = 1; i < j; ++i) {
			if (arr[i] == arr[i-1]) z++;
			else {
				ans = max(ans, z); z = 1;
			}
		}
		ans = max(ans, z);

		printf("%d\n", ans);
	}

	return 0;
}

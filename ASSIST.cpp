#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

#define END 35000

int ans[4000], arr[100001], BIT[200001];

void insert(int x, int val)
{
	for (; x <= END; x += (x&-x)) 
		BIT[x] += val;
}

int query(int x)
{
	int ret = 0;
	for (; x > 0; x -= (x&-x))
		ret += BIT[x];
	return ret;
}

int find(int l)
{
	int start = 2, end = END, mid, i;
	i = 1000000;
	while (start <= end) {
		mid = (start + end) >> 1;
		if (query(mid) >= l) {
			i = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return i;
}

int main()
{
	int i, j, x, k = 1, y;

	for (i = 2; i <= END; ++i) {
		insert(i, 1);
	}

	for (i = 2; i <= END; ++i) {
		//cout << i << " " << arr[i] << endl;
		y = 0;
		if (arr[i] == 0) {
			//cout << k << " " << i << endl;
			ans[k++] = i;
			insert(i, -1);
			for (j = i; j <= END; j += i-1) {
				x = find(j);
				if (x > END) break;
				arr[x] = 1;
				insert(x, -1);
			}
		}
	}

	//cout << k << endl;


	while (1) {
		scanf("%d", &k);
		if (k == 0) break;
		printf("%d\n", ans[k]);
	}

	return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, i;
	long long int total, req, start, end, mid, ans;
	cin>>n>>req;
	int tree[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &tree[i]);
	}

	sort(tree, tree + n);

	start = 0; end = tree[n-1]; ans = 0;
	while (start <= end) {
		mid = start + (end - start) / 2;
		total = 0;
		for (i = (n-1); i >= 0; i--) {
			if ((tree[i] >= mid) && (total <= req)) {
				total = total + tree[i] - mid;
			} else {
				break;
			}
		}
		if (total == req) {
			ans = mid;
			break;
		} else if (total < req) {
			end = mid - 1;
		} else if (total > req) {
			if (mid > ans) {
				ans = mid;
			}
			start = mid + 1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}

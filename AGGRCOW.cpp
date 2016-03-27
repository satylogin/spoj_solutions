#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	int t, n, c, low, high, mid, index, i, worker, cur, min;
	cin >> t;

	for (; t; --t) {
		cin >> n >> c;
		int arr[n];

		for (i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		sort(arr, arr + n);

		low = 0; 
		high = arr[n-1]; 
		min = INT_MIN;
		while (low <= high) {
			mid = low + (high - low) / 2;
			worker = 1; 
			cur = arr[0]; 
			index = INT_MAX;
			for (i = 1; i < n; i++) {
				if ((arr[i] - cur) >= mid) {
					if ((arr[i] - cur) < index) {
						index = arr[i] - cur;
					}
					worker++;
					cur = arr[i];
					if (worker >= c) {
						break;
					}
				}
			}
			if (worker >= c) {
				if (index > min) {
					min = index;
				}
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}

		cout << min << endl;
	}

	return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

int max(int, int);

int main()
{
	int n, m, x, y, i, j, k, t;
	cin >> n >> m >> x >> y;
	int arr[n][m];
	char str[10];

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> str;
			t = 0;
			if (strcmp(str, "Â") == 0) {
				--j;
				continue;
			}
			for (k = 0; str[k] >= '0'&& str[k] <= '9'; ++k) {
				t = t * 10 + (str[k] - '0');
			}
			arr[i][j] = t;
		}
	}

	for (i = x-1; i < n; ++i) {
		for (j = y-1; j < m; ++j) {
			if ((i != x-1) || (j != y-1)) {
				if (i == x-1) {
					arr[i][j] = arr[i][j-1] - arr[i][j];
				} else if (j == y-1) {
					arr[i][j] = arr[i-1][j] - arr[i][j];
				} else {
					arr[i][j] = max(arr[i-1][j], arr[i][j-1]) - arr[i][j];
				}
			}
		}
	}

	if (arr[n-1][m-1] >= 0) {
		cout << "Y " << arr[n-1][m-1] << endl;
	} else {
		cout << "N" << endl;
	}
}

int max(int a, int b)
{
	if (a >= b) return a;
	return b;
}

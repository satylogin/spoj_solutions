#include <iostream>

using namespace std;
int n, m;
int arr[100][100];
int ans[100][100];

int min_three(int, int, int);
int min_two(int, int);
int calc(int, int);

int main()
{
	int t, i, j, M = 0, a;
	t = 1;

	for (; t; t--) {
		cin >> n >> m;
		M = 99999999;
		
		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				ans[i][j] = 0;
			}
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		for (i = 0; i < m; i++) {
			a = calc(n-1, i);
			if (a < M) M = a;
		}

		cout << M << endl;
	}

	return 0;
}

int calc(int i, int j)
{
	if (ans[i][j] != 0) return ans[i][j];
	if (i == 0) {
		ans[i][j] = arr[i][j];
	} else if (j == 0) {
		ans[i][j] = arr[i][j] + min_two(calc(i-1, j), calc(i-1, j+1));
	} else if (j == m-1) {
		ans[i][j] = arr[i][j] + min_two(calc(i-1, j-1), calc(i-1, j));
	} else {
		ans[i][j] = arr[i][j] + min_three(calc(i-1, j-1), calc(i-1, j), calc(i-1, j+1));
	}

	return ans[i][j];
}

int min_two(int a, int b)
{
	if (a <= b) return a;
	return b;
}

int min_three(int a, int b, int c)
{
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;

	return min;
}

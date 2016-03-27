#include <iostream>

using namespace std;

int arr[2000], ans[2000][2000], n;

int calc(int, int, int);
int max(int, int);

int main()
{
	int i, x, y;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << calc(0, n-1, 1) << endl;

	return 0;
}

int calc(int start, int end, int age)
{
	if (start == end) {
		return (age * arr[start]);
	} else if(ans[start][end]){
		return ans[start][end];
	} else {
		return (ans[start][end] = max(age * arr[start] + calc(start + 1, end, age + 1), age * arr[end] + calc(start, end - 1, age + 1)));
	}
} 

int max(int a, int b)
{
	if (a >= b) return a;
	return b;
}

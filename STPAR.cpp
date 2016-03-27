#include <iostream>

using namespace std;

int main()
{
	int n, j, tmp, stk[1001], top, i, k, l, flag;
	cin >> n;

	while (n != 0) {
		int arr[n], ans[n];
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}

		top = -1; j = 0;
		for (i = 0; i < n; i++) {
			if (top == -1) {
				if(i != (n-1)) {
					if (arr[i] > arr[i+1]) {
						stk[++top] = arr[i];
					} else {
						ans[j++] = arr[i];
					}
				} else {
					ans[j++] = arr[i];
				}
			} else {	
				if (i != (n-1)) {
					while ((top >= 0) && (stk[top] < arr[i])) {
						ans[j++] = stk[top--];
					}
					if (arr[i] > arr[i+1]) {
						stk[++top] = arr[i];
					} else {
						ans[j++] = arr[i];
					}
				} else {
					while ((top >= 0) && (stk[top] < arr[i])) {
						ans[j++] = stk[top--];
					}
					ans[j++] = arr[i];
				}
			}	
		}

		while (top >= 0) {
			ans[j++] = stk[top--];
		}

		flag = 1;
		for (i = 0; i < n; i++) {
			if (ans[i] != (i + 1)) {
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}

		cin >> n;
	}

	return 0;
}

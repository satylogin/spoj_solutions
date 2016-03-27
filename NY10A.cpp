#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int t, a, b, c, i, j, n;
	char str[50], tmp[4];
	cin >> t;

	for (; t; --t) {
		cin >> n;
		int arr[8] = {0};
		cin >> str;

		a = 0; b = 1; c = 2;
		for (i = 0; i < 38; i++) {
			tmp[0] = str[a++];
			tmp[1] = str[b++];
			tmp[2] = str[c++];
			tmp[3] = '\0';
			
			if (strcmp(tmp, "TTT") == 0) {
				arr[0]++;
			} else if (strcmp(tmp, "TTH") == 0) {
				arr[1]++;
			} else if (strcmp(tmp, "THT") == 0) {
				arr[2]++;
			} else if (strcmp(tmp, "THH") == 0) {
				arr[3]++;
			} else if (strcmp(tmp, "HTT") == 0) {
				arr[4]++;
			} else if (strcmp(tmp, "HTH") == 0) {
				arr[5]++;
			} else if (strcmp(tmp, "HHT") == 0) {
				arr[6]++;
			} else if (strcmp(tmp, "HHH") == 0) {
				arr[7]++;
			}
		}

		cout << n << " ";
		for (i = 0; i < 8; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int t;
	unsigned long long a, b, c, l, r, m, i, count;
	cin >> t;

	for (; t; t--) {
		cin >> l >> r >> m;
		a = 1;
		b = 1;
		count = 0;
		
		if (m == 1) {
			cout << r - l + 1 << endl;
			continue;
		}	

		for (i = 3; i < l; i++) {
			c = a + b;
			a = b;
			b = c;
			if (a > m) a -= m;
			if (b > m) b -= m;
			if (c > m) c -= m;
		}

		for (; i <= r; i++) {
			c = a + b;
			a = b;
			b = c;
			if (a > m) a -= m;
			if (b > m) b -= m;
			if (c > m) c -= m;
			if ((c % m) == 0) count++;
		}

		cout << count << endl;
	}

	return 0;
}

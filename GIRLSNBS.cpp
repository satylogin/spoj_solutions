#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int b, g, i, j, k;
	cin >> b >> g;

	while ((b != -1) && (g != -1)) {
		if (b == 0 && g == 0) {
			cout << 0 << endl;
		} else if (b == g) {
			cout << 1 << endl;
		} else if ((b == 0) || (g == 0)) {
			if (b == 0) cout << g << endl;
			else cout << b << endl;
		} else {
			if (b < g) {
				b = b ^ g;
				g = b ^ g;
				b = b ^ g;
			}

			i = ceil((float)b / (float)(g + 1));
			j = b - (g * i);
			if (i > j) cout << i << endl;
			else cout << j << endl;
		}

		cin >> b >> g;
	}

	return 0;
}

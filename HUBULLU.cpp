#include <iostream>

using namespace std;

int main()
{
	int t, n, i;
	cin >> t;

	for (; t; --t) {
		cin >> n >> i;
		if (i == 0) {
			cout << "Airborne wins." << endl;
		} else if (i == 1) {
			cout << "Pagfloyd wins." << endl;
		}
	}

	return 0;
}

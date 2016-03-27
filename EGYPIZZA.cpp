#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	int t, pizza[3] = {0}, total = 0, tmp;
	char str[5];
	cin>>t;
	
	for ( ; t; t--) {
		cin>>str;
		if (strcmp(str, "1/4") == 0) {
			pizza[0]++;
		} else if (strcmp(str, "1/2") == 0) {
			pizza[1]++;
		} else if (strcmp(str, "3/4") == 0) {
			pizza[2]++;
		}
	}

	if (pizza[0] <= pizza[2]) {
		total = pizza[2];
		pizza[0] = 0;
	} else {
		total = pizza[2];
		pizza[0] = pizza[0] - pizza[2];
	}
	tmp = pizza[1] % 2;
	total = total + (pizza[1] / 2);
	if (tmp == 1) {
		total = total + 1;
		pizza[0] = pizza[0] - 2;
	}
	if (pizza[0] > 0) {
		total = total + ceil(pizza[0] / 4.0);
	}
	cout<<total+1<<endl;
	return 0;
}

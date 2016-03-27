#include <iostream>
using namespace std;

int main()
{
	int t, i, flag;
	cin>>t;

	while (t != 0) {
		int num[t], hash[t+1];
		for (i = 0; i < t; i++) {
			cin>>num[i];
		}

		for (i = 1; i < (t + 1); i++) {
			hash[num[i-1]] = i;
		}

		flag = 0;
		for (i = 1; i <= t; i++) {
			if (hash[i] != num[i-1]) {
				flag = 1;
				break;
			}			
		}
		if (flag == 1) {
			cout<<"not ambiguous"<<endl;
		} else if (flag == 0) {
			cout<<"ambiguous"<<endl;
		}

		cin>>t;
	}

	return 0;
}

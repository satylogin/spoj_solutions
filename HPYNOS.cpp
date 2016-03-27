#include <iostream>

using namespace std;

int main()
{
	long long int n, tmp, tmp1;
	cin>>n;
	long long int arr[100000];
	int count = 0, i, flag = 0;

	while (n != 1) {
		tmp = n;
		tmp1 = 0;
		while (tmp > 0) {
			tmp1 = tmp1 + (tmp%10)*(tmp%10);
			tmp = tmp/10;
		}
		arr[count++] = tmp1;
		for (i = 0; i < count-1; i++) {
			if (arr[i] == tmp1) {
				cout<<-1<<endl;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
		n = tmp1;
	}
	if (n == 1) cout<<count<<endl;

	return 0;
}

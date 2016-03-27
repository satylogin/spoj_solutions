#include <iostream>
using namespace std;

int arr[10000];

int main()
{
	int n, m, i, tmp, count = 0;
	cin>>n;

	for (i = 0; i < n; i++) {
		cin>>tmp;
		arr[tmp] = 1;
		cin>>m;
		while (m--) {
			cin>>tmp;
			arr[tmp] = 1;
		}
	}

	for (i = 0; i < 10000; i++) {
		if (arr[i] == 1) count++;
	}
	
	cout<<count - n<<endl;

	return 0;
}

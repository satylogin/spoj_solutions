#include <iostream>
#include <map>
using namespace std;

map <int, int> frnd;

int main()
{
	int n, m, i, tmp, count = 0;
	cin>>n;

	for (i = 0; i < n; i++) {
		cin>>tmp;
		frnd[tmp] = 1;
		cin>>m;
		while (m--) {
			cin>>tmp;
			frnd[tmp] = 1;
		}
	}

	count = frnd.size();
	
	cout<<count - n<<endl;

	return 0;
}

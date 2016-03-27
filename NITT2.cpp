#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int t, q, r, i, len, d;
	char num[50001];
	cin>>t;
	
	for (; t; t--) {
		cin>>num;
		len = strlen(num);
		d = 0; q = 252; r = 0;
		for (i = 0; i < len;) {
			if (d < q) {
				d = d * 10 + (num[i] - '0');
				i++;
			} else {
				r = d % q;
				d = r;
			}
		}
		r = d % q;
		d = r;
		if ((r == 0) && (d == 0)) {
			cout<<"Yes ";
		} else {
			cout<<"No ";
		}
		
		d = 0; q = 525; r = 0;
		for (i = 0; i < len;) {
			if (d < q) {
				d = d * 10 + (num[i] - '0');
				i++;
			} else {
				r = d % q;
				d = r;
			}
		}
		r = d % q;
		d = r;
		if ((r == 0) && (d == 0)) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}

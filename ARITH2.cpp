#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int main()
{
	int t; cin>>t;
	
	while (t--) {
		long long int num;
		long long int ans;
		char str[4] = "a";
		cin>>ans;
		cin>>str;
		while (strcmp(str,"=") != 0) {
			if (strcmp(str,"+") == 0) {
				cin>>num;
				ans = ans + num;
			} else if (strcmp(str,"-") == 0) {
				cin>>num;
				ans = ans - num;
			} else if (strcmp(str,"*") == 0) {
				cin>>num;
				ans = ans * num;
			} else if (strcmp(str,"/") == 0) {
				cin>>num;
				ans = ans / num;
			}
			cin>>str;
		}
		cout<<ans<<endl;
	}

	return 0;
}

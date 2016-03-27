#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str[200], ans[200];
	int i, flag = 2, j, e, len;	

	while (scanf("%s", str) != EOF) {
		flag = 2; j = 0; e = 0;
		len = strlen(str);
		for (i = 0; str[i] != '\0'; i++) {
			if ((i == 0) || (i == len-1)) {
				if (str[i] == '_') {
					e = 1;
					break;
				}
			}
			if (i == 0) {
				if (str[i] >= 'A' && str[i] <= 'Z') {
					e = 1;
					break;
				}
			}
			if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] <= 'z' && str[i] >= 'a') || (str[i] == '_'))) {
				e = 1;
				break;
			}
			if (str[i] >= 'A' && str[i] <= 'Z') {
				if (flag == 1) {
					e = 1;
					break;
				}
				ans[j++] = '_';
				ans[j++] = str[i] + ('a' - 'A');
				flag = 0;
			} else if (str[i] == '_') {
				if (flag == 0) {
					e = 1;
					break;
				}
				if (str[i] == '_') {
					i++;
				}
				if ((str[i] >= 'a') && (str[i] <= 'z')) {
					flag = 1;
					ans[j++] = str[i] - ('a' - 'A');
				} else {
					e = 1;
					break;
				}
			} else {
				ans[j++] = str[i];
			}
		}
		ans[j] = '\0';

		if (e == 0) {
			cout << ans << endl;
		} else if (e == 1) {
			cout << "Error!" << endl;
		}
	}	
}

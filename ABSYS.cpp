#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while (t--) {
		char str1[20],str2[2],str3[20],str4[2],str5[20];
		int num1=0,num2=0,num3=0;
		cin>>str1>>str2>>str3>>str4>>str5;
		if (strstr(str5,"machula")) {
			int i = 0;
			while (str1[i] != '\0') {
				num1 = num1 * 10 + (str1[i] - '0');
				i++;
			}
			i = 0;
			while (str3[i] != '\0') {
				num2 = num2 * 10 + (str3[i] - '0');
				i++;
			}
			cout<<num1<<" + "<<num2<<" = "<<(num1 + num2)<<endl;
		}
		else if (strstr(str3,"machula")) {
			int i = 0;
			while (str1[i] != '\0') {
				num1 = num1 * 10 + (str1[i] - '0');
				i++;
			}
			i = 0;
			while (str5[i] != '\0') {
				num3 = num3 * 10 + (str5[i] - '0');
				i++;
			}
			cout<<num1<<" + "<<(num3 - num1)<<" = "<<num3<<endl;
		}
		else if (strstr(str1,"machula")) {
			int i = 0;
			while (str3[i] != '\0') {
				num2 = num2 * 10 + (str3[i] - '0');
				i++;
			}
			i = 0;
			while (str5[i] != '\0') {
				num3 = num3 * 10 + (str5[i] - '0');
				i++;
			}
			cout<<(num3 - num2)<<" + "<<num2<<" = "<<num3<<endl;
		}
	}

	return 0;
}

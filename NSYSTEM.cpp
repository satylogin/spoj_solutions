#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int to_int(char *, int);
void to_num(int);

int main()
{
	int t, a, b, c, len1, len2;
	char A[10], B[10];
	cin>>t;

	for (; t; t--) {
		cin>>A>>B;
		len1 = strlen(A); 
		len2 = strlen(B);
		a = to_int(A, len1);
		b = to_int(B, len2);
		to_num(a+b);
	}

	return 0;
}

void to_num(int n)
{
	int i = 0, tmp;
	char str[10];
	tmp = n / 1000;
	if (tmp > 0) n = n % 1000;
	if (tmp != 0) {
		if (tmp == 1) {
			str[i++] = 'm';
		} else {
			str[i++] = tmp + '0';
			str[i++] = 'm';
		}
	}
	tmp = n / 100;
	if (tmp > 0) n = n % 100;
	if (tmp != 0) {
		if (tmp == 1) {
			str[i++] = 'c';
		} else {
			str[i++] = tmp + '0';
			str[i++] = 'c';
		}
	}
	tmp = n / 10;
	if (tmp > 0) n = n % 10;
	if (tmp != 0) {
		if (tmp == 1) {
			str[i++] = 'x';
		} else {
			str[i++] = tmp + '0';
			str[i++] = 'x';
		}
	}
	tmp = n;
	if (tmp != 0) {
		if (tmp == 1) {
			str[i++] = 'i';
		} else {
			str[i++] = tmp + '0';
			str[i++] = 'i';
		}
	}
	str[i] = '\0';

	cout<<str<<endl;
}

int to_int(char str[], int len)
{
	int i, ans = 0, tmp;
	for (i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			switch (str[i]) {
				case 'm': ans = ans + 1000; break;
				case 'c': ans = ans + 100; break;
				case 'x': ans = ans + 10; break;
				case 'i': ans = ans + 1; break;
			}
		} else {
			tmp = str[i] - '0';
			i++;
			switch(str[i]) {
				case 'm': ans = ans + tmp * 1000; break;
				case 'c': ans = ans + tmp * 100; break;
				case 'x': ans = ans + tmp * 10; break;
				case 'i': ans = ans + tmp * 1; break; 
			}	
		}
	}

	return ans;
}

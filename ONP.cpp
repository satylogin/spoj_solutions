#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

void push(char*, char, int*);
void pop(char*, int*);
char top(char*, int*);

int main()
{
	int t;
	cin>>t;

	while (t--) {
		char arr[1000];
		cin>>arr;
		int length = strlen(arr), i, end1 = -1, end2 = -1;
		char a, s1[1000], s2[1000];

		//maintaining the loop counter
		for (i = 0; i < length; i++) {
			// if the character is an alphabet
			if (arr[i] >= 'a' && arr[i] <= 'z') {
				push(s2, arr[i], &end2);
			}
			// if the character is an opening bracket
			if (arr[i] == '(') {
				push(s1, arr[i], &end1);
			}
			// if the character is an closing bracket
			else if (arr[i] == ')') {
				while (top(s1, &end1) != '(') {
					push(s2, top(s1, &end1), &end2);
					pop(s1, &end1);
				}
				pop(s1, &end1);
			}
			// if the operator is '+' sign
			else if (arr[i] == '+') {
				while(end1 > -1) {
					a = top(s1, &end1);
					if (a=='+'|| a=='-' || a=='*' || a=='/' || a=='^') {
						push(s2, a, &end2);
						pop(s1, &end1);
					} else {
						break;
					}
				}
				push(s1, arr[i], &end1);
			}
			// if the operator is '-' sign
			else if (arr[i] == '-') {
				while (end1 > -1) {
					a = top(s1, &end1);
					if (a=='-' || a=='*' || a=='/' || a=='^') {
						push(s2, a, &end2);
						pop(s1, &end1);
					} else {
						break;
					}
				}
				push(s1, arr[i], &end1);
			}
			// if the operator is '*' sign
			else if (arr[i] == '*') {
				while (end1 > -1) {
					a = top(s1, &end1);
					if (a== '*' || a=='/' || a=='^') {
						push(s2, a, &end2);
						pop(s1, &end1);
					} else {
						break;
					}
				}
				push(s1, arr[i], &end1);
			}
			// if the operator is '/' sign
			else if (arr[i] == '/') {
				while (end1 > -1) {
					a = top(s1, &end1);
					if (a=='/' || a=='^') {
						push(s2, a, &end2);
						pop(s1, &end1);
					} else {
						break;
					}
				}
				push(s1, arr[i], &end1);
			}
			//if the operator is '^' sign
			else if (arr[i] == '^') {
				while (end1 > -1) {
					a = top(s1, &end1);
					if (a=='^') {
						push(s2, a, &end2);
						pop(s1, &end1);
					} else {
						break;
					}
				}	
				push(s1, arr[i], &end1);
			}
		}
		// to empty the stack
		while (end1 > -1) {
			push(s2, top(s1, &end1), &end2);
			pop(s1, &end1);
		}

		// printing the value of final array
		for (i = 0; i <= end2; i++) {
			cout<<s2[i];
		}
		cout<<endl;
	}	

	return 0;
}

void push(char* stack, char data, int* end)
{
	*end = *end + 1;
	*(stack + *end) = data;
}

void pop(char* stack, int* end)
{
	*end = *end - 1;
}

char top(char* stack, int* end)
{
	return *(stack + *end);
}

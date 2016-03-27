#include <iostream>
#include <cstdio>
#include <bitset>
#include <stdlib.h>
using namespace std;
#define MAX 1000001

bitset <MAX> sieve;
int prime[MAX/10], k;

void set()
{
	int i, j;
	for (i = 2; i*i < MAX; i++) {
		if (sieve[i] == 0) {
			prime[k++] = i;
			for (j = i*i; j < MAX; j+=i) {
				sieve[j] = 1;
			}
		}
	}
	for (; i < MAX; i++) 
		if (sieve[i] == 0)
			prime[k++] = i;
}

int bs(int num)
{
	int start, mid, end, index = -1, min = MAX;
	start = 0;
	end = k-1;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (prime[mid] == num) {
			return mid;
		} else if (prime[mid] < num) {
			start = mid + 1;
		} else {
			if (prime[mid] < min) {
				min = prime[mid];
				index = mid;
			}
			end = mid - 1;
		}
	}
	return index;
}

int is_prime(int n)
{
	for (int i = 0; prime[i]*prime[i] <= n; i++) {
		if ((n % prime[i]) == 0) {
			return -1;
		}
	}
	return 1;
}

int main()
{
	set();

	int t, i, j, a, b, c, x, y;
	scanf("%d", &t);
	for (; t; t--) {
		scanf("%d%d", &a, &b);
		i = bs(a);
		if (i != -1) {
			for (; i < k && prime[i] <= b; i++) {
				printf("%d\n", prime[i]);
			}
		}
		if (b >= MAX) {
			if (a > prime[k-1]) {
				j = a;
			} else {
				j = prime[k-1] + 1;
			}
			for (; j <= b; j++) {
				if (is_prime(j) == 1) {
					printf("%d\n", j);
				}
			}
		}
		printf("\n");
	}
	return 0;
}

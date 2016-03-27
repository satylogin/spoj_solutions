#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int sum1[16000000], sum2[16000000];

int main()
{
	int n, i, j, start, mid1, end, count = 0, mid2, k = 0, x, y;
	scanf("%d", &n);
	int a[n], b[n], c[n], d[n];

	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum1[k] = a[i] + b[j];
			sum2[k++] = c[i] + d[j];
		}
	}

	sort(sum1, sum1+k);
	sort(sum2, sum2+k);
	
	i = 0; j = k - 1; x = 1; y = 1;
	while ((i < k) && (j >= 0)) {
	    if (sum1[i] + sum2[j] == 0) {
	        if ((i < (k - 1)) && (j > 0)) {
    	        while ((i < (k - 1)) && (sum1[i] == sum1[i+1])) {
    	            i++;
    	            x++;
    	        }
    	        while ((j > 0) && (sum2[j] == sum2[j-1])) {
    	            j--;
    	            y++;
    	        }
    	        count = count + x * y;
    	        x = 1;
    	        y = 1;
    	        i++;
    	        j--;
	        } else if (i < (k - 1)) {
	            count++;
	            i++;
	        } else if (j > 0) {
	            count++;
	            j--;
	        }
	    } else if (sum1[i] + sum2[j] > 0) {
	        j--;
	    } else if (sum1[i] + sum2[j] < 0) {
	        i++;
	    }
	}

	printf("%d\n", count);

	return 0;
}

#include <stdio.h>

int main()
{
	int t, n, count1, num2, num1, count2, i;
	scanf("%d", &t);

	for (; t; t--) {
		count1 = 0; count2 = 0;
		scanf("%d", &n);
		int person[n];
		
		for (i = 0; i < n; i++) {
			scanf("%d", &person[i]);
		}

		for (i = 0; i < n; i++)
			if (count1 == 0) {
				num1 = person[i];
				count1++;
			} else 
				if (person[i] == num1) 
					count1++;
				else 
					count1--;

		for (i = (n - 1); i >= 0; i--)
			if (count2 == 0) {
				num2 = person[i];
				count2++;
			} else 
				if (person[i] == num2) 
					count2++;
				else 
					count2--;

		if (((count1 > 0) && (count2 > 0)) && (num1 == num2)) {
			printf("YES %d\n\n", num1);
		} else {
			printf("NO\n\n");
		}
	}

	return 0;
}

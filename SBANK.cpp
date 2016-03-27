#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct bank {
    long long int a, b, x;  
};

int comp(const void *a3, const void *a4)
{
    	bank *a1, *a2;
    	a1 = (bank *)a3;
    	a2 = (bank *)a4;
    	
	if (a1->a < a2->a) {
    	    return 0;
    	} else if (a1->a == a2->a) {
    	    	if (a1->b < a2->b) {
    	        	return 0;
    	    	} else if (a1->b == a2->b) {
    	        	if (a1->x <= a2->x) {
    	            		return 0;
    	        	} else {
    	           		 return 1;
    	        	}
    	    	} else {
    	        	return 1;
    	    	}
    	} else {
    	    return 1;
    	}
}

int main()
{
	int t, n, i, j;
    	long long int tmp, a, b, c, d;
    	cin>>t;
    	for (; t; t--) {
    	    	cin>>n;
    	    	bank acc[n];
    		char str[n][50];

	    	for (i = 0; i < n; i++) {
    	    		    cin>>acc[i].a>>acc[i].b>>a>>b>>c>>d;
    	    		    tmp = a;
    	    		    tmp = tmp * 10000 + b;
    	    		    tmp = tmp * 10000 + c;
    	    		    tmp = tmp * 10000 + d;
    	    		    //tmp = a * 1000000000000 + b * 100000000 + c * 10000 + d;
    	    		    acc[i].x = tmp;
    	    	}
    	    	
    	    	qsort(acc, n, sizeof(bank), comp);
		
		for (i = 0; i < n; i++) {
			for (j = 1; j >= 0; j--) {
				str[i][j] = (acc[i].a % 10) + '0';
				acc[i].a = acc[i].a / 10;
			}
			str[i][2] = ' ';
			for (j = 10; j >= 3; j--) {
				str[i][j] = (acc[i].b % 10) + '0';
				acc[i].b = acc[i].b / 10;
			}
			str[i][11] = ' ';
			str[i][31] = '\0';
			for (j = 30; j >= 27; j--) {
				str[i][j] = (acc[i].x % 10) + '0';
				acc[i].x = acc[i].x / 10;
			}
			str[i][26] = ' ';
			for (j = 25; j >= 22; j--) {
				str[i][j] = (acc[i].x % 10) + '0';
				acc[i].x = acc[i].x / 10;
			}
			str[i][21] = ' ';
			for (j = 20; j >= 17; j--) {
				str[i][j] = (acc[i].x % 10) + '0';
				acc[i].x = acc[i].x / 10;
			}
			str[i][16] = ' ';
			for (j = 15; j >= 12; j--) {
				str[i][j] = (acc[i].x % 10) + '0';
				acc[i].x = acc[i].x / 10;
			}
		}
	    	
		tmp = 1;
    		for (i = 1; i < n; i++) {
			if (strcmp(str[i], str[i-1]) == 0) {
				tmp++;
			} else {
				cout<<str[i-1]<<" "<<tmp<<endl;
				tmp = 1;
			}
		}
		if (strcmp(str[n-1], str[n-2]) == 0) {
			cout<<str[n-1]<<" "<<tmp<<endl;
		} else {
			cout<<str[n-1]<<" "<<1<<endl;
		}
		cout<<endl;
    	}
    	
    	return 0;
}	

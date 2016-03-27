#include <iostream>
using namespace std;

int max1(int, int);
int max2(int, int, int);

int main()
{
        int a, b, i, j, t, ans, m, n;
        cin>>t;
        for (; t; t--) {
                cin>>n>>m;
                int stones[n][m];
                for (i = 0; i < n; i++) {
                        for (j = 0; j < m; j++) {
                                cin>>stones[i][j];
                        }
                }
                if (m >= 2) {
                        for (i = 1; i < n; i++) {
                                for (j = 0; j < m; j++) {
                                        if (j == 0) {
                                                stones[i][j] += max1(stones[i-1][j], stones[i-1][j+1]);        
                                        } else if (j == m-1) {
                                                stones[i][j] += max1(stones[i-1][j], stones[i-1][j-1]);
                                        } else {
                                                stones[i][j] += max2(stones[i-1][j-1], stones[i-1][j], stones[i-1][j+1]);
                                        }
                                }
                        }
			ans = 0;
			for (i = 0; i < m; i++) 
				if (stones[n-1][i] >= ans) 
					ans = stones[n-1][i];
			cout<<ans<<endl;
                } else if (m == 1) {
                        ans = 0;
                        for (i = 0; i < n; i++) {
                                ans += stones[i][0];
                        }
                        cout<<ans<<endl;
                }
        }
        
        return 0;
}

int max1(int a, int b)
{
        if (a >= b) {
                return a;
        } else {
                return b;
        }
}

int max2(int x, int y, int z)
{
        if (x >= y && x >= z) {
                return x;
        } else if (y >= x && y >= z) {
                return y;
        } else {
                return z;
        }
}

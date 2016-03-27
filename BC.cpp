#include <iostream>
using namespace std;

int main()
{
    int t, i;
    long long int ans1, ans2, n, m, k;
    cin>>t;
    for (i = 0; i < t; i++) {
        cin>>n>>m>>k;
        ans1 = (n * m * k) - 1;
        ans2 = 0;
        while (n) {
            if (n == 1) {
                break;
            }
            if ((n % 2) == 0) {
                ans2++;
                n = n / 2;
            } else {
                ans2++;
                n = (n + 1) / 2;
            }
        }
        while (m) {
            if (m == 1) {
                break;
            }
            if ((m % 2) == 0) {
                ans2++;
                m = m / 2;
            } else {
                ans2++;
                m = (m + 1) / 2;
            }
        }
        while (k) {
            if (k == 1) {
                break;
            }
            if ((k % 2) == 0) {
                ans2++;
                k = k / 2;
            } else {
                ans2++;
                k = (k + 1) / 2;
            }
        }
        cout<<"Case #"<<(i+1)<<": "<<ans1<<" "<<ans2<<endl;
    }
    
    return 0;
}

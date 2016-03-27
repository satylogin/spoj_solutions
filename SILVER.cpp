#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    float a, b;
    cin>>n;
    while (n != 0) {
        a = log2(n);
        cout<<floor(a)<<endl;
        cin>>n;
    }
    
    return 0;
}

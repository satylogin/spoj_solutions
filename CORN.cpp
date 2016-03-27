#include <stdio.h>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int t, i, len, j; scanf("%d", &t);
    char str1[100], str2[100], str3[100], str[100], ch1, ch2;
    double r, s, h, ans;
    for ( ; t; t--) {
        scanf("%s", str);
        len = strlen(str);
        for (i = 0; str[i] != 'e'; i++) {
            str1[i] = str[i];
        }
        str1[i] = '\0';
        i++; j = 0;
        for (; str[i] != 'e'; i++) {
            str2[j++] = str[i];
        }
        str2[j] = '\0';
        i++; j = 0;
        for (; i < len; i++) {
            str3[j++] = str[i];
        }
        str3[j] = '\0';
        r = atof(str1);
        s = atof(str2);
        h = atof(str3);
        ans = 3.1415 * r * sqrt(r*r + h*h) * s;
        cout<<ceil(ans)<<endl;
    }
    
    return 0;
}

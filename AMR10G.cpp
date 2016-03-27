#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t,i,j,k;
	cin>>t;
	int m,n;
	long tmp;
	for(i=0;i<t;i++)
	{
		cin>>n>>m;
		long h[n];
		for(j=0;j<n;j++)
		{
			cin>>h[j];
		}

/*		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(h[j] > h[k])
				{
					tmp = h[j];
					h[j] = h[k];
					h[k] = tmp;
				}
			}
		}
*/
		sort(h,h+n);
		
		long x,y,min = h[m-1] - h[0];
		for(j=0;j<=(n-m);j++)
		{
			x = h[j];
			y = h[j+m-1];
			if(min > (y-x))
			{
				min = y-x;
			}
		}
		cout<<min<<endl;
	}
	return 0;
}
		

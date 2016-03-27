#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int t,i,j,k;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int m[n];
		int f[n];
		int sum = 0;
		
		for(i=0;i<n;i++)
		{
			cin>>m[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>f[i];
		}
		
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(m[j] < m[i])
				{
					k = m[j];
					m[j] = m[i];
					m[i] = k;
				}
				if(f[j] < f[i])
				{
					k = f[j];
					f[j] = f[i];
					f[i] = k;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			sum = sum + m[i]*f[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}

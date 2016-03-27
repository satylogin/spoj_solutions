#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
long long int power(int);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,k;
		cin>>n>>k;
		long long int ans = 1;
		int i;
		int count = 1;
		for(i=62;i>0;i--)
		{
			if((ans + power(i) < n) && ((count+1) <= k))
			{
				ans = ans + power(i);
				count++;
			}
		}
		if(k > 0)
		{
			cout<<ans<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}	
	return 0;
}

long long int power(int n)
{
	long long int ans = 1;
	int i;
	for(i=0;i<n;i++)
		ans=ans*2;
	return ans;
}

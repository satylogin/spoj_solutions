#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int x[t],y[t];
	int i;

	for(i=0;i<t;i++)
	{
		cin>>x[i]>>y[i];
	}

	for(i=0;i<t;i++)
	{
		int num = 0;
		if(x[i] == y[i])
		{
			if(x[i]%2 == 0)
			{
				num = x[i]*2;
			}
			else
			{
				num = x[i]*2 - 1;
			}
			cout<<num<<'\n';
		}
		else if(x[i] == (y[i]+2))
		{
			if(x[i]%2 == 0)
			{
				num = x[i]*2 - 2;
			}
			else
			{
				num = y[i]*2 + 1;
			}
			cout<<num<<'\n';
		}
		else
		{
			cout<<"No Number"<<'\n';
		}
	}
	return 0;
}

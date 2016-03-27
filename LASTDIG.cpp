#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t,i;
	cin>>t;
	int a[t];
	long long b[t];
	for(i=0;i<t;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	for(i=0;i<t;i++)
	{
		int x = a[i]%10;
		int y = b[i]%4;
		if(b[i] == 0)
		{
			cout<<1<<endl;
		}
		else if(x == 0)
		{
			cout<<0<<endl;
		}
		else if(y == 0)
		{
			int z = pow(x,4);
			z = z%10;
			cout<<z<<'\n';
		}
		else
		{
			int z = pow(x,y);
			z = z%10;
			cout<<z<<'\n';
		}
	}
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	int i,j,sum=0,tmp;
	for(i=1;i<=t;i++)
	{
		tmp = 0;
		for(j=1;j<=sqrt(i);j++)
		{
			if(i%j == 0)
			{
				tmp++;
			}
		}
		sum = sum + tmp;
	}
	cout<<sum<<endl;
	return 0;
}

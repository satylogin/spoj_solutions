#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	long long num[t];
	long long count[t];
	long long i,j,k;

	for(i=0;i<t;i++)
	{
		cin>>num[i];
	}
	
	for(i=0;i<t;i++)
	{
		count[i] = 0;
		long long f = 5;
		while(num[i]/f > 0)
		{
			count[i] = count[i] + num[i]/f;
			f = f*5;
		}
		cout<<count[i]<<endl;
	}

	return 0;
}

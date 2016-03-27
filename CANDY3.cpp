#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long num;
		long long sum = 0;
		long long i;
		for(i=0;i<n;i++)
		{
			cin>>num;
			sum = sum + num%n;
		}
		if(sum%n == 0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

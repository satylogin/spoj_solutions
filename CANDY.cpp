#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int t,i;
	while(1)
	{
		cin>>t;
		if(t == -1)
		{
			break;
		}
		int arr[t];
		int sum = 0;
		for(i=0;i<t;i++)
		{
			cin>>arr[i];
			sum = sum + arr[i];
		}
		if(sum%t != 0)
		{
			cout<<-1<<endl;
			continue;
		}
		sum = sum/t;
		int ans = 0;
		for(i=0;i<t;i++)
		{
			if(arr[i] > sum)
			{
				ans = ans + arr[i] - sum;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

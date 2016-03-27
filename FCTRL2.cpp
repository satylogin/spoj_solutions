#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int t,i;
	cin>>t;
	int num[t];
	for(i=0;i<t;i++)
	{
		cin>>num[i];
	}
//	int n[200]= {0};
	int tmp,j,k;
	for(i=0;i<t;i++)
	{
		tmp = 0;
		int n[200] = {0};
		n[0] = 1;		
		int index = 0;
		for(j=num[i];j>1;j--)
		{
			for(k=0;k<=index;k++)
			{
				tmp = tmp + n[k]*j;
				n[k] = tmp%10;
				tmp = tmp/10;
			}

			while(tmp>0)
			{
				n[++index] = tmp%10;
				tmp = tmp/10;
			}
		}
		for(k=index;k>=0;k--)
		{
			cout<<n[k];
		}
		cout<<endl;
	}
	return 0;
}

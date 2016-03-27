#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

void half(int *p,int len)
{
	int i,tmp = 0;
	for(i=0;i<len;i++)
	{
		tmp = tmp*10 + *(p+i);
		*(p+i) = tmp/2;
		tmp = tmp - (*(p+i) * 2);
	}
}

void sum(int *p,int len,int *e, int elen,int * k)
{
	int tmp = 0;
	int i = len-1;
	int j = elen-1;
	while(j>=0)
	{
		tmp = tmp + *(p+i) + *(e+j);
		*(k+i) = tmp%10;
		tmp = tmp/10;
		i--;
		j--;
	}
	while(i>=0)
	{
		tmp = tmp + *(p+i);
		*(k+i) = tmp%10;
		tmp = tmp/10;
		i--;
	}
	i = 0;
	while(*(k+i) == 0)
	{
		i++;
		if(i==len)
		{
			break;
		}
	}
	if(i == len)
	{
		cout<<0;
	}
	for(;i<len;i++)
	{
		cout<<*(k+i);
	}
	cout<<endl;
}

void diff(int *p,int len,int *e,int elen,int* n)
{
	int i = len-1;	
	int j = elen-1;
	while(j>=0)
	{
		if(*(p+i) < 0)
		{
			*(p+i) = *(p+i) + 10;
			*(p+i-1) = *(p+i-1)-1;
		}
		if(*(p+i) < *(e+j))
		{
			*(n+i) = 10 + *(p+i) - *(e+j);
			*(p+i-1) = *(p+i-1) - 1;
		}
		else
		{
			*(n+i) = *(p+i) - *(e+j);
		}
		i--;
		j--;
	}
	while(i>=0)
	{
		if(*(p+i) < 0 && i!= 0)
		{
			*(p+i) = *(p+i) + 10;
			*(p+i-1) = *(p+i-1) - 1;
		}
		*(n+i) = *(p+i);
		i--;
	}
	i = 0;
	while(*(n+i) == 0)
	{
		i++;
		if(i==len)
		{
			break;
		}
	}
	if(i==len)
	{
		cout<<0;
	}
	for(;i<len;i++)
	{
		cout<<*(n+i);
	}
	cout<<endl;
}

void sum1(int *p,int len,int *e,int elen,int *k)
{
	int tmp = 0;
	int i = len-1;
	int j = elen-1;
	while(j>=0)
	{
		tmp = tmp + *(p+i) + *(e+j);
		*(k+i) = tmp%10;
		tmp = tmp/10;
		i--;
		j--;
	}
	while(i>=0)
	{
		tmp = tmp + *(p+i);
		*(k+i) = tmp%10;
		tmp = tmp/10;
		i--;
	}
	tmp = 1;
	i = len-1;
	while(tmp >0)
	{
		tmp = tmp + *(k+i);
		*(k+i) = tmp%10;
		tmp = tmp/10;
		i--;
	}
	i = 0;
	while(*(k+i) == 0)
	{
		i++;
		if(i==len)
		{
			break;
		}
	}
	if(i== len)
	{
		cout<<0;
	}
	for(;i<len;i++)
	{
		cout<<*(k+i);
	}
	cout<<endl;
}

int main()
{
	char n[10][130];
	char ex[10][130];
	int len[10];
	int elen[10];
	int i,j;

	for(i=0;i<10;i++)
	{
		cin>>n[i];
		len[i] = strlen(n[i]);
		cin>>ex[i];
		elen[i] = strlen(ex[i]);
	}

	int num[10][130] = {0};
	int extra[10][130] = {0};

	for(i=0;i<10;i++)
	{
		for(j=0;j<len[i];j++)
		{
			num[i][j] = n[i][j]-48;
		}
		for(j=0;j<elen[i];j++)
		{
			extra[i][j] = ex[i][j] - 48;
		}
		
		half(num[i],len[i]);
		int *nu = num[i];
		int *ext = extra[i];
		if(extra[i][elen[i]-1]%2 == 0)
		{
			half(extra[i],elen[i]);
			int kla[130] = {0};
			int *kl = kla;
			int nat[130] = {0};
			int *na = nat;
			sum(nu,len[i],ext,elen[i],kl);
			diff(nu,len[i],ext,elen[i],na);
		}
		else
		{
			half(extra[i],elen[i]);
			int kla[130] = {0};
			int *kl = kla;
			int nat[130] = {0};
			int *na = nat;
			sum1(nu,len[i],ext,elen[i],kl);
			diff(nu,len[i],ext,elen[i],na);
		}
	}
	
	return 0;
}

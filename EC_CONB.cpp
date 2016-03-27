#include <iostream>
#include <stdio.h>

using namespace std;

int number();
void binary(int );
int num[32];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n%2 == 0)
		{
			binary(n);
			cout<<number()<<endl;
		}
		else
		{
			cout<<n<<endl;
		}
	}
	return 0;
}

int number()
{
	int i;
	int temp = 1,sum = 0;
	for(i=31;i>=0;i--)
	{
		sum = sum + num[i]*temp;
		temp = temp*2;
	}
	return sum;
}

void binary(int n)
{
	int count = 31;
	int i;
	for(i=0;i<32;i++)
	{
		num[i] = 0;
	}
	while(n>0)
	{
		num[count--] = n%2;
		n = n/2;
	}
	count++;
	i = 31;
	int temp;
	while(i > count)
	{
		temp = num[i];
		num[i] = num[count];
		num[count] = temp;
		i--;
		count++;
	}
}

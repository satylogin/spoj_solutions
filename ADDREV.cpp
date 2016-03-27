//adding the reverse of number and then giving the reversed sum of the number
#include <stdio.h>
int main()
{
	int tc;//test cases
	scanf("%d",&tc);
	int num1[tc];//number 1
	int num2[tc];//number 2
	int sum[tc];//for storing the sum
	int i=0,j=0,k=0;
	for(i=0;i<tc;i++)
	{
		scanf("%d%d",&num1[i],&num2[i]);//scanning the two numbers
	}
	for(i=0;i<tc;i++)//for reversing
	{
		while(num1[i]!=0)//reversing number 1
		{
			j=num1[i]%10;
			k=k*10+j;
			num1[i]=num1[i]/10;
		}
		num1[i]=k;//assingning reversed number to orignal varriable
		k=0;//setting counter back to 0
		while(num2[i]!=0)//reversing number 2
		{
			j=num2[i]%10;
			k=k*10+j;
			num2[i]=num2[i]/10;
		}
		num2[i]=k;//assigning reversed number to orignal variable 
		k=0;//setting counter back to 0
	}
	for(i=0;i<tc;i++)
	{
		sum[i]=num1[i]+num2[i];//adding the reversed number
		while(sum[i]!=0)//reversing the sum
		{
			j=sum[i]%10;
			k=k*10+j;
			sum[i]=sum[i]/10;
		}
		sum[i]=k;//assigning the reversed value
		k=0;//setting counter back to 0
	}
	for(i=0;i<tc;i++)
	{
		printf("%d\n",sum[i]);
	}
	return 0;
}

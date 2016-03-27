#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>

using namespace std;

int converter(int);
char* reconverter(int);

int main()
{
	char num[100000];
	cin>>num;
	while(strcmp(num,"BYE") != 0)
	{
		int i=0,j=0,len1=0,len2=0;
		int a[100000] = {0};
		int b[100000] = {0};
		while(num[i] != '+')
		{
			a[len1] = num[i]-48;
			i++;
			len1++;
		}
		i++;
		while(num[i] != '=')
		{
			b[len2] = num[i]-48;
			i++;
			len2++;
		}
		i=0,j=0;
		int tmp=0;
		long long num1=0,num2=0;
		while(i<len1)
		{
			for(j=0;j<3;j++)
			{
				tmp = tmp*10 + a[i+j];
			}
			i = i+3;
			num1 = num1*10 + converter(tmp);
			tmp = 0;
		}
		i=0,j=0;
		while(i<len2)
		{
			for(j=0;j<3;j++)
			{
				tmp = tmp*10 + b[i+j];
			}
			i = i+3;
			num2 = num2*10 + converter(tmp);
			tmp = 0;
		}
		long long num3 = num1 + num2;
		char ans[100000] = {0};
		char an[100000];
		char *t;
		while(num3 > 0)
		{
			t = reconverter(num3%10);
			strcpy(an,t);
			strcat(an,ans);
			strcpy(ans,an);
			num3 = num3 / 10;
		}
		cout<<num<<ans<<endl;
		cin>>num;
	}
	return 0;
}

int converter(int tmp)
{
	int x=0;
	switch(tmp)
	{
		case 63:x = 0;break;
		case 10:x = 1;break;
		case 93:x = 2;break;
		case 79:x = 3;break;
		case 106:x = 4;break;
		case 103:x = 5;break;
		case 119:x = 6;break;
		case 11:x = 7;break;
		case 127:x = 8;break;
		case 107:x = 9;break;
	}
	return x;
}

char* reconverter(int n)
{
	static char ans1[4];
	char *a = ans1;
	switch(n)
	{
		case 0: strcpy(ans1,"063");break;
		case 1: strcpy(ans1,"010");break;
		case 2: strcpy(ans1,"093");break;
		case 3: strcpy(ans1,"079");break;
		case 4: strcpy(ans1,"106");break;
		case 5: strcpy(ans1,"103");break;
		case 6: strcpy(ans1,"119");break;
		case 7: strcpy(ans1,"011");break;
		case 8: strcpy(ans1,"127");break;
		case 9: strcpy(ans1,"107");break;
	}
	return a;
}

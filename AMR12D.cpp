#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;
void reverse(char *,int);

int main()
{
	int t,i,j,k,l,m;
	char *c;
	cin>>t;
	char str[t][15];
	int len[t];
	for(i=0;i<t;i++)
	{
		cin>>str[i];
		len[i] = strlen(str[i]);
	}
	for(i=0;i<t;i++)
	{
		for(j=2;j<=len[i];j++)
		{
			char ch[j+1];
		//	c = ch;
			for(k=0;k<=len[i]-j;k++)
			{
				m = 0;
				for(l=k;l<k+j;l++)
				{
					ch[m] = str[i][l];
					m++;
				}
				ch[j] = '\0';
				reverse(ch,j);
			//	cout<<ch<<endl;
				c = strstr(str[i],ch);
				//cout<<c<<endl;
				if(c == NULL)
				{
					break;
				}
			}
			if(c == NULL)
			{
				break;
			}
		}
		if(j == len[i]+1)
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

void reverse(char *s,int len)
{
	int i;
	char ch;
	for(i=0;i<len/2;i++)
	{
		ch = *(s+i);
		*(s+i) = *(s+len-1-i);
		*(s+len-1-i) = ch;
	}
}

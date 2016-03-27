#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,max,min;
		cin>>n;
		int r[n],R[n];
		for(i=0;i<n;i++)
			cin>>r[i]>>R[i];
		max = 0;
		for(i=0;i<n;i++)
			if(r[i] > r[max])
				max = i;
		for(i=0;i<n;i++)
			if(i != max)
				if(R[i] >= r[max])
					break;
		if(i != n)
			cout<<-1<<endl;
		else
			cout<<max+1<<endl;
	}
	return 0;
}

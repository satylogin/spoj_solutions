#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;

	int i,j,tmp;
	int arr1[10000];
	for(i=0;i<10000;i++){
		arr1[i] = i+2;
	}
	for(i=0;i<10000;i++){
		tmp = arr1[i];
		if(tmp != 0){
			for(j=i+1;j<10000;j++){
				if(arr1[j]%tmp == 0)
					arr1[j] = 0;
			}
		}
	}
	j = 0;
	int arr2[2000];
	for(i=0;i<10000;i++){
		if(arr1[i] != 0){
			arr2[j] = arr1[i];
			j++;
		}
	}
	
	while (t--) {
		int n,count = 0, ans = 0;
		cin>>n;
		long long int x, y;
		for ( x = 30; x < 100000; x++) {
			for (y = 0; y < j; y++) {
				if (x % arr2[y] == 0)
					count++;
				if (count == 3)
					break;
			}
			if(count == 3)
				ans++;
			if (ans == n){
				cout<<x<<endl;
				break;
			}
			count = 0;
		}
		
	}

	return 0;
}

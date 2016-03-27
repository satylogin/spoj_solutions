#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

long long int gcd(long long int,long long int);
long long int lcm(long long int,long long int);

int main(){
	long long int x,y;
	cin>>x>>y;
	while((x!=0) && (y!=0)){
		long long int k = lcm(x,y);
		cout<<(k/x)*(k/y)<<endl;
		cin>>x>>y;
	}
	return 0;
}

long long int gcd(long long int x,long long int y){
	if(y%x == 0){
		return x;
	}
	else{
		return gcd(y%x,x);
	}
}

long long int lcm(long long int x,long long int y){
	return ((x*y)/gcd(x,y));
}

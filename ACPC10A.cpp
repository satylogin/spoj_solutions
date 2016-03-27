#include <iostream>

using namespace std;

int main()
{
	int num1,num2,num3;
	cin>>num1>>num2>>num3;
	
	while((num1 != 0) || (num2 != 0) || (num3 != 0)) {
		int d1,d2;
		d1 = num2 - num1;
		d2 = num3 - num2;
		if(d1 == d2) {
			cout<<"AP "<<(num3 + d1)<<endl;
		} else {
			cout<<"GP "<<(num3 * num3)/num2<<endl;
		}
		cin>>num1>>num2>>num3;
	}

	return 0;
}

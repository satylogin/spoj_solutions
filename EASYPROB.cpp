#include <stdio.h>

void convert(int n);
void print(int n);
void print1(int n);

int main()
{
	convert(137);
	printf("\n");
	convert(1315);
	printf("\n");
	convert(73);
	printf("\n");
	convert(136);
	printf("\n");
	convert(255);
	printf("\n");
	convert(1384);
	printf("\n");
	convert(16385);
	printf("\n");
		
	return 0;
}

void convert(int n)
{
	printf("%d=",n);
	int k = 2,count = 1;
	while(n/(k*2)>0){
		k = k*2;
		count++;
	}
	print(count);
	print1(n%k);
}

void print(int n)
{
	printf("2(");
	if(n == 0){

	}
	else if(n == 1){
		
	}
	else if(n == 2){
		printf("2");
	}
	else if(n == 3){
		printf("2+2(0)");
	}
	else{
		int k = 2,count = 1;
		while(n/(k*2)>0){
			k = k*2;
			count++;
		}
		print(count);
		print1(n%k);
	}
	printf(")");
}

void print1(int n)
{
	if(n != 0){	
		printf("+");
		if(n == 0){
			;
		}
		else if(n == 1){
			printf("2(0)");
		}
		else if(n == 2){
			printf("2");
		}
		else if(n == 3){
			printf("2+2(0)");
		}
		else{
			int k = 2,count = 1;
			while(n/(k*2)>0){
				k = k*2;
				count++;
			}
			print(count);
			print1(n%k);
		}
	}
}

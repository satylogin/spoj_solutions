#include <stdio.h>

int main()
{
	int i;
	while(1)
	{
		scanf("%d",&i);
		if(i!=42){
			printf("%d\n",i);
		}
		else{
			break;
		}
	}
	return 0;
}

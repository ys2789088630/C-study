#include<stdio.h>
int main()
{
	int x,t=0;
	scanf("%d",&x);
	do{
		int d=x%10;
		t=t*10+d;
		x/=10;
	}while(x>0);
	printf("t=%d\n",t);
	x=t;
	do{
	int d=x%10;
	printf("%d",d);
	if(x>9){
		printf(" ");
	}x/=10;
	}while(x>0);
	printf("\n");
	return 0;
}//逆序两次，不适用于个位为0
 

#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
//	x=13425;
//	13425/10000->1^
//	13425%10000->3425
//	10000/10	->1000
//	3425/1000	->3^
//	3425%1000	->425
//	1000/10	->100
//	425/100	->4^
//	425%100	->25
//	100/10	->10
//	25/10	->2^
//	25%10	->5
//	10/10	->1
//	5/1	->5^
//	5%1	->0
//	1/10 ->0
	int mask=1;
	int t=x;
	while(t>9){
		t/=10;
		mask*=10;
	}//确定mask的初始值，直接用x会使x的值更改，因此用t挡刀 
	printf("x=%d,mask=%d\n",x,mask);
	do{//do-while使个位数也执行循环 
		int d=x/mask;
		printf("%d",d);
		if(mask>9){
			printf(" ");
		}
		x%=mask;
		mask/=10;
	} while(mask>0);
	printf("\n");
	return 0;
}

#include<stdio.h>
int main()
{
	int a,b;
	int t;
	scanf("%d %d",&a,&b);
	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}
	printf("gcd=%d\n",a);
	return 0;
}//欧几里得算法/辗转相除法求最大公因数 

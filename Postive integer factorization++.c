#include<stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int digit[10]={0};
	int cnt=0;
	do{
		int d=n%10;
		if(!digit[d]){
			digit[d]=1;
			cnt++;
		}
		n/=10;
	}while(n>0);
	for(i=9;i>=0;i--){
		if(digit[i]==1){
			printf("%d\n",digit[i]);
		}
	}
	return 0;
}

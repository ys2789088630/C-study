#include<stdio.h>
int main()
{
	int m,n,i,k;
	int cnt=0,sum=0;
	scanf("%d %d",&m,&n);
	for(i=m;i<=n;i++){
		int isPrime=1;
		for(k=2;k<i;k++){
			if(i%k==0){
				isPrime=0;
				break;
			}
		}
		if(isPrime==1&&i!=1){
			cnt++;
			sum+=i;
		}
	}
	printf("%d %d\n",cnt,sum);
	return 0;
}

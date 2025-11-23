#include<stdio.h>//连续的四个数组成无重复数字的三位数，一行6个 
int main()
{
	int a;
	scanf("%d",&a);
	int i,j,k;
	int cnt=0;
	i=a;
	for(i=a;i<=a+3;i++){
		for(j=a;j<=a+3;j++){
			for(k=a;k<=a+3;k++){
				if(i!=j&&i!=k&&j!=k){
				
							cnt++;
							cnt%=6;
							printf("%d%d%d ",i,j,k);
							if(cnt==0){
								printf("\n");
					}
				}
			}
		}
	}
}

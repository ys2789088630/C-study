#include<stdio.h>
int main()
{
	int n=9;
	int i=1,j=1;
	while(i<=n){
		j=1;
		while(j<=i){
			printf("%d*%d=%-4d",j,i,i*j);//ÏÈÖ´ÐÐÍâ²ã,i>=j 
			j++;
		}
		printf("\n");
		i++;
	}	
	return 0;
}

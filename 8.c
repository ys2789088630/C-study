#include <stdio.h>
void DY( int x){
	
	int i= 0,j = 0;
	for (i = 0; i< x; i++){
		
		for (j = 0; j < x - i-1;j++){
			
			printf(" ");
		}
		for ( j= 0; j < 2*i +1 ; j++ ){
			
			printf("*");
		}
		printf("\n");
	}

	for ( i = x - 1; i > 0; i --){
		for ( j = 0; j < x - i ; j++){
			printf(" ");
		}
		for ( j = 0;j < 2*i -1;j++){
			printf("*");
		}
		printf("\n");
	}

}
int main(){
	
	int x;
	scanf("%d",&x);
	DY(x);
	return 0;
}
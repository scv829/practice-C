#include <stdio.h>

int main(void){
	int A = 1000, B = 70, C = 170, i, count;
	
//	scanf("%d %d %d",&A, &B, &C);
	
	if( B < C ){
		for(i = 1 ;i <=A && i <=C; i++){
			if(A % i == 0 && C % i == 0) count = i;
		}
		count = (A * C) / count;
		count++;
	}
	else count = -1;
	
	printf("%d",count);
	
}

#include <stdio.h>

int main(void){
	int T, N, M, i, result;
	scanf("%d",&T);
	
	for( i = 0 ; i < T ; i++){
		scanf("%d %d",&N, &M);
		if(N > M-N) N = M - N;
		result = 1;
		while(N > 0 && N != M ){
				result *= (M1)/N;
				printf("%llf ",result);
				N = N - 1;
		}
		printf("%.llf\n",result);
	}
}

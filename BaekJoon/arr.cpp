#include <stdio.h>

int main(){
	int C, N, score, i, j, count = 0;
	float ave = 0;
	scanf("%d",&C);
	float result[C];
	
	for(i = 0; i < C; i++, ave = 0, count = 0){
		scanf("%d", &N);
		int stu[N];
		for(j = 0; j < N; j++){
			scanf("%d",&stu[j]);
			ave += stu[j]; 
		}
		ave /= (float)N;
		for(j = 0; j < N; j++) if( ave < (float)stu[j]) count++;
		result[i] = ( count / (float)N )* 100;
		
	}
	for(i = 0; i < C ; i++){
		printf("%2.3f%%\n", result[i]);
	}
	
}


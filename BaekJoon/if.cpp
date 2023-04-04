#include <stdio.h>

int main(){
	int a,oriA,cycle = 0;
	scanf("%d",&oriA);
	a = oriA;
	while(1){
		a =  (a%10) * 10 + (a/10 + a%10)%10 ;
		cycle++;
		if( oriA == a) break;
	}
	printf("%d",cycle);
}

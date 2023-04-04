#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100

// 선택정령 함수
int selectSort(int x[]){

	int i, j , temp, min, searchCount = 0;

	for(i = 0 ; i < MAX - 1 ; i++){
		min = i;
		for(j = i + 1; j < MAX; j++){
			if(x[j] < x[min]){
				temp = x[j]; x[j] = x[min]; x[min] = temp;
			}
			searchCount++;
		}
	}

	return searchCount;
}

// 교환정렬 함수
int bubbleSort(int x[]){
	int  i, j, temp, searchCount = 0, check = 0;

	for(i = 0; i < MAX - 1; i++){
		check = 0;
		for(j =i + 1; j < MAX; j++){
			if(x[j] < x[i]){
				check = 1;
				temp = x[j]; x[j] = x[i]; x[i] = temp;
			}
			searchCount++;
		}
		if(check == 0) break;
	}
	return searchCount;
}

// 삽입정렬 함수
int insertSort(int x[]){

	int i,j,value, searchCount = 0;

	for(i = 1; i < MAX; i++){
		value = x[i]; j = i;
		while( (j > 0 ) && ( x[j-1] > value) ){
			x[j] = x[j - 1]; j--;
			searchCount++;
		}
		x[j] = value;
	}

	return searchCount;
}

// 배열 출력함수
void printArray(int x[]){

	int i;

	for(i = 0; i < MAX ; i++){
		if( i % 10 == 0 ) printf("\n");
		printf(" %3d", x[i]);

	}
}

// 메인함수
int main(int argc, char *argv[]) {

	int count, i;
	int root[MAX], son1[MAX], son2[MAX], son3[MAX];

	srand(time(NULL));

	for(i = 0; i < MAX ; i++){
		root[i] = rand()%1000;
	}

    // 부모배열을 자식 배열들에게 복사해 준다
	memcpy(son1, root, sizeof(int)*MAX);
	memcpy(son2, root, sizeof(int)*MAX);
	memcpy(son3, root, sizeof(int)*MAX);


	printf("\nroot 배열(정렬 전 배열)\n");
	printArray(root);

	printf("\n\n선택정렬 비교연산 수행횟수 = %2d", selectSort(son1) );
	printf("\n선택정렬 배열\n"); printArray(son1);

	printf("\n\n교환정렬 비교연산 수행횟수 = %2d", bubbleSort(son2) );
	printf("\n교환정렬 배열\n"); printArray(son2);

	printf("\n\n삽입정렬 비교연산 수행횟수 = %2d", insertSort(son3) );
	printf("\n삽입정렬 배열\n"); printArray(son3);

	return 0;
}

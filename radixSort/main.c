#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node{
    int data;
    struct node *link;

};

void radixLSBsort(int x[], int n){
    int i,j,k, digit;
    node *list = NULL, *c, *t = NULL, *front[10],*rear[10];


    // 배열->연결리스트
    for(i = 0 ; i < n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = x[i]; t->link = list;
        list = t;
    }
    // 기수 정렬
    for(i = 0; i < 4 ; i++){
        for(j = 0; j < 10; j++) front[j] = rear[j] = NULL;
              printf("a");
        // 각 자리의 배열에 연결
        for(c = list ; c != NULL; c = c->link){
            digit = c->data;
            for(j = 0; j < i; j++) { digit /=10; }
            digit %= 10;

            if(front[digit] == NULL){
                front[digit] = list;
            }
            else{
                front[digit]->link = c;
                rear[digit]->link = c;
                c = c->link;
            }
            printf("b");
        }

        //초기화 및 새로 생성
        for(k = 0; k < 9; k++){
                      printf("c");
            for( t = front[k] ; t != rear[k] ; t = t->link){
                printf("%d %d", t->data, rear[k]->data);
                list = t;
                t->link = list;
            }
        }
        // 확인
        printf("\n%d 번째 정렬\n", i+1);
        for( c = list; c != NULL; c = c->link ){
                  printf("e");
            printf("%4d ", c->data);
        }

    }
    // 연결리스트 -> 배열
    for( c = list, i = 0; c != NULL; c = c->link, i++){
        x[i] = c->data;
    }
    free(t);
}



int main()
{
    int i, j, num, size;
    srand(time(NULL));

    printf("입력받을 배열의 크기를 적어주세요: "); scanf("%d", &size);

    int arr[size];

    printf("\n기수 정렬 전 크기 %d 인 배열\n",size);
    for(i = 0; i < size; i++){
        if(i % 10 == 0) printf("\n");
        arr[i] = (rand()%9000) + 1000;
        printf("%4d ",arr[i]);
    }

    radixLSBsort(arr,size);


    return 0;
}

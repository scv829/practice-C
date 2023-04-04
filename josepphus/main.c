#include <stdio.h>
#include <stdlib.h>


typedef struct node{

    struct node *f_link;
    int data;
    struct node *l_link;

}node;

int algorithmJosephus(int n, int m, int start, FILE *f1){
    node *list, *current, *temp, *s, *back, *next;
    list = current = temp = s = back = next = NULL;
    int i, direction = 0, count = n; //direction = 0 : 시계방향 / = 1 : 반시계방향

    // 원형연결리스트 생성
    for(i = 1; i <= n ; i++){
        temp = (node*)malloc(sizeof(node));
        temp->data = i; temp->f_link = temp->l_link = NULL;
        //시작 지점 기억
        if(i == start) s = temp;
        // 노드들 추가
        if(list == NULL) list = current = temp;
        else if(i == n){ // 마지막 노드와 첫 번째 노드 연결
            temp->f_link = current;
            current->l_link = temp;

            temp->l_link = list;
            list->f_link = temp;
        }
        else{
            temp->f_link = current;
            current->l_link = temp;
            current = current->l_link;
        }
    }

    //제거
    current = s;
    printf("%d 시작\n",current->data);
    while(count > 1){
        if(direction == 0){
            for(i = 1 ; i < m; i++)current = current->l_link;
            temp = (node*)malloc(sizeof(node)); temp = NULL;
            temp = current;
            printf("\n%d제거",temp->data); fprintf(f1, "\n%d제거",temp->data);

            next = current->l_link; back = current->f_link;

            next->f_link = back;
            back->l_link = next;

            current = current->f_link;
            free(temp);
            direction = 1; count--;
        }
        else{
            for(i = 1 ; i < m; i++)current = current->f_link;

            temp = (node*)malloc(sizeof(node)); temp = NULL;
            temp = current;
            printf("\n%d제거",temp->data); fprintf(f1, "\n%d제거",temp->data);

            next = current->l_link; back = current->f_link;

            next->f_link = back;
            back->l_link = next;


            current = current->l_link;
            free(temp);
            direction = 0;
            count--;
        }
    }

    return current->data;

}

int main()
{
    int n, m ,start, winner;
    FILE *f1;

    printf("n , m , start 값을 입력 하세요: ");
    scanf("%d %d %d",&n, &m, &start);

    f1 = fopen("201968038 result.io","w");
    fprintf(f1, "\n=======================================\n");
    fprintf(f1, "입력 받은 숫자\n");
    fprintf(f1, "n = %d, m = %d, start = %d \n",n, m , start);

    winner = algorithmJosephus(n , m, start, f1);

    printf("\n승자는 : %d 입니다.", winner);
    fprintf(f1, "\n결과\n");
    fprintf(f1, "\n승자는 : %d 입니다.", winner);

    fclose(f1);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6

//함수 : 주사위 굴릴 횟수 입력받기
int intro(){
    int i;
    printf("주사위를 던질 횟수를 적으시오 : ");
    scanf("%d",&i);

    while(i <= 0){
        if(i <= 0)
        printf("\n오류입니다.\n\n주사위를 던질 횟수를 적으시오 : ");
        scanf("%d",&i);
    }
    return i;
}
//함수 : 주사위 굴리기
void Roll_dice(int x, int arr[]){
    srand( (unsigned)time(NULL) );
    int i = 0,random_d;

    while(x>0){
        arr[i] = random_d = (rand() % MAX)+ 1;

        i++, x--;
    }
    printf("\n");
}
//함수 : 주사위 굴려 나온 눈의 수 적기
void counter(int y, int arr[], int count[]){
    int i;
    for(i = 0 ; i < y ; i++){
        if(arr[i] == 1) count[0] += 1;
        else if(arr[i] == 2) count[1] += 1;
        else if(arr[i] == 3) count[2] += 1;
        else if(arr[i] == 4) count[3] += 1;
        else if(arr[i] == 5) count[4] += 1;
        else if(arr[i] == 6) count[5] += 1;
    }
}
//함수 : 나온 횟수가 많은 순으로 정리하기
void line_up(int n ,int line[],int place[]){

    int i,j,c = 1;
    int temp;

    for(i = MAX-1 ; i > 0; i--){
        for(j = 0; j < i; j++){
            if(line[j] < line[j+1]){
                temp = line[j]; line[j] = line[j+1]; line[j+1] = temp;
                temp = place[j]; place[j] = place[j+1]; place[j+1] = temp;
            }
        }
    }

}
//함수 : 나온 횟수가 많은 눈 출력하기
void Print(int Number[], int line[],int rank[]){
    int i = 0,ranking = 1;



    while(line[i] != 0 && i < 6){
        if(line[i-1] == line[i]){
            rank[i] = rank[i-1];
            ranking++;
        }
        else{
            rank[i] = ranking++;
        }
        i++;
    }
    printf("\n%d",Number[0]);
    for(i = 1; i < 6; i++){
        if(line[0] == line[i]){
            printf(", %d",Number[i]);
        }
    }
    printf("눈의 주사위가 %d의 횟수로 가장 많이 나왔습니다.\n\n",line[0]);

    for(i = 0; i < 6; i++)
        printf("%d이 나온 횟수 : %d\n%d의 등수 : %d등\n\n", Number[i], line[i], Number[i], rank[i]);

}

int main()
{
    srand( (unsigned)time(NULL) );
    int number;

    //주사위 굴릴 횟수 입력받기
    number = intro();

    int dice[number], count_dice[MAX] = {0,0,0,0,0,0}, count_arr[MAX] = {1,2,3,4,5,6}, rank_arr[MAX];

    //주사위 굴리기
    Roll_dice(number, dice);

    //나온 눈의 수 적기
    counter(number, dice, count_dice);

    //나온 횟수가 많은 순으로 정리하기
    line_up(number, count_dice, count_arr);

    //나온 횟수가 많은 눈 출력하기
    Print(count_arr, count_dice, rank_arr);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int question1(void);
int question2(void);
int question3(void);
int food(void);

struct food_arr{
    char fname[1024];
};

typedef struct food_arr FOOD;



int main(void)
{
    food();
    return 0;
}
int question1(void){
    int i;
    printf("\n먹고 싶은 장소\n");
    printf("\n① 신정문 ② 구정문 ③ 학교 ④ 로비로\n");
    scanf("%d",&i);
    fflush(stdin);
    if( 1<= i && i <= 3) return i;
    else if( i == 4) return main();
    else{
        printf("\n입력 오류.\n다시 선택하세요.\n");
        question1();
    }
}

int question2(void){
    int i;
    printf("\n먹고 싶은 식\n");
    printf("① 분식,일식 ② 중식 ③ 한식 ④ 양식\n");
    scanf("%d",&i);
    fflush(stdin);
    if( 1<= i && i <= 4) return i;
    else{
        printf("\n입력 오류.\n다시 선택하세요.\n");
        question2();
    }

}

int question3(void){
    int i;
    printf("\n생각하는 가격대\n");
    printf("① 0원~5,000원 ② 5,000원~8,000원 ③ 8,000원 ~ \n");
    scanf("%d",&i);
    fflush(stdin);
    if( 1<= i && i <= 3) return i;
    else{
        printf("\n입력 오류.\n다시 선택하세요.\n");
        question3();
    }
}

int food(void){

    printf("\n===맞춤 음식점 찾기 ==\n");
    int i[3], j, k, a,number = 0;
    FILE *f;
    i[0] = question1();
    i[1] = question2();
    i[2] = question3();
    j = i[0] * 100 + i[1] * 10 + i[2];
    FOOD fod[80];
    if(100 < j && j < 200){
        f = fopen("신정문.txt","rt");
        for(k = 0; k < 20; k++)
            fscanf(f,"%s",fod[k].fname);
        for(k = 0; k < 17; k++){
            a = (fod[k].fname[0]-48) * 100 + (fod[k].fname[1]-48) * 10 + (fod[k].fname[2]-48);
            if( a == j ){
                printf("\n음식점 이름 : %s\n대표 음식 : %s\n가격 : %s\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
                number++;
            }
        }
        if(number == 0){
            printf("\n맞는 음식점이 없습니다.\n");
        }
    }
    else if(200 < j && j < 300){
        f = fopen("구정문.txt","rt");
        for(k = 0; k < 64; k++)
            fscanf(f,"%s",fod[k].fname);
        for(k = 0; k < 61; k++){
            a = (fod[k].fname[0]-48) * 100 + (fod[k].fname[1]-48) * 10 + (fod[k].fname[2]-48);
            if( a == j ){
                printf("\n음식점 이름 : %s\n대표 음식 : %s\n가격 : %s\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
                number++;
            }
        }
        if(number == 0){
            printf("\n맞는 음식점이 없습니다.\n");
        }
    }
    else{
        f = fopen("학교.txt","rt");
        for(k = 0; k < 20; k++)
            fscanf(f,"%s",fod[k].fname);
        for(k = 0; k < 17; k++){
            a = (fod[k].fname[0]-48) * 100 + (fod[k].fname[1]-48) * 10 + (fod[k].fname[2]-48);
            if( a == j ){
                printf("\n음식점 이름 : %s\n대표 음식 : %s\n가격 : %s\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
                number++;
            }
        }
        if(number == 0){
            printf("\n맞는 음식점이 없습니다.\n");
        }
    }
    printf("\n①더 찾는다.  ②로비로 간다.\n");
    scanf("%d",&j);
    fflush(stdin);
    while(1){
        if( 1<= j && j <= 2){
                if(j == 1) food();
                else{
                    system("cls");
                    return main();
                }
        }
        else{
            printf("\n입력 오류.\n다시 선택하세요.\n");
            printf("\n①더 찾는다.  ②로비로 간다.\n");
            scanf("%d",&j);
            fflush(stdin);
        }
    }
}

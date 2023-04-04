#include <stdio.h>
#include <stdlib.h>

int intro(void){
    int i;
    printf("-------------------------------\n");
    printf("1. 사전예약 참여\n");
    printf("2. 사전예약 취소\n");
    printf("3. 사전예약 확인\n");
    printf("4. 종료\n");
    printf("-------------------------------\n");
    scanf("%d",&i);
    return i;
}

struct User {
    char name[10];
    char Phone_number[13];
};

typedef struct User User;

int main()
{
    FILE *Par, *A_number;
    User infor;
    int R_number = rand()%((999999-100000)+1)+100000;
    int i = intro(),num;
    Par = fopen("사전예약 리스트.txt","a");
    A_number = fopen("인증번호.txt","a");

    printf("이름을 적으시오 : ");
    scanf("%s",infor.name);

    printf("\n전화번호를 입력하시오 : ");
    scanf("%s",infor.Phone_number);

    fputs(R_number ,A_number);
    printf("\n인증번호를 입력하시오 : ");
    scanf("%d",&num);
    while(num != fgetc(A_number)){
        scanf("%d",&num);
        if(num == fgetc(A_number)){
            fputs(infor.name ,Par);
            fputs(infor.Phone_number,Par);
            fclose(Par);
            printf("\n사전예약 완료\n");
        }
    }

    printf("%d",num);

    return 0;
}

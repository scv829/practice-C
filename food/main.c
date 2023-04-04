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
    printf("\n�԰� ���� ���\n");
    printf("\n�� ������ �� ������ �� �б� �� �κ��\n");
    scanf("%d",&i);
    fflush(stdin);
    if( 1<= i && i <= 3) return i;
    else if( i == 4) return main();
    else{
        printf("\n�Է� ����.\n�ٽ� �����ϼ���.\n");
        question1();
    }
}

int question2(void){
    int i;
    printf("\n�԰� ���� ��\n");
    printf("�� �н�,�Ͻ� �� �߽� �� �ѽ� �� ���\n");
    scanf("%d",&i);
    fflush(stdin);
    if( 1<= i && i <= 4) return i;
    else{
        printf("\n�Է� ����.\n�ٽ� �����ϼ���.\n");
        question2();
    }

}

int question3(void){
    int i;
    printf("\n�����ϴ� ���ݴ�\n");
    printf("�� 0��~5,000�� �� 5,000��~8,000�� �� 8,000�� ~ \n");
    scanf("%d",&i);
    fflush(stdin);
    if( 1<= i && i <= 3) return i;
    else{
        printf("\n�Է� ����.\n�ٽ� �����ϼ���.\n");
        question3();
    }
}

int food(void){

    printf("\n===���� ������ ã�� ==\n");
    int i[3], j, k, a,number = 0;
    FILE *f;
    i[0] = question1();
    i[1] = question2();
    i[2] = question3();
    j = i[0] * 100 + i[1] * 10 + i[2];
    FOOD fod[80];
    if(100 < j && j < 200){
        f = fopen("������.txt","rt");
        for(k = 0; k < 20; k++)
            fscanf(f,"%s",fod[k].fname);
        for(k = 0; k < 17; k++){
            a = (fod[k].fname[0]-48) * 100 + (fod[k].fname[1]-48) * 10 + (fod[k].fname[2]-48);
            if( a == j ){
                printf("\n������ �̸� : %s\n��ǥ ���� : %s\n���� : %s\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
                number++;
            }
        }
        if(number == 0){
            printf("\n�´� �������� �����ϴ�.\n");
        }
    }
    else if(200 < j && j < 300){
        f = fopen("������.txt","rt");
        for(k = 0; k < 64; k++)
            fscanf(f,"%s",fod[k].fname);
        for(k = 0; k < 61; k++){
            a = (fod[k].fname[0]-48) * 100 + (fod[k].fname[1]-48) * 10 + (fod[k].fname[2]-48);
            if( a == j ){
                printf("\n������ �̸� : %s\n��ǥ ���� : %s\n���� : %s\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
                number++;
            }
        }
        if(number == 0){
            printf("\n�´� �������� �����ϴ�.\n");
        }
    }
    else{
        f = fopen("�б�.txt","rt");
        for(k = 0; k < 20; k++)
            fscanf(f,"%s",fod[k].fname);
        for(k = 0; k < 17; k++){
            a = (fod[k].fname[0]-48) * 100 + (fod[k].fname[1]-48) * 10 + (fod[k].fname[2]-48);
            if( a == j ){
                printf("\n������ �̸� : %s\n��ǥ ���� : %s\n���� : %s\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
                number++;
            }
        }
        if(number == 0){
            printf("\n�´� �������� �����ϴ�.\n");
        }
    }
    printf("\n��� ã�´�.  ��κ�� ����.\n");
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
            printf("\n�Է� ����.\n�ٽ� �����ϼ���.\n");
            printf("\n��� ã�´�.  ��κ�� ����.\n");
            scanf("%d",&j);
            fflush(stdin);
        }
    }
}

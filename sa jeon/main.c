#include <stdio.h>
#include <stdlib.h>

int intro(void){
    int i;
    printf("-------------------------------\n");
    printf("1. �������� ����\n");
    printf("2. �������� ���\n");
    printf("3. �������� Ȯ��\n");
    printf("4. ����\n");
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
    Par = fopen("�������� ����Ʈ.txt","a");
    A_number = fopen("������ȣ.txt","a");

    printf("�̸��� �����ÿ� : ");
    scanf("%s",infor.name);

    printf("\n��ȭ��ȣ�� �Է��Ͻÿ� : ");
    scanf("%s",infor.Phone_number);

    fputs(R_number ,A_number);
    printf("\n������ȣ�� �Է��Ͻÿ� : ");
    scanf("%d",&num);
    while(num != fgetc(A_number)){
        scanf("%d",&num);
        if(num == fgetc(A_number)){
            fputs(infor.name ,Par);
            fputs(infor.Phone_number,Par);
            fclose(Par);
            printf("\n�������� �Ϸ�\n");
        }
    }

    printf("%d",num);

    return 0;
}

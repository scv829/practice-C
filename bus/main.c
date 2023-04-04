#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

struct bus
{
    int select;
    int pick;

};

struct bus_t{
    char bus_arr[6];
};

int choo(void);
typedef struct bus BUS;
typedef struct bus_t BUS_T;



void Print_b(int max,BUS_T bus_time[80]){
    int i;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int hour,min;

    printf("\n���� �ð�ǥ\n");
    for(i = 0 ; i < max; i++){
        hour =  (bus_time[i].bus_arr[0] - 48) * 10  +  bus_time[i].bus_arr[1] - 48;
        min = (bus_time[i].bus_arr[3] -48) * 10 +(bus_time[i].bus_arr[4] - 48);
        if(hour < tm.tm_hour || (hour == tm.tm_hour) && (min < tm.tm_min) ){
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE), 8);
        }
        else{
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE), 15);
        }
        printf("%s\n",bus_time[i].bus_arr);
    }
    choo();
}
void Gaek(int sel){
    int i,j;
    FILE *b;
    BUS_T t[70];
    if(sel == 1){
        printf("\n==���� �ð�ǥ(������)==\n");
        printf("1. 535��\n");
        printf("2. 354��\n");
        printf("3. 385��\n");
        printf("4. 119��\n");
        printf("5. 108��\n");
        printf("6. 355��\n");
        printf("7. 165��\n");
        printf("8. 6��\n");
        printf("9. 61��\n");
        printf("\n���� : ");

        scanf("%d",&i);
        fflush(stdin);

        switch(i){
            case 1 :
                b = fopen("535��.txt","r");
                for(j = 0; j < 39 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b(39, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("354��.txt","r");
                for(j = 0; j < 16 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 16, t);
                fclose(b);
                break;
            case 3 :
                b = fopen("385��.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
            break;
            case 4 :
                b = fopen("119��.txt","r");
                for(j = 0; j < 65 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 65, t);
                fclose(b);
                break;
            case 5 :
                b = fopen("108��.txt","r");
                for(j = 0; j < 27 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 27, t);
                fclose(b);
                break;
            case 6 :
                b = fopen("355��.txt","r");
                for(j = 0; j < 22 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 22, t);
                fclose(b);
                break;
            case 7 :
                b = fopen("165��.txt","r");
                for(j = 0; j < 62 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 62, t);
                fclose(b);
                break;
            case 8 :
                b = fopen("6��.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
                break;
            case 9 :
                b = fopen("61��.txt","r");
                for(j = 0; j < 59 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 59, t);
                fclose(b);
                break;
            default :
                printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
                Gaek(sel);            }
        }
    else{
        printf("\n==���� �ð�ǥ(������)==\n");
        printf("������ �����ϴ�.");
    }
}

void Cheon(int sel){

    int i,j;
    FILE *b;
    BUS_T t[70];
    if(sel == 1){
        printf("\n==���ϴ� �ð�ǥ(������)==\n");
        printf("1. 104��\n");
        printf("2. 119��\n");
        printf("3. 165��\n");
        printf("4. 354��\n");
        printf("5. 355��\n");
        printf("6. 385��\n");
        printf("\n���� : ");

        scanf("%d",&i);
        fflush(stdin);
        switch(i) {
            case 1 :
                b = fopen("104��.txt","r");
                for(j = 0; j < 50 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 50, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("354��.txt","r");
                for(j = 0; j < 16 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 16, t);
                fclose(b);
                break;
            case 3 :
                b = fopen("385��.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
            break;
            case 4 :
                b = fopen("119��.txt","r");
                for(j = 0; j < 65 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 65, t);
                fclose(b);
                break;
            case 5 :
                b = fopen("165��.txt","r");
                for(j = 0; j < 62 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 62, t);
                fclose(b);
                break;
            case 6 :
                b = fopen("355��.txt","r");
                for(j = 0; j < 22 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 22, t);
                fclose(b);
                break;
            default :
                printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
                Cheon(sel);
        }
    }
    else{
        printf("\n==���ϴ� �ð�ǥ(����)==\n");
        printf("1. 3-1��\n");
        printf("2. 74��\n");
        scanf("%d",&i);
        fflush(stdin);
        switch(i) {
            case 1 :
                b = fopen("3-1��.txt","r");
                for(j = 0; j < 63 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 63, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("74��.txt","r");
                for(j = 0; j < 30 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b(30, t);
                fclose(b);
                break;
            default :
                printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
                Cheon(sel);
        }
    }
}

void Lotte(int sel){

    int i,j;
    FILE *b;
    BUS_T t[70];
    if(sel == 1){
        printf("\n==�Ե��ó׸� �ð�ǥ(������)==\n");
        printf("1. 104��\n");
        printf("2. 119��\n");
        printf("3. 61��\n");
        scanf("%d",&i);
        fflush(stdin);
            switch(i){
                case 1 :
                b = fopen("104��.txt","r");
                for(j = 0; j < 50 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 50, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("119��.txt","r");
                for(j = 0; j < 65 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 65, t);
                fclose(b);
                break;
             case 3 :
                b = fopen("61��.txt","r");
                for(j = 0; j < 59 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 59, t);
                fclose(b);
                break;
            default :
                printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
                Lotte(sel);
            }
    }
    else{
        printf("\n==�Ե��ó׸� �ð�ǥ(������)==\n");
        printf("1. 3-1��\n");
        printf("2. 72��\n");
        printf("3. 74��\n");
        scanf("%d",&i);
        fflush(stdin);
        switch(i){
            case 1 :
                b = fopen("3-1��.txt","r");
                for(j = 0; j < 63 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 63, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("72��.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
                break;
             case 3 :
                b = fopen("74��.txt","r");
                for(j = 0; j < 30 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 30, t);
                fclose(b);
                break;
            default :
                printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
                Lotte(sel);
        }
    }
}
void Han(int sel){

    int i,j;
    FILE *b;
    BUS_T t[70];
    if(sel == 1){
        printf("\n==�Ե��ó׸� �ð�ǥ(������)==\n");
        printf("1. 121��\n");
        printf("2. 200��\n");
        printf("3. 220��\n");
        printf("4. 165��\n");
        printf("5. 385��\n");
        printf("6. 61��\n");
        scanf("%d",&i);
        fflush(stdin);
    switch(i) {
            case 1 :
                b = fopen("121��.txt","r");
                for(j = 0; j < 50 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 50, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("200��.txt","r");
                for(j = 0; j < 16 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 16, t);
                fclose(b);
                break;
            case 3 :
                b = fopen("220��.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
            break;
            case 4 :
                b = fopen("165��.txt","r");
                for(j = 0; j < 62 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 62, t);
                fclose(b);
                break;
           case 5 :
                b = fopen("385��.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
                break;
            case 6 :
                b = fopen("61��.txt","r");
                for(j = 0; j < 59 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 59, t);
                fclose(b);
                break;
            default :
                printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
                Han(sel);
        }
    }
    else{
        printf("\n==�Ե��ó׸� �ð�ǥ(������)==\n");
        printf("1. 3-1��\n");
        scanf("%d",&i);
        fflush(stdin);
        switch(i){
            case 1 :
                b = fopen("3-1��.txt","r");
                for(j = 0; j < 63 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 63, t);
                fclose(b);
                break;
             default :
                printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
                Han(sel);
        }
    }
}

void sel_b(void){
    BUS sel;

    printf("\n==���� ���θ޴�==\n");
    printf("1.���ִ��б� �� ����\n");

    printf("2.���ִ��б� �� ����\n");

    scanf("%d",&sel.select);
    fflush(stdin);

    if(sel.select == 1){
        printf("\n���� ������ ��ġ : ������\n");
    }
    else if(sel.select == 2){
        printf("\n���� ������ ��ġ : ������\n");
    }
    else{
        printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
        sel_b();
    }

    while(1){
        printf("\n==������ ���ø޴�==\n");

        printf("1. ����\n");
        printf("2. ���ϴ��б�\n");
        printf("3. �Ե��ó׸�\n");
        printf("4. �ѿ�����\n");
        scanf("%d", &sel.pick);
        fflush(stdin);

        if(sel.pick == 1){
            Gaek(sel.select);
            break;
        }
        else if(sel.pick == 2){
            Cheon(sel.select);
            break;
        }
        else if(sel.pick == 3){
            Lotte(sel.select);
            break;
        }
        else if(sel.pick == 4){
            Han(sel.select);
            break;
        }
        else{
            printf("\n�Է� ����.\n�ٽ� �Է��Ͻÿ�.\n");
        }
    }


}
int main()
{
    sel_b();

    return 0;

}

int choo(void){
    int i;
    printf("\n\n1. �� ã�´�.    2. �κ�� ����.\n");
    scanf("%d",&i);
    fflush(stdin);
    while(1){
        if(1 <= i && i <= 2){
            if(i == 1) sel_b();
            else return {
                    system("cls");
                    main();
            }
        }
        else {
            printf("\n�Է� ����. �ٽ� �Է��ϼ���.");
            choo();
        }

    }

}



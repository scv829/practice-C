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

    printf("\n버스 시간표\n");
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
        printf("\n==객사 시간표(신정문)==\n");
        printf("1. 535번\n");
        printf("2. 354번\n");
        printf("3. 385번\n");
        printf("4. 119번\n");
        printf("5. 108번\n");
        printf("6. 355번\n");
        printf("7. 165번\n");
        printf("8. 6번\n");
        printf("9. 61번\n");
        printf("\n선택 : ");

        scanf("%d",&i);
        fflush(stdin);

        switch(i){
            case 1 :
                b = fopen("535번.txt","r");
                for(j = 0; j < 39 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b(39, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("354번.txt","r");
                for(j = 0; j < 16 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 16, t);
                fclose(b);
                break;
            case 3 :
                b = fopen("385번.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
            break;
            case 4 :
                b = fopen("119번.txt","r");
                for(j = 0; j < 65 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 65, t);
                fclose(b);
                break;
            case 5 :
                b = fopen("108번.txt","r");
                for(j = 0; j < 27 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 27, t);
                fclose(b);
                break;
            case 6 :
                b = fopen("355번.txt","r");
                for(j = 0; j < 22 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 22, t);
                fclose(b);
                break;
            case 7 :
                b = fopen("165번.txt","r");
                for(j = 0; j < 62 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 62, t);
                fclose(b);
                break;
            case 8 :
                b = fopen("6번.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
                break;
            case 9 :
                b = fopen("61번.txt","r");
                for(j = 0; j < 59 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 59, t);
                fclose(b);
                break;
            default :
                printf("\n입력 오류.\n다시 입력하시오.\n");
                Gaek(sel);            }
        }
    else{
        printf("\n==객사 시간표(구정문)==\n");
        printf("버스가 없습니다.");
    }
}

void Cheon(int sel){

    int i,j;
    FILE *b;
    BUS_T t[70];
    if(sel == 1){
        printf("\n==전북대 시간표(신정문)==\n");
        printf("1. 104번\n");
        printf("2. 119번\n");
        printf("3. 165번\n");
        printf("4. 354번\n");
        printf("5. 355번\n");
        printf("6. 385번\n");
        printf("\n선택 : ");

        scanf("%d",&i);
        fflush(stdin);
        switch(i) {
            case 1 :
                b = fopen("104번.txt","r");
                for(j = 0; j < 50 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 50, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("354번.txt","r");
                for(j = 0; j < 16 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 16, t);
                fclose(b);
                break;
            case 3 :
                b = fopen("385번.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
            break;
            case 4 :
                b = fopen("119번.txt","r");
                for(j = 0; j < 65 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 65, t);
                fclose(b);
                break;
            case 5 :
                b = fopen("165번.txt","r");
                for(j = 0; j < 62 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 62, t);
                fclose(b);
                break;
            case 6 :
                b = fopen("355번.txt","r");
                for(j = 0; j < 22 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 22, t);
                fclose(b);
                break;
            default :
                printf("\n입력 오류.\n다시 입력하시오.\n");
                Cheon(sel);
        }
    }
    else{
        printf("\n==전북대 시간표(정문)==\n");
        printf("1. 3-1번\n");
        printf("2. 74번\n");
        scanf("%d",&i);
        fflush(stdin);
        switch(i) {
            case 1 :
                b = fopen("3-1번.txt","r");
                for(j = 0; j < 63 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 63, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("74번.txt","r");
                for(j = 0; j < 30 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b(30, t);
                fclose(b);
                break;
            default :
                printf("\n입력 오류.\n다시 입력하시오.\n");
                Cheon(sel);
        }
    }
}

void Lotte(int sel){

    int i,j;
    FILE *b;
    BUS_T t[70];
    if(sel == 1){
        printf("\n==롯데시네마 시간표(신정문)==\n");
        printf("1. 104번\n");
        printf("2. 119번\n");
        printf("3. 61번\n");
        scanf("%d",&i);
        fflush(stdin);
            switch(i){
                case 1 :
                b = fopen("104번.txt","r");
                for(j = 0; j < 50 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 50, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("119번.txt","r");
                for(j = 0; j < 65 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 65, t);
                fclose(b);
                break;
             case 3 :
                b = fopen("61번.txt","r");
                for(j = 0; j < 59 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 59, t);
                fclose(b);
                break;
            default :
                printf("\n입력 오류.\n다시 입력하시오.\n");
                Lotte(sel);
            }
    }
    else{
        printf("\n==롯데시네마 시간표(구정문)==\n");
        printf("1. 3-1번\n");
        printf("2. 72번\n");
        printf("3. 74번\n");
        scanf("%d",&i);
        fflush(stdin);
        switch(i){
            case 1 :
                b = fopen("3-1번.txt","r");
                for(j = 0; j < 63 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 63, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("72번.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
                break;
             case 3 :
                b = fopen("74번.txt","r");
                for(j = 0; j < 30 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 30, t);
                fclose(b);
                break;
            default :
                printf("\n입력 오류.\n다시 입력하시오.\n");
                Lotte(sel);
        }
    }
}
void Han(int sel){

    int i,j;
    FILE *b;
    BUS_T t[70];
    if(sel == 1){
        printf("\n==롯데시네마 시간표(신정문)==\n");
        printf("1. 121번\n");
        printf("2. 200번\n");
        printf("3. 220번\n");
        printf("4. 165번\n");
        printf("5. 385번\n");
        printf("6. 61번\n");
        scanf("%d",&i);
        fflush(stdin);
    switch(i) {
            case 1 :
                b = fopen("121번.txt","r");
                for(j = 0; j < 50 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 50, t);
                fclose(b);
                break;
            case 2 :
                b = fopen("200번.txt","r");
                for(j = 0; j < 16 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 16, t);
                fclose(b);
                break;
            case 3 :
                b = fopen("220번.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
            break;
            case 4 :
                b = fopen("165번.txt","r");
                for(j = 0; j < 62 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 62, t);
                fclose(b);
                break;
           case 5 :
                b = fopen("385번.txt","r");
                for(j = 0; j < 40 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 40, t);
                fclose(b);
                break;
            case 6 :
                b = fopen("61번.txt","r");
                for(j = 0; j < 59 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 59, t);
                fclose(b);
                break;
            default :
                printf("\n입력 오류.\n다시 입력하시오.\n");
                Han(sel);
        }
    }
    else{
        printf("\n==롯데시네마 시간표(신정문)==\n");
        printf("1. 3-1번\n");
        scanf("%d",&i);
        fflush(stdin);
        switch(i){
            case 1 :
                b = fopen("3-1번.txt","r");
                for(j = 0; j < 63 ; j++)
                    fscanf(b,"%s",t[j].bus_arr);
                Print_b( 63, t);
                fclose(b);
                break;
             default :
                printf("\n입력 오류.\n다시 입력하시오.\n");
                Han(sel);
        }
    }
}

void sel_b(void){
    BUS sel;

    printf("\n==버스 메인메뉴==\n");
    printf("1.전주대학교 신 정문\n");

    printf("2.전주대학교 구 정문\n");

    scanf("%d",&sel.select);
    fflush(stdin);

    if(sel.select == 1){
        printf("\n버스 정류장 위치 : 신정문\n");
    }
    else if(sel.select == 2){
        printf("\n버스 정류장 위치 : 구정문\n");
    }
    else{
        printf("\n입력 오류.\n다시 입력하시오.\n");
        sel_b();
    }

    while(1){
        printf("\n==도착지 선택메뉴==\n");

        printf("1. 객사\n");
        printf("2. 전북대학교\n");
        printf("3. 롯데시네마\n");
        printf("4. 한옥마을\n");
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
            printf("\n입력 오류.\n다시 입력하시오.\n");
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
    printf("\n\n1. 더 찾는다.    2. 로비로 간다.\n");
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
            printf("\n입력 오류. 다시 입력하세요.");
            choo();
        }

    }

}



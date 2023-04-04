#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define After -1
#define Before -2
#define END -3
#define MAX 1024

typedef struct schedule_s{

    int year_s;
    int month_s;
    int day_s;
    char Name[MAX];
    char place[MAX];
    char time[MAX];

}Sch;

struct food_arr{
    char fname[MAX];
};

typedef struct food_arr FOOD;

struct bus
{
    int select;
    int pick;

};

struct bus_t{
    char bus_arr[6];
};

struct Info{
    int isIncome;           // 1=수입, 0=지출
    char contents[20];      // 내용
    int money;              // 금액
};

struct Info book[1000];
int bookIdx = 0;

typedef struct bus BUS;
typedef struct bus_t BUS_T;

void calendar(int year, int month, int con, int sche_point);
int count_leap(int year);
int leap(int year);
void cur(int x, int y);
void print_cal(int year, int month, int total_day, int days, int calendar_arr[6][7], int sche_point);
int sel_calen(int con, int today, int calendar[6][7]);
void check(int year, int month, int day, int sche_point);
int ch_cal(void);
int check_sche_point(void);

int question1(void);
int question2(void);
int question3(void);
int food(void);

int choo(void);
int sel_b(void);
void Han(int sel);
void Lotte(int sel);
void Cheon(int sel);
void Gaek(int sel);
void Print_b(int max, BUS_T bus_time[80]);

void showBalance(void);
void showExList(void);
void showInList(void);
void registEx(void);
void registIn(void);
void showMainMenu(void);
int household(void);

int main()
{
    int i;
    cur(15,5);
    printf("======메뉴======\n");
    printf("\t\t1. 캘린더\n\t\t2. 음식점 추천\n\t\t3. 버스 시간표\n\t\t4. 가계부\n\t\t5. 종료");
    cur(17,11);
    printf("선택 : ");
    scanf("%d",&i);
    while( 1 ){
        if(1 <= i && i <= 5) break;
        else{
            system("cls");

            cur(15,3);
            printf("입력 오류.\n 다시 입력하시오.\n\n");
            cur(15,5);
            printf("======메뉴======\n");
            printf("\t\t1. 캘린더\n\t\t2. 음식점 추천\n\t\t3. 버스 시간표\n\t\t4. 가계부\n\t\t5. 종료");
            cur(17,11);
            printf("선택 : ");
            scanf("%d",&i);
        }
    }
    switch(i){
        case 1 :
            ch_cal();
            break;

        case 2 :
            food();
            break;

        case 3 :
            sel_b();
            break;

        case 4 :
            household();
            break;
        case 5 :
            system("cls");
            printf("종료하였습니다");
            exit(0);
    }
    return 0;
}
//한재성 코드
int ch_cal(void){

    int j;
    cur(16,12);
    printf("==== 캘린더 ====\n");
    printf("\t\t하시겠습니까?\n");
    printf("\t\t① yes ② no \n");
    cur(16,15);
    printf("선택 : ");
    scanf("%d",&j);
    while( 1 ){
        if(1 <= j && j <= 2) {
            if( j == 1){
                system("cls");
                break;
            }
            else{
                system("cls");
                return main();
            }
        }
        else{
            system("cls");
            printf("입력 오류.\n 다시 입력하시오.\n\n");
            printf("\n=== 캘린더 ===\n");
            printf("    하시겠습니까?\n");
            printf("    ① yes ② no \n");
            scanf("%d",&j);
        }
    }

    time_t TIME = time(NULL);
    struct tm tm = *localtime(&TIME);

    int sche_point = check_sche_point();

    int year = tm.tm_year + 1900 , month = tm.tm_mon + 1, condition = 0;

    calendar(year, month, condition, sche_point);
}

int check_sche_point(void){

    int sche = 0, i = 0, j = 5;
    char buffer[MAX];
    FILE *date_file;

    date_file = fopen("일정 수.txt","rt");

    if(date_file == NULL){
        fclose(date_file);
        return 0;
    }
    else{
        fscanf(date_file,"%d",&sche);
    }
    fclose(date_file);

    return sche;
}

void sche1(int year, int month, int day, int sche_point){

    system("cls");

    int i;
    Sch s1;
    FILE *schedule, *date_file;
    schedule = fopen("일정.txt","a+");
    date_file = fopen("일정 수.txt","w");


    fprintf(schedule,"%4d %2d %2d\n",year, month, day);

    printf("약속 이름 : ");
    gets(s1.Name);
    fflush(stdin);
    fprintf(schedule,"%s\n", s1.Name);

    printf("약속 장소 : ");
    gets(s1.place);
    fflush(stdin);
    fprintf(schedule,"%s\n", s1.place);

    printf("약속 시간 : ");
    gets(s1.time);
    fflush(stdin);
    fprintf(schedule,"%s\n", s1.time);

    printf("\n일정을 더 추가하시겠습니까?\n");
    printf("① 예 ② 아니오\n");

    scanf("%d",&i);
    fflush(stdin);

    if(i == 1){
        fclose(schedule);
        sche_point++;
        sche1(year, month, day, sche_point);
    }
    else if(i == 2){
        fclose(schedule);
    }
    else{
        printf("오류 발생\n 지금 일정을 저장하고 2초 후 달력으로 돌아갑니다.\n");
        fclose(schedule);
        fclose(date_file);
        Sleep(2000);
        calendar(year, month, day, sche_point);

    }
    sche_point++;


    fprintf(date_file,"%d", sche_point);
    fclose(date_file);

    getch();
    fflush(stdin);

    system("cls");
    check(year, month, day, sche_point);
}

void sche2(int year, int month, int day, int sche_point){

    system("cls");

    int i, j = 0, k = 0 ;
    Sch s2[sche_point];

    FILE *schedule;
    schedule = fopen("일정.txt","r");

    printf("\n선택 요일 : %4d년 %2d월 %2d일\n",year ,month ,day);

    if(sche_point == 0){
        printf("\n일정이 없습니다.\n");
    }
    else{
        for( i = 0, j = 0; i < sche_point; i++){
                fscanf(schedule,"%d %d %d",&s2[i].year_s, &s2[i].month_s, &s2[i].day_s);                fscanf(schedule,"%s",s2[i].Name);
                fscanf(schedule,"%s",s2[i].place);
                fscanf(schedule,"%s",s2[i].time);
                if(s2[i].year_s == year && s2[i].month_s == month && s2[i].day_s == day){
                    printf("\n------%d번째 일정------\n\n",j+1);
                    printf("약속 제목 : %s\n",s2[i].Name);
                    printf("약속 장소 : %s\n",s2[i].place);
                    printf("약속 시간 : %s\n",s2[i].time);
                    j++;
                }
            }
            if(j == 0) printf("\n일정이 없습니다.\n");
            else printf("\n=======================\n");
    }
    fclose(schedule);
    getch();
    system("cls");
    check( year, month, day, sche_point);
}
void sche3(int year, int month, int day, int sche_point){

    system("cls");

    int i, j = 0, k = 0, sch;
    Sch s3[sche_point];
    int del[sche_point];

    FILE *schedule, *date_file;
    schedule = fopen("일정.txt","r");

    printf("\n선택 요일 : %4d년 %2d월 %2d일\n",year ,month ,day);


    if(sche_point == 0){
        printf("\n일정이 없습니다.\n");
    }
    else{
        for( i = 0, j = 0, k = 0; i < sche_point; i++){
                fscanf(schedule,"%d %d %d",&s3[i].year_s, &s3[i].month_s, &s3[i].day_s);
                fscanf(schedule,"%s",s3[i].Name);
                fscanf(schedule,"%s",s3[i].place);
                fscanf(schedule,"%s",s3[i].time);
                del[i] = i;
                if(s3[i].year_s == year && s3[i].month_s == month && s3[i].day_s == day){
                    printf("\n------%d번째 일정------\n\n",j + 1);
                    printf("약속 제목 : %s\n",s3[i].Name);
                    printf("약속 장소 : %s\n",s3[i].place);
                    printf("약속 시간 : %s\n",s3[i].time);
                    del[i] = j + 1;
                    j++;
                }
            }
            if(j == 0) printf("\n일정이 없습니다.\n");
            else {printf("\n=======================\n");
            k = 1;
            }
    }
    fclose(schedule);
    if(k == 0){
    getch();
    system("cls");
    check( year, month, day, sche_point);
    }
    else{
        printf("삭제할 일정을 입력하시오 : ");
        scanf("%d",&sch);
        fflush(stdin);
        for(i = 0; i < sche_point; i++){
            if(del[i] == sch){
            break;
            }
        }
        for(; i < sche_point; i++){
            s3[i] = s3[i+1];
        }
        sche_point--;

        schedule = fopen("일정.txt","w+");
        date_file = fopen("일정 수.txt","w+");

        for(i = 0; i < sche_point; i++){
            fprintf(schedule,"%d %d %d\n",s3[i].year_s, s3[i].month_s, s3[i].day_s);
            fprintf(schedule,"%s\n",s3[i].Name);
            fprintf(schedule,"%s\n",s3[i].place);
            fprintf(schedule,"%s\n",s3[i].time);
        }
        fprintf(date_file,"%d",sche_point);

        fclose(schedule); fclose(date_file);
        getch();
        system("cls");
        check(year, month, day, sche_point);
    }
}

void calendar(int year, int month, int con, int sche_point){

    system("cls");

    time_t TIME = time(NULL);
    struct tm tm = *localtime(&TIME);
    int month_day[2][12] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                             {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

    int calendar_arr[6][7] = { {0 ,0 ,0 ,0 ,0 ,0 ,0},
                               {0 ,0 ,0 ,0 ,0 ,0 ,0},
                               {0 ,0 ,0 ,0 ,0 ,0 ,0},
                               {0 ,0 ,0 ,0 ,0 ,0 ,0},
                               {0 ,0 ,0 ,0 ,0 ,0 ,0},
                               {0 ,0 ,0 ,0 ,0 ,0 ,0} };

    int year_f = year, month_f = month, con_f = con;
    int i, last_year_days = 0, today_year_days = 0, total_day = 0, days = 0, sel;

    last_year_days = 365 * ( year - 1 ) + count_leap(year);

    switch (leap(year)) {
        case 0 : for (i = 0; i < month-1; i++)
                        today_year_days = today_year_days + month_day[0][i]; break;
        case 1 : for (i = 0; i < month-1; i++)
                        today_year_days = today_year_days + month_day[1][i];
    }

    total_day = (last_year_days + today_year_days + 1) % 7;

    if(month != 2) days = month_day[0][month - 1];
    else if(leap(year)) days = month_day[1][1];
    else days = month_day[0][1];

    print_cal(year, month, total_day, days, calendar_arr, sche_point);

    sel = sel_calen(con, tm.tm_mday, calendar_arr);
    if( sel == Before ) {
        if( (month_f - 1) == 0 ) {
            year_f = year_f - 1;
            month_f = 12;
        }
        else month_f = month_f - 1;
        con_f = -2;
        calendar(year_f, month_f, con_f, sche_point);
    }
    else if( sel == After ) {
        if( (month_f + 1) > 12 ) {
            year_f = year_f + 1;
            month_f = 1;
        }
        else month_f = month_f + 1;
        con_f = -1;
        calendar(year_f, month_f, con_f, sche_point);
    }
    else if( sel == END){
        system("cls");
        main();
    }
    else{
        system("cls");
        check( year_f, month_f, sel, sche_point);
    }
}

int leap(int year){
    if( ( (year % 4 == 0) && year % 100 ) || (year % 400 == 0) ) return (1);
    return (0);
}

int count_leap(int year){

    int i,count = 0;
    for( i = 1 ; i < year; i++){
        if( leap(i) ) count++;
    }
    return (count);
}

void check(int year, int month, int day, int sche_point){

            int i = 0;

            cur(5,3);
            printf("선택 요일 : %4d년 %2d월 %2d일\n",year, month, day);
            cur(4,6);
            printf("\n[메뉴]\n");
            printf("① 일정 추가 \n② 일정 확인\n③ 일정 삭제\n④ 뒤로가기\n");
            cur(9,7);
            printf("답 : ");
            scanf("%d",&i);
            fflush(stdin);

            switch(i){
                    case 1 :
                        sche1(year, month, day, sche_point);
                        break;

                    case 2 :
                        sche2(year, month, day, sche_point);
                        break;

                    case 3 :
                        sche3(year, month, day, sche_point);
                        break;

                    case 4 :
                        calendar(year, month, day, sche_point);
                        break;

                    default :
                        system("cls");
                        printf("오류 발생. 달력으로 돌아갑니다.\n\n");
                        Sleep(500);
                        system("cls");
                        i = 0;
                        calendar(year, month, day, sche_point);
                        break;
            }
}

int sel_calen(int con, int today, int calendar[6][7]){

    char key;
    int x, y, n_x, n_y, p_x, p_y;
    if(con == 0){
        for(y = 0; y < 5; y++){
            for(x = 0; x < 7 ;x++){
                if( calendar[y][x] == today )
                {
                    p_x = n_x = 5 + x * 6; p_y = n_y = 5 + 3 * y;
                    cur(5 + x * 6,5 + 3 * y);
                    printf("%2c",'*');
                }
            }
        }
    }
    else if(con == Before) {
        p_x = n_x = 8;
        p_y = n_y = 1;
        cur(8, 1);
        printf("%2c",'*');
    }
    else if(con == After){
        p_x = n_x = 38;
        p_y = n_y = 1;
        cur(38, 1);
        printf("%2c",'*');
    }
    else{
        for(y = 0; y < 5; y++){
            for(x = 0; x < 7 ;x++){
                if( calendar[y][x] == con )
                {
                    p_x = n_x = 5 + x * 6; p_y = n_y = 5 + 3 * y;
                    cur(5 + x * 6,5 + 3 * y);
                    printf("%2c",'*');
                }
            }
        }
    }

    while( 1 ){
        if( kbhit() ){

            key = getch();

        switch(key){

            case UP:
                  p_x = n_x;
                  p_y = n_y;
                  n_y = n_y - 3;
                  if(calendar[(n_y - 5) / 3][(n_x - 5) / 6] == 0 || n_y < 5) {
                        if(n_x < 18) { n_y = 1; n_x = 8; }
                        else { n_y = 1; n_x = 38; }
                  }
                  if(p_x == 55){
                    n_y = 1; n_x = 38;
                  }
                  break;

            case DOWN:
                  p_x = n_x;
                  p_y = n_y;
                  n_y = n_y +3;
                  if (n_y > 20)
                    n_y = 20;
                  if( p_y == 1 ){
                        if(p_x == 8) {
                                if(calendar[(5 - 5) / 3][(5 - 5) / 6] == 0){ n_y = 8; n_x = 5;}
                                else n_y = 5; n_x = 5;
                        }
                        else { n_y = 5; n_x = 41;}
                  }
                  else if(calendar[(n_y - 5) / 3][(n_x - 5) / 6] == 0 ){ n_y = p_y; }
                  else if(n_x == 55){
                    n_x = 41; n_y = 14;
                  }
                  break;

            case LEFT:
                  p_y = n_y;
                  p_x = n_x;

                  if(n_x == 38 || n_x == 8) n_x = 8;
                  else n_x = n_x - 6;

                  if(p_x == 55){
                        n_y = 11 ;n_x = 41;
                  }

                  if (n_x < 5)
                    n_x = 5;

                  if(calendar[(n_y - 5) / 3][(n_x - 5) / 6] == 0) n_x = p_x;

                  break;

            case RIGHT:
                  p_y = n_y;
                  p_x = n_x;

                  if( p_y == 1 && (p_x == 8 || p_x == 38) ) n_x = 38;
                  else n_x = n_x + 6;

                  if (n_x > 41){
                   n_y = 10; n_x = 55;
                  }

                  if(calendar[(n_y - 5) / 3][(n_x - 5) / 6] == 0 && p_y != 1) n_x = p_x;

                  break;

             case ENTER :
                  if(n_x == 8 && n_y == 1) return(Before);
                  else if(n_x == 38 && n_y == 1) return(After);
                  else if(n_y == 10 && n_x == 55) return (END);
                  else return(calendar[(n_y - 5) / 3][(n_x - 5) / 6]);

                  break;
            }

        cur(p_x, p_y);
        if(p_x == 55 && p_y == 10){
                printf("■");
        }
        else if(p_y == 1){
            if(p_x == 8) printf("◀");
            else printf("▶");
        }
        else{
            x = (p_x - 5) / 6 ; y = (p_y - 5) / 3  ;
            printf("%2d",calendar[y][x]);
        }
        cur(n_x, n_y); printf("%2c",'*');
        }
    }
}

void print_cal(int year, int month, int total_day, int days, int calendar_arr[6][7], int sche_point)
{

     system("cls");
     int i, n, x, y;

     time_t TIME = time(NULL);
     struct tm tm = *localtime(&TIME);

     printf("\n\t◀   Year : %4d  Month : %2d   ▶ \n\n", year, month);
     printf("    SUN   MON   TUE   WEN   THU   FRI   SAT\n");
     for (i = 0, x = 0, y = 0 ; i < total_day ; i++, x++)  {
        calendar_arr[y][x] = 0;
        printf("    ");
     }
     for (n = 1,y = 0; n <= days; n++, x++) {
         calendar_arr[y][x] = n;
         cur(5 + (x * 6),5 + 3 * y);
         printf("%2d",n);

         if((n + total_day) % 7 == 0){
                printf("\n");
                y++;
                x = -1;
         }
     }
     printf("\n");
     cur(55,10);
     printf("■");
     cur(7, 23);
     printf("[Enter 를 눌러 날짜를 선택하세요.]");
     cur(0, 25);
     printf(" ◀: 지난달 \n ▶: 다음 달\n * : 선택 커서 \n■ : 종료 버튼\n");
     printf("오늘 날짜 : %4d년 %2d월 %2d일",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

void cur(int x, int y){

    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

}
//

//이현승 코드

int question1(void){
    int i;
    printf("\n먹고 싶은 장소\n");
    printf("\n① 신정문 ② 구정문 ③ 학교\n");
    scanf("%d",&i);
    fflush(stdin);
    if( 1<= i && i <= 3) return i;
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

    int i[3], j, k, a,number = 0;
    FILE *f;
    cur(16,12);
    printf("\n\t   === 맞춤 음식점 찾기 ===\n");
    printf("\t\t하시겠습니까?\n");
    printf("\t\t① yes ② no \n");
    cur(16,16);
    printf("선택 : ");
    scanf("%d",&j);
    fflush(stdin);
    while( 1 ){
        if(1 <= j && j <= 2) {
            if( j == 1){
                system("cls");
                printf("\n=== 맞춤 음식점 찾기 ===\n");
                break;
            }
            else{
                system("cls");
                return main();
            }
        }
        else{
            system("cls");
            cur(16,12);
            printf("입력 오류.\n\t\t다시 입력하시오.\n\n");
            printf("\t   === 맞춤 음식점 찾기 ===\n");
            printf("\t\t하시겠습니까?\n");
            printf("\t\t① yes ② no \n");
            cur(16,18);
            printf("선택 : ");
            scanf("%d",&j);
            fflush(stdin);
        }

    }
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
                printf("\n음식점 이름 : %s\n대표 음식 : %s\n가격 : %s원\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
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
                printf("\n음식점 이름 : %s\n대표 음식 : %s\n가격 : %s원\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
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
                printf("\n음식점 이름 : %s\n대표 음식 : %s\n가격 : %s원\n", fod[k+1].fname, fod[k+2].fname, fod[k + 3].fname);
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
                if(j == 1){
                    system("cls");
                        food();
                }
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
//

//우진환 코드
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
                Gaek(sel);
            }
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

int sel_b(void){
    BUS sel;
    int j;

    cur(16,12);
    printf("\n\t   === 버스 메인메뉴 ===\n");
    printf("\t\t하시겠습니까?\n");
    printf("\t\t① yes ② no \n");
    cur(16,18);
    printf("선택 : ");
    scanf("%d",&j);
    fflush(stdin);
    while( 1 ){
        if(1 <= j && j <= 2) {
            if( j == 1){
                system("cls");
                printf("\n=== 버스 메인메뉴 ===\n");
                break;
            }
            else{
                system("cls");
                return main();
            }
        }
        else{
            system("cls");
            cur(16,12);
            printf("입력 오류.\n\t\t다시 입력하시오.\n\n");
            printf("\n\t   === 버스 메인메뉴 ===\n");
            printf("\t\t하시겠습니까?\n");
            printf("\t\t① yes ② no \n");
            cur(16,18);
            printf("선택 : ");
            scanf("%d",&j);
            fflush(stdin);
        }
    }

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

int choo(void){
    int i;
    printf("\n\n1. 더 찾는다.    2. 로비로 간다.\n");
    scanf("%d",&i);
    fflush(stdin);
    while(1){
        if(1 <= i && i <= 2){
            if(i == 1) {
                    system("cls");
                    sel_b();
            }
            else {
                    system("cls");
                    return main();
            }
        }
        else {
            printf("\n입력 오류. 다시 입력하세요.");
            choo();
        }
    }
}
//

//김민철 코드
int household(void)
{
    int j;
    cur(16,12);
    printf("\n\t\t=== 가계부 ===\n");
    printf("\t\t하시겠습니까?\n");
    printf("\t\t① yes ② no \n");
    cur(16,18);
    printf("선택 : ");
    scanf("%d",&j);
    fflush(stdin);
    while( 1 ){
        if(1 <= j && j <= 2) {
            if( j == 1){
                system("cls");
                break;
            }
            else{
                system("cls");
                return main();
            }
        }
        else{
            system("cls");
            cur(16,12);
            printf("입력 오류.\n\t\t다시 입력하시오.\n\n");
            printf("\n\t\t === 가계부 ===\n");
            printf("\t\t하시겠습니까?\n");
            printf("\t\t① yes ② no \n");
            cur(16,19);
            printf("선택 : ");
            scanf("%d",&j);
            fflush(stdin);
        }
    }
    system("cls");

    int quit = 0;
    int menu;

    while(!quit){
        showMainMenu();
        printf("메뉴>");
        scanf("%d", &menu);

        switch(menu){
        case 1:
            registIn();
            break;
        case 2:
            registEx();
            break;
        case 3:
            showInList();
            break;
        case 4:
            showExList();
            break;
        case 5:
            showBalance();
            break;
        case 0:
            system("cls");
            return main();
            break;
        }
    }
}
void showMainMenu()
{
    printf("\n* 가계부\n\n");
    printf("1. 수입 등록\n");
    printf("2. 지출 등록\n");
    printf("3. 수입 목록\n");
    printf("4. 지출 목록\n");
    printf("5. 잔액\n");
    printf("0. 로비\n\n");
}
void registIn()
{
    book[bookIdx].isIncome = 1;
    printf("\n* 수입 등록\n\n");
    printf("- 내용 : ");
    scanf("%s", book[bookIdx].contents);
    printf("- 금액 : ");
    scanf("%d", &(book[bookIdx].money));
    bookIdx += 1;
}
void registEx()
{
    book[bookIdx].isIncome = 0;
    printf("\n* 지출 등록\n\n");
    printf("- 내용 : ");
    scanf("%s", book[bookIdx].contents);
    printf("- 금액 : ");
    scanf("%d", &(book[bookIdx].money));
    bookIdx += 1;
}
void showInList()
{
    int i;
    int num = 0;
    int tot = 0;

    printf("\n* 수입 목록\n\n");
    printf("%4s %20s %8s\n", "순서", "내용", "금액");
    printf("====================================\n");
    for (i=0; i<bookIdx; i++)
    {
        if (book[i].isIncome == 1)
        {
            num += 1;
            tot += book[i].money;
            printf("%4d %20s %8d원\n", num, book[i].contents, book[i].money);
        }
    }
    printf("====================================\n");
    printf("   총수입 : %d원\n", tot);
}
void showExList()
{
    int i;
    int num = 0;
    int tot = 0;

    printf("* 지출 목록\n\n");
    printf("%4s %20s %8s\n", "차례", "내용", "금액");
    printf("====================================\n");
    for (i=0; i<bookIdx; i++)
    {
        if (book[i].isIncome != 1)
        {
            num += 1;
            tot += book[i].money;
            printf("%4d %20s %8d원\n", num, book[i].contents, book[i].money);
        }
    }
    printf("====================================\n");
    printf("   총지출 : %d원\n", tot);
}

void showBalance()
{
    int i;
    int in = 0;
    int ex = 0;
    int balance = 0;

    for (i=0; i<bookIdx; i++)
    {
        if (book[i].isIncome == 1)
        {
            in += book[i].money;
        }else
        {
            ex += book[i].money;
        }
    }
    printf("\n* 잔액\n\n");
    printf("- 수입 : %d원\n", in);
    printf("- 지출 : %d원\n", ex);
    printf("- 잔액 : %d원\n", (in-ex));
}

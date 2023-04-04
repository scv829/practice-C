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

void calendar(int year, int month, int con, int sche_point);
int count_leap(int year);
int leap(int year);
void cur(int x, int y);
void print_cal(int year, int month, int total_day, int days, int calendar_arr[6][7], int sche_point);
int sel_calen(int con, int today, int calendar[6][7]);
void check(int year, int month, int day, int sche_point);

typedef struct schedule_s{

    int year_s;
    int month_s;
    int day_s;
    char Name[MAX];
    char place[MAX];
    char time[MAX];

}Sch;

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
                fscanf(schedule,"%d %d %d",&s2[i].year_s, &s2[i].month_s, &s2[i].day_s);
                fscanf(schedule,"%s",s2[i].Name);
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

int main()
{
    time_t TIME = time(NULL);
    struct tm tm = *localtime(&TIME);

    int sche_point = check_sche_point();
    int year = tm.tm_year + 1900 , month = tm.tm_mon + 1, condition = 0;

    calendar(year, month, condition, sche_point);

    return 0;
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
        exit(0);
    }
    else{
        system("cls");
        check( year_f, month_f, sel, sche_point);
    }
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

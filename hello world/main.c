#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ft_a(int* a,int* b){
    printf("\ndata = ");
    scanf("%d",a);
    printf("\ndata = ");
    scanf("%d",b);
}


int main()
{

    /*chapter 1*/

    { //chapter 1 실습문제 1번
        /*

        for(int a = 0 ; a < 3 ; a++)
            printf("한재성\n");;
        */
    }

    { //chapter 1 실습문제 2번
    /*
    int a;
    printf("한 달이 몇 일 인지 쓰시오 : ");
    scanf("%d",&a);

    printf("한 달(%d일)은 %d 초로 되어있습니다.\n",a, a*24*60*60);
    */
    }

    { //chapter 1 실습문제 3번
       /*
        char a;

        printf("한개의 문자르 입력하시오 : ");
        scanf("%c",&a);

        printf("%c의 아스키 코드값 : %d\n",a,a);
        */
    }

    { //chapter 1 실습문제 4번
    /*
        int a;
        printf("10진수 숫자 하나를 적으시오 : ");
        scanf("%d",&a);

        printf("10진수 %d의 8진수의 값 : %o\n10진수 %d의 16진수의값 : %x",a,a,a,a);
    */
    }

    /*chapter 2*/

    { //chapter 2 실습문제 1번
    /*
        printf("char의 크기 : %d\n",sizeof(char));
        printf("int의 크기 : %d\n",sizeof(int));
        printf("float의 크기 : %d\n",sizeof(float));
        printf("double의 크기 : %d\n",sizeof(double));
    */
    }

    { //chapter 2 실습문제 2번
    /*
        for(char a = 97; a <=122 ; a++)
            printf("%c ",a);
    */
    }

    { //chapter 2 실습문제 3번
    /*
        float l, h;
        printf("밑면을 적으시오 : ");
        scanf("%f",&l);
        printf("높이를 적으시오 : ");
        scanf("%f",&h);

        printf("%f",1./2.*l*h);
    */
    }

    { //chapter 2 실습문제 4번
    /*
        int a, b, c,sum;
        float f;
        printf("aX^2-bX+c 인 이차방정식의 계수를 순서대로 적으시오 : ");
        scanf("%d %d %d",&a,&b,&c);
        sum = b*b-4*a*c;

        if(a == 0 && b==0)
             printf("방정식이 아니다.\n");
        else{
            if(sum > 0)
            {
                printf("x = %f or x = %f\n",-(-b+sqrt((double)sum))/2*a,-(-b-sqrt((double)sum))/2*a);
            }
            else if(sum == 0)
            {
                printf("x = %f",(float)c/(float)b);
            }
            else if(sum < 0)
            {
                printf("근이 없다.\n");
            }
        }
        */
    }

    { //chapter 2 실습문제 5번
    /*
        int num = 0;
        char c;
        printf("문자를 입력하세요\n");
        c = getchar();

        while(c != EOF)
        {
            if(c >= '0' && c <= '9')
            {
                num++;
                c = getchar();
            }
            else{
                c = getchar();
            }
        }
            printf("숫자의 개수 : %d\n",num);
        */
    }

    { //chapter 2 실습문제 6번
    /*
        int a, b;
        printf("첫번째 자연수를 입력하세요 : ");
        scanf("%d",&a);
        printf("두번째 자연수를 입력하세요 : ");
        scanf("%d",&b);

        printf("%d를 %d로 나누었을 때의 몫 :%d\n",a,b,a/b);
        printf("%d를 %d로 나누었을 때의 나머지 :%d",a,b,a%b);
    */
    }

    /*chapter 3*/
    { //chapter 3 연습문제 3번
/*
        char c;
        int count, digit_count;
        count = -1; digit_count = 0;
        while(c = getchar()){
            if(c=='E')
                return printf("Word = %d Number = %d\n",count,digit_count); /* break -> return*/
       /*     count++;
            if(c >= '0' && c<='9')
                digit_count++;
        }

    /*
        char c = 0;
        int count ,digit_count;
        count = 0; digit_count = 0;
        c = getchar();
        while( c != 'E')
        {
            count++;
            if(c>= '0' && c <= '9')
                digit_count++;
            c = getchar();
        }
        printf("char c = %c , count = %d , digit_count = %d\n",c,count,digit_count);


        char c = 0;
        int count = -1,digit_count = 0;

        for( c = getchar(); c != 'E' ; c = getchar()){
            count++;
            if(c>= '0' && c <= '9')
                digit_count++;
        }
        printf("char c = %c , count = %d , digit_count = %d\n",c,count,digit_count);
        */
    }

    { //chapter 3 연습문제 4번
     /*
        int i,n,total;
        i = -5; n = 50; total = 0;
        while(i < n){
            i++;
            if( i == 0 )
                if(i < n) //continue -> if문을 하나 더씀;
                    i++;
            total +=i;
        }
        printf("%d\n",total); //1265

        int i,n,total;
        i = -5; n = 50; total = 0;
        while(i < n){
            i++;
            total +=i;
        }
        printf("%d\n",total);
        */
    }

    { //chapter 3 연습문제 7번
    /*
        float a,b,c,d ,r1,r2;
        a=1;b=2;c=1;d=0;r1=0;r2=0;


        d= b*b-4.0*a*c;
        if (d==0){
            if (a !=0.0) r1 = r2 = -b / (2.0 * a);
        else
            printf("degenerate case\n");
        printf("L4\n");
        }
        else if( d > 0.0){
            if(a != 0.0){
                r1 = (-b+sqrt(d)) / (2.0 * a);
                r2 = (-b-sqrt(d)) / (2.0 * a);
                printf("L4\n");
            }
            else{
                printf("degenerate case\n");
            }
        }
        else{
             if(a != 0.0){
                printf("imaginary roots\n");
                printf("L4\n");}
        }
        */

    }

    { //chapter 3 실전문제 1번
    /*
        int i = 0, total = 0;

        while(total < 1000){
            i++;
            total = total+i*i;

        }
        printf("i = %d\n",i); */

    }

    { //chapter 3 실전문제 2번


          /*  //for

           int n = 0; int total = 0; int i = 0;
            scanf("%d",&n);


            if(n >= 0)
                for(i = n ; i <= 2*n ; i++)
                    total = total + i;
            else if(n < 0)
                for(i = 2*n ; i <= n ; i++)
                    total = total + i;

           printf("for total = %d\n",total);

           //while

            int n = 0; int total = 0; int i = 0;
            scanf("%d",&n);
            if(n >= 0){
                i = n ;
                while(i <= 2*n){
                    total = total + i;
                    i++;
                }
            }
            else if(n < 0){
                i = 2*n;
                while(i <= n){
                    total = total + i;
                    i++;
                }
            }
            printf("while total = %d\n",total); */

    }

    /*chapter 4*/
    { //chapter 4 실습문제 3번

     /*   int n, m,i,total = 1;
        printf("숫자를 입력하시오 : ");
        scanf("%d",&m);
        printf("멱승을 입력하시오 : ");
        scanf("%d",&n);
        i = n;
        while(1){
            if(i > 0){
                total = total * m;
                i--;
                continue;
            }
            else if(i == 0){
                total = total * 1;
            }
            else if(i < 0){
                printf("멱승을 구할수가 없습니다.");
                break;
            }
            printf("%d^%d = %d\n",m,n,total);
            break;
        }
    */
    }

    { //chapter 4 실습문제 4번

      /*  int n, i;
        printf("몇 번째의 급수의 값을 알고싶은지 적으시오 : ");
        scanf("%d",&n);
        int total[n];
        total[0] = 1;
        total[1] = 1;
        if(n >= 2){
            for(i = 2 ; i <=n; i++)
                total[i] = total[i-1] + total[i-2];
            printf("%d번째 급수의 값 = %d\n",n,total[n]);
        }
        else if(n == 0 || n == 1)
            printf("%d번째 급수의 값 = %d\n",n,n);
        else
            printf("입력한 숫자로는 찾을 수 없습니다.\n"); */

    }
    /*chapter 5*/
    { //chapter 5 연습문제 1번
    /*
        char *p,*q;
        p = q = "UNIX";
        while(*p) p++;
        while(p > q){
            p--;
            putchar(*p);
        }
        putchar('\n');
        */
    }

    { //chapter 5 연습문제 3번

      /*{ //void ft_a()
        void ft_a(int* a,int* b){
        printf("\ndata = ");
        scanf("%d",a);
        printf("\ndata = ");
        scanf("%d",b);
        }

        { //void main(void)
            int x,y;
            ft_a(&x,&y);
            printf("\n%d + %d = %d\n",x,y,x+y);
        } */
    }

    { //chapter 5 실습문제 3번
     /*
        int n,i,total = 0;
        float mean = 0;
        printf("입력할 갯수를 적으시오 : ");
        scanf("%d",&n);
        if(n >= 0){
            int str[n];
            printf("원소들을 입력하시오 : ");
            for(i = 0; i < n ; i++){
                scanf("%d",&str[i]);
                total += str[i];
            }
            mean = (float)total/(float)n;

            printf("average = %f",mean);
        }
        else if(n < 0)
            printf("입력한 단어로는 함수를 실행할 수 없습니다.");
            */
    }


}

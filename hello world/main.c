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

    { //chapter 1 �ǽ����� 1��
        /*

        for(int a = 0 ; a < 3 ; a++)
            printf("���缺\n");;
        */
    }

    { //chapter 1 �ǽ����� 2��
    /*
    int a;
    printf("�� ���� �� �� ���� ���ÿ� : ");
    scanf("%d",&a);

    printf("�� ��(%d��)�� %d �ʷ� �Ǿ��ֽ��ϴ�.\n",a, a*24*60*60);
    */
    }

    { //chapter 1 �ǽ����� 3��
       /*
        char a;

        printf("�Ѱ��� ���ڸ� �Է��Ͻÿ� : ");
        scanf("%c",&a);

        printf("%c�� �ƽ�Ű �ڵ尪 : %d\n",a,a);
        */
    }

    { //chapter 1 �ǽ����� 4��
    /*
        int a;
        printf("10���� ���� �ϳ��� �����ÿ� : ");
        scanf("%d",&a);

        printf("10���� %d�� 8������ �� : %o\n10���� %d�� 16�����ǰ� : %x",a,a,a,a);
    */
    }

    /*chapter 2*/

    { //chapter 2 �ǽ����� 1��
    /*
        printf("char�� ũ�� : %d\n",sizeof(char));
        printf("int�� ũ�� : %d\n",sizeof(int));
        printf("float�� ũ�� : %d\n",sizeof(float));
        printf("double�� ũ�� : %d\n",sizeof(double));
    */
    }

    { //chapter 2 �ǽ����� 2��
    /*
        for(char a = 97; a <=122 ; a++)
            printf("%c ",a);
    */
    }

    { //chapter 2 �ǽ����� 3��
    /*
        float l, h;
        printf("�ظ��� �����ÿ� : ");
        scanf("%f",&l);
        printf("���̸� �����ÿ� : ");
        scanf("%f",&h);

        printf("%f",1./2.*l*h);
    */
    }

    { //chapter 2 �ǽ����� 4��
    /*
        int a, b, c,sum;
        float f;
        printf("aX^2-bX+c �� ������������ ����� ������� �����ÿ� : ");
        scanf("%d %d %d",&a,&b,&c);
        sum = b*b-4*a*c;

        if(a == 0 && b==0)
             printf("�������� �ƴϴ�.\n");
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
                printf("���� ����.\n");
            }
        }
        */
    }

    { //chapter 2 �ǽ����� 5��
    /*
        int num = 0;
        char c;
        printf("���ڸ� �Է��ϼ���\n");
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
            printf("������ ���� : %d\n",num);
        */
    }

    { //chapter 2 �ǽ����� 6��
    /*
        int a, b;
        printf("ù��° �ڿ����� �Է��ϼ��� : ");
        scanf("%d",&a);
        printf("�ι�° �ڿ����� �Է��ϼ��� : ");
        scanf("%d",&b);

        printf("%d�� %d�� �������� ���� �� :%d\n",a,b,a/b);
        printf("%d�� %d�� �������� ���� ������ :%d",a,b,a%b);
    */
    }

    /*chapter 3*/
    { //chapter 3 �������� 3��
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

    { //chapter 3 �������� 4��
     /*
        int i,n,total;
        i = -5; n = 50; total = 0;
        while(i < n){
            i++;
            if( i == 0 )
                if(i < n) //continue -> if���� �ϳ� ����;
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

    { //chapter 3 �������� 7��
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

    { //chapter 3 �������� 1��
    /*
        int i = 0, total = 0;

        while(total < 1000){
            i++;
            total = total+i*i;

        }
        printf("i = %d\n",i); */

    }

    { //chapter 3 �������� 2��


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
    { //chapter 4 �ǽ����� 3��

     /*   int n, m,i,total = 1;
        printf("���ڸ� �Է��Ͻÿ� : ");
        scanf("%d",&m);
        printf("����� �Է��Ͻÿ� : ");
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
                printf("����� ���Ҽ��� �����ϴ�.");
                break;
            }
            printf("%d^%d = %d\n",m,n,total);
            break;
        }
    */
    }

    { //chapter 4 �ǽ����� 4��

      /*  int n, i;
        printf("�� ��°�� �޼��� ���� �˰������ �����ÿ� : ");
        scanf("%d",&n);
        int total[n];
        total[0] = 1;
        total[1] = 1;
        if(n >= 2){
            for(i = 2 ; i <=n; i++)
                total[i] = total[i-1] + total[i-2];
            printf("%d��° �޼��� �� = %d\n",n,total[n]);
        }
        else if(n == 0 || n == 1)
            printf("%d��° �޼��� �� = %d\n",n,n);
        else
            printf("�Է��� ���ڷδ� ã�� �� �����ϴ�.\n"); */

    }
    /*chapter 5*/
    { //chapter 5 �������� 1��
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

    { //chapter 5 �������� 3��

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

    { //chapter 5 �ǽ����� 3��
     /*
        int n,i,total = 0;
        float mean = 0;
        printf("�Է��� ������ �����ÿ� : ");
        scanf("%d",&n);
        if(n >= 0){
            int str[n];
            printf("���ҵ��� �Է��Ͻÿ� : ");
            for(i = 0; i < n ; i++){
                scanf("%d",&str[i]);
                total += str[i];
            }
            mean = (float)total/(float)n;

            printf("average = %f",mean);
        }
        else if(n < 0)
            printf("�Է��� �ܾ�δ� �Լ��� ������ �� �����ϴ�.");
            */
    }


}

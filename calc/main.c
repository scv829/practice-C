#include <stdio.h>

int intro(int c)
{
    printf("****************************\n");
    printf("(1) 덧셈(+)\n");
    printf("(2) 뺄셈(-)\n");
    printf("(3) 곱셈(*)\n");
    printf("(4) 나눗셈(÷)\n");
    printf("****************************\n");
    printf("위에서 수행하고자 하는 사칙연산 번호를 선택하시오 : ");
    scanf("%d",&c);
    while( !(1 <= c && c <= 4) )
    {
        if(!( 1 <= c && c <= 4))
            {
            printf("\n(1)~(4) 범위의 번호만 입력하시오.\n\n");
            scanf("%d",&c);
            }
    }
    return c;
}

float plus(int a, int b)
{
    printf("\n연산을 수행하고자 하는 2개의 수를 입력하시오 : ");
    scanf("%d %d",&a,&b);
    return( (float)a + (float)b );
}

float minus(int a, int b)
{
    printf("\n연산을 수행하고자 하는 2개의 수를 입력하시오 : ");
    scanf("%d %d",&a,&b);
    return( (float)a - (float)b );
}

float multi(int a, int b)
{
    printf("\n연산을 수행하고자 하는 2개의 수를 입력하시오 : ");
    scanf("%d %d",&a,&b);
    return( (float)a * (float)b );
}

float divis(int a, int b)
{
    printf("\n연산을 수행하고자 하는 2개의 수를 입력하시오 : ");
    scanf("%d %d",&a,&b);
    return( (float)a / (float)b );
}

int main(void)
{

    int i,x,y;

    i = intro(i);

    switch (i){
        case 1 : printf("\n계산 결과 : %0.2f\n", plus(x,y)); break;

        case 2 : printf("\n계산 결과 : %0.2f\n", minus(x,y)); break;

        case 3 : printf("\n계산 결과 : %0.2f\n", multi(x,y)); break;

        case 4 : printf("\n계산 결과 : %0.2f\n", divis(x,y)); break;
    }

    return 0;
}

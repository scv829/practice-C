#include <stdio.h>

int intro(int c)
{
    printf("****************************\n");
    printf("(1) ����(+)\n");
    printf("(2) ����(-)\n");
    printf("(3) ����(*)\n");
    printf("(4) ������(��)\n");
    printf("****************************\n");
    printf("������ �����ϰ��� �ϴ� ��Ģ���� ��ȣ�� �����Ͻÿ� : ");
    scanf("%d",&c);
    while( !(1 <= c && c <= 4) )
    {
        if(!( 1 <= c && c <= 4))
            {
            printf("\n(1)~(4) ������ ��ȣ�� �Է��Ͻÿ�.\n\n");
            scanf("%d",&c);
            }
    }
    return c;
}

float plus(int a, int b)
{
    printf("\n������ �����ϰ��� �ϴ� 2���� ���� �Է��Ͻÿ� : ");
    scanf("%d %d",&a,&b);
    return( (float)a + (float)b );
}

float minus(int a, int b)
{
    printf("\n������ �����ϰ��� �ϴ� 2���� ���� �Է��Ͻÿ� : ");
    scanf("%d %d",&a,&b);
    return( (float)a - (float)b );
}

float multi(int a, int b)
{
    printf("\n������ �����ϰ��� �ϴ� 2���� ���� �Է��Ͻÿ� : ");
    scanf("%d %d",&a,&b);
    return( (float)a * (float)b );
}

float divis(int a, int b)
{
    printf("\n������ �����ϰ��� �ϴ� 2���� ���� �Է��Ͻÿ� : ");
    scanf("%d %d",&a,&b);
    return( (float)a / (float)b );
}

int main(void)
{

    int i,x,y;

    i = intro(i);

    switch (i){
        case 1 : printf("\n��� ��� : %0.2f\n", plus(x,y)); break;

        case 2 : printf("\n��� ��� : %0.2f\n", minus(x,y)); break;

        case 3 : printf("\n��� ��� : %0.2f\n", multi(x,y)); break;

        case 4 : printf("\n��� ��� : %0.2f\n", divis(x,y)); break;
    }

    return 0;
}

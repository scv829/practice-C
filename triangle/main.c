#include <stdio.h>

int main()
{
    int m,h;
    float t;

    printf("�ﰢ���� �غ� : ");
    scanf("%d",&m);
    printf("�ﰢ���� ���� : ");
    scanf("%d",&h);

    t = 0.5 * m * h;

    printf("�ﰢ���� ���� : %0.2f",t);
}

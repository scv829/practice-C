#include <stdio.h>

int main()
{
    int m,h;
    float t;

    printf("삼각형의 밑변 : ");
    scanf("%d",&m);
    printf("삼각형의 높이 : ");
    scanf("%d",&h);

    t = 0.5 * m * h;

    printf("삼각형의 넓이 : %0.2f",t);
}

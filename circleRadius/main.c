#include <stdio.h>

int main()
{
    unsigned int r;
    float area;
    printf("반지름을 입력하시오 : ");
    scanf("%d",&r);

    area = 3.14*(float)(r*r);
    printf("반지름이 %d인 원의 넓이 : ",r);
    printf("%0.3f",area);

    return 0;
}

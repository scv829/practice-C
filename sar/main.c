#include <stdio.h>
//int power(int m, int e);
int power(int x, int y){

    int tmp = 1;

    for(;y>0;y--)
        tmp *= x;
    return tmp;
}

int main(void)
{
    int result;
    int m,e;
    m = 3; e=5;

    result = power(m,e);
    printf("%d��%d�� : %d \n", m,e,result);
    printf("%d��%d�� : %d \n", 2,3,power(2,3));
    printf("%d��%d�� : %d \n", 4,3,power(4,3));

    return 0;
}

#include <stdio.h>

int main()
{
    int f_number, e_number,i,j;

    printf("구구단의 범위를 적으시오 : ");

    scanf("%d %d",&f_number,&e_number);

    for(i = f_number ; i <= e_number ; i++)
    {
        for(j = 1 ; j <= 9 ; j++)
        {
            printf("%d x %d = %2d", i, j, i*j);
            printf("\n");
        }
            printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Main()
{
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


    return 0;
}


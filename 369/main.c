#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    for(b = 0 ; b <= 90 ; b +=10){
        if(b == 30 || b == 60 || b == 90)
        {
            for(c = 0 ; c <= 9 ; c++)
                printf("%d ",b+c);
        }
        else
        {
            for(a = 3 ; a <=9 ; a += 3)
                printf("%d ",a+b);
        }
    }
    return 0;
}

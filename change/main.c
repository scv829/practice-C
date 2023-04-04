#include <stdio.h>
#include <stdlib.h>

int main()
{

    char str[20] = "kingdom";
    int i = 0;
    int cn = 0;
    for(cn = 0; cn < 20; cn++)
        if(str[cn] == '\0') break;
    for(i = cn-1; i >= 0 ; i--)
        printf("%c",str[i]);
    return 0;
}

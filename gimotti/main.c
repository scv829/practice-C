#include <stdio.h>

int main()
{
    char i;
    scanf("%c",&i);
    if( i <= 'A' && i <= 'Z')
    {
        printf("읽은 문자 : %c ,ASCII : %x\n",i,(int)i);
        i = i + ('a' - 'A');
        printf("변환 문자 : %c ,ASCII : %x",i,(int)i);
    }
    else if( i <= 'a' && i <= 'z')
    {
        printf("읽은 문자 : %c ,ASCII : %x\n",i,(int)i);
        i = i - ('a' - 'A');
        printf("변환 문자 : %c ,ASCII : %x",i,(int)i);
    }
    else
        printf("입력 오류입니다.");
    return 0;
}

#include <stdio.h>

int main()
{
    char i;
    scanf("%c",&i);
    if( i <= 'A' && i <= 'Z')
    {
        printf("���� ���� : %c ,ASCII : %x\n",i,(int)i);
        i = i + ('a' - 'A');
        printf("��ȯ ���� : %c ,ASCII : %x",i,(int)i);
    }
    else if( i <= 'a' && i <= 'z')
    {
        printf("���� ���� : %c ,ASCII : %x\n",i,(int)i);
        i = i - ('a' - 'A');
        printf("��ȯ ���� : %c ,ASCII : %x",i,(int)i);
    }
    else
        printf("�Է� �����Դϴ�.");
    return 0;
}

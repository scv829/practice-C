#include <stdio.h>
void decimal_to_binary(int d)
{
    int  binary = 0, count = 0;

    for(count = 1; d / 2 >= 1  ; count *= 10)
    {
        if(d % 2 == 1)
            binary += 1*count;
        d = d / 2;
    }
    binary += d*(count);
    printf("�������δ� %d�Դϴ�.",binary);

}
int main()
{
    int decimal;
    printf("�������� �Է��ϼ���: ");
    scanf("%d",&decimal);
    decimal_to_binary(decimal);
    return 0;
}

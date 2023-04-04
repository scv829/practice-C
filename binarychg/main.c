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
    printf("이진수로는 %d입니다.",binary);

}
int main()
{
    int decimal;
    printf("십진수를 입력하세요: ");
    scanf("%d",&decimal);
    decimal_to_binary(decimal);
    return 0;
}

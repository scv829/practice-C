#include <stdio.h>

int main()
{
    unsigned int r;
    float area;
    printf("�������� �Է��Ͻÿ� : ");
    scanf("%d",&r);

    area = 3.14*(float)(r*r);
    printf("�������� %d�� ���� ���� : ",r);
    printf("%0.3f",area);

    return 0;
}

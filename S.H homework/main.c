#include <stdio.h>

int main()
{
    int a, b, i, j, max = 0;
    printf("ù��° ���� �Է� : ");
    scanf("%d",&a);
    printf("�ι�° ���� �Է� : ");
    scanf("%d",&b);
    if(a > b){
        int temp = a; a = b; b = temp;
    }
    int arr_a[a], arr_b[b];

    for(i = 1, j = 0 ; i <= a ; i++){
        if(a % i == 0){
            arr_a[j] = i; j++;
        }
    }
    arr_a[j] = 0;
    for(i = 1, j = 0; i <= b ; i++){
        if(b % i == 0){
            arr_b[j] = i; j++;
        }
    }
    arr_b[j] = 0;

    i = 0, j = 0;

    printf("%d �� ��� : ",a);
    while(arr_a[i] != 0){
        printf("%d ",arr_a[i]);
        i++;
    }

    printf("\n%d �� ��� : ",b);
    while(arr_b[j] != 0)
    {
        printf("%d ",arr_b[j]); j++;
    }

    for(i = 0; i <= a ; i++)
    {
        if(arr_a[i] == arr_b[i] && arr_a[i] > max) max = arr_a[i];
    }
    printf("\n%d �� %d �� ��� : %d",a,b,max);

    return 0;
}

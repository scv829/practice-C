#include <stdio.h>
#include <stdlib.h>
#define N 10

void insertList(int list[] , int * length){

    int num, i, pos = 0;
    printf("num �ֱ� \n");
    scanf("%d",&num);

    if(*length != -1)
    {
        for(i = 0 ; i < *length-1 ; i++){
            if(num < list[i]) pos = i;
        }
        for(i = *length ; i >= pos ; i--){
            list[i + 1] = list[i];
        }
    }
    list[pos] = num;
    *length += 1;
}



int main()
{
    int list[N], length = -1;
    printf("��������Ʈ insertList\n");
    insertList(list,&length);
    printf("����");

    return 0;
}

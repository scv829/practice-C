#include <stdio.h>
#include <stdlib.h>
#define N 10

void insertList(int list[] , int * length){

    int num, i, pos = 0;
    printf("num 넣기 \n");
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
    printf("순차리스트 insertList\n");
    insertList(list,&length);
    printf("종료");

    return 0;
}

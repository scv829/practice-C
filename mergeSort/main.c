#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void mergeTwoList(int L[], int temp[], int left, int mid, int right){

    int i, j, k, p;
    i = left; j = mid+1; k=left;
    while (i<=mid && j <=right){
        if (L[i] <= L[j]) temp[k++]=L[i++];
        else temp[k++]=L[j++];
    }
    if (i > mid)
        for(p=j; p<=right; p++) temp[k++]=L[p];
    else
        for(p=i; p<=mid; p++) temp[k++]=L[p];

    for (i = left; i<=right; i++)
        L[i] = temp[i];

    return;

}

void iteratorMerge(int x[], int n){
    int length, temp[MAX], i, j;
    length =1;
    while(length < n) {
        for(i=0; i<=n-2*length; i=i+2*length)
            mergeTwoList(x, temp, i, i+length-1, i+2*length-1);
        if (i+length < n)
            mergeTwoList(x, temp, i, i+length-1, n-1);
        length = length * 2;
    }
    return;
}
int main()
{
    int x[MAX], i;

    srand(time(NULL));

    for(i = 0 ; i < MAX ; i++){
        x[i] = rand()%1000;
    }

    printf("\n\n정렬 전\n\n"); for(i = 0; i < MAX ; i++) { if(i % 10 == 0) printf("\n"); printf("%3d ", x[i]); }
    printf("\n");
    iteratorMerge(x,MAX);

    printf("\n\n정렬 후\n\n"); for(i = 0; i < MAX ; i++) { if(i % 10 == 0) printf("\n"); printf("%3d ", x[i]); }


    return 0;
}

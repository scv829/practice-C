#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void shellSort(int x[], int n){
    int i, j, v, h = 1;

    while(h < n) h = 3*h + 1;

    for(h = h/3 ; h > 0 ; h = h / 3){
        for(i = h ; i < n ; i++){
            v = x[i];
            j = i;
            while( (j - h >= 0) && (x[j-h] > v) ){
                x[j] = x[j-h];
                j = j-h;
            }
            x[j] = v;
        }
    }
}

int partitionList(int x[], int left,int right){
    int pos = x[left];
    int l = left + 1, r = right, temp;

    while(l <= r){
            while( l <= right && x[l] <= pos ) l = l+1;
            while( r > left && x[r] >= pos ) r = r-1;
            if( l < r ){
                temp = x[l];
                x[l] = x[r];
                x[r] = temp;
            }
        }
        x[left] = x[r]; x[r] = pos;
        return (r);
}

void quickSort(int x[],int left, int right){

    int middle, len = right - left;
    if(len <= 20) shellSort(x, len);
        if (left < right){
            middle = partitionList(x, left, right);
            quickSort(x, left, middle-1);
            quickSort(x, middle+1, right);
        }
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
    quickSort(x , 0, MAX - 1);

    printf("\n\n정렬 후\n\n"); for(i = 0; i < MAX ; i++) { if(i % 10 == 0) printf("\n"); printf("%3d ", x[i]); }


    return 0;
}

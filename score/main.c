#include <stdio.h>
int main()
{
    float score[5];
    int i,j;
    float tmp,total = 0;
    printf("5명의 학생 점수를 입력하세요.\n");
    for(i = 0 ; i < 5 ; i++){
        scanf("%f",&score[i]);
        total += score[i];
        if(score[i] < 0 || score[i] > 100) return printf("점수 오류\n");
    }
    float mean = total/5.0;

    for(i = 4 ; i >= 0 ; i--)
        for(j = 0 ; j <= i; j++)
            if(score[j]>score[j+1]){
                tmp = score[j]; score[j] = score[j+1]; score[j+1] = tmp;
            }
    printf("Min = %0.1f Max = %0.1f average = %0.1f\n",score[0],score[4],mean);
    return 0;
}

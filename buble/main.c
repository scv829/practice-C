#include <stdio.h>
int main()
{
    int MAX;
    printf("정렬할 학생의 수 : ");
    scanf("%d",&MAX);
    int id[MAX],kor[MAX],mat[MAX],total[MAX],rank[MAX]; float mean[MAX];
    int i,j,tmp; float tp;

    printf("그 학생의 ID 국어점수 수학점수 순으로 적으시오\n");
    for(i = 0 ; i < MAX ; i++){
        scanf("%d %d %d",&id[i],&kor[i],&mat[i]);
        total[i] = kor[i] + mat[i];
        mean[i] = (float)total[i]/2.0;
    }
    for(i = MAX-2 ; i >= 0; i--){
        for(j = 0 ; j <= i ; j++){
            if(total[j+1] > total[j]){
                tmp = id[j+1]; id[j+1] = id[j]; id[j] = tmp;
                tmp = kor[j+1]; kor[j+1] = kor[j]; kor[j] = tmp;
                tmp = mat[j+1]; mat[j+1] = mat[j]; mat[j] = tmp;
                tmp = total[j+1]; total[j+1] = total[j]; total[j] = tmp;
                tp = mean[j+1]; mean[j+1] = mean[j]; mean[j] = tp;
            }
        }
    }
    rank[0]=1;
    for(i = 0 ; i < MAX ; i++){
        if(total[i] == total[i-1]){
            rank[i] = rank[i-1];}
        else
            rank[i] = i+1;}
    printf("\n결과\n");
    printf("등수 ID 국어점수 수학점수 총합 평균\n");
    for(i = MAX-1 ; i >=0  ; i--)
        printf("%3d %7d %7d %7d %7d %8.2f\n",rank[i],id[i],kor[i],mat[i],total[i],mean[i]);

    return 0;
}

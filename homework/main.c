#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n,i,total = 0;
        float mean = 0;
        printf("입력할 갯수를 적으시오 : ");
        scanf("%d",&n);
        if(n >= 0){
            int str[n];
            printf("원소들을 입력하시오\n");
            for(i = 0; i < n ; i++){
                scanf("%d",&str[i]);
                total += str[i];
            }
            mean = (float)total/(float)n;

            printf("average = %f",mean);
        }
        else if(n < 0)
            printf("입력한 단어로는 함수를 실행할 수 없습니다.");

    return 0;
}

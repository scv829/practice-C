#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n,i,total = 0;
        float mean = 0;
        printf("�Է��� ������ �����ÿ� : ");
        scanf("%d",&n);
        if(n >= 0){
            int str[n];
            printf("���ҵ��� �Է��Ͻÿ�\n");
            for(i = 0; i < n ; i++){
                scanf("%d",&str[i]);
                total += str[i];
            }
            mean = (float)total/(float)n;

            printf("average = %f",mean);
        }
        else if(n < 0)
            printf("�Է��� �ܾ�δ� �Լ��� ������ �� �����ϴ�.");

    return 0;
}

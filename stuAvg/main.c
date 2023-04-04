#include <stdio.h>
#include <stdlib.h>

int intro(int number)
{
    printf("�л��� �Է� : ");
    scanf("%d",&number);
    while( number <= 0)
    {
        if(number <= 0)
        {
            printf("�����Դϴ�. �ٽ� �Է��Ͻÿ�\n");
            printf("�л��� �Է� : ");
            scanf("%d",&number);
        }
    }
    return number;
}

void input_infor(int number, float Aver[], float Sum[], int Rank[]){

    int i;
    float kor,eng,mat;

    for(i = 0 ; i < number ; i++){
        printf("%d���л� ���� : ",i+1);
        scanf("%f",&kor);
        printf("%d���л� ���� : ",i+1);
        scanf("%f",&eng);
        printf("%d���л� ���� : ",i+1);
        scanf("%f",&mat);
        Sum[i] = kor + eng + mat;
        Aver[i] = Sum[i] / (float)3;
        Rank[i] = 1;
        printf("\n");
    }
}

void line_up(int number, float total[], int Rank[])
{
    int i, ranking = 1;

    for(i = 0; i < number; i++){
		if(total[i - 1] == total[i]){
			Rank[i] = Rank[i - 1];
			ranking += 1;
    }
		else
			Rank[i] += ranking;
			ranking = 1;
    }
}

int main()
{
    int students, i,j;

    students = intro(students);

    int rank[students];
    float aver[students], sum[students];

    input_infor(students, aver, sum, rank);

    line_up(students, sum, rank);

    for(i = 0; i < students; i++){
        printf("\n%d���л� : �հ� : %0.2f ��� : %0.2f ��� : %d \n",i+1, sum[i] , aver[i] , rank[i]);
    }
    return 0;
}

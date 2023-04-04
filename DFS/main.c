#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

typedef struct Graph{
    int data;
    struct Graph * link;
}Graph;

//�׷����� ��� �߰��ϴ� �Լ�
void insertNode(Graph ** g, int data){

    //�޸� �Ҵ� temp : �߰��� ��� current : ���� ��� parent : ���� ����� �θ� ���
    Graph* temp = (Graph*)malloc(sizeof(Graph));
    Graph* current = (Graph*)malloc(sizeof(Graph));
    Graph* parent = (Graph*)malloc(sizeof(Graph));
    //�ʱ�ȭ
    parent = current = *g;
    //�߰��� ��� ���� �Է�
    temp->data = data;
    temp->link = NULL;
    //��� �߰�
    if( *g == NULL ){
        *g = temp;
    }
    else{
        //�߰� �� ��ġ ã��
        while(current != NULL){
            parent = current;
            current = current->link;
        }
        parent->link = temp;

    }

    //�Ҵ�� �޸� ��ȯ
    temp = NULL; current = NULL; parent = NULL;
    free(temp);free(current);free(parent);
}

//������ �о �� �������� �׷��� �ʱ�ȭ �ϴ� �Լ�
void dataRoad(Graph * g[], int *maxNum){
    int re; // ���� �д� Ƚ��
    int i;  // �ݺ��� �ʱ� ����
    // ���� ����
    FILE* f = fopen("DFS-Insert-Data-201968038.txt","r");
    // ������ ���� �ִ밪 & ������ �д� Ƚ�� �Է¹ޱ�
    fscanf(f,"%d %d\n",maxNum, &re);
    // g �迭 �ʱ�ȭ
    for(i = 0; i < *maxNum ; i++){ g[i] = NULL; }
    // �� ���� ���� �ޱ�
    for(i = 0; i < re ; i++){
        int start,arrive;                   // ��� ,����
        fscanf(f,"%d %d\n",&start, &arrive);// ��� ,���� ���Ͽ��� �Է� �ޱ�
        insertNode( &g[start] ,arrive);        // �Է¹��� �������� ����߰�
    }
    // ���� �ݱ�
    fclose(f);
}
//DFS ��ȸ �Լ�
void DFS(Graph * g[], int result[], int start, int max){

    int stack[max]; //  ���������� �����ϴ� ����
    int top = -1;   // ������ top
    memset(stack, -1, sizeof(int) * max);// ���� �ʱ�ȭ

    int nowNum = start; // ���� ��ġ�� �˷��ִ� ��
    int insertNum = 1;  // ��� �迭�� ����ִ� ���� ����
    int i = 0;


    result[0] = nowNum; // �������� ������ ���� �ʱ⿡ �־���

    // ���� ���ڰ� �ִ� ������ �� �� ���� �ݺ�
    while(insertNum <= max){
        // temp�� �����Ͽ� ��������Ʈ�� ����
        Graph* temp = g[nowNum];
        // �̹� ������ ���� ���� �ִ��� Ȯ��
        for(i = 0; i < max ; i++){
            // ������ ���̸� ���� ���� ��
            if(result[i] == temp->data){
                temp = temp->link;
                i = -1;
                //�������� �� ��尡 ������ ����
                if(temp == NULL) break;
            }
        }
        // �������� ���� ���� ��
        if(temp != NULL){
            stack[++top] = nowNum;
            nowNum = temp->data;
            result[insertNum++] = nowNum;
        }
        // �̹� ������ ���̰ų� �� �̻� �� ���� ���� ��
        else{
            nowNum = stack[top--];
        }
    }
}
//���� ���� �Լ�
void saveFile(Graph * g[], int result[], int max, int start){

    FILE* f = fopen("DFS-Result-Data-201968038.txt","w");
    int i = 0;
    Graph * temp[N];

    // ���� ����
    fprintf(f,"������ [%d] : DFS��ȸ ���\n",start);
    for(i = 0 ; i < max; i++){
        fprintf(f," %d",result[i]);
        if(i != max - 1) fprintf(f,"->");
    }

    fprintf(f,"\n�׷����� ��������Ʈ\n");
    for( i = 0 ; i < max ; i++ ){
        fprintf(f,"G[%d] : ",i);
        temp[i] = g[i];
        while(temp[i] != NULL){
            fprintf(f,"%d ", temp[i]->data);
            temp[i] = temp[i]->link;
        }
        fprintf(f,"\n");
    }

    fclose(f);
}
int main()
{

    Graph * g[N];
    int maxNum = 0;
    // ���� �ҷ�����
    dataRoad(g, &maxNum);
    //��� �迭 ���� �� �ʱ�ȭ
    int result[maxNum];
    memset(result, -1, sizeof(int) * maxNum);

    int i = 0, start;


    printf("���� ������ ������ �����ּ���[0~%d] : ",maxNum);
    scanf("%d",&start);

    Graph * temp[N];

    printf("\n�׷����� ��������Ʈ\n");
    for( i = 0 ; i < maxNum ; i++ ){
        printf("G[%d] : ",i);
        temp[i] = g[i];
        while(temp[i] != NULL){
            printf("%d ", temp[i]->data);
            temp[i] = temp[i]->link;
        }
        printf("\n");
    }

    DFS(g,result,start,maxNum);

    printf("\nDFS��ȸ ���\n");
    for(i = 0 ; i < maxNum; i++){
        printf(" %d",result[i]);
        if(i != maxNum - 1)printf("->");
    }

    saveFile(g,result,maxNum, start);

    return 0;
}

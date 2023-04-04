#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

typedef struct Graph{
    int data;
    struct Graph * link;
}Graph;

//그래프에 노드 추가하는 함수
void insertNode(Graph ** g, int data){

    //메모리 할당 temp : 추가할 노드 current : 현재 노드 parent : 현재 노드의 부모 노드
    Graph* temp = (Graph*)malloc(sizeof(Graph));
    Graph* current = (Graph*)malloc(sizeof(Graph));
    Graph* parent = (Graph*)malloc(sizeof(Graph));
    //초기화
    parent = current = *g;
    //추가할 노드 정보 입력
    temp->data = data;
    temp->link = NULL;
    //노드 추가
    if( *g == NULL ){
        *g = temp;
    }
    else{
        //추가 할 위치 찾기
        while(current != NULL){
            parent = current;
            current = current->link;
        }
        parent->link = temp;

    }

    //할당된 메모리 반환
    temp = NULL; current = NULL; parent = NULL;
    free(temp);free(current);free(parent);
}

//파일을 읽어서 그 내용으로 그래프 초기화 하는 함수
void dataRoad(Graph * g[], int *maxNum){
    int re; // 파일 읽는 횟수
    int i;  // 반복문 초기 변수
    // 파일 열가
    FILE* f = fopen("DFS-Insert-Data-201968038.txt","r");
    // 데이터 값의 최대값 & 파일을 읽는 횟수 입력받기
    fscanf(f,"%d %d\n",maxNum, &re);
    // g 배열 초기화
    for(i = 0; i < *maxNum ; i++){ g[i] = NULL; }
    // 연 파일 내용 받기
    for(i = 0; i < re ; i++){
        int start,arrive;                   // 출발 ,도착
        fscanf(f,"%d %d\n",&start, &arrive);// 출발 ,도착 파일에서 입력 받기
        insertNode( &g[start] ,arrive);        // 입력받은 내용으로 노드추가
    }
    // 파일 닫기
    fclose(f);
}
//DFS 순회 함수
void DFS(Graph * g[], int result[], int start, int max){

    int stack[max]; //  지나온점을 저장하는 스택
    int top = -1;   // 스택의 top
    memset(stack, -1, sizeof(int) * max);// 스택 초기화

    int nowNum = start; // 현재 위치를 알려주는 수
    int insertNum = 1;  // 결과 배열에 들어있는 수의 갯수
    int i = 0;


    result[0] = nowNum; // 시작점은 무조건 들어가니 초기에 넣어줌

    // 넣은 숫자가 최대 갯수가 될 때 까지 반복
    while(insertNum <= max){
        // temp를 선언하여 인접리스트를 받음
        Graph* temp = g[nowNum];
        // 이미 지나온 점에 값이 있는지 확인
        for(i = 0; i < max ; i++){
            // 지나온 점이면 다음 노드로 감
            if(result[i] == temp->data){
                temp = temp->link;
                i = -1;
                //다음으로 갈 노드가 없으면 정지
                if(temp == NULL) break;
            }
        }
        // 지나가지 않은 점일 때
        if(temp != NULL){
            stack[++top] = nowNum;
            nowNum = temp->data;
            result[insertNum++] = nowNum;
        }
        // 이미 지나간 점이거나 더 이상 갈 곳이 없을 때
        else{
            nowNum = stack[top--];
        }
    }
}
//파일 저장 함수
void saveFile(Graph * g[], int result[], int max, int start){

    FILE* f = fopen("DFS-Result-Data-201968038.txt","w");
    int i = 0;
    Graph * temp[N];

    // 파일 저장
    fprintf(f,"시작점 [%d] : DFS순회 결과\n",start);
    for(i = 0 ; i < max; i++){
        fprintf(f," %d",result[i]);
        if(i != max - 1) fprintf(f,"->");
    }

    fprintf(f,"\n그래프의 인접리스트\n");
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
    // 파일 불러오기
    dataRoad(g, &maxNum);
    //결과 배열 선언 및 초기화
    int result[maxNum];
    memset(result, -1, sizeof(int) * maxNum);

    int i = 0, start;


    printf("시작 지점을 정수로 적어주세요[0~%d] : ",maxNum);
    scanf("%d",&start);

    Graph * temp[N];

    printf("\n그래프의 인접리스트\n");
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

    printf("\nDFS순회 결과\n");
    for(i = 0 ; i < maxNum; i++){
        printf(" %d",result[i]);
        if(i != maxNum - 1)printf("->");
    }

    saveFile(g,result,maxNum, start);

    return 0;
}

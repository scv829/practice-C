#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct vertex{

    int row;
    int col;
    int dir;

}vertex;

//���� top �߰� �Լ�
void insertStack(vertex current, vertex posStack[] , int* top){
    *top = *top+1;
    posStack[*top].row = current.row;
    posStack[*top].col = current.col;
    posStack[*top].dir = current.dir;

    return;
}
//���� top ���� �Լ�
vertex deleteStack(vertex posStack[], int * top){
    vertex temp;
    temp = posStack[*top];
    *top = *top - 1;
    return temp;
}

//���� ������ �Լ�
vertex* upsetStack(vertex posStack[], int top, int MAX){
    int i,j;
    vertex temp[MAX];
    for(i = top,j = 0; i >= 0; i--, j++){
        temp[j] = posStack[i];
    }
    for(i = 0; i <= top; i++){
        posStack[i] = temp[i];
    }

    return posStack;
}
//�� ��� �Լ�
void printWay(vertex posStack[],int top, bool found, int ExitRow, int ExitCol, int MAX){

    FILE* f1 = NULL;
    f1 = fopen("maze-hjs.out", "w");

    if (found == true){
        posStack = upsetStack(posStack, top, MAX);
        int i = 0;
        for(i = top; i >= 0; i--){
            printf("( %2d , %2d )���� %d ��������\n",posStack[i].row, posStack[i].col, posStack[i].dir);
            fprintf(f1,"( %2d , %2d )���� %d ��������\n",posStack[i].row, posStack[i].col, posStack[i].dir );
        }
        printf("�����( %2d , %2d ) ����\n",ExitRow,ExitCol);
        fprintf(f1,"�����( %2d , %2d ) ����\n",ExitRow,ExitCol);
        posStack = upsetStack(posStack, top, MAX);
    }
    else printf("\�Ա����� �ٱ����� ��ξ���\n");

    fclose(f1);

}
//���� �Լ�
int main()
{

    FILE* f1 = NULL;
    f1 = fopen("maze-hjs.map", "r");

    if (f1 == NULL) printf("no file");
    int i = 0, j = 0, num, MAX;
    int Row , Col;

    fscanf(f1," %d %d",&Row, &Col);

    MAX = Row * Col;

    int maze[Row][Col] = {0};
    int mark[Row][Col] = {0};

    for(i = 0; i < Row; i++){
        for(j = 0; j < Col; j++){
            fscanf(f1,"%d",&num);
            maze[i][j] = num;
        }
    }

    fclose(f1);
    printf("\n�̷�\n");
    for(i = 0; i < Row ; i++){
        for(j = 0; j < Col; j++) printf("%d ",maze[i][j]);
        printf("\n");
    }

    int move[8][2] = {  {-1, 0 }, {-1, 1 },
                        { 0, 1 }, { 1, 1 },
                        { 1, 0 }, { 1, -1},
                        { 0, -1}, { 1, -1}};

    vertex current; // ������ġ
    vertex posStack[MAX]; // ������ �� ����ϴ� ����
    current.row = 1; current.col = 1; current.dir = 0; // ������ġ ����
    int top = -1, nextRow, nextCol, ExitRow = Row - 2, ExitCol = Col - 2; // ž, ���� ��, ���� ��, ���� ��, ���� ��
    bool found = false; //found : �������� �����ߴ��� Ȯ���ϴ� ����

    insertStack(current, posStack, &top); // ���� ����ġ ����

    while(top >= 0 && found == false){
        current = deleteStack(posStack, &top);
        while(current.dir < 8 && found == false){
            nextRow = current.row + move[current.dir][0];
            nextCol = current.col + move[current.dir][1];
            if(nextRow == ExitRow && nextCol == ExitCol) found = true;
            if(maze[nextRow][nextCol] == 0 && mark[nextRow][nextCol] == 0){
                mark[nextRow][nextCol] = 1;
                insertStack(current, posStack, &top);
                current.row = nextRow; current.col = nextCol; current.dir = 0;
            }
            else current.dir += 1;
        }

    }

    printWay(posStack, top, found, ExitRow, ExitCol, MAX);


    return 0;
}

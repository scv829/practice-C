#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// 일반적으로 실핼 후 종료하면 한번씩 저장이 안되서 599~646 라인을 디버깅설정 후 디버깅 모드로 하면 저장이 됩니다.

typedef struct student{
    int key;                // 학번
    char name[20];          // 이름
    char residence[2][20];  // 거주지 [0] : 도 , [1] : 시
    float score;            // 점수
    struct student * left;  // 왼쪽 자식 노드
    struct student * right; // 오른쪽 자식 노드

}student;

typedef struct queue{
    student* data;
    struct queue * link;   // 다음 노드

}queue;

typedef struct queueType{
	struct queue *front;
	struct queue *rear; // 큐 처음 | 끝
}queueType;


void init(queueType *q){ q->front = q->rear = NULL;}
int is_empty(queueType *q){ return (q->front == NULL); } // 큐가 비어있는지 확인
int is_full(queueType *q){ return 0;}                      // 큐가 포화되었는지 확인
void error(char *message) {fprintf(stderr, "%s\n", message);exit(1);} // 오류메세지 출력

void insert(); // 추가함수
void nodeInsert(int key, char name[], char residence1[], char residence2[], float score); //노드 추가 함수

void Delete(); //삭제함수
void nodeDelete(int choice); //노드 삭제 함수

void update(); // 갱신(수정)함수

void retrival(); // 탐색함수
student* searchKey(int key, student *t); // 학번으로 검색
void searchName(char name[], student *t); // 이름으로 검색
void searchResidence(char residence1[], char residenec2[], student *t , int state); // 주소지로 검색
void searchScore(float score, student *t, int state); // 점수로 검색
void printInf(student *t); // 검색 결과 출력

void retrivelAll(); // 전체 확인 함수
void dataLoading(); // 파일 읽기 함수

void quit(); //종료 함수(파일 저장 함수)
void levelOrder(); // 레벨순회
void enqueue(queueType *q, student* s); // 큐 추가함수
student* dequeue(queueType *q); // 큐 삭제함수

void inorderTraversal(student *t); // 중위순회

student* root = NULL; // root
int num = 0;          // 학생 수
int repeatCount = 0;  // 검색할 때 일치하는 항목을 찾은 횟수


int main() { //메인함수
    char ch;

    dataLoading();

    do {
        system("cls");
        printf("\n----------------------------------------\n");
        printf(" 정보 관리 시스템 \n");
        printf("----------------------------------------\n");
        printf(" 1. 검색(Retrieval) ('1')\n");
        printf(" 2. 갱신(update)) ('2')\n");
        printf(" 3. 추가(Insert)('3')\n");
        printf(" 4. 삭제(Delete) ('4')\n");
        printf(" 5. 전체조회(Sort List)('5')\n");
        printf(" 6. 종료(Quit) ('q') \n");
        printf("----------------------------------------\n");
        printf("\n\n 원하시는 서비스를 선택하세요. ");
        ch = getche();
        getche();
        switch (ch){
            case '1' : system("cls"); retrival(); break;
            case '2' : system("cls"); update(); break;
            case '3' : system("cls"); insert(); break;
            case '4' : system("cls"); Delete(); break;
            case '5' : system("cls"); retrivelAll(); break;
            case 'q' : system("cls"); quit(); break;
            default : system("cls");
                printf("\n\n 키를 잘못 입력했습니다.\n");
                printf(" 화면의 설명을 보신 후,");
                printf(" '1'~'5' 또는 'q'를 입력해 주세요 \n\n");
        }
    } while (ch != 'q') ;
}


void insert(){ // 추가함수

    int key;
    float score;
    char name[20];
    char residence1[50];
    char residence2[50];

    printf("===============================\n");
    printf("추가하실 학생의 정보를 입력하세요\n");
    printf("학번 : ");                        scanf("%d",&key);
    printf("이름 : ");                        scanf("%s",name);
    printf("거주하는 시/도(ex. 전라북도) : ");     scanf("%s",residence1);
    printf("거주하는 시/군/구 (ex. 전주시) :  ");  scanf("%s",residence2);
    printf("성적 : ");                        scanf("%f",&score);

    nodeInsert(key,name,residence1,residence2,score);
    num = num + 1;

    printf("\n 추가 완료\n");
    printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
    char ch;
    ch = getche();
    getche();

}

void nodeInsert(int key, char name[], char residence1[], char residence2[], float score){ //노드 추가 함수

    int dir = 0; // 왼쪽 = 0 , 오른쪽 = 1

    student* temp = (student*)malloc(sizeof(student));
    temp->right = temp->left = NULL;
    temp->key = key;
    strcpy(temp->name, name);
    strcpy(temp->residence[0], residence1);
    strcpy(temp->residence[1], residence2);
    temp->score = score;

    if(root == NULL){
        root = temp;
    }
    else{
        student* parents = (student*)malloc(sizeof(student));
        student* current = (student*)malloc(sizeof(student));
        parents = current = root;

        while(current != NULL){
            if(current->key >= temp->key){
                parents = current;
                current = current->left;
                dir = 0;
            }
            else {
                parents = current;
                current = current->right;
                dir = 1;
            }
        }
        if(dir == 0){
            parents->left = temp;
        }
        else {
            parents->right = temp;
        }
    }

    temp = NULL;
    free(temp);

}

void Delete(){ //삭제함수

    if(root == NULL){
        printf("\n등록된 학생이 없습니다\n");
        printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
        char ch;
        ch = getche();
        getche();

        return;
    }

    printf("등록되있는 총 학생 수 : %d\n", num);
    inorderTraversal(root);

    int choice = 0;

    printf("\n===========\n");
    printf("삭제하고 싶은 학생의 학번을 입력하세요 : "); scanf("%d",&choice);

    nodeDelete(choice);

    printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
    char ch;
    ch = getche();
    getche();

}

void nodeDelete(int choice){ //노드 삭제 함수

    student* parents = (student*)malloc( sizeof(student) );
    student* current = (student*)malloc(sizeof(student));
    student* key_node = (student*)malloc(sizeof(student));
    parents = current = root;

    int dir = 0; // 왼쪽 = 0 , 오른쪽 = 1

    key_node = searchKey(choice,root);

    if(key_node == NULL){
        printf("\n=================\n");
        printf("일치하는 학번이 없습니다.");
        printf("\n=================\n");
        return;
    }
    else{
    while(current != key_node){
        if(current->key >= choice){
            parents = current;
            current = current->left;
            dir = 0;
        }
        else {
            parents = current;
            current = current->right;
            dir = 1;
        }
    }

    if(key_node->left == NULL && key_node->right == NULL){
        if(key_node == root){ root = NULL; }
        else{
            if(dir == 0) parents->left = NULL;
            else parents->right = NULL;
        }
    }
    else if( (key_node->left == NULL && key_node->right != NULL) ){
        if(key_node == root){ root = key_node->right; }
        else{
            if(dir == 0) parents->left = key_node->right;
            else parents->right = key_node->right;
        }
    }
    else if( (key_node->left != NULL && key_node->right == NULL) ){
        if(key_node == root){ root = key_node->left; }
        else{
            if(dir == 0) parents->left = key_node->left;
            else parents->right = key_node->left;
        }
    }
    else{
        int lmax, rmin;
        student* Lparents = (student*)malloc( sizeof(student) );
        student* Rparents = (student*)malloc( sizeof(student) );
        student* Lcurrent = (student*)malloc( sizeof(student) );
        student* Rcurrent = (student*)malloc( sizeof(student) );

        Lparents = Rparents = root;
        Lcurrent = key_node->left;
        while(Lcurrent -> right != NULL){
            Lparents = Lcurrent;
            Lcurrent = Lcurrent->right;
        }
        while(current != key_node){
            if(current->key >= choice){
                parents = current;
                current = current->left;
                dir = 0;
            }
            else {
                parents = current;
                current = current->right;
                dir = 1;
            }
        }

        if(key_node->left == NULL && key_node->right == NULL){
            if(key_node == root){ root = NULL; }
            else{
                if(dir == 0) parents->left = NULL;
                else parents->right = NULL;
            }
        }
        else if( (key_node->left == NULL && key_node->right != NULL) ){
            if(key_node == root){ root = key_node->right; }
            else{
                if(dir == 0) parents->left = key_node->right;
                else parents->right = key_node->right;
            }
        }
        else if( (key_node->left != NULL && key_node->right == NULL) ){
            if(key_node == root){ root = key_node->left; }
            else{
                if(dir == 0) parents->left = key_node->left;
                else parents->right = key_node->left;
            }
        }
        else{
            int lmax, rmin;
            student* Lparents = (student*)malloc( sizeof(student) );
            student* Rparents = (student*)malloc( sizeof(student) );
            student* Lcurrent = (student*)malloc( sizeof(student) );
            student* Rcurrent = (student*)malloc( sizeof(student) );


            lmax = Lcurrent->key;
            Rcurrent = key_node->right;
            while(Rcurrent -> left != NULL){
                Rparents = Rcurrent;
                Rcurrent = Rcurrent->left;
            }
            rmin = Rcurrent->key;

            if( (key_node->key - lmax) <= (rmin - key_node->key) ){
                if(Lparents == root){
                    if(Lcurrent->left != NULL) Lparents->left = Lcurrent->left;
                    else Lparents->left = NULL;
                }
                else{
                    if(Lcurrent->left != NULL) Lparents->right = Lcurrent->left;
                    else Lparents->right = NULL;
                }
                key_node->key = Lcurrent->key;
                strcpy(key_node->name ,Lcurrent->name);
                strcpy(key_node->residence[0], Lcurrent->residence[0]);
                strcpy(key_node->residence[1], Lcurrent->residence[1]);
                key_node->score = Lcurrent->score;
            }
            else{
                if(Rparents == root){
                    if(Rcurrent->right != NULL) Rparents->right = Rcurrent->right;
                    else Rparents->right = NULL;
                }
                else {
                    if(Rcurrent->right != NULL) Rparents->left = Rcurrent->right;
                    else Rparents->left = NULL;
                }
                key_node->key = Rcurrent->key;
                strcpy(key_node->name ,Rcurrent->name);
                strcpy(key_node->residence[0], Rcurrent->residence[0]);
                strcpy(key_node->residence[1], Rcurrent->residence[1]);
                key_node->score = Rcurrent->score;

            }
            Rparents = Rcurrent = Lcurrent = Lparents = NULL;
            free(Rparents);
            free(Rcurrent);
            free(Lcurrent);
            free(Lparents);
        }
    }
    parents = current = key_node = NULL;
    free(parents);
    free(current);
    free(key_node);
    num = num - 1;
    printf("\n삭제 완료\n");
    }
}

void update(){ // 갱신(수정)함수

    if(root == NULL){
        printf("\n등록된 학생이 없습니다\n");
        printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
        char ch;
        ch = getche();
        getche();

        return;
    }

    printf("등록되있는 총 학생 수 : %d\n", num);
    inorderTraversal(root);

    int choice = 0, studentNum = 0;
    student *t = (student*)malloc(sizeof(student));

    printf("\n===========\n");
    printf("수정하고 싶은 학생의 학번을 입력하세요 : "); scanf("%d",&studentNum);

    t = searchKey(studentNum,root);

    if(t == NULL){
        system("cls");
        printf("\n===================================\n");
        printf("[학번 : %9d]과 일치하는 학번이 없습니다.", studentNum);
        printf("\n===================================\n");
    }
    else{
        printf("\n=================\n");
        printf("\n1. 이름 \n2. 주소지 \n3. 점수\n");

        printf("\n수정하고 싶은 항목을 선택하세요 : "); scanf("%d",&choice);

        printf("\n[선택한 학번 : %9d]\n", t->key);

        switch(choice){
            case 1:{
                char name[20];
                printf("\n===================================\n");
                printf("변경 전 이름 : %s\n",t->name);
                printf("\n변경 할 이름을 적어주세요 : "); scanf("%s",name);
                strcpy(t->name, name);
                printf("\n수정 완료\n");
                break;
            }
            case 2:{
                char residence1[50], residence2[50];
                printf("\n===================================\n");
                printf("변경 전 주소지 : %s %s\n",t->residence[0], t->residence[1]);
                printf("\n입력을 넘기고 싶은면 -1을 입력하세요\n");
                printf("변경 할 거주지의 시/도(ex. 전라북도)를 입력하세요: "); scanf("%s",residence1);
                printf("변경 할 거주지의 시/군/구 (ex. 전주시)를 입력하세요: "); scanf("%s",residence2);

                if( strcmp(residence1, "-1") != 0 && strcmp(residence2, "-1") != 0 ) {
                    strcpy(t->residence[0], residence1); strcpy(t->residence[1], residence2);
                    printf("\n수정 완료\n");
                }
                else if( strcmp(residence1, "-1") != 0 && strcmp(residence2, "-1") == 0 ){ strcpy(t->residence[0], residence1);  printf("\n수정 완료\n");}
                else if( strcmp(residence1, "-1") == 0 && strcmp(residence2, "-1") != 0 ){ strcpy(t->residence[1], residence2);  printf("\n수정 완료\n");}
                else printf("내용을 변경하지 않았습니다.");

                break;
            }
            case 3:{
                float score;
                printf("\n===================================\n");
                printf("변경 전 성적 : %3.1f\n",t->score);
                printf("변경 할 성적을 적어주세요 : "); scanf("%f",&score);
                t->score = score;
                printf("\n수정 완료\n");
                break;
            }
            default :
                printf("\n입력 오류\n");
            }
        }

    printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
    char ch;
    ch = getche();
    getche();
}

void retrival(){ // 탐색함수
    int choice = -1;
    int state;

    if(root == NULL){
        system("cls");
        printf("\n등록된 학생이 없습니다\n");
        printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
        char ch;
        ch = getche();
        getche();

        return;
    }

    printf("1. 학번 \n2. 이름 \n3. 거주지 \n4. 성적\n");
    printf("찾고싶은 정보를 선택하세요.\n"); scanf("%d",&choice);
    switch(choice){
        case 1:{
            int key;
            printf("찾고싶은 학번을 입력하세요 : "); scanf("%d",&key);
            repeatCount = 0;
            student *t = (student*)malloc(sizeof(student));
            t = searchKey(key,root);

            if(repeatCount == 0) printf("일치하는 학번이 없습니다");
            else{
                printf("\n[학번 : %d] 로 찾은 결과\n",key);
                printInf(t);
            }
            t = NULL;
            free(t);
            break;
        }
        case 2:{
            char name[20];
            printf("찾고싶은 이름을 입력하세요 : "); scanf("%s",name);
            repeatCount = 0;
            searchName(name,root);
            if(repeatCount == 0) printf("일치하는 이름이 없습니다");

            break;
        }
        case 3:{
            char residence1[50], residence2[50];
            printf("\n입력을 넘기고 싶은면 -1을 입력하세요\n");
            printf("찾고싶은 사람의 거주지의 시/도(ex. 전라북도)를 입력하세요: "); scanf("%s",residence1);
            printf("찾고싶은 사람의 거주지의 시/군/구 (ex. 전주시)를 입력하세요: "); scanf("%s",residence2);

            if( strcmp(residence1, "-1") == 0 && strcmp(residence2, "-1") == 0 ) state = 0;
            else if( strcmp(residence1, "-1") != 0 && strcmp(residence2, "-1") == 0 ) state = 1;
            else if( strcmp(residence1, "-1") == 0 && strcmp(residence2, "-1") != 0 ) state = 2;
            else state = 3;

            repeatCount = 0;

            searchResidence(residence1, residence2, root , state);
            if(repeatCount == 0) printf("일치하는 거주지가 없습니다");

            break;
        }
        case 4:{
            float score;
            printf("찾고싶은 성적을 입력하세요 : "); scanf("%f",&score);
            printf("\n찾고싶은 방법\n");
            printf("1. [%3.1f]와 일치한 점수 \n2. [%3.1f]보다 이상인 점수 \n3. [%3.1f]보다 이하인 점수 \n4. [%3.1f]보다 초과인 점수 \n5. [%3.1f]보다 미만이 점수 ", score, score, score, score, score);
            scanf("%d",&state);

            repeatCount = 0;
            searchScore(score,root,state);
            if(repeatCount == 0) printf("조건에 맞는 성적이 없습니다");

            break;
        }
        default :
            printf("\n입력 오류\n");
    }

    printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
    char ch;
    ch = getche();
    getche();
}

void retrivelAll(){ // 전체 확인 함수

    if(root == NULL){
        system("cls");
        printf("\n등록된 학생이 없습니다\n");
        printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
        char ch;
        ch = getche();
        getche();

        return;
    }

    printf("등록되있는 총 학생 수 : %d\n", num);
    inorderTraversal(root);
    printf("\n\n 메뉴로 돌아가시려면 아무키나 눌러주세요.");
    char ch;
    ch = getche();
    getche();
}


void dataLoading(){ // 파일 읽기 함수

    FILE* f = fopen("studentData-201968038.dat","r");

    int i;
    int key;
    float score;
    char name[20];
    char residence1[50];
    char residence2[50];

    fscanf(f,"%d\n",&num);
    for(i = 0; i < num; i++){
        fscanf(f,"%d %s %s %s %f\n",&key, name, residence1, residence2, &score);
        nodeInsert(key,name,residence1,residence2,score);
    }

    fclose(f);
}

void quit(){ //종료 함수(파일 저장 함수)

    levelOrder();
}

void levelOrder() { // 레벨순회
    int i;
    int key;
    float score;
    char name[20];
    char residence1[20];
    char residence2[20];

	queueType *q;


    student* t = (student*)malloc(sizeof(student));

    FILE* f = fopen("studentData-201968038.dat","w");

    fprintf(f,"%d\n",num);
    init(q);
	if (!root) return;
	enqueue(q, root);
	while( !is_empty(q) ) {
		t = dequeue(q);
		fprintf(f,"%d %s %s %s %0.0f\n",t->key,t->name,t->residence[0],t->residence[1],t->score);
		if (t->left)
			enqueue(q, t->left);
		if (t->right)
			enqueue(q, t->right);
	}
	t = NULL;
	free(t);
	fclose(f);
}

void enqueue(queueType *q, student* s) { // 큐 추가함수
	queue *t = (queue*)malloc(sizeof(queue));

    t->data = s;
    t->link = NULL;

    if ( is_empty(q) ) {
        q->front = t;
        q->rear = t;
    }
    else {
        q->rear->link = t;
        q->rear = t;
    }
}

student* dequeue(queueType *q)  // 큐 삭제함수
{
	queue *t = q->front;
	student* temp;
	if (is_empty(q))
		error("큐가 비어 있읍니다");
	else {
		temp = t->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
        t = NULL;
		free(t);
		return temp;
	}
}

student* searchKey(int key, student *t){ // 학번으로 검색

    if( t == NULL ) return NULL;
    if(t->key == key){
        repeatCount = repeatCount + 1;
        return t;
    }
    if (t->key > key) return searchKey(key,t->left);
    return searchKey(key,t->right);

}

void searchName(char name[], student *t){ // 이름으로 검색

    if(t == NULL ) return;
    searchName(name,t->left);
    if( strcmp(t->name ,name) == 0 ){
        printInf(t);
        repeatCount = repeatCount + 1;
    }
    searchName(name,t->right);

}

void searchResidence(char residence1[], char residence2[], student *t , int state){ // 주소지로 검색

    if( state == 0 ){
        inorderTraversal(t);
    }
    else{
        if(t == NULL ) return;
        searchResidence(residence1, residence2, t->left, state);
        if(state == 1){
            if( strcmp(t->residence[0] ,residence1) == 0 ){
                printInf(t);
                repeatCount = repeatCount + 1;
            }
        }
        else if(state == 2){
            if( strcmp(t->residence[1], residence2 ) == 0 ){
                printInf(t);
                repeatCount = repeatCount + 1;
            }
        }
        else {
            if( strcmp(residence1, t->residence[0] ) == 0 && strcmp(residence2, t->residence[1] ) == 0 )
            {
                    printInf(t);
                    repeatCount = repeatCount + 1;
            }
        }
        searchResidence(residence1,residence2, t->right, state);
    }
}

void searchScore(float score, student *t, int state){ // 점수로 검색

    if(t == NULL ) return;
    searchScore(score, t->left, state);

    if(state == 1 && t->score == score){
        printInf(t);
        repeatCount = repeatCount + 1;
    }
    else if(state == 2 && t->score >= score ){
        printInf(t);
        repeatCount = repeatCount + 1;
    }
    else if(state == 3 && t->score <= score ){
        printInf(t);
        repeatCount = repeatCount + 1;
    }
    else if (state == 4 && t->score > score ){
        printInf(t);
        repeatCount = repeatCount + 1;
    }
    else if (state == 5 && t->score < score ){
        printInf(t);
        repeatCount = repeatCount + 1;
    }
    else return;

    searchScore(score,t->right,state);
}

void printInf(student *t){ // 검색 결과 출력
    printf("==========================================\n");
    printf("학번: %9d | 이름: %s\n",t->key, t->name);
    printf("거주지: %s %s\n",t->residence[0], t->residence[1]);
    printf("성적: %3.1f\n",t->score);
}


void inorderTraversal(student *t){ // 중위순회
    if(t == NULL ) return;
    inorderTraversal(t->left);
    printInf(t);
    inorderTraversal(t->right);
}

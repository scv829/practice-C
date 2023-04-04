#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// �Ϲ������� ���� �� �����ϸ� �ѹ��� ������ �ȵǼ� 599~646 ������ ����뼳�� �� ����� ���� �ϸ� ������ �˴ϴ�.

typedef struct student{
    int key;                // �й�
    char name[20];          // �̸�
    char residence[2][20];  // ������ [0] : �� , [1] : ��
    float score;            // ����
    struct student * left;  // ���� �ڽ� ���
    struct student * right; // ������ �ڽ� ���

}student;

typedef struct queue{
    student* data;
    struct queue * link;   // ���� ���

}queue;

typedef struct queueType{
	struct queue *front;
	struct queue *rear; // ť ó�� | ��
}queueType;


void init(queueType *q){ q->front = q->rear = NULL;}
int is_empty(queueType *q){ return (q->front == NULL); } // ť�� ����ִ��� Ȯ��
int is_full(queueType *q){ return 0;}                      // ť�� ��ȭ�Ǿ����� Ȯ��
void error(char *message) {fprintf(stderr, "%s\n", message);exit(1);} // �����޼��� ���

void insert(); // �߰��Լ�
void nodeInsert(int key, char name[], char residence1[], char residence2[], float score); //��� �߰� �Լ�

void Delete(); //�����Լ�
void nodeDelete(int choice); //��� ���� �Լ�

void update(); // ����(����)�Լ�

void retrival(); // Ž���Լ�
student* searchKey(int key, student *t); // �й����� �˻�
void searchName(char name[], student *t); // �̸����� �˻�
void searchResidence(char residence1[], char residenec2[], student *t , int state); // �ּ����� �˻�
void searchScore(float score, student *t, int state); // ������ �˻�
void printInf(student *t); // �˻� ��� ���

void retrivelAll(); // ��ü Ȯ�� �Լ�
void dataLoading(); // ���� �б� �Լ�

void quit(); //���� �Լ�(���� ���� �Լ�)
void levelOrder(); // ������ȸ
void enqueue(queueType *q, student* s); // ť �߰��Լ�
student* dequeue(queueType *q); // ť �����Լ�

void inorderTraversal(student *t); // ������ȸ

student* root = NULL; // root
int num = 0;          // �л� ��
int repeatCount = 0;  // �˻��� �� ��ġ�ϴ� �׸��� ã�� Ƚ��


int main() { //�����Լ�
    char ch;

    dataLoading();

    do {
        system("cls");
        printf("\n----------------------------------------\n");
        printf(" ���� ���� �ý��� \n");
        printf("----------------------------------------\n");
        printf(" 1. �˻�(Retrieval) ('1')\n");
        printf(" 2. ����(update)) ('2')\n");
        printf(" 3. �߰�(Insert)('3')\n");
        printf(" 4. ����(Delete) ('4')\n");
        printf(" 5. ��ü��ȸ(Sort List)('5')\n");
        printf(" 6. ����(Quit) ('q') \n");
        printf("----------------------------------------\n");
        printf("\n\n ���Ͻô� ���񽺸� �����ϼ���. ");
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
                printf("\n\n Ű�� �߸� �Է��߽��ϴ�.\n");
                printf(" ȭ���� ������ ���� ��,");
                printf(" '1'~'5' �Ǵ� 'q'�� �Է��� �ּ��� \n\n");
        }
    } while (ch != 'q') ;
}


void insert(){ // �߰��Լ�

    int key;
    float score;
    char name[20];
    char residence1[50];
    char residence2[50];

    printf("===============================\n");
    printf("�߰��Ͻ� �л��� ������ �Է��ϼ���\n");
    printf("�й� : ");                        scanf("%d",&key);
    printf("�̸� : ");                        scanf("%s",name);
    printf("�����ϴ� ��/��(ex. ����ϵ�) : ");     scanf("%s",residence1);
    printf("�����ϴ� ��/��/�� (ex. ���ֽ�) :  ");  scanf("%s",residence2);
    printf("���� : ");                        scanf("%f",&score);

    nodeInsert(key,name,residence1,residence2,score);
    num = num + 1;

    printf("\n �߰� �Ϸ�\n");
    printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
    char ch;
    ch = getche();
    getche();

}

void nodeInsert(int key, char name[], char residence1[], char residence2[], float score){ //��� �߰� �Լ�

    int dir = 0; // ���� = 0 , ������ = 1

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

void Delete(){ //�����Լ�

    if(root == NULL){
        printf("\n��ϵ� �л��� �����ϴ�\n");
        printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
        char ch;
        ch = getche();
        getche();

        return;
    }

    printf("��ϵ��ִ� �� �л� �� : %d\n", num);
    inorderTraversal(root);

    int choice = 0;

    printf("\n===========\n");
    printf("�����ϰ� ���� �л��� �й��� �Է��ϼ��� : "); scanf("%d",&choice);

    nodeDelete(choice);

    printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
    char ch;
    ch = getche();
    getche();

}

void nodeDelete(int choice){ //��� ���� �Լ�

    student* parents = (student*)malloc( sizeof(student) );
    student* current = (student*)malloc(sizeof(student));
    student* key_node = (student*)malloc(sizeof(student));
    parents = current = root;

    int dir = 0; // ���� = 0 , ������ = 1

    key_node = searchKey(choice,root);

    if(key_node == NULL){
        printf("\n=================\n");
        printf("��ġ�ϴ� �й��� �����ϴ�.");
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
    printf("\n���� �Ϸ�\n");
    }
}

void update(){ // ����(����)�Լ�

    if(root == NULL){
        printf("\n��ϵ� �л��� �����ϴ�\n");
        printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
        char ch;
        ch = getche();
        getche();

        return;
    }

    printf("��ϵ��ִ� �� �л� �� : %d\n", num);
    inorderTraversal(root);

    int choice = 0, studentNum = 0;
    student *t = (student*)malloc(sizeof(student));

    printf("\n===========\n");
    printf("�����ϰ� ���� �л��� �й��� �Է��ϼ��� : "); scanf("%d",&studentNum);

    t = searchKey(studentNum,root);

    if(t == NULL){
        system("cls");
        printf("\n===================================\n");
        printf("[�й� : %9d]�� ��ġ�ϴ� �й��� �����ϴ�.", studentNum);
        printf("\n===================================\n");
    }
    else{
        printf("\n=================\n");
        printf("\n1. �̸� \n2. �ּ��� \n3. ����\n");

        printf("\n�����ϰ� ���� �׸��� �����ϼ��� : "); scanf("%d",&choice);

        printf("\n[������ �й� : %9d]\n", t->key);

        switch(choice){
            case 1:{
                char name[20];
                printf("\n===================================\n");
                printf("���� �� �̸� : %s\n",t->name);
                printf("\n���� �� �̸��� �����ּ��� : "); scanf("%s",name);
                strcpy(t->name, name);
                printf("\n���� �Ϸ�\n");
                break;
            }
            case 2:{
                char residence1[50], residence2[50];
                printf("\n===================================\n");
                printf("���� �� �ּ��� : %s %s\n",t->residence[0], t->residence[1]);
                printf("\n�Է��� �ѱ�� ������ -1�� �Է��ϼ���\n");
                printf("���� �� �������� ��/��(ex. ����ϵ�)�� �Է��ϼ���: "); scanf("%s",residence1);
                printf("���� �� �������� ��/��/�� (ex. ���ֽ�)�� �Է��ϼ���: "); scanf("%s",residence2);

                if( strcmp(residence1, "-1") != 0 && strcmp(residence2, "-1") != 0 ) {
                    strcpy(t->residence[0], residence1); strcpy(t->residence[1], residence2);
                    printf("\n���� �Ϸ�\n");
                }
                else if( strcmp(residence1, "-1") != 0 && strcmp(residence2, "-1") == 0 ){ strcpy(t->residence[0], residence1);  printf("\n���� �Ϸ�\n");}
                else if( strcmp(residence1, "-1") == 0 && strcmp(residence2, "-1") != 0 ){ strcpy(t->residence[1], residence2);  printf("\n���� �Ϸ�\n");}
                else printf("������ �������� �ʾҽ��ϴ�.");

                break;
            }
            case 3:{
                float score;
                printf("\n===================================\n");
                printf("���� �� ���� : %3.1f\n",t->score);
                printf("���� �� ������ �����ּ��� : "); scanf("%f",&score);
                t->score = score;
                printf("\n���� �Ϸ�\n");
                break;
            }
            default :
                printf("\n�Է� ����\n");
            }
        }

    printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
    char ch;
    ch = getche();
    getche();
}

void retrival(){ // Ž���Լ�
    int choice = -1;
    int state;

    if(root == NULL){
        system("cls");
        printf("\n��ϵ� �л��� �����ϴ�\n");
        printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
        char ch;
        ch = getche();
        getche();

        return;
    }

    printf("1. �й� \n2. �̸� \n3. ������ \n4. ����\n");
    printf("ã����� ������ �����ϼ���.\n"); scanf("%d",&choice);
    switch(choice){
        case 1:{
            int key;
            printf("ã����� �й��� �Է��ϼ��� : "); scanf("%d",&key);
            repeatCount = 0;
            student *t = (student*)malloc(sizeof(student));
            t = searchKey(key,root);

            if(repeatCount == 0) printf("��ġ�ϴ� �й��� �����ϴ�");
            else{
                printf("\n[�й� : %d] �� ã�� ���\n",key);
                printInf(t);
            }
            t = NULL;
            free(t);
            break;
        }
        case 2:{
            char name[20];
            printf("ã����� �̸��� �Է��ϼ��� : "); scanf("%s",name);
            repeatCount = 0;
            searchName(name,root);
            if(repeatCount == 0) printf("��ġ�ϴ� �̸��� �����ϴ�");

            break;
        }
        case 3:{
            char residence1[50], residence2[50];
            printf("\n�Է��� �ѱ�� ������ -1�� �Է��ϼ���\n");
            printf("ã����� ����� �������� ��/��(ex. ����ϵ�)�� �Է��ϼ���: "); scanf("%s",residence1);
            printf("ã����� ����� �������� ��/��/�� (ex. ���ֽ�)�� �Է��ϼ���: "); scanf("%s",residence2);

            if( strcmp(residence1, "-1") == 0 && strcmp(residence2, "-1") == 0 ) state = 0;
            else if( strcmp(residence1, "-1") != 0 && strcmp(residence2, "-1") == 0 ) state = 1;
            else if( strcmp(residence1, "-1") == 0 && strcmp(residence2, "-1") != 0 ) state = 2;
            else state = 3;

            repeatCount = 0;

            searchResidence(residence1, residence2, root , state);
            if(repeatCount == 0) printf("��ġ�ϴ� �������� �����ϴ�");

            break;
        }
        case 4:{
            float score;
            printf("ã����� ������ �Է��ϼ��� : "); scanf("%f",&score);
            printf("\nã����� ���\n");
            printf("1. [%3.1f]�� ��ġ�� ���� \n2. [%3.1f]���� �̻��� ���� \n3. [%3.1f]���� ������ ���� \n4. [%3.1f]���� �ʰ��� ���� \n5. [%3.1f]���� �̸��� ���� ", score, score, score, score, score);
            scanf("%d",&state);

            repeatCount = 0;
            searchScore(score,root,state);
            if(repeatCount == 0) printf("���ǿ� �´� ������ �����ϴ�");

            break;
        }
        default :
            printf("\n�Է� ����\n");
    }

    printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
    char ch;
    ch = getche();
    getche();
}

void retrivelAll(){ // ��ü Ȯ�� �Լ�

    if(root == NULL){
        system("cls");
        printf("\n��ϵ� �л��� �����ϴ�\n");
        printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
        char ch;
        ch = getche();
        getche();

        return;
    }

    printf("��ϵ��ִ� �� �л� �� : %d\n", num);
    inorderTraversal(root);
    printf("\n\n �޴��� ���ư��÷��� �ƹ�Ű�� �����ּ���.");
    char ch;
    ch = getche();
    getche();
}


void dataLoading(){ // ���� �б� �Լ�

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

void quit(){ //���� �Լ�(���� ���� �Լ�)

    levelOrder();
}

void levelOrder() { // ������ȸ
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

void enqueue(queueType *q, student* s) { // ť �߰��Լ�
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

student* dequeue(queueType *q)  // ť �����Լ�
{
	queue *t = q->front;
	student* temp;
	if (is_empty(q))
		error("ť�� ��� �����ϴ�");
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

student* searchKey(int key, student *t){ // �й����� �˻�

    if( t == NULL ) return NULL;
    if(t->key == key){
        repeatCount = repeatCount + 1;
        return t;
    }
    if (t->key > key) return searchKey(key,t->left);
    return searchKey(key,t->right);

}

void searchName(char name[], student *t){ // �̸����� �˻�

    if(t == NULL ) return;
    searchName(name,t->left);
    if( strcmp(t->name ,name) == 0 ){
        printInf(t);
        repeatCount = repeatCount + 1;
    }
    searchName(name,t->right);

}

void searchResidence(char residence1[], char residence2[], student *t , int state){ // �ּ����� �˻�

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

void searchScore(float score, student *t, int state){ // ������ �˻�

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

void printInf(student *t){ // �˻� ��� ���
    printf("==========================================\n");
    printf("�й�: %9d | �̸�: %s\n",t->key, t->name);
    printf("������: %s %s\n",t->residence[0], t->residence[1]);
    printf("����: %3.1f\n",t->score);
}


void inorderTraversal(student *t){ // ������ȸ
    if(t == NULL ) return;
    inorderTraversal(t->left);
    printInf(t);
    inorderTraversal(t->right);
}

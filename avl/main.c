#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE	100


typedef struct TreeNode{        // 트리 노드 구조체 선언
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TNode;

TNode* data[MAX_QUEUE_SIZE];	// 요소의 배열
int	front;			// 전단
int	rear;			// 후단

void error(char str[])		// 오류 함수
{
	printf("%s\n", str);
	exit(1);
}
// 큐 초기화 함수들
void init_queue() { front = rear = 0; ; }
int is_empty() { return (front == rear); }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }
void levelorder(TNode * n);

int calc_height(TNode *n) // 트리 높이 확인 함수
{
	int hLeft, hRight;
	if( n == NULL ) return 0;

	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);

	return (hLeft>hRight) ? hLeft+1 : hRight+1;
}


TNode* create_node(int data, TNode *l, TNode *r){ // 노드 생성 수함

	TNode*	node = (TNode*)malloc(sizeof(TNode));
	node->data = data;
	node->left = l;
	node->right = r;
	return node;
}

TNode * searchNode( TNode * n , int key , TNode * parent = NULL){ // 노드 확인 함수

        if( key != n->data){
            if( key < n->data ){
                if( n->left != NULL) {
                    searchNode(n->left , key , n);
                }
                else{
                    return n;
                }
            }
            else if(key > n-> data) {
                if( n->right != NULL) {
                    searchNode(n->right , key , n);
                }
                else{
                    return n;
                }
            }
        }
        else if( key == n->data && parent != NULL) return parent;
        else{
            return n;
        }

}

int countBalance(TNode * n ){ // 노드의 균형 인수를 계산하는 함수

	int leftBalance, rightBalance, balance;
    if(n != NULL) {
        leftBalance = calc_height(n-> left);
        rightBalance =  -calc_height(n-> right);
        balance = leftBalance + rightBalance;
    }
    return balance;

}

void insert(TNode * n , int key){ // 노드 삽입 함수

	TNode * parentNode = searchNode(n, key);
	TNode* node = (TNode*)malloc(sizeof(TNode));
    node = create_node(key, NULL, NULL);

    if(parentNode -> data < key){
    	parentNode->right = node;
    	node = NULL;
    	free(node);
	}
	else{
    parentNode -> left = node;
    node = NULL;
    free(node);
	}

}

void rotate_LL(TNode * A , TNode * B, TNode ** root){ // LL 회전

    TNode* node = (TNode*)malloc(sizeof(TNode));
    if(A == *root) {
        A->left = B->right;
        B->right = A;
        (*root) = B;
    }
    else{
        node = searchNode( *root , A ->data , NULL);
        A->left = B->right;
        B->right = A;
        if( node->data < B->data  ) node->right = B;
        else node->left = B;
    }
    node = NULL;
    free(node);
}

void rotate_RR(TNode * A , TNode * B, TNode ** root){ // RR 회전

    TNode* node = (TNode*)malloc(sizeof(TNode));
    if(A == *root) {
        A->right = B->left;
        B->left = A;
        (*root) = B;

    }
    else{
        node = searchNode( *root , A ->data, NULL);
        A->right = B->left;
        B->left = A;
        if( node->data > B->data ) node->left = B;
        else node->right = B;
    }
    node = NULL;
    free(node);
}

void rotate_LR(TNode * A , TNode ** root){ // LR 회전

    rotate_RR(A->left, (A->left)->right, root);
    rotate_LL(A,A->left,root);

}

void rotate_RL(TNode * A ,  TNode ** root){ // RL 회전


    rotate_LL(A->right, (A->right)->left, root);
    rotate_RR(A, A->right, root );

}

void insert_node_AVL(TNode ** root , int key){ // AVL노드 삽입 함수

	insert(*root , key);

	TNode*	node = (TNode*)malloc(sizeof(TNode));
	TNode*	n = (TNode*)malloc(sizeof(TNode));
	node = *root; n = NULL;

	while( node!= NULL ){

        if( countBalance(node) == 2 || countBalance(node) == -2) n = node;

        if( countBalance(node) < 0) node = node->right;
        else if( countBalance(node) > 0) node = node->left;
        else{
            if( node->data > key) node = node->left;
            else node = node->right;
        }
	}

    if(n != NULL){
        if( countBalance(n) == -2 && countBalance(n->right) == -1) rotate_RR(n, n->right , root);
        else if( countBalance(n) == 2 && countBalance(n->left) == 1 ) rotate_LL(n, n->left , root);
        else if( countBalance(n) == -2 && countBalance(n->right) == 1 ) rotate_RL(n, root);
        else rotate_LR(n, root);
    }

	n = NULL; node = NULL;
	free(n); free(node);

}


void enqueue(TNode* val) // 큐 데이터 추가 함수
{
	if (is_full())
		error("  큐 포화 에러");

	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}

TNode* dequeue() // 큐 데이터 추줄 함수
{
	if ( is_empty() )
		error("  큐 공백 에러");

	front = (front + 1) % MAX_QUEUE_SIZE;

	return data[front];
}

TNode* peek() // 큐 맨 앞 읽기 함수
{
	if (is_empty())
		error("  큐 공백 에러");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void levelorder(TNode * n){ // 레벨 회순
	TNode * queue;
	if( n != NULL){
		enqueue(n);
		while( !is_empty() ){
			queue = dequeue();
			if( queue != NULL){
				printf("[%2d] ", queue->data);
				enqueue(queue->left);
				enqueue(queue->right);
			}
		}
	}
}

int count_node(TNode *n) // 노드 개수 확인 함수
{
	if( n == NULL ) return 0;
	return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode *n){ // 단말 노드 개수 확인 함수
	if( n ==  NULL) return 0;
	if(n->left == NULL && n->right == NULL ) return 1;
	else{
		return count_leaf(n->left) + count_leaf(n->right);
	}
}


int main(int argc, char *argv[]) {
	// test_set : 30, 40, 100, 20, 10, 60, 70, 120, 110
	// train_set :  7, 8, 9, 2, 1, 5, 3, 6, 4
	TNode * root = NULL;
	int numList[] = { 30, 40, 100, 20, 10, 60, 70, 120, 110 };
	int i;
	for(i = 0 ; i < 9 ; i++){
		if( root == NULL ) {
			root = create_node(numList[i], NULL , NULL);
		}
		else {
			insert_node_AVL(&root, numList[i]);
		}
		printf("\nAVL(%3d): ",numList[i]); levelorder(root);
	}


	printf("\n 노드의 개수 = %d\n", count_node(root));
	printf(" 단말의 개수 = %d\n", count_leaf(root));
	printf(" 트리의 높이 = %d\n", calc_height(root));


	return 0;
}

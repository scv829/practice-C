#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VTXS 256

typedef int VtxData; // �׷��� ������ ������ �������� �ڷ���
int adj[MAX_VTXS][MAX_VTXS]; // ���� ���
int vsize; // ��ü ������ ����

int front ,rear; // ť�� ���� && ť�� ��
// ť �ʱ�ȭ �Լ���
void init_queue() { front = rear = 0; ; }
int is_empty() { return (front == rear); }
int is_full() { return front == (rear + 1) % MAX_VTXS; }
int size() { return(rear - front + MAX_VTXS) % MAX_VTXS; }


VtxData vdata[MAX_VTXS]; // ������ ������ ������ �迭

typedef struct GraphNode {
	int id; // ������ id
	struct GraphNode* link; // ���� ����� ������
} GNode;

GNode* adj_list[MAX_VTXS]; // ��������Ʈ���� �� ������ ���� ����Ʈ

int visited[MAX_VTXS]; // DFS ����
int queue[MAX_VTXS]; // BFS ť

void init_graph() { // �׷��� �ʱ� ����
	int i, j;
	vsize=0;
	for(i=0 ; i<MAX_VTXS; i++)
		for(j=0 ; j<MAX_VTXS; j++)
			adj[i][j] = 0;
}
void reset_graph(){ // �׷��� �ʱ�ȭ �Լ�
	int i = 0;
	for(i = 0 ; i < MAX_VTXS; i++) adj_list[i] = NULL;
}

int is_full_graph() { return (vsize >= MAX_VTXS); }
int is_empty_graph() { return (vsize == 0); }

int is_full_queue() { return (rear >= MAX_VTXS && front < MAX_VTXS); }
int is_empty_queue() { return (rear < 0 && front < 0); }


void insert_vertex( VtxData name ) { // ���� �߰� �Լ�
	if (is_full_graph()){
		printf("Error: ���� ���� �ʰ�\n");
	}
	else
		vdata[vsize++] = name;
}

void insert_edge(int u, int v) // ���� ����Ʈ �߰� �Լ�
{
		if(adj_list[u] == NULL){
			GNode * temp = (GNode*)malloc(sizeof(GNode));
			temp->id = v; temp->link = NULL;
			adj_list[u] = temp;
			temp = NULL;
			free(temp);
		}
		else{
			GNode * temp = (GNode*)malloc(sizeof(GNode));
			GNode * current = (GNode*)malloc(sizeof(GNode));
			GNode * parent = (GNode*)malloc(sizeof(GNode));
			parent = adj_list[u];
			current = parent->link;
			temp->id = v; temp->link = NULL;
			while(current != NULL){
				if(current->id > temp->id) break;
				else{
					parent = parent->link;
					current = current->link;
				}
			}
			temp->link = parent->link;
			parent->link = temp;
			temp = current = parent = NULL;
			free(temp); free(current); free(parent);
		}
}

void insert_edge2(int u, int v) // ���� �迭 �߰� �Լ�
{
	adj[u][v] = adj[v][u] = 1;
}

void reset_visited() //  ���� �ʱ�ȭ �Լ�
{
	int i;
	for( i=0 ; i<vsize ; i++ )
		visited[i] = 0;
}

void enqueue(int val) // ť ������ �߰� �Լ�
{
	if (is_full()){
		printf("  ť ��ȭ ����");
		exit(1);
	}

	rear = (rear + 1) % MAX_VTXS;
	queue[rear] = val;
}

int dequeue() // ť ������ ���� �Լ�
{
	if ( is_empty() ){
		printf("  ť ���� ����");
		exit(1);
	}
	front = (front + 1) % MAX_VTXS;

	return queue[front];
}

void DFS( int v ) // DFS �Լ�
{
	int w;
	visited[v] = 1;
	printf("%d ", vdata[v]);
	for( w=0 ; w<vsize ; w++)
		if( adj[v][w]!=0 && visited[w]==0 )
			DFS( w );
}


void BFS( int v ) { // BFS �Լ�
	int i = 0;
	GNode *w;
	init_queue();
	visited[v] = 1;
	printf("%d ", vdata[v]);
	enqueue( v );
	while(!is_empty()){
		v = dequeue();
		for( w = adj_list[v] ; w != NULL ; w = w->link ) {
			if( !visited[w->id] ){
			visited[w->id] = 1;
			printf("%d ", vdata[w->id]);
			enqueue(w->id);
			}
		}
	}
}

int main(int argc, char *argv[]) { // ���� �Լ�

	init_graph();
	reset_visited();
	init_queue();
    int start = 0, count = 0, line = 5 ,i;

	scanf("%d %d %d", &count,&line,&start);

	for( i=1 ; i <= count ; i++ ) insert_vertex( i );
    int u[line], v[line];

	for(i = 0 ; i < line ; i++){
	    scanf("%d %d", &u[i],&v[i]);
        insert_edge2(u[i]-1,v[i]-1);
	}

	printf("\nDFS => "); DFS(0);

	reset_visited();
	reset_graph();
	for(i = 0 ; i < line ; i++){
        insert_edge(u[i]-1,v[i]-1);
	}

	printf("\nBFS => "); BFS(start - 1);


	return 0;
}

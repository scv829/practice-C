#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct student{ /* �л� ���� */
	int id;            //�й�
	char name[20];     //�̸�
}student;

typedef struct node{ /* ��� ���� */
	int id;            //�й�
	char name[20];     //�̸�
	struct node *next; //���� ��带 ����ų ������

}node;

void menu(void){ /* �޴� �Լ� */
	system("cls");
	printf("\n----------------------------------------\n");
	printf("     ������û�� �� ���������� ����");
	printf("\n----------------------------------------\n");
	printf("  1. ���� ��û ('1')\n");
	printf("  2. ����öȸ ��û ('2')\n");
	printf("  3. ������û�� ����Ʈ Ȯ�� ('3')\n");
	printf("  4. ����öȸ�� ����Ʈ Ȯ�� ('4')\n");
	printf("  5. ���α׷� ����  ('q')");
	printf("\n----------------------------------------\n");
	printf("\n\n  ���Ͻô� ���񽺸� �����ϼ��� : ");
}

int addapplyList(student *stu, int *len_apply, int id, char *name,  node ** drop, node * current){ /* ������û�� ��Ͽ� �߰��ϴ� �Լ�  */

	int pos ,i;

	current = *drop;

	while(current != NULL){                 /* ����öȸ�� ����Ʈ�� �ִ� �й����� Ȯ��*/
        if(current->id == id) return -3;    /* ���� : öȸ����Ʈ�� ����*/
        else current = current->next;
	}

	for(pos = 0 ; pos <= *len_apply; pos++){ /* �й��� ������ Ȯ�� */
	 	if( id < stu[pos].id ) {	break;	 }
	 	else if( id == stu[pos].id) return -2; /* ���� : �̹̽�û */
	}

	if (pos >= N) return -1;  /* ���� : ���� �ʰ� */
	else {
		for( i = *len_apply ; i >= pos ; i--){ /* ��ġ ���� */
			stu[i + 1] = stu[i];
		}
		//�� ��ġ�� �������� ����
		stu[pos].id = id;
		strcpy(stu[pos].name, name);
		*len_apply += 1;

	}

}

void addDropList(node **drop, node *current, int id, char *name, int *len_drop){ /* ������ȸ�� ��Ͽ� �߰��ϴ� �Լ�  */
	int i;
	node* back_current = (node*)malloc(sizeof(node)); //�ٷ� �� ���
	back_current = NULL;                              //�ٷ� �� ��带 NULL�� �ʱ�ȭ ��
	node * temp = (node*)malloc(sizeof(node));        //�� ���

	current = *drop; // ���� ��� �� öȸ�� ����Ʈ�� �� ó������ �ʱ�ȭ

	while(current != NULL){ /* ���ǿ� �´� ��� ã�� */
		if(current->id > id) break;
		else{
			back_current = current;
			current = current->next;
		}
	}
	if(current == *drop){                        /* ��尡 ��� �� ��ġ�� �� ���� �� */
		temp->id=id; strcpy(temp->name,name);
		temp->next = *drop;
		*drop = temp;
	}
	else{                                        /* ��尡 ��� �� ��ġ�� �� ���� �ƴ� �� ex)���� ��� ����, �ǳ� */
        temp->id=id; strcpy(temp->name,name);
        temp->next = back_current->next;
        back_current->next = temp;
	}
	temp = NULL; back_current = NULL;            //������ NULL ������ �ʱ�ȭ
	free(temp); free(back_current);              //�Ҵ�� �޸𸮸� Ǯ����
    *len_drop += 1 ;
}
void opening(student *stu, int *len_apply, node ** drop, node * current ,  int * len_drop){ /* ������ �о���� �Լ� */

    printf("\n\n   �ε� ��...\n\n");

    int id; char name[20];
    FILE *applyList, * dropList;                             // apply = ������û�� ��� , drop = ����öȸ�� ���
    applyList = fopen("apply.dat","r");
    while(fscanf(applyList, "%d %s ", &id, name) != EOF) {   // ���Ͼȿ� ������ �о��
        *len_apply += 1;
        stu[*len_apply].id = id;
        strcpy(stu[*len_apply].name, name);
    };
    fclose(applyList);

    dropList = fopen("drop.dat","r");
    while(fscanf(dropList, "%d %s ", &id , name) != EOF){    // ���Ͼȿ� ������ �о��
        addDropList( drop, current, id, name, len_drop);
    }
    fclose(dropList);

    printf("\n\n   �ε��Ϸ�\n\n   ���α׷��� �����Ϸ��� ������ Ű�� �����ּ���.");
    getchar();
    fflush(stdin);

}

void closing(student *stu, int *len_apply, node ** drop, node * current ,  int * len_drop){ /* ������ �����ϴ� �Լ� */

    int i;
    FILE *applyList, * dropList;                                // apply = ������û�� ��� , drop = ����öȸ�� ���

    applyList = fopen("apply.dat","w");                         // ����Ʈ���� ���Ͼȿ� �Է���
    for( i = 0; i <= *len_apply; i++)
        fprintf(applyList, "%d %s ", stu[i].id, stu[i].name);
    fclose(applyList);

    dropList = fopen("drop.dat","w");
    for( i = 0 , current = *drop ; i <= *len_drop ; i++){       // ����Ʈ���� ���Ͼȿ� �Է���
        fprintf(dropList, "%d %s ", current->id, current->name);
        current = current->next;
    }
    fclose(dropList);

}

int main(int argc, char *argv[]) {
    /*������ ����*/
	student stu[N]; node *list,  *current;
	list = NULL, current = NULL;
	int id, i, pos, len_apply = -1 ,len_drop = -1;
	char choice, name[20];

	opening(stu, &len_apply, &list, current, &len_drop);
	do{
		menu();
		choice = getchar();
        fflush(stdin);
		switch(choice){
                /* ������û */
			case '1' : system("cls");
				printf("\n\n  ��û�Ͻ� ������û�� ó���� �Դϴ�. \n\n");
				printf("  �й��� �Է��ϼ��� : ");
				if( !scanf("%d",&id) )  // ���� Ȯ��
                {
                        printf("\n\n  ���� �߻� \n\n");
                        printf("  ���� : �й��� ���� �� �ٸ� ���� ��.\n\n  ó�� ���� �ٽ� �Ͻʽÿ�.");
                        break;
                }
				printf("\n  �̸��� �Է��ϼ��� : "); scanf("%s",name);
                /* ������û �Լ� ȣ�� */
                i = addapplyList(stu, &len_apply, id, name, &list, current);

                if(i == -1){
                    printf("\n\n  �˼��մϴ�. ������û�� �����Ǿ����ϴ�.");                                        // ���� Ȯ��
                    break;
                }
                else if(i == -2){
                    printf("\n\n  �̹� ������û�� �Ǿ��ֽ��ϴ�. \n");                                          // ���� Ȯ��
                    break;
                }
                else if(i == -3){
                    printf("\n\n �˼��մϴ�. �̹� ����öȸ�� �Ͽ� ���û�� �Ұ����մϴ�. \n");                           // ���� Ȯ��
                }
                else printf("\n\n  ��û�Ͻ� ������û�� ó���߽��ϴ�. \n");
                    break;

                /* ����öȸ */
			case '2' : system("cls");
				printf("\n\n  ��û�Ͻ� ����öȸ�� ó���� �Դϴ�. \n\n");
				printf("  �й��� �Է��ϼ��� : ");
				if( !scanf("%d",&id) )                                                              // ���� Ȯ��
                {
                        printf("\n\n  ���� �߻� \n\n");
                        printf("  ���� : �й��� ���� �� �ٸ� ���� ��.\n\n  ó�� ���� �ٽ� �Ͻʽÿ�.");
                        break;
                }
				printf("  �̸��� �Է��ϼ��� : "); scanf("%s",name);
                /* ��ġã�� */
				for(pos = 0 ; pos <= len_apply; pos++){
				 	if( id == stu[pos].id ) {  	break;	 }
				}

				if (pos > len_apply){                                                               // ���� Ȯ��
					 printf("\n  �˼��մϴ�. ������û ����Ʈ��  ��ġ�ϴ� �й��� �����ϴ�.\n");
					 break;
				}
				else{
                    if( strcmp(stu[pos].name, name) != 0 ){                                         // ���� Ȯ��
                        printf("\n\n  ���� �߻� \n\n");
                        printf("  ���� : �Է��� �̸��� ������û ����Ʈ�� �ִ� �̸���  ����ġ.\n\n  ó�� ���� �ٽ� �Ͻʽÿ�.");
                        break;
                    }
                    else{
                        /* �ڸ� ���� */
                        for( i = pos ; i <= len_apply ; i++){
                            stu[i] = stu[i + 1];
                        }
                        len_apply--;
                        /* ����öȸ �Լ� ȣ�� */
                        addDropList(&list, current, id, name, &len_drop);
                        printf("  ��û�Ͻ� ������û ����� ó���߽��ϴ�. \n\n");
                    }
				}
				break;

				/* ������û�� ���� */
			case '3' : system("cls");
				if(len_apply == -1) printf("\n\n ������û�ڰ� �����ϴ�.\n\n");                                // ���� Ȯ��
				else{
					printf("\n\n  ������û�� �� : %d �� \n",len_apply + 1);
					printf("\n\n  ������û�� ����� ������ �����ϴ�.\n\n");
					for(i = 0 ; i <= len_apply ; i++)
						printf(" [%d] �й� : %d    �̸� : %s\n",i ,stu[i].id ,stu[i].name);
				}
				break;

				/* ����öȸ�� ���� */
			case '4' : system("cls");
				if(list == NULL) printf("\n\n  ������û ����ڰ� �����ϴ�.\n\n");                               // ���� Ȯ��
				else{
					current = list;
					printf("\n\n  ������û �����  �� : %d �� \n",len_drop + 1);
					printf("\n\n  ������û ����� ����� ������ �����ϴ�.\n\n");
					for(i = 0 ; current != NULL; i++){
						printf(" [%d] �й� : %d    �̸� : %s\n",i ,current->id ,current->name);
						current = current->next;
					}
				}
				break;

				/* �����ϱ� */
			case 'q' :  system("cls");
                printf("\n\n   ���� ��...");
                /* �����ϱ� �Լ� ȣ�� */
                closing(stu, &len_apply, &list, current, &len_drop);
				printf("\n\n  ���α׷��� �����մϴ�.");
				break;

            default :
                printf("\n\n  �Է��� ���� �������� ���� �ƴմϴ�. �ٽ� �Է��ϼ���.\n\n");
		}
		printf("\n\n  ������ Ű�� ���� �ּ���.");
		fflush(stdin);
		getchar();

	}while(choice != 'q');

	return 0;
}

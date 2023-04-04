#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct student{ /* 학생 정보 */
	int id;            //학번
	char name[20];     //이름
}student;

typedef struct node{ /* 노드 정보 */
	int id;            //학번
	char name[20];     //이름
	struct node *next; //다음 노드를 가르킬 포인터

}node;

void menu(void){ /* 메뉴 함수 */
	system("cls");
	printf("\n----------------------------------------\n");
	printf("     수강신청자 및 수강포기자 관리");
	printf("\n----------------------------------------\n");
	printf("  1. 수강 신청 ('1')\n");
	printf("  2. 수강철회 신청 ('2')\n");
	printf("  3. 수강신청자 리스트 확인 ('3')\n");
	printf("  4. 수강철회자 리스트 확인 ('4')\n");
	printf("  5. 프로그램 종료  ('q')");
	printf("\n----------------------------------------\n");
	printf("\n\n  원하시는 서비스를 선택하세요 : ");
}

int addapplyList(student *stu, int *len_apply, int id, char *name,  node ** drop, node * current){ /* 수강신청자 목록에 추가하는 함수  */

	int pos ,i;

	current = *drop;

	while(current != NULL){                 /* 수강철회자 리스트에 있는 학번인지 확인*/
        if(current->id == id) return -3;    /* 실패 : 철회리스트에 있음*/
        else current = current->next;
	}

	for(pos = 0 ; pos <= *len_apply; pos++){ /* 학번의 순서를 확인 */
	 	if( id < stu[pos].id ) {	break;	 }
	 	else if( id == stu[pos].id) return -2; /* 실패 : 이미신청 */
	}

	if (pos >= N) return -1;  /* 실패 : 정원 초과 */
	else {
		for( i = *len_apply ; i >= pos ; i--){ /* 위치 조정 */
			stu[i + 1] = stu[i];
		}
		//그 위치에 정보들을 넣음
		stu[pos].id = id;
		strcpy(stu[pos].name, name);
		*len_apply += 1;

	}

}

void addDropList(node **drop, node *current, int id, char *name, int *len_drop){ /* 수강절회자 목록에 추가하는 함수  */
	int i;
	node* back_current = (node*)malloc(sizeof(node)); //바로 전 노드
	back_current = NULL;                              //바로 전 노드를 NULL로 초기화 함
	node * temp = (node*)malloc(sizeof(node));        //빈 노드

	current = *drop; // 현재 노드 를 철회자 리스트의 맨 처음으로 초기화

	while(current != NULL){ /* 조건에 맞는 노드 찾기 */
		if(current->id > id) break;
		else{
			back_current = current;
			current = current->next;
		}
	}
	if(current == *drop){                        /* 노드가 들어 갈 위치가 맨 앞일 때 */
		temp->id=id; strcpy(temp->name,name);
		temp->next = *drop;
		*drop = temp;
	}
	else{                                        /* 노드가 들어 갈 위치가 맨 앞이 아닐 때 ex)노드와 노드 사이, 맨끝 */
        temp->id=id; strcpy(temp->name,name);
        temp->next = back_current->next;
        back_current->next = temp;
	}
	temp = NULL; back_current = NULL;            //노드들을 NULL 값으로 초기화
	free(temp); free(back_current);              //할당된 메모리를 풀어줌
    *len_drop += 1 ;
}
void opening(student *stu, int *len_apply, node ** drop, node * current ,  int * len_drop){ /* 파일을 읽어오는 함수 */

    printf("\n\n   로딩 중...\n\n");

    int id; char name[20];
    FILE *applyList, * dropList;                             // apply = 수강신청자 목록 , drop = 수강철회자 목록
    applyList = fopen("apply.dat","r");
    while(fscanf(applyList, "%d %s ", &id, name) != EOF) {   // 파일안에 내용을 읽어옴
        *len_apply += 1;
        stu[*len_apply].id = id;
        strcpy(stu[*len_apply].name, name);
    };
    fclose(applyList);

    dropList = fopen("drop.dat","r");
    while(fscanf(dropList, "%d %s ", &id , name) != EOF){    // 파일안에 내용을 읽어옴
        addDropList( drop, current, id, name, len_drop);
    }
    fclose(dropList);

    printf("\n\n   로딩완료\n\n   프로그램을 시작하려면 임의의 키를 눌러주세요.");
    getchar();
    fflush(stdin);

}

void closing(student *stu, int *len_apply, node ** drop, node * current ,  int * len_drop){ /* 파일을 저장하는 함수 */

    int i;
    FILE *applyList, * dropList;                                // apply = 수강신청자 목록 , drop = 수강철회자 목록

    applyList = fopen("apply.dat","w");                         // 리스트들을 파일안에 입력함
    for( i = 0; i <= *len_apply; i++)
        fprintf(applyList, "%d %s ", stu[i].id, stu[i].name);
    fclose(applyList);

    dropList = fopen("drop.dat","w");
    for( i = 0 , current = *drop ; i <= *len_drop ; i++){       // 리스트들을 파일안에 입력함
        fprintf(dropList, "%d %s ", current->id, current->name);
        current = current->next;
    }
    fclose(dropList);

}

int main(int argc, char *argv[]) {
    /*변수들 선언*/
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
                /* 수강신청 */
			case '1' : system("cls");
				printf("\n\n  요청하신 수강신청을 처리중 입니다. \n\n");
				printf("  학번을 입력하세요 : ");
				if( !scanf("%d",&id) )  // 예외 확인
                {
                        printf("\n\n  오류 발생 \n\n");
                        printf("  원인 : 학번에 숫자 외 다른 값이 들어감.\n\n  처음 부터 다시 하십시오.");
                        break;
                }
				printf("\n  이름을 입력하세요 : "); scanf("%s",name);
                /* 수강신청 함수 호출 */
                i = addapplyList(stu, &len_apply, id, name, &list, current);

                if(i == -1){
                    printf("\n\n  죄송합니다. 수강신청이 마감되었습니다.");                                        // 예외 확인
                    break;
                }
                else if(i == -2){
                    printf("\n\n  이미 수강신청이 되어있습니다. \n");                                          // 예외 확인
                    break;
                }
                else if(i == -3){
                    printf("\n\n 죄송합니다. 이미 수강철회를 하여 재신청이 불가능합니다. \n");                           // 예외 확인
                }
                else printf("\n\n  요청하신 수강신청을 처리했습니다. \n");
                    break;

                /* 수강철회 */
			case '2' : system("cls");
				printf("\n\n  요청하신 수강철회를 처리중 입니다. \n\n");
				printf("  학번을 입력하세요 : ");
				if( !scanf("%d",&id) )                                                              // 예외 확인
                {
                        printf("\n\n  오류 발생 \n\n");
                        printf("  원인 : 학번에 숫자 외 다른 값이 들어감.\n\n  처음 부터 다시 하십시오.");
                        break;
                }
				printf("  이름을 입력하세요 : "); scanf("%s",name);
                /* 위치찾기 */
				for(pos = 0 ; pos <= len_apply; pos++){
				 	if( id == stu[pos].id ) {  	break;	 }
				}

				if (pos > len_apply){                                                               // 예외 확인
					 printf("\n  죄송합니다. 수강신청 리스트에  일치하는 학번이 없습니다.\n");
					 break;
				}
				else{
                    if( strcmp(stu[pos].name, name) != 0 ){                                         // 예외 확인
                        printf("\n\n  오류 발생 \n\n");
                        printf("  원인 : 입력한 이름이 수강신청 리스트에 있는 이름과  불일치.\n\n  처음 부터 다시 하십시오.");
                        break;
                    }
                    else{
                        /* 자리 조정 */
                        for( i = pos ; i <= len_apply ; i++){
                            stu[i] = stu[i + 1];
                        }
                        len_apply--;
                        /* 수강철회 함수 호출 */
                        addDropList(&list, current, id, name, &len_drop);
                        printf("  요청하신 수강신청 취소을 처리했습니다. \n\n");
                    }
				}
				break;

				/* 수강신청자 보기 */
			case '3' : system("cls");
				if(len_apply == -1) printf("\n\n 수강신청자가 없습니다.\n\n");                                // 예외 확인
				else{
					printf("\n\n  수강신청자 수 : %d 명 \n",len_apply + 1);
					printf("\n\n  수강신청자 명단은 다음과 같습니다.\n\n");
					for(i = 0 ; i <= len_apply ; i++)
						printf(" [%d] 학번 : %d    이름 : %s\n",i ,stu[i].id ,stu[i].name);
				}
				break;

				/* 수강철회자 보기 */
			case '4' : system("cls");
				if(list == NULL) printf("\n\n  수강신청 취소자가 없습니다.\n\n");                               // 예외 확인
				else{
					current = list;
					printf("\n\n  수강신청 취소자  수 : %d 명 \n",len_drop + 1);
					printf("\n\n  수강신청 취소자 명단은 다음과 같습니다.\n\n");
					for(i = 0 ; current != NULL; i++){
						printf(" [%d] 학번 : %d    이름 : %s\n",i ,current->id ,current->name);
						current = current->next;
					}
				}
				break;

				/* 종료하기 */
			case 'q' :  system("cls");
                printf("\n\n   저장 중...");
                /* 종료하기 함수 호출 */
                closing(stu, &len_apply, &list, current, &len_drop);
				printf("\n\n  프로그램을 종료합니다.");
				break;

            default :
                printf("\n\n  입력한 값은 정상적인 값이 아닙니다. 다시 입력하세요.\n\n");
		}
		printf("\n\n  임의의 키를 눌러 주세요.");
		fflush(stdin);
		getchar();

	}while(choice != 'q');

	return 0;
}

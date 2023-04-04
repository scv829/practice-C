#include <stdio.h>
#include <stdlib.h>
#include <String.h>

// 프로세스 생성 구조체
typedef struct processInfo{  
	// 프로세스 구성 요소 
    int processID; 		// 프로세스 고유 번호 
    int processAT;      // 프로세스 도착시간			[AT = Arrive Time]
    int processBT;      // 프로세스 작업시간(= 실행시간)[BT = Burst Time]
    int processP;       // 프로세스 우선순위			[P = Priority] 

}processInfo; // typedef로 struct processInfo -> processInfo로 사용 할 수 있다는 의미 

// FCFS 스케줄링 함수 
void FCFS(processInfo p[], int num){ // p[] : 프로세스 구조체 배열, num :  프로세스의 갯수 	
	
	int pWait[num], pReturn[num];		// pWait : 프로세스 대기시간 , pReturn : 프로세스 반환시간	 
	float sum = 0;						// sum : AWT(평균 대기 시간)[= Average Wait Time]을 구하는데 필요한 분자(각 pWait들의 합)  
	int i = 0 , j = 0;					// i ,j : 반복문 사용에 들어가는 변수들 
	
	// 도착시간 기준으로 오름차순으로 정렬시키는 반복문 
	for( i = 0 ; i < num ; i++){					// i의 반복문 
		for( j = num - 1; j > i ; j--){				// j 의 반복문 
			if(p[i].processAT > p[j].processAT){	// 현재 i번째 프로세스 구조체배열의 도착시간이 j번째 크다면  
				processInfo temp = p[i];			// 새로운 temp라는 이름의 프로세스 구조체를 생성하여 i번째 프로세스 구조체를 가리키게 한다.
				p[i] = p[j];						// i번째 프로세스에 j번째 프로세스를 넣고 
				p[j] = temp;						// j번째 프로세스에 temp 프로세스를 넣는다 
			}
		}
	}
	// FCFS 스케줄링 시작 
	printf("===========================================================\n"); // 칸을 나눠주는 표시 
	printf("		### FCFS ###\n");				// FCFS 스케줄링 시작을 표시 
	printf("[ 프로세스 실행순서 : ");				// 프로세스 실행순서의 머리말 표시 
	// 프로세스들의 실행 순서를 표시 및 pWait(대기시간), pReturn(반환시간) 값을 구하는 반복문  
	for(i = 0; i< num; i++){						
		p[i].processAT -= p[0].processAT;						// p[0] 즉 맨 첫 번째로 도착하는 프로세스가 0이 아닌 값으로 도착했을때 p[0].processAT = 0 처럼 표시한다  
		if(i == 0){												// 맨 처음으로 도착하는 프로세스는 기준이여서 맨 처음 도착하는 프로세스에 대한 내용이다  
			pReturn[i] = p[i].processAT + p[i].processBT; 		// 맨 처음으로 도착하는 프로세스의  반환시간은[ 도착시간 +  실행시간]이다 
			pWait[i] = p[i].processAT;					  		// 맨 처음으로 도착하는 프로세스의 대기시간은 도착시간이다 
		}
		else{															// 맨 처음으로 도착하는 프로세스를 제외한 프로레스들에 대한 내용이다 
			pReturn[i] = pReturn[i-1] + p[i].processBT;					// 맨 처음을 제외한 프로세스의 반환시간 = [전 프로세스의 반환시간 + 현 프로세스의 실행시간]
			pWait[i] = pReturn[i] - p[i].processBT - p[i].processAT; 	// 맨 처음을 제외한 프로세스의 대기시간 = [현 프로세스의 반환시간 - 현 프로세스의 (실행시간 + 도착시간)] 
		}
		printf("P%d", p[i].processID);							// 프로세스 출력 
		if(i < num - 1) printf(" -> "); 	 					// 프로세스 이동한다는 표시 출력 
		else printf(" ]\n");									// FCFS 스케줄링 맺음말 표시 
	}
	// 프로세스들의 대기시간들의 합 구하는 반복문 
	for(i = 0 ; i < num; i++){
		printf("[ 프로세스 P%d | 대기시간 : %2d ]\n", i+1, pWait[i]);	// 해당 프로세스의 대기시간 출력 
		sum += pWait[i];												// sum 에 해당 프로세스의 대기시간 더한다 
	}
	// FCFS 스케줄링의 평균대기시간 출력 
	printf("[ AWT : %0.1f ]\n", sum / num);								// 모든 대기시간을 프로세스의 갯수로 나눈다 
}

// SJF 스케줄링 함수 
void SJF(processInfo p[], int num){ // p[] : 프로세스 구조체 배열, num : 프로세스의 갯수 
	
	int pWait[num], pReturn[num];		// pWait : 프로세스 대기시간 , pReturn : 프로세스 반환시간	 
	float sum = 0;						// sum : AWT(평균 대기 시간)[= Average Wait Time]을 구하는데 필요한 분자(각 pWait들의 합)  
	int i = 0 , j = 0;					// i ,j : 반복문 사용에 들어가는 변수들 
	
	// 우선순위 기준으로 오름차순으로 정렬시키는 반복문   
	for( i = 1 ; i < num ; i++){				// i의 반복문 
		for( j = num - 1; j > i ; j--){			// j의 반복문 
			if(p[i].processP > p[j].processP){ 	// 현재 i번째 프로세스 구조체배열의 우선순위가 j번째 낮다면  
				processInfo temp = p[i];		// 새로운 temp라는 이름의 프로세스 구조체를 생성하여 i번째 프로세스 구조체를 가리키게 한다.
				p[i] = p[j];					// i번째 프로세스에 j번째 프로세스를 넣고 
				p[j] = temp;					// j번째 프로세스에 temp 프로세스를 넣는다 
			}
		}
	}
	// SJF 스케줄링 시작 
	printf("===========================================================\n");
	printf("		### SJF ###\n"); 	// SJF 스케줄링 시작을 표시 
	printf("[ 프로세스 실행순서 : ");	// 프로세스 실행순서의 머리말 표시 
	// 프로세스들의 실행 순서를 표시 및 pWait(대기시간), pReturn(반환시간) 값을 구하는 반복문 
	for(i = 0; i< num; i++){						
		p[i].processAT -= p[0].processAT;						// 맨 첫 번째로 도착하는 프로세스가 0이 아닌 값으로 도착했을때 0일 때의 차이를 맨 처음을 제외한 프로세스의 도착시간에서 뺀다  
		if(i == 0){												// 맨 처음으로 도착하는 프로세스는 기준이여서 맨 처음 도착하는 프로세스에 대한 내용이다  
			pReturn[i] = p[i].processAT + p[i].processBT; 		// 맨 처음으로 도착하는 프로세스의  반환시간은[ 도착시간 +  실행시간]이다 
			pWait[i] = p[i].processAT;					  		// 맨 처음으로 도착하는 프로세스의 대기시간은 도착시간이다 
		}
		else{															// 맨 처음으로 도착하는 프로세스를 제외한 프로레스들에 대한 내용이다 
			pReturn[i] = pReturn[i-1] + p[i].processBT;					// 맨 처음을 제외한 프로세스의 반환시간 = [전 프로세스의 반환시간 + 현 프로세스의 실행시간]
			pWait[i] = pReturn[i] - p[i].processBT - p[i].processAT;	// 맨 처음을 제외한 프로세스의 대기시간 = [현 프로세스의 반환시간 - 현 프로세스의 (실행시간 + 도착시간)] 
		}
		printf("P%d", p[i].processID);							// 프로세스 출력 
		if(i < num - 1) printf(" -> "); 	 					// 프로세스 이동한다는 표시 출력 
		else printf(" ]\n");									// SJF 스케줄링 맺음말 표시 
	}
	// 프로세스들의 대기시간들의 합 구하는 반복문 
	for(i = 0 ; i < num; i++){
		printf("[ 프로세스 P%d | 대기시간 : %2d ]\n", i+1, pWait[i]);	// 해당 프로세스의 대기시간 출력 
		sum += pWait[i];												// sum 에 해당 프로세스의 대기시간 더한다
	}
	// SJF 스케줄링의 평균대기시간 출력 
	printf("[ AWT : %0.1f ]\n", sum / num);								// 모든 대기시간을 프로세스의 갯수로 나눈다
}

// RR 스케줄링에서 프로세스의 실행시간을 처리했는지 확인하는 함수 
int checkProcess(processInfo p[], int num){	// p[] : 프로세스 구조체 배열, num : 프로세스의 갯수 
	int i;									// i : 반복문 사용에 들어가는 변수들 
	// 프로세스 구조체배열 안에 있는 프로세스의 처리해야할 실행시간이 남아있으면 1 | 없으면 0 을 리턴하는 반복문   
	for(i = 0; i < num; i++){				
		if(p[i].processBT != 0 ) return 1;	// 프로세스의 처리해야할 실행시간 여부확인 
	}
	return 0;								// 위의 처리과정이 없으면 없다고 리턴 
}

// RR 스케줄링 함수 
void RR(processInfo p[], int num, int timeSlice){ 	// p[] : 프로세스 구조체 배열, num : 프로세스의 갯수, ts : 타임 슬라이스 
	int pWait[num];									// pWait : 프로세스 대기시간
	float sum = 0;									// sum : AWT(평균 대기 시간)[= Average Wait Time]을 구하는데 필요한 분자(각 pWait들의 합)  
	int i = 0 , j = 0;								// i : 반복문 사용에 들어가는 변수 겸 큐 역활 , j : 	반복문 사용에 들어가는 변수				
	int leftTime = 0;								// 프로세스의 처리해야할 실행시간에서 처리한 시간 
	int totalTime = 0;								// 현재까지 걸린 시간 

	memset( pWait, 0, num*sizeof(int) );			// 프로세스 대기시간 0으로 초기화 
	// 도착시간 기준으로 오름차순으로 정렬시키는 반복문 
	for( i = 0 ; i < num ; i++){					// i의 반복문 
		for( j = num - 1; j > i ; j--){				// j의 반복문 
			if(p[i].processAT > p[j].processAT){	// 현재 i번째 프로세스 구조체배열의 도착시간이 j번째 크다면  
				processInfo temp = p[i];			// 새로운 temp라는 이름의 프로세스 구조체를 생성하여 i번째 프로세스 구조체를 가리키게 한다.
				p[i] = p[j];						// i번째 프로세스에 j번째 프로세스를 넣고 
				p[j] = temp;						// j번째 프로세스에 temp 프로세스를 넣는다 
			}
		}
	}
	// RR 스케줄링 시작 
	printf("===========================================================\n");
	printf("		### RR ###\n"); 	// RR 스케줄링 시작을 표시
	printf("[ 프로세스 실행순서 : ");	// 프로세스 실행순서의 머리말 표시 
	// p[0] 가 0이 아닌 값을 받았을 때 0 처럼 표시하기 위한 반복문 
	for(i = 0,j = 0 ; j < num ; j++){	p[i].processAT -= p[0].processAT; } // p[0] 즉 맨 첫 번째로 도착하는 프로세스가 0이 아닌 값으로 도착했을때 p[0].processAT = 0 처럼 표시한다  
	// 프로세스들의 실행 순서를 표시 및 pWait(대기시간)값을 구하는 반복문
	while(checkProcess(p, num)){					// checkProcess(p, num) : RR 스케줄링에서 프로세스의 실행시간을 처리했는지 확인하는 함수 
		
		if( totalTime >= p[i].processAT ) {			// i번째 프로세스가 아직 도착했는지 안했는지 확인 
													// 도착 했다면 
			if( p[i].processBT != 0 ){				// i번째 프로세스의 실행시간이 남아있는지 확인 
													// 실행시간이 남아있다면  
				if(p[i].processBT >= timeSlice){	// i번째 프로세스의 실행시간이 타임슬라이스보다 크거나 같은지 확인 
					p[i].processBT -= timeSlice;	// 참(타임슬라이스 안에 처리를 못하거나 타임 슬라이스에 딱 맞게 처리했다면) : 타임 슬라이스의 값 만큼 실행시간을 빼주고 
					leftTime = timeSlice;			// leftTime 에 타임 슬라이스의 값을 넣는다. 
				}
				else{ 								// 거짓(타임 슬라이스 안에 처리했다면) 
					leftTime = p[i].processBT;		// leftTime 에 실행시간의 값을 넣고  
					p[i].processBT = 0;				// 실행시간의 값을 0으로 한다
				}
				totalTime += leftTime;				// 총 시간에 leftTime을 더한다 
				
				printf("P%d", p[i].processID);				// 해당하는 프로세스를 출력한다. 
				if(checkProcess(p, num)) printf(" -> ");	// 처리해야할 프로세스가 더 있다면 출력 
				//해당하는 프로세스를 제외한 나머지 프로세스들의 대기시간 변경하는 반복문 
				for(j = 0; j < num; j++){						// 프로세스 갯수만큼 반복문을 돌린다				
					if(i == j || p[j].processBT == 0) continue;	// 반복문의 해당하는 프로세스가 현재 프로세스이거나 해당하는 프로세스의 실행시간을 모두 처리했는지 확인|참 : 반복문 증감식으로 이동 
					else{										// 거짓에서 
						if(totalTime >= p[j].processAT && p[j].processAT != 0){ // 해당하는 프로세스가 도착했고 도착시간이 0이 아닌지 확인 | 참 : 
							pWait[j] = totalTime-p[j].processAT;				// 대기시간에 총시간에서 도착시간을 뺀 값을 넣는다 
							p[j].processAT = 0;									// 그리고 해당 프로세스의 도착시간을 0으로 한다
						}														// (이유 : 프로세스마다 단 한번만 작동하기 위해 도착시간을 처음에만 사용하고 0으로 초기화시켜 더이상 작동못하게 하기위해)  
						else pWait[j] += leftTime;								// 거짓 : 대기시간에 leftTime을 더한다 
					}
				}
			}
		}
		//큐의 역활 
		i++;					//해당 프로세스가 끝나면 +1 시켜 맨 뒤로 가는 효과를 보여줌 
		if(i >= num) i %= num;	// 프로세스의 갯수보다 i가 크거나 같으면 다시 나눠 맨 처음으로 보내줌 
	}
	printf(" ]\n");				// RR 스케줄링 맺음말 표시 
	// 프로세스들의 대기시간들의 합 구하는 반복문 
	for(i = 0 ; i < num; i++){
		printf("[ 프로세스 P%d | 대기시간 : %2d ]\n", i+1, pWait[i]);	// 해당 프로세스의 대기시간 출력 
		sum += pWait[i];												// sum 에 해당 프로세스의 대기시간 더한다
	}
	// RR 스케줄링의 평균대기시간 출력 
	printf("[ AWT : %0.1f ]\n", sum / num);								// 모든 대기시간을 프로세스의 갯수로 나눈다
}
// 메인 함수 
int main()
{
	// select : 사용자가 정적데이터,동적데이터 중 뭘 선택했는지 알려주는 변수 , i : 반복문 사용에 들어가는 변수
	// num : 프로세스 갯수, at : 도착시간 변수, bt : 실행시간 변수 , pri : 우선순위 변수, timeSlice : 타임 슬라이스 변수 
	int select = 0, i = 0, num, at, bt, pri, timeSlice;		
	// 데이터 선택 
	printf("===========================================================\n");		// 나누는 창 출력  
	printf("   [201968038]		 [한재성]	    [운영체제]\n");						// 이름 창 출력 
	printf("===========================================================\n");		// 나누는 창 출력 
	printf("우선순위 스케쥴링 알고리즘에 사용할 데이터 양식을 선택해주세요\n");		// 양식을 선택하라는 알림 출력 
	printf("\n	1. 정적 데이터 | 2. 동적 데이터\n선택 : ") ;						// 선택 메뉴 출력 
	scanf("%d",&select);															// 선택 메뉴 입력  
	
	if(select == 1){ // 선택한 데이터가 정적일 때(저장된 값을 사용할 때)
		// 과제 PDF에 나와있는 데이터 set 
		num = 4; timeSlice = 4;																			// num : 프로세스 갯수 | timeSlice : 타임슬라이스 
		processInfo p[num];																				// 프로세스 구조체 배열 p 생성 
		p[0].processID = 1;		p[0].processAT = 0;		p[0].processBT = 15; 	p[0].processP = 3;		// 프로세스 p1 내용 입력 
		p[1].processID = 2;		p[1].processAT = 5;		p[1].processBT = 8;		p[1].processP = 4;		// 프로세스 p2 내용 입력
		p[2].processID = 3;		p[2].processAT = 8;		p[2].processBT = 2;		p[2].processP = 1;		// 프로세스 p3 내용 입력
		p[3].processID = 4;		p[3].processAT = 10;	p[3].processBT = 5; 	p[3].processP = 2;		// 프로세스 p4 내용 입력
		//  pFCFS[num], pSJF[num], pRR[num] 각각 해당하는 스케줄링 함수에 보내줄 프로세스 구조체 배열 
		processInfo pFCFS[num], pSJF[num], pRR[num];													// 각각에 해당하는 프로세스 구조체 배열 생성 
		// 오리지널 p의 값을 복제하는 반복문 
		for(i = 0; i < num ; i++){															// i를0 부터 num(프로세스의 갯수)보다 작다면 i증가  
			pFCFS[i].processID = pSJF[i].processID = pRR[i].processID = p[i].processID;		// 각각에 해당하는 프로세스 구조체 배열에 오리지널 프로세스 구조체 배열의 ID값을 넣음 
			pFCFS[i].processAT = pSJF[i].processAT = pRR[i].processAT = p[i].processAT;		// 각각에 해당하는 프로세스 구조체 배열에 오리지널 프로세스 구조체 배열의 AT값을 넣음
			pFCFS[i].processBT = pSJF[i].processBT = pRR[i].processBT = p[i].processBT;		// 각각에 해당하는 프로세스 구조체 배열에 오리지널 프로세스 구조체 배열의 BT값을 넣음
			pFCFS[i].processP  = pSJF[i].processP  = pRR[i].processP  = p[i].processP;		// 각각에 해당하는 프로세스 구조체 배열에 오리지널 프로세스 구조체 배열의 P값을 넣음
		}		
		//프로세스 기초 정보 출력 & 반복문 
		printf("===========================================================\n");		// 나누는 창 출력		
		printf("		정적 데이터		|타임슬라이스 : %d초\n",timeSlice);				// 정적 데이터, 타임슬라이스 표시창 출력 
		// 프로세스 기초 정보를 출력해주는 반복문 부분  
		printf("------------------------------------------------------------\n");		// 나누는 창 출력
		for(i = 0; i < num ; i++){														// i를0 부터 num(프로세스의 갯수)보다 작다면 i증가 
			printf("프로세스 P%d | 도착시간 : %2d / 작업시간 : %2d / 우선순위 : %2d \n",p[i].processID, p[i].processAT, p[i].processBT, p[i].processP); // 프로세스의 ID,AT,BT,P 출력 
				}
		printf("===========================================================\n");		// 나누는 창 출력 
		FCFS(pFCFS, num);						// FCFS 스케줄링 실행 
		SJF(pSJF, num);							// SJF 스케줄링 실행
		RR(pRR, num, timeSlice);				// RR 스케줄링 실행
		printf("===========================================================\n");		// 나누는 창 출력
		
	}
	
	else if(select == 2){ // 선택한 데이터가 동적일 때(사용자 값을 사용할 때)
		// 입력할 프로세스 갯수 입력 
		printf("입력할 프로세스의 갯수를 입력해 주세요 : ");							// 입력할 프로세스의 갯수를 입력해 주세요 창  출력  
		scanf("%d",&num);																// 프로세스 의 갯수num 을 입력 
		processInfo p[num]; 	// 프로세스 갯수만큼의 크기인 프로세스 구조체 배열 선언 
		// 프로세스 갯수만큼 위 구조제배열에  내용 저장 
		for(i = 0 ; i < num; i++){														// i를0 부터 num(프로세스의 갯수)보다 작다면 i증가  
			printf("프로세스 P%d 의 도착시간 / 작업시간 / 우선순위 순으로 입력하세요\n",i + 1);	// 프로세스 의 정보를 입력하라는 창 출력  
			scanf("%d %d %d",&at,&bt,&pri);												//at : 대기시간(AT) |bt : 작업시간(BT) |pri : 우선순위(P) 에 각각 대응하는 정보 입력 
			p[i].processID = i + 1;														// ID에 i + 1 값을 넣음 (ex. i == 0 -> ID = 1) 
			p[i].processAT = at;														// 입력받은 at를 프로세스 구조체에 있는 AT에 넣음 
			p[i].processBT = bt;														// 입력받은 bt를 프로세스 구조체에 있는 BT에 넣음
			p[i].processP = pri;														// 입력받은 pri를 프로세스 구조체에 있는 P에 넣음
		}
		// RR 스케줄링에서 사용할 타임슬라이스 값을 입력 
		printf("RR 스케줄링에서 사용할 타임슬라이스 값을 입력하세요 : ");				// RR 스케줄링에 필요한 데이터인 타임슬라이스를 입력하라는 창 출력  
		scanf("%d",&timeSlice);															// timeSlice 에 타임슬라이스 값 입력 
		
		// pFCFS[num], pSJF[num], pRR[num] 각각 해당하는 스케줄링 함수에 보내줄 프로세스 구조체 배열 
		processInfo pFCFS[num], pSJF[num], pRR[num];
	// 오리지널 p의 값을 복제하는 반복문 
		for(i = 0; i < num ; i++){															// i를0 부터 num(프로세스의 갯수)보다 작다면 i증가  
			pFCFS[i].processID = pSJF[i].processID = pRR[i].processID = p[i].processID;		// 각각에 해당하는 프로세스 구조체 배열에 오리지널 프로세스 구조체 배열의 ID값을 넣음 
			pFCFS[i].processAT = pSJF[i].processAT = pRR[i].processAT = p[i].processAT;		// 각각에 해당하는 프로세스 구조체 배열에 오리지널 프로세스 구조체 배열의 AT값을 넣음
			pFCFS[i].processBT = pSJF[i].processBT = pRR[i].processBT = p[i].processBT;		// 각각에 해당하는 프로세스 구조체 배열에 오리지널 프로세스 구조체 배열의 BT값을 넣음
			pFCFS[i].processP  = pSJF[i].processP  = pRR[i].processP  = p[i].processP;		// 각각에 해당하는 프로세스 구조체 배열에 오리지널 프로세스 구조체 배열의 P값을 넣음
		}	
		
		//프로세스 기초 정보 출력 & 반복문 
		printf("===========================================================\n");		// 나누는 창 출력		
		printf("		동적 데이터		|타임슬라이스 : %d초\n",timeSlice);				// 동적 데이터, 타임슬라이스 표시창 출력
		// 프로세스 기초 정보를 출력해주는 반복문 부분  
		printf("------------------------------------------------------------\n");		// 나누는 창 출력
		for(i = 0; i < num ; i++){														// i를0 부터 num(프로세스의 갯수)보다 작다면 i증가 
			printf("프로세스 P%d | 도착시간 : %2d / 작업시간 : %2d / 우선순위 : %2d \n",p[i].processID, p[i].processAT, p[i].processBT, p[i].processP); // 프로세스의 ID,AT,BT,P 출력 
				}
		printf("===========================================================\n");		// 나누는 창 출력 
		FCFS(pFCFS, num);						// FCFS 스케줄링 실행 
		SJF(pSJF, num);							// SJF 스케줄링 실행
		RR(pRR, num, timeSlice);				// RR 스케줄링 실행
		printf("===========================================================\n");		// 나누는 창 출력
	}
	else{			// 1,2 외의 값을 입력했을 때 오류 출력 
		printf("===========================================================\n");		// 나누는 창 출력	
		printf("\n입력오류 프로그램을 다시 시작해주세요\n\n");							// 입력오류로 프로그램을 다시 시작해 달라는 창 출력 
		printf("===========================================================\n");		// 나누는 창 출력
	}
    return 0;																			// int(정수형)로 만들었으니 정수형 return 값이 필요하고 return값은 0으로 보내주면서 끝을 낸다는 의미 
}

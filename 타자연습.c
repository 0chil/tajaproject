#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

int countdown(int t){
			printf("%d",t);sleep(1);
			int i;
			for(i=t-1;i>=1;i--){
				printf("\b%d",i);
				sleep(1);
			}
			printf("\b ");
}

void positionT(){
}

void wordT(){
	//낱말 연습 코드
}

void SparagraphT(){
	//짧은 문장 연습 코드
}

char long_para[4][10][100]={"The Middle\n","Take a seat right over there, sat on the stairs\n","Stay or leave, the cabinets are bare and I'm unaware\n","Of just how we got into this mess, got so aggressive\n","I know we meant all good intentions\n", \ 
	"So pull me closer\n","Why don't you pull me close?\n","Why don't you come on over?\n","I can't just let you go\n","Oh baby, why don't you just meet me in the middle?\n", \
	
	"Faint\n","I am a little bit of loneliness, a little bit of disregard\n","Handful of complaints but I can't help the fact\n","That everyone can see these scars\n","I am what I want you to want, what I want you to feel\n", \
	"But it's like no matter what I do, I can't convince you\n","To just believe this is real\n","So I, let go watching you turn your back like you always do\n","Face away and pretend I'm not\n","But I'll be here 'cause you're all that I've got\n", \
	
	"Wolves\n","In your eyes, there's a heavy blue\n","One to love and one to lose\n","Sweet divide, a heavy truth\n","Water or wine, don't make me choose\n", \
	"I wanna feel the way that we did that summer night\n","Drunk on a feeling, alone with the stars in the sky\n","I've been running through the jungle\n","I've been running with the wolves\n","To get to you, to get to you\n", \
	
	"Butterflies And Hurricanes\n","Change everything you are\n","And everything you were\n","Your number has been called\n","Fights and battles have begun\n", \
	"Revenge will surely come\n"," Your hard times are ahead\n","Best, You've got to be the best\n","You've got to change the world\n","And use this chance to be heard\n"};
char long_input[10][100]={0};
int LT_length[10]={0};
int LT_ln=0,LT_col=0;

int LT_count_answers(int randint){
	if(LT_ln==0 && LT_col==0) return 0;//처음 실행시 0%로 표시
	int corcnt=0;
	for(int i=0;i<=LT_ln;i++)
		for(int j=0;j<=LT_length[i];j++)
			if(long_para[randint][i][j]==long_input[i][j] && long_input[i][j]!='\n' && long_input[i][j]!='\0')
			corcnt++;
	return corcnt;
}

int LT_count_inputs(){
	if(LT_ln==0 && LT_col==0) return 1; //처음 실행시 0%로 표시  
	int cnt=0;
	for(int i=0;i<=LT_ln;i++)
		for(int j=0;j<=LT_length[i];j++)
			if(long_input[i][j]!='\n' && long_input[i][j]!='\0')
			cnt++;
	return cnt;
}

void LT_print(int randint,int ln,int col){
	system("cls");
	printf("%d %d\n",LT_ln,LT_col);
	//정확도, 현재타수 출력
	printf("정확도 : %.0f%% 현재타수 : %d\n",(float)LT_count_answers(randint)/LT_count_inputs()*100,0); 
	//정답 출력  
	if(ln<5)
		for(int i=0;i<5;i++)
			printf("%s",long_para[randint][i]);
	else
		for(int i=5;i<10;i++)
			printf("%s",long_para[randint][i]);
	//지금까지 입력된 것 출력
	if(ln<5)
		for(int i=0;i<=ln;i++)
			printf("%s",long_input[i]);
	else
		for(int i=5;i<=ln;i++)
			printf("%s",long_input[i]);
}
int main(); //메인 함수로 돌아가기 위해 

int LparagraphT(){
	srand(time(NULL)); //시드 초기화
	for(int i=0;i<10;i++)
		for(int j=0;j<100;j++)
		long_input[i][j]=0; //입력 배열 초기화 
	LT_ln=0,LT_col=0; //행,열 초기화 
	int randint=rand()%4,c; //랜덤 지정 
	//각 줄의 글자수 셈 
	for(int i=0;i<10;i++)
			LT_length[i]=strlen(long_para[randint][i])-1;//1부터 센다(길이) 
	LT_print(randint,LT_ln,LT_col);
	while(LT_ln<10){
		if((c=getch())==27){ //ESC 키  
				system("cls");
				main();
			}
		else if(c=='\b'){ //백스페이스
			if(LT_col>0 && LT_ln>0){
				long_input[LT_ln][LT_col-1]=0;
				LT_col--;
			}
			else if(LT_col==0 && LT_ln>0){
				long_input[LT_ln][LT_col-1]=0;
				LT_ln--;
				LT_col=LT_length[LT_ln]-1;
				long_input[LT_ln][LT_col]=0;
			}
			else if(LT_col>0 && LT_ln==0){
				long_input[LT_ln][LT_col-1]=0;
				LT_col--;
			}
			LT_print(randint,LT_ln,LT_col);
		}
		else{
			 if(LT_col>LT_length[LT_ln]-2 && LT_ln<=10){
			 	long_input[LT_ln][LT_col]=c;
			 	long_input[LT_ln][LT_col+1]='\n';
				LT_col=0;
				LT_ln++;
			}
			else if(LT_col<LT_length[LT_ln] && LT_ln<=10){
				long_input[LT_ln][LT_col]=c;
				LT_col++;
			}
			LT_print(randint,LT_ln,LT_col);
			}
	}
}

int main(){
	int selection=-1; //선택 함수 초기화
	printf("무엇을 연습하시겠습니까?\n1) 자리 연습\n2) 낱말 연습\n3) 짧은 글 연습\n4) 긴 글 연습\n5) 종료\n입력 : ");
	scanf("%d",&selection); //입력 받음
	switch(selection){
		case 1: //1 입력시
			printf("자리 연습을 시작합니다\n");
			//countdown(5);
			system("cls");//cygwin 에서 clear 
			positionT(); //자리연습 함수 실행
			break;
		case 2: //2 입력시
			printf("낱말 연습을 시작합니다\n");
			countdown(5);
			wordT();
			break;
		case 3: //3 입력시
			printf("짧은 글 연습을 시작합니다\n");
			countdown(5);
			SparagraphT();
			break;
		case 4: //4 입력시
			printf("긴 글 연습을 시작합니다\n");
			//countdown(5);
			LparagraphT();
			break;
		default: //5 혹은 이외의 수 입력시
			system("cls");
			printf("프로그램을 종료합니다");
			sleep(1);
			exit(1);
	}
}

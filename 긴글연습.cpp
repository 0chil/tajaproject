#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

char long_para[4][10][100]={"The Middle\n","Take a seat right over there, sat on the stairs\n","Stay or leave, the cabinets are bare and I'm unaware\n","Of just how we got into this mess, got so aggressive\n","I know we meant all good intentions\n", \ 
	"So pull me closer\n","Why don't you pull me close?\n","Why don't you come on over?\n","I can't just let you go\n","Oh baby, why don't you just meet me in the middle?\n", \
	
	"Faint\n","I am a little bit of loneliness, a little bit of disregard\n","Handful of complaints but I can't help the fact\n","That everyone can see these scars\n","I am what I want you to want, what I want you to feel\n", \
	"But it's like no matter what I do, I can't convince you\n","To just believe this is real\n","So I, let go watching you turn your back like you always do\n","Face away and pretend I'm not\n","But I'll be here 'cause you're all that I've got\n", \
	
	"Wolves\n","In your eyes, there's a heavy blue\n","One to love and one to lose\n","Sweet divide, a heavy truth\n","Water or wine, don't make me choose\n", \
	"I wanna feel the way that we did that summer night\n","Drunk on a feeling, alone with the stars in the sky\n","I've been running through the jungle\n","I've been running with the wolves\n","To get to you, to get to you\n", \
	
	"Butterflies And Hurricanes\n","Change everything you are\n","And everything you were\n","Your number has been called\n","Fights and battles have begun\n", \
	"Revenge will surely come\n"," Your hard times are ahead\n","Best, You've got to be the best\n","You've got to change the world\n","And use this chance to be heard\n"};
char long_input[10][100]={0};
int length[10]={0};
int ln=0,col=0;
int count_answers(int randint){
	if(ln==0 && col==0) return 1;
	int corcnt=0;
	for(int i=0;i<=ln;i++){
		for(int j=0;j<length[ln];j++){
			if(long_para[randint][i][j]==long_input[i][j] && long_input[i][j]!='\n' && long_input[i][j]!='\0')
			corcnt++;
		}
	}
	return corcnt;
}

int count_inputs(){
	if(ln==0 && col==0) return 1;
	//갯수 잘 세는거 확인 완료 
	int cnt=0;
	for(int i=0;i<ln;i++){
		cnt+=length[i];
	}
	cnt+=col;
	return cnt;
}
void print(int randint,int ln,int col){
	system("cls");
	for(int i=0;i<10;i++)
	printf("%d ",length[i]);
	printf("\n");
	printf("%d %d\n",ln,col);
	//정확도, 현재타수 출력
	printf("정확도 : %.0f%% 현재타수 : %d\n",(float)count_answers(randint)/count_inputs()*100,0); 
	//정답 출력  
	if(ln<5){
		for(int i=0;i<5;i++)
			printf("%s",long_para[randint][i]);
	}
	else{
		for(int i=5;i<10;i++)
			printf("%s",long_para[randint][i]);
	}
	
	//지금까지 입력된 것 출력
	if(ln<5){
		for(int i=0;i<=ln;i++){
			printf("%s",long_input[i]);
		}
	}
	else{
		for(int i=5;i<=ln;i++){
			printf("%s",long_input[i]);
		}
	}
}

int main(){
	srand(time(NULL)); //시드 초기화
	int randint=rand()%4,c;
	//각 줄의 글자수 셈 
	for(int i=0;i<10;i++){
		for(int j=0;j<200;j++){
			if(long_para[randint][i][j]=='\n'){
			length[i]=j;break;//1부터 센다(길이) 
			} 
		}
	}

	int accu,tpm;
	print(randint,ln,col);
	while(ln<10){
		if((c=getch())==27){ //ESC 키  
				main();
			}
		else if(c=='\b'){ //백스페이스
			if(col>0 && ln>0){
				long_input[ln][col-1]=0;
				col--;
			}
			else if(col==0 && ln>0){
				long_input[ln][col-1]=0;
				ln--;
				col=length[ln]-1;
				long_input[ln][col]=0;
			}
			else if(col>0 && ln==0){
				long_input[ln][col-1]=0;
				col--;
			}
			print(randint,ln,col);
		}
		else{
			 if(col>=length[ln]-1 && ln<=10){
			 	long_input[ln][col]=c;
			 	long_input[ln][col+1]='\n';
				col=0;
				ln++;
			}
			else if(col<length[ln] && ln<=10){
				long_input[ln][col]=c;
				col++;
			}
			print(randint,ln,col);
			}
	}
}

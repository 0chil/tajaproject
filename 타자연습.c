#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>


char long_para[4][10][100] = {"The Middle\n","Take a seat right over there, sat on the stairs\n","Stay or leave, the cabinets are bare and I'm unaware\n","Of just how we got into this mess, got so aggressive\n","I know we meant all good intentions\n", \
"So pull me closer\n","Why don't you pull me close?\n","Why don't you come on over?\n","I can't just let you go\n","Oh baby, why don't you just meet me in the middle?\n", \

"Faint\n","I am a little bit of loneliness, a little bit of disregard\n","Handful of complaints but I can't help the fact\n","That everyone can see these scars\n","I am what I want you to want, what I want you to feel\n", \
"But it's like no matter what I do, I can't convince you\n","To just believe this is real\n","So I, let go watching you turn your back like you always do\n","Face away and pretend I'm not\n","But I'll be here 'cause you're all that I've got\n", \

"Wolves\n","In your eyes, there's a heavy blue\n","One to love and one to lose\n","Sweet divide, a heavy truth\n","Water or wine, don't make me choose\n", \
"I wanna feel the way that we did that summer night\n","Drunk on a feeling, alone with the stars in the sky\n","I've been running through the jungle\n","I've been running with the wolves\n","To get to you, to get to you\n", \

"Butterflies And Hurricanes\n","Change everything you are\n","And everything you were\n","Your number has been called\n","Fights and battles have begun\n", \
"Revenge will surely come\n","Your hard times are ahead\n","Best, You've got to be the best\n","You've got to change the world\n","And use this chance to be heard\n"};
char long_input[10][100] = {'\0',};
int LT_length[10] = { 0, };
int LT_ln = 0, LT_col = 0;
	clock_t start_clock, end_clock, els_time;

char short_para[30][200] = { "To marry is to halve your rights and double your duties.","He makes no friend who never made a foe.","Common sense is the collection of prejudices acquired by age 18.","The unleashed power of the atom has changed everything save our modes of thinking, and we thus drift toward unparalleled catastrophes.","Nothing is more despicable than respect based on fear.","Television has proved that people will look at anything rather than each other.","It is only with the heart that one can see rightly; what is essential is invisible to the eye.","Love does not consist in gazing at each other, but in looking together in the same direction.","Business? It's quite simple. It's other people's money.","I would as soon leave my son a curse as the almighty dollar.","A great writer is, so to speak, a second government in his country. And for that reason no regime has ever loved great writers, only minor ones.","You don't live in a world all alone. Your brothers are here too.","A hungry man is not a free man.","To know is nothing at all; to imagine is everything.","Truth is generally the best vindication against slander.","It is my intention to present - through the medium of photography - intuitive observations of the natural world which may have meaning to the spectators.","America is a large, friendly dog in a very small room. Every time it wags its tail it knocks over a chair.","The secret of business is to know something that nobody else knows.","One man with courage makes a majority.","Television has a real problem. They have no page two.","Man is born to live, not to prepare for life. Life itself, the phenomenon of life, the gift of life, is so breathtakingly serious!","Like all great travellers, I have seen more than I remember, and remember more than I have seen.","The magic of first love is our ignorance that it can ever end.","When men are employed, they are best contented.","When she finally stopped conforming to the conventional picture of femininity she finally began to enjoy being a woman.","Anything you're good at contributes to happiness.","Accurst be he that first invented war.","Since a politician never believes what he says, he is surprised when others believe him.","A woman means by unselfishness chiefly taking trouble for others; a man means not giving trouble to others. Thus each sex regards the other as basically selfish.","Freedom is a system based on courage." };
char short_input[5][200] = { '\0', };
int st_length[5] = {0,};
int corcnt=0;
double tpm=0.0,htpm=0.0;

int getch_flush(void){
	fflush(stdout);
	char ch;
	struct termios t_old,t_new;
	tcgetattr(STDIN_FILENO,&t_old);
	t_new=t_old;
	t_new.c_lflag&=~(ECHO|ICANON);
	tcsetattr( STDIN_FILENO, TCSANOW, &t_new);
	read(0,&ch,1);
	tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
	return ch;
}
int main(); //메인 함수로 돌아가기 위해

void positionT() {
	srand(time(NULL));
	int caps = rand() % 2, alpha = rand() % 26;
	int answer = (caps ? 65 : 97) + alpha, input;
	int prog = 0, miss = 0, hit = 0;
	double acc = 0;
	while (prog < 20) {
		if (hit>0)
			acc = (hit - miss) / (double)hit;
		system("clear");
		printf("***********\n");
		printf("     %c     \n", answer);
		printf("***********\n");
		printf("%d번째 입력\n", hit + 1);
		printf("진행도:%.0f%%\n오타수:%d\n정확도:%.2f%%\n", (double)prog/20*100, miss, acc * 100);
		input = getch_flush();
		if (input == answer) {
			prog++;
			hit++;
			caps = rand() % 2;
			alpha = rand() % 26;
			answer = (caps ? 65 : 97) + alpha, input;
		}
		else if (input == 27) {
			system("clear");
			main();
		}
		else {
			miss++;
			hit++;
		}
	}
	system("clear");
	printf("시도횟수: %d , 오타수:%d , 정확도:%.2f%%\n", hit, miss, acc * 100);
	while(1) {
		if (input=getch_flush() == '\n') {
			system("clear");
			main();
		}
	}
}

void wordT() {
	//낱말 연습 코드
}

void ST_print(int randint, int T, int save, double els_time) {
	system("clear");
	int son=0;
	for(int i=0;i<=strlen(short_input[T]);i++){
		if( (short_para[randint][i] == short_input[T][i]) && short_input[T][i] != '\0'){
			son++;
		}
	}
	if(save==1){
		corcnt+=son;
		son=0;
	}
	int mother=0;
	for(int i=0;i<=T;i++){
		mother+=strlen(short_input[i]);
	}
	tpm=(double)(corcnt+son)/els_time*60;
	if(tpm<5000.0) 
		htpm=(tpm>htpm)?tpm:htpm;
	//진행도, 정확도, 최고타수, 현재타수 출력
	if((corcnt+son)<1)
		printf("진행도 : %.0f%% 정확도 : %.0f%% 최고타수 : %.2lf 현재타수 : %.2lf\n", (double)T/5*100, 0.0, 0.0, 0.0);
	else
		printf("진행도 : %.0f%% 정확도 : %.0f%% 최고타수 : %.2lf 현재타수 : %.2lf\n", (double)T/5*100, (double)(corcnt+son)/mother*100, htpm, tpm);
	if (T>4) return;
	//정답 출력  
	printf("%s\n\n", short_para[randint]);
	//지금까지 입력된 것 출력
	printf("%s", short_input[T]);
}

void SparagraphT(){
	tpm=0.0;htpm=0.0;corcnt=0;

	for(int i=0;i<5;i++)
		st_length[i]=0;

	clock_t start_clock, end_clock, diff_clock, els_time;
	start_clock = clock();

	int T = 0,c;
	srand(time(NULL)); //시드 초기화

	for (int i = 0; i<5; i++)
		for (int j = 0; j<200; j++)
			short_input[i][j] = '\0'; //입력 배열 초기화 

	int randint;
	while (T<5) {
		randint = rand() % 30; //랜덤 지정

		for (int i = 0; i<5; i++)
			st_length[i] = strlen(short_para[randint]) - 1;//1부터 센다(길이) 

		end_clock = clock();
		diff_clock = end_clock - start_clock;
		els_time = diff_clock / CLOCKS_PER_SEC;
		ST_print(randint, T, 0,els_time);

		while(strlen(short_input[T]) <= st_length[T]){
			if ((c = getch_flush()) == 27) { //ESC 키  
				system("clear");
				main();
			}
			else if (c == 127) { //백스페이스

				int len = strlen(short_input[T]);
				if (len > 0) {
					short_input[T][len] = '\0';
					short_input[T][len - 1] = '\0';
					end_clock = clock();
					diff_clock = end_clock - start_clock;
					els_time = diff_clock / CLOCKS_PER_SEC;
					ST_print(randint, T, 0,els_time);
				}
			}
			else if(c!='\n') {
				short_input[T][strlen(short_input[T])] = c;
				end_clock = clock();
				diff_clock = end_clock - start_clock;
				els_time = diff_clock / CLOCKS_PER_SEC;
				ST_print(randint, T, 0,els_time);
			}
		}
		diff_clock = end_clock - start_clock;
				els_time = diff_clock / CLOCKS_PER_SEC;
				ST_print(randint, T, 0,els_time);
		while (1) {
			if (c = getch_flush()=='\n') break;
			else if(c == 27){
				system("clear");
				main();
			}
		}
		end_clock = clock();
		diff_clock = end_clock - start_clock;
		els_time = diff_clock / CLOCKS_PER_SEC;
		ST_print(randint, T, 1, els_time);
		T++;
	}
	system("clear");
	ST_print(randint, T, 0,els_time);
	printf("Enter 키를 누르면 돌아갑니다.\n");
	while (1) {
		if (c = getch_flush() == '\n') {
			system("clear");
			main();
		}
	}
}


int LT_count_answers(int randint) {
	int corcnt = 0;
	for (int i = 0; i <= LT_ln; i++){
		for (int j = 0; j <= LT_length[i]; j++){
			if (long_para[randint][i][j] == long_input[i][j] && long_input[i][j] != '\n' && long_input[i][j] != '\0'){
				corcnt++;
			}
		}
	}
	return corcnt;
}

int LT_count_inputs() {
	int cnt = 0;
	for (int i = 0; i <= LT_ln; i++){
		for (int j = 0; j <= LT_length[i]; j++){
			if (long_input[i][j] != '\n' && long_input[i][j] != '\0'){
				cnt++;
			}
		}
	}
	return cnt;
}

void LT_print(int randint,double els) {
	//fflush(stdout);
	system("clear");
	//printf("\n");
	//printf("%d %d / %d %d\n", LT_ln, LT_col, LT_count_answers(randint),LT_count_inputs()); //현 위치 체크(디버깅) 
	//정확도, 현재타수 출력
	
	if((double)LT_count_answers(randint) / LT_count_inputs() * 100 < 1){
		printf("정확도 : %.0lf%% 현재타수 : %.2lf\n", 0.0, 0.0);
	}
	else{
		printf("정확도 : %.0lf%% 현재타수 : %.2lf\n", (double)LT_count_answers(randint) / LT_count_inputs() * 100, els);
	}


	//정답 출력  
	if (LT_ln<5){
		for (int i = 0; i<5; i++){
			printf("%s", long_para[randint][i]);
		}
		printf("\n");
		for (int j = 0; j <= LT_ln; j++){
			printf("%s",long_input[j]);
		}
	}
	else{
		for (int i = 5; i<10; i++){
			printf("%s", long_para[randint][i]);
		}
		printf("\n");
		for (int i = 5; i <= LT_ln; i++){
			printf("%s", long_input[i]);
		}
	}
}

void LparagraphT() {
	srand(time(NULL)); //시드 초기화

	for (int i = 0; i<10; i++)
		for (int j = 0; j<100; j++)
			long_input[i][j] = '\0'; //입력 배열 초기화 

	LT_ln = 0, LT_col = 0; //행,열 초기화 

	int randint = rand() % 4, c; //랜덤 지정 

	for (int i = 0; i<10; i++)
		LT_length[i] = strlen(long_para[randint][i]) - 1;//1부터 센다(길이) 

	end_clock = clock();
	els_time = (float)(end_clock - start_clock) / (CLOCKS_PER_SEC);
	LT_print(randint, (double)els_time);

	while (LT_ln<10) {
		c = getch_flush();
		if (c == 27) { //ESC 키  
			system("clear");
			main();
		}
		else if (c == 127) { //백스페이스 처리 
			if (LT_col>0 && LT_ln>0) {
				long_input[LT_ln][LT_col - 1] = '\0';
				LT_col--;
			}
			else if (LT_col == 0 && LT_ln>0) {
				long_input[LT_ln][LT_col - 1] = '\0';
				LT_ln--;
				LT_col = LT_length[LT_ln] - 1;
				long_input[LT_ln][LT_col] = '\0';
				long_input[LT_ln][LT_col+1] = '\0';
			}
			else if (LT_col>0 && LT_ln == 0) {
				long_input[LT_ln][LT_col - 1] = '\0';
				LT_col--;
			}
			else{

			}
		}
		else if (c == '\n') {
			if(LT_ln<10 && (LT_col>=LT_length[LT_ln]-1)){
				long_input[LT_ln][LT_col] = '\n';
				LT_ln++;
				LT_col=0;
			}
			else{

			}
		}
		else {
			if (LT_col>LT_length[LT_ln] - 1 && LT_ln <= 10) {
				long_input[LT_ln][LT_col] = '\n';
				long_input[LT_ln+1][0] = c;
				LT_col = 1;
				LT_ln++;
			}
			else if (LT_col<LT_length[LT_ln] && LT_ln <= 10) {
				long_input[LT_ln][LT_col] = c;
				LT_col++;
			}
		}
		end_clock = clock();
		els_time = (float)(end_clock - start_clock) / (CLOCKS_PER_SEC);
		LT_print(randint, els_time);
	}
	//연습 끝 ===
	system("clear");
	printf("정확도 : %.0f%% 현재타수 : %.2lf\nEnter 키를 누르면 돌아갑니다", (double)LT_count_answers(randint) / LT_count_inputs() * 100, (double)LT_count_answers(randint)/els_time*60);
	while (1) {
		if (c = getch_flush() == 13) {
			system("clear");
			main();
		}
	}
}

int main() {
	int selection = -1; //선택 함수 초기화
	system("clear");
	printf("무엇을 연습하시겠습니까?\n1) 자리 연습\n2) 낱말 연습\n3) 짧은 글 연습\n4) 긴 글 연습\n5) 종료\n입력 : ");
	scanf("%d", &selection); //입력 받음
	switch (selection) {
	case 1: //1 입력시
		printf("자리 연습을 시작합니다\n");
		system("clear");//cygwin 에서 clear 
		positionT(); //자리연습 함수 실행
		break;
	case 2: //2 입력시
		printf("낱말 연습을 시작합니다\n");
		system("clear");//cygwin 에서 clear 
		wordT();
		break;
	case 3: //3 입력시
		printf("짧은 글 연습을 시작합니다\n");
		system("clear");//cygwin 에서 clear 
		SparagraphT();
		break;
	case 4: //4 입력시
		printf("긴 글 연습을 시작합니다\n");
		system("clear");//cygwin 에서 clear 
		LparagraphT();
		start_clock = clock();
		break;
	default: //5 혹은 이외의 수 입력시
		system("clear");
		printf("프로그램을 종료합니다");
		exit(1);
	}
}


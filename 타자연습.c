#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

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
	srand(time(NULL));
	int rancap = rand() % 2;
	int randomchar=rand() % (((25 - 0) + 1) + 0);
	int answerchar=(rancap ? 97:65)+randomchar;
	int userinput=0,testcase=20,cnt=1,wrong=0;
	while(testcase>0){
		//system("clear");
		system("cls"); //cygwin���� clear()�� ���� 
		printf("---------\n");
		printf("|   %c   |\n",answerchar);
		printf("---------\n");
		printf("%d��° �Է�\n",cnt);
		printf("������ : %d%%\n��Ÿ�� : %d\n��Ȯ�� : %d%%\n",(int)((double)(20-testcase)/(double)20*(double)100),wrong,100-(int)((double)wrong/(double)cnt*(double)100));
		printf("�Է�:");
		userinput=getch();
		if (userinput==answerchar){
			testcase--;
			cnt++;
			rancap = rand() % 2;
			randomchar=rand() % (((25 - 0) + 1) + 0);
			answerchar=0;
			userinput=0;
			answerchar = (rancap ? 97:65)+randomchar;
		}
		else if(userinput==27){
		main();
		}
		else{
			wrong++;
			cnt++;
		}
	}
	//system("clear");
	system("cls");
	printf("��Ÿ�� : %d\n��Ȯ�� : %d%%\n",wrong,100-(int)((double)wrong/(double)cnt*(double)100));
	printf("Enter�� ������ ���ư��ϴ�");
	while(1){
		userinput=getch();
		if(userinput==13){
			//system("clear");
			system("cls");
			main();
		}
	}
}

void wordT(){
	
}

void SparagraphT(){
	
}

void LparagraphT(){
	
}

int main(){
	int selection=-1;
	printf("������ �����Ͻðڽ��ϱ�?\n1) �ڸ� ����\n2) ���� ����\n3) ª�� �� ����\n4) �� �� ����\n5) ����\n:");
	scanf("%d",&selection);
	switch(selection){
		case 1:
			printf("�ڸ� ������ �����մϴ�\n");
			//countdown(5);
			system("cls");//cygwin ���� clear 
			positionT();
			break;
		case 2:
			printf("���� ������ �����մϴ�\n");
			countdown(5);
			wordT();
			break;
		case 3:
			printf("ª�� �� ������ �����մϴ�\n");
			countdown(5);
			SparagraphT();
			break;
		case 4:
			printf("�� �� ������ �����մϴ�\n");
			countdown(5);
			LparagraphT();
			break;
		case 5:
			printf("���α׷��� �����մϴ�");
			sleep(1);
			break;
	}
}

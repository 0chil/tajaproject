#include <stdio.h>
#include <termio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int getch(void)
{
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0,&save);
	buf=save;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN]=1;
	buf.c_cc[VTIME]=0;
	tcsetattr(0,TCSAFLUSH,&buf);
	ch=getchar();
	tcsetattr(0,TCSAFLUSH,&save);
	return ch;
}
void main()
{	
	srand(time(NULL));	
	char word[100][10]={"the","of","and","a","to","in","is","you","that","it","he","was","for","on","are","as","with","his","they","I","at","be","this","have","from","or","one","had","by","word","but","not","what","we","when","your","can","said","there","use","an","each","which","she","do","how","their","if","will","up","other","about","out","many","then","them","these","so","some","her","would","make","like","him","into","time","has","look","two","more","write","go","see","number","no","way","could","people","my","than","first","water","been","call","who","oil","its","now","find","long","down","day","did","get","come","made","may","part"};
	int userinput,try=0,wrong=0;
	system("clear");
	while(try<20)
	{	
		if(try==0)
			printf("진행율: %d%%  오타수 : %d  정확도 : %d%% \n",5*try,wrong,0);
		else
			printf("진행율: %d%%  오타수 : %d  정확도 : %d%% \n",5*try,wrong,(int)((double)100*((try-wrong)/try)));
		int random=rand()%100;
		printf("%s",word[random]);
		printf("\n");
		while(1)
		{
			userinput=getch();
			printf("%c",userinput);
			if(userinput==8)
				printf("\b \b");
			else if(userinput=='\n')
			{
				try++;		
				break;
			}
		}
	}
	printf("진행율: %d%%  오타수 : %d  정확도 : %d%% \n",5*try,wrong,(int)(100*((try-wrong)/try)));

	return;
}


















#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
void word()
{	
	srand(time(NULL));	
	char word[100][10]={"present","realize","the","of","and","a","to","in","is","you","that","it","he","was","for","on","are","as","with","his","they","I","at","be","this","have","from","or","one","had","by","word","but","not","what","we","when","your","can","said","there","use","an","each","which","she","do","how","their","if","will","up","other","about","out","many","then","them","these","so","some","her","would","make","like","him","into","time","has","look","two","more","write","go","see","number","no","way","could","people","my","than","first","water","been","call","who","oil","its","now","find","long","down","day","did","get","come","made","may","part"};
	int try=0,wrong=0,a;
	char out[]="###";
	system("clear");
	while(try<20)
	{	
		char userinput[30]={0};//입력값 넣을 배열 초기화
		if(try==0)
			printf("진행율: %d%%  오타수 : %d  정확도 : %d%% \n",5*try,wrong,0);
		else
			printf("진행율: %d%%  오타수 : %d  정확도 : %d%% \n",5*try,wrong,(int)(double)100*(try-wrong)/try);
		int random=rand()%100;
		printf("%s",word[random]);
		printf("\n");
		scanf("%s",&userinput);//입력
		try++;
		a=strcmp(userinput,out);
		if(a==0)
		{
			printf("메뉴로 돌아갑니다");
			sleep(3);
			main();
		}
		for(int i=0;i<10;i++)//오타수 결정
		{
			if(userinput[i]!=word[random][i])
			{
				wrong++;
				break;
			}
		}
		system("clear");
	}
	printf("메뉴로 돌아갑니다");
	sleep(3);
	main();
}


#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h> //getch()
int main(void)
{
	srand(time(NULL)); //랜덤함수 시드초기화
	int prog=0, ntype=0, htype=0, accu=0,corcnt=0, random = rand() % 30,len,inputn=0;
	char short_para[30][500] = { "To marry is to halve your rights and double your duties.","He makes no friend who never made a foe.","Common sense is the collection of prejudices acquired by age 18.","The unleashed power of the atom has changed everything save our modes of thinking, and we thus drift toward unparalleled catastrophes.","Nothing is more despicable than respect based on fear.","Television has proved that people will look at anything rather than each other.","It is only with the heart that one can see rightly; what is essential is invisible to the eye.","Love does not consist in gazing at each other, but in looking together in the same direction.","Business? It's quite simple. It's other people's money.","I would as soon leave my son a curse as the almighty dollar.","A great writer is, so to speak, a second government in his country. And for that reason no regime has ever loved great writers, only minor ones.","You don't live in a world all alone. Your brothers are here too.","A hungry man is not a free man.","To know is nothing at all; to imagine is everything.","Truth is generally the best vindication against slander.","It is my intention to present - through the medium of photography - intuitive observations of the natural world which may have meaning to the spectators.","America is a large, friendly dog in a very small room. Every time it wags its tail it knocks over a chair.","The secret of business is to know something that nobody else knows.","One man with courage makes a majority.","Television has a real problem. They have no page two.","Man is born to live, not to prepare for life. Life itself, the phenomenon of life, the gift of life, is so breathtakingly serious!","Like all great travellers, I have seen more than I remember, and remember more than I have seen.","The magic of first love is our ignorance that it can ever end.","When men are employed, they are best contented.","When she finally stopped conforming to the conventional picture of femininity she finally began to enjoy being a woman.","Anything you're good at contributes to happiness.","Accurst be he that first invented war.","Since a politician never believes what he says, he is surprised when others believe him.","A woman means by unselfishness chiefly taking trouble for others; a man means not giving trouble to others. Thus each sex regards the other as basically selfish.","Freedom is a system based on courage." };
	printf("정확도 : %d%%\n", accu);
	for (int i = 0; i < 500; i++) 
	{
		if (short_para[random][i] == 0)
		{
			len = (i-1)+1; // 배열의 값이 0이 되기 직전의 i값이 문장 길이이다.
			break;
		}
		printf("%c", short_para[random][i]);
	}
	printf("\n");
	char c,bef_c;
	while (len > inputn) {
		if ((c = getch()) == 27) {
			//ESC
			main();
		}
		else if ((c = getch()) == '\b') {
			//Backspace
			printf("\b \b");
			inputn--;
			if (bef_c == short_para[random][inputn])
				corcnt--;
		}
		else {
			//정상입력
			inputn++;
			bef_c = c;
			printf("%c", c);
			if (short_para[random][inputn] == c)
				corcnt++;
			accu = corcnt / inputn * 100; //정확도 %로 계산

		}
			
	}
}

#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <conio.h>  
#include <Windows.h>
#include <string.h>
#include <time.h>


void gotoxy(int xpos, int ypos)
{
  COORD scrn;    
 
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
 
  scrn.X = xpos; scrn.Y = ypos;
 
  SetConsoleCursorPosition(hOuput,scrn);
}

#define gWINDOW "mode con cols=65 lines=29"


//Объявление позиций (menu config)
	const char pOne[] = "New Game";
	const char pTwo[] = "Test";
	const char ext[] = "Exit";
	
	const int xsizeglob = 66;
	const int ysizeglob = 29;
	
	const int oX = xsizeglob/2-4; //позиция Gmenu по оси X 
	const int oY = 19; //Позиция Gmenu ро оси Y




void Gmenu()  //Прорисовка пунктов меню
{
	int k;
	gotoxy(oX,oY-3);
	puts(pOne);

	k=strlen(pOne)-strlen(pTwo);
	gotoxy(oX+(k/2),oY);
	puts(pTwo);
	
	k=strlen(pOne)-strlen(ext);
	gotoxy(oX+(k/2),oY+3);
	puts(ext);		
}

void pun1() 
{    
}
void pun2()
{	
}


void ss(int x, int c)
{
	int k;
	if (x==0) {
		gotoxy((oX-2),(oY-3));
		printf("->");
		gotoxy((strlen(pOne)+oX),(oY-3));
		printf("<-");
	    if (c==13) {
	    	pun1();
		}
	} else {
		gotoxy((oX-2),(oY-3));
		printf("  ");
		gotoxy((strlen(pOne)+oX),(oY-3));
		printf("  ");
	}
	
	k=strlen(pOne)-strlen(pTwo);
	if ((x==1)||(x==-2)) {
		gotoxy((oX-2+(k/2)),(oY));
		printf("->");
		gotoxy((strlen(pTwo)+oX+(k/2)),(oY));
		printf("<-");
		if (c==13) pun2();
	} else {
		gotoxy((oX-2+(k/2)),(oY));
		printf("  ");
		gotoxy((strlen(pTwo)+oX+(k/2)),(oY));
		printf("  ");
	}
	
	k=strlen(pOne)-strlen(ext);
	if ((x==2)||(x==-1)) {
		gotoxy((oX-2+(k/2)),(oY+3));
		printf("->");
		gotoxy((strlen(ext)+oX+(k/2)),(oY+3));
		printf("<-");
		if (c==13) {
			system("cls");
			gotoxy(xsizeglob/2-2,14);
			printf("Bye!");
			getch();
			exit(1);
			
		} 
		
	} else {
		gotoxy((oX-2+(k/2)),(oY+3));
		printf("  ");
		gotoxy((strlen(ext)+oX+(k/2)),(oY+3));
		printf("  ");
		}
}


int main()
{ 	
	system (gWINDOW);
	char c; int x,ic;
    x=0;
    Gmenu();
	while (true){

	ss(ic,c);
	c=getch();
	if (c=='w') x--;
	if (c=='s') x++;
	ic=x%3;

	}
	
}


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


void printsnake(int x,int y){
							 gotoxy(x,y);
	printf(" xXXXXx");  	 gotoxy(x,y+1);
	printf("XX    XX");	     gotoxy(x,y+2);
	printf(" XXx");	         gotoxy(x,y+3);
	printf("  xXXx");	     gotoxy(x,y+4);
	printf("    xXX");	     gotoxy(x,y+5);
	printf("XX    XX");  	 gotoxy(x,y+6);
	printf(" xXXXXx");
	
	
							 gotoxy(x+13,y);
	printf("XXx     XX"); 	 gotoxy(x+13,y+1);
	printf("XXXX    XX");	 gotoxy(x+13,y+2);
	printf("XX XX   XX"); 	 gotoxy(x+13,y+3);
	printf("XX  XX  XX");  	 gotoxy(x+13,y+4);
	printf("XX   XX XX");    gotoxy(x+13,y+5);
	printf("XX    XXXX");    gotoxy(x+13,y+6);
	printf("XX     xXX");
	
	
						     gotoxy(x+28,y);
	printf("   XXXXX");      gotoxy(x+28,y+1);
    printf("  xX   Xx");     gotoxy(x+28,y+2);
	printf("  Xx   xX");     gotoxy(x+28,y+3);
    printf(" xX     Xx");    gotoxy(x+28,y+4);
    printf(" XXXXXXXXX");    gotoxy(x+28,y+5);
    printf("xX       Xx");   gotoxy(x+28,y+6);
    printf("Xx       xX");
    
   							 gotoxy(x+44,y);
    printf("XX   XX");    	 gotoxy(x+44,y+1);
    printf("XX  XX");    	 gotoxy(x+44,y+2);
    printf("XX XX");    	 gotoxy(x+44,y+3);
    printf("XXXX");    		 gotoxy(x+44,y+4);
    printf("XX XX");		 gotoxy(x+44,y+5);
	printf("XX  XX");   	 gotoxy(x+44,y+6);
    printf("XX   XX");
    
    
    						 gotoxy(x+56,y);
    printf("XXXXXXX");  	 gotoxy(x+56,y+1);
    printf("XX");       	 gotoxy(x+56,y+2);
    printf("XX");       	 gotoxy(x+56,y+3);
    printf("XXXXX");    	 gotoxy(x+56,y+4);
    printf("XX");       	 gotoxy(x+56,y+5);
    printf("XX");       	 gotoxy(x+56,y+6);
    printf("XXXXXXX");
}


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
    printsnake(1,3);
	while (true){

	ss(ic,c);
	c=getch();
	if (c=='w') x--;
	if (c=='s') x++;
	ic=x%3;

	}
	
}


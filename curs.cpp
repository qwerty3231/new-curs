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

void mercanie()   //Штука убирающая мерцание курсора
{ 
	CONSOLE_CURSOR_INFO cci; 
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
    cci.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
}
// Настройки змейки	
	const int xtabl = 46;  // Ширина поля (max=119, !!! (xtabl%2=0) default 118) 
	const int ytabl = 29;  // Высота поля (max =29, default 29)
	const int maxl = xtabl*ytabl/2;  //Макситмальная длина змейки 

#define WINDOW "mode con cols=47 lines=31"  //Размер окна (xtabl+1, ytabl+2)
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
int spd()  //Уровень сложности
{
	int speed;
	spd:;
	system("cls");
	gotoxy(xtabl/2-8,14);	
	printf("Select lvl (1-10) ");
	gotoxy(xtabl/2,ytabl/2+2);
	scanf("%d",&speed);
	if ((speed>=1)&&(speed<=10)) speed = 325-(speed*25); else {
		system("cls");
		gotoxy(xtabl/2-3,ytabl/2);
		printf("ERROR!");
		getch();
		goto spd;
	} //
	return(speed);
	
}
void pun1() 
{    
    system (WINDOW);
	char c1,c;
	int x[maxl],y[maxl],i,rdx,rdy,l,mx,my,speed,boolean;
	srand(time(NULL));
	c='d';
	boolean=1;
	rdx=1;
    rdy=14;
	i=0; x[0]=1; y[0]=14;	
	speed=spd();	
	system("cls");
	gotoxy(xtabl/2-6,14);
	printf("Press any key ");
	getch();
    system("cls"); 		  
	while (true) {    //Начало игры


	if ((rdx==x[0]) && (rdy==y[0])) {
		i++;
		x[i]=x[0];
		y[i]=y[0];
		
		rd:;
		rdx=(((rand()+rand()+rand())/3)%(xtabl-2)/2*2)+1;
    	rdy=(((rand()+rand()+rand())/3)%(ytabl-2))+1;
		for (l=0;l!=i;l++) {
			if ((rdx==x[l])&&(rdy==y[l])) goto rd;
		}
	} 
	
	gotoxy(rdx,rdy);
	printf("O");
	

	l=i;
	while (l>0){
		gotoxy(x[l],y[l]);
		printf("#");
		l--;
	}

	if (c=='w') gotoxy(x[0],y[0]),printf("A");
	if (c=='s') gotoxy(x[0],y[0]),printf("V");
	if (c=='a') gotoxy(x[0],y[0]),printf("<");
	if (c=='d') gotoxy(x[0],y[0]),printf(">");

	l=i+1;
	while (l!=0) {
		x[l]=x[l-1];
		y[l]=y[l-1];		
		l--;
	}


	Sleep(speed/2);
	if (kbhit()!=0) c1=getch(),Sleep(speed/2); else Sleep(speed/2);
	if ((c1=='w')&&(c=='s') || (c1=='s')&&(c=='w') || (c1=='a')&&(c=='d') || (c1=='d')&&(c=='a'))
	{;} else {
		if ((c1=='w')||(c1=='s')||(c1=='a')||(c1=='d')) c=c1;
	}	
	if (c=='w') y[0]--;
	if (c=='s') y[0]++;
	if (c=='a') x[0]-=2; 
	if (c=='d') x[0]+=2;
	if (c1=='p') {
		Sleep(200);
		c1=getch();
	}
	
	
	if ((x[0]==(xtabl+1))||(x[0]==-1)||(y[0]==0)||(y[0])==ytabl) boolean=0;	
	l=i;
	while (l>0){
		if ((x[l]==x[0]) && (y[0]==y[l])) boolean=0;
		l--;
	}
	if (boolean==0) {
		gotoxy(xtabl/2-4,ytabl/2);
		printf("Game Over");
		getch();
	return;
	}
	
	gotoxy(x[1],y[1]);     
	printf("#");
	gotoxy(x[i+1],y[i+1]);
	printf(" ");
	
    }
	
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
	system("title SNAKE");
	mercanie();
    printsnake(1,3);
	while (true){

	ss(ic,c);
	c=getch();
	if (c=='w') x--;
	if (c=='s') x++;
	ic=x%3;

	}
	
}


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

void mercanie()  
{ 
	CONSOLE_CURSOR_INFO cci; 
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
    cci.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
}


	const int xtabl = 46;  
	const int ytabl = 29;  
	const int maxl = xtabl*ytabl/2;  

#define WINDOW "mode con cols=47 lines=31"  
#define gWINDOW "mode con cols=65 lines=29" 

	const char pOne[] = "New Game";
	const char pTwo[] = "Test";
	const char ext[] = "Exit";
	
	const int xsizeglob = 66;
	const int ysizeglob = 29;
	
	const int oX = xsizeglob/2-4;
	const int oY = 19; 
	
	const int l = 8; 



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



void ramki()
{
	int i;
	gotoxy(0,0);
	printf("\xc9");
	for (i=1;i!=xtabl;i++){
		printf("\xcd");
	}
	printf("\xbb\n");
	for(i=1;i!=ytabl;i++){
		printf("\xba");
		gotoxy(xtabl,i);
		printf("\xba\n");
	}
	printf("\xc8");
		for (i=1;i!=xtabl;i++){
		printf("\xcd");
	}
	printf("\xbc");
	gotoxy(2,30);
	printf("Length: ");
	gotoxy(37,30);
	printf("lvl:");
}

void Gmenu()
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

int spd() 
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
	} 
	return(speed);
	
}

void GameOver(int speed, int i){
			gotoxy(xtabl/2-4,ytabl/2);
			printf("Game Over");
			gotoxy(xtabl/2-7,ytabl/2+1);
			printf("Your Scrore: %d",((10000/speed)*i));
			Sleep(500);
			getch();
			system("cls");
			return;	
}

void pun1() 
{    
    system (WINDOW);
    
    char Button,_Button;
	int Speed;
	int Length;
	int Life = 1;
	struct _SnakePos{
		int X;
		int Y;
	}SnakePos[maxl];
	struct _FructPos{
		int RdX;
		int RdY;
	}FructPos;    
	srand(time(NULL));
	Life = 1;
	FructPos.RdX=1;
    FructPos.RdY=14;
	SnakePos[0].X = 1;
	SnakePos[0].Y = 14;
	Length=0;
	Button = 'd';	
	Speed=spd();	
	system("cls");
	gotoxy(xtabl/2-6,14);
	printf("Press any key ");
	getch();
    system("cls"); 	
    ramki();	  
	while (true) { 

	
	if ((FructPos.RdX==SnakePos[0].X)&&(FructPos.RdY==SnakePos[0].Y)){
		Length++;	
		Rand:;
		FructPos.RdX=(((rand()+rand()+rand())/3)%(xtabl-2)/2*2)+1;;
		FructPos.RdY=(((rand()+rand()+rand())/3)%(ytabl-2))+1;	
		for (int i=0;i!=Length;i++){
			if ((FructPos.RdX==SnakePos[i].X)&&(FructPos.RdY==SnakePos[i].Y)){
				goto Rand;
			}
		}		
	}
	
	gotoxy(FructPos.RdX,FructPos.RdY);
	printf("O");
	
	gotoxy(SnakePos[1].X,SnakePos[1].Y);
	printf("#");

	if (Button=='w') gotoxy(SnakePos[0].X,SnakePos[0].Y),printf("A");
	if (Button=='s') gotoxy(SnakePos[0].X,SnakePos[0].Y),printf("V");
	if (Button=='a') gotoxy(SnakePos[0].X,SnakePos[0].Y),printf("<");
	if (Button=='d') gotoxy(SnakePos[0].X,SnakePos[0].Y),printf(">");

	
	for (int i=Length+1;i!=0;i--){
		SnakePos[i].X=SnakePos[i-1].X;
		SnakePos[i].Y=SnakePos[i-1].Y;
	}
	
	Sleep(Speed/2);
	if (kbhit()!=0) _Button=getch();
	Sleep(Speed/2);
	if ((_Button=='w')&&(Button=='s') || (_Button=='s')&&(Button=='w') || (_Button=='a')&&(Button=='d') || (_Button=='d')&&(Button=='a')) {;} else {
		if ((_Button=='a') || (_Button=='d') || (_Button=='w') || (_Button=='s'))
			Button=_Button;
	}
	
	
	if (Button=='w') SnakePos[0].Y--;
	if (Button=='s') SnakePos[0].Y++;
	if (Button=='a') SnakePos[0].X-=2; 
	if (Button=='d') SnakePos[0].X+=2;
	if (Button=='p') {
		Sleep(200);
		Button=getch();
	}
	
	
	if ((SnakePos[0].X==(xtabl+1))||(SnakePos[0].X==-1)||(SnakePos[0].Y==0)||(SnakePos[0].Y==ytabl)){
		Life=0;
	}
	for (int i=Length;i>0;i--){
		if ((SnakePos[i].X==SnakePos[0].X)&&(SnakePos[i].Y==SnakePos[0].Y)){
			Life=0;
		}		
	}
	if (Life==0){
		GameOver(Speed,Length);
		return;
	}
	
	gotoxy(SnakePos[Length+1].X,SnakePos[Length+1].Y);
	printf(" ");
	
	
    gotoxy(10,30);     
	printf("%d",Length+1);
	gotoxy(42,30);             
	printf("%d",(325-Speed)/25);	
	
    }


			
}
void pun2()
{
	
	system("cls");
	ramki();
	getch();
	system("cls");
	
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
	    	system (gWINDOW);
	    	printsnake(1,3);
			Gmenu();
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
	int xsize = GetSystemMetrics(SM_CXSCREEN); 
	int ysize = GetSystemMetrics(SM_CYSCREEN);
	

	
	system (gWINDOW);
	system("title SNAKE");
	mercanie();

	   
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


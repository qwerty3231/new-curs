#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <ncurses.h>
void gotox(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
} 

	
	#define xtabl 30  // Øèðèíà ïîëÿ (max=119, !!! (xtabl%2=0) default 118) 
	#define ytabl 20  // Âûñîòà ïîëÿ (max =29, default 29)
	const int maxl = xtabl*ytabl/2;  //Ìàêñèòìàëüíàÿ äëèíà çìåéêè 

#define WINDOW "mode con cols=47 lines=31"  //Ðàçìåð îêíà (xtabl+1, ytabl+2)


//Îáúÿâëåíèå ïîçèöèé (menu config)
	const char pOne[] = "New Game";
	const char pTwo[] = "Test";
	const char ext[] = "Exit";
	
	#define xsizeglob 66
	#define ysizeglob 29
	
	const int oX = 29; //ïîçèöèÿ Gmenu ïî îñè X 
	#define oY 19 //Ïîçèöèÿ Gmenu ðî îñè Y
	



void printsnake(int x,int y){
							 gotox(x,y);
	printf(" xXXXXx");  	 gotox(x,y+1);
	printf("XX    XX");	     gotox(x,y+2);
	printf(" XXx");	         gotox(x,y+3);
	printf("  xXXx");	     gotox(x,y+4);
	printf("    xXX");	     gotox(x,y+5);
	printf("XX    XX");  	 gotox(x,y+6);
	printf(" xXXXXx");
	
	
							 gotox(x+13,y);
	printf("XXx     XX"); 	 gotox(x+13,y+1);
	printf("XXXX    XX");	 gotox(x+13,y+2);
	printf("XX XX   XX"); 	 gotox(x+13,y+3);
	printf("XX  XX  XX");  	 gotox(x+13,y+4);
	printf("XX   XX XX");    gotox(x+13,y+5);
	printf("XX    XXXX");    gotox(x+13,y+6);
	printf("XX     xXX");
	
	
						     gotox(x+28,y);
	printf("   XXXXX");      gotox(x+28,y+1);
    printf("  xX   Xx");     gotox(x+28,y+2);
	printf("  Xx   xX");     gotox(x+28,y+3);
    printf(" xX     Xx");    gotox(x+28,y+4);
    printf(" XXXXXXXXX");    gotox(x+28,y+5);
    printf("xX       Xx");   gotox(x+28,y+6);
    printf("Xx       xX");
    
   							 gotox(x+44,y);
    printf("XX   XX");    	 gotox(x+44,y+1);
    printf("XX  XX");    	 gotox(x+44,y+2);
    printf("XX XX");    	 gotox(x+44,y+3);
    printf("XXXX");    		 gotox(x+44,y+4);
    printf("XX XX");		 gotox(x+44,y+5);
	printf("XX  XX");   	 gotox(x+44,y+6);
    printf("XX   XX");
    
    
    						 gotox(x+56,y);
    printf("XXXXXXX");  	 gotox(x+56,y+1);
    printf("XX");       	 gotox(x+56,y+2);
    printf("XX");       	 gotox(x+56,y+3);
    printf("XXXXX");    	 gotox(x+56,y+4);
    printf("XX");       	 gotox(x+56,y+5);
    printf("XX");       	 gotox(x+56,y+6);
    printf("XXXXXXX");
}



void ramki()
{
	int i;
	system("clear");
	gotox(0,0);
	for (i=1;i!=xtabl;i++){
		printf("+");
	}
	printf("+\n");
	for(i=1;i!=ytabl;i++){
		gotox(0,i);
		printf("+");
		gotox(xtabl,i);
		printf("+");
	}
	gotox(0,ytabl);
		for (i=1;i!=xtabl;i++){
		printf("+");
	}
}

void Gmenu(int xsizeglob,int ysizeglob)
{
	int k;
	gotox(oX,oY-3);
	puts(pOne);

	k=strlen(pOne)-strlen(pTwo);
	gotox(oX+(k/2),oY);
	puts(pTwo);
	
	k=strlen(pOne)-strlen(ext);
	gotox(oX+(k/2),oY+3);
	puts(ext);		
}

int spd()
{
	int speed;
	spd:;
	system("clear");
	gotox(xtabl/2-8,14);	
	printf("Select lvl (1-10) ");
	gotox(xtabl/2,ytabl/2+2);
	scanf("%d",&speed);
	if ((speed>=1)&&(speed<=10)) speed = 325-(speed*25); else {
		system("clear");
		gotox(xtabl/2-3,ytabl/2);
		printf("ERROR!");
		getchar();
		goto spd;
	} 
	return(speed);
	
}

void GameOver(int speed, int i){
			gotox(xtabl/2-4,ytabl/2);
			printf("Game Over");
			gotox(xtabl/2-7,ytabl/2+1);
			printf("Your Scrore: %d",((10000/speed)*i));
			//sleep(500/1000);
			sleep(1);
			getchar();
			system("clear");
			return;	
}

char naprav(char Button){
	if (Button=='w') return 'A';
	if (Button=='s') return 'V';
	if (Button=='a') return '<';
	if (Button=='d') return '>';
}

void pun1() 
{    
    
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
	system("clear");
	gotox(xtabl/2-6,14);
	printf("Press any key ");
	getchar();
    system("clear"); 	
    ramki();	  
	while (1) {    //Íà÷àëî èãðû

	
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
	
	gotox(FructPos.RdX,FructPos.RdY);
	printf("O");
	
	gotox(SnakePos[1].X,SnakePos[1].Y);
	printf("@");

	gotox(SnakePos[0].X,SnakePos[0].Y);
	printf("%c",naprav(Button));

	
	for (int i=Length+1;i!=0;i--){
		SnakePos[i].X=SnakePos[i-1].X;
		SnakePos[i].Y=SnakePos[i-1].Y;
	}
	
	//sleep(Speed/2000);
	sleep(1);
	if (kbhit()!=0) _Button=getchar();
	//sleep(Speed/2000);
	sleep(1);
	if (((_Button=='w')&&(Button=='s')) || ((_Button=='s')&&(Button=='w')) || ((_Button=='a')&&(Button=='d')) || ((_Button=='d')&&(Button=='a'))){;} else {
		if ((_Button=='a') || (_Button=='d') || (_Button=='w') || (_Button=='s'))
			Button=_Button;
	}
	
	
	if (Button=='w') SnakePos[0].Y--;
	if (Button=='s') SnakePos[0].Y++;
	if (Button=='a') SnakePos[0].X-=2; 
	if (Button=='d') SnakePos[0].X+=2;
	if (Button=='p') {
		//sleep(200/1000);
		sleep(1);
		Button=getchar();
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
	
	gotox(SnakePos[Length+1].X,SnakePos[Length+1].Y);
	printf(" ");	
	
    }


			
}
void pun2()
{
	
	system("clear");
	ramki();
	getchar();
	system("clear");
	
}


void ss(int x, int c)
{
	int k;
	if (x==0) {
		gotox((oX-2),(oY-3));
		printf("->");
		gotox((strlen(pOne)+oX),(oY-3));
		printf("<-");
	    if (c==13) {
		system("clear");
	    	pun1();
		return;
	    	printsnake(1,3);
			Gmenu(66,29);
		}
	} else {
		gotox((oX-2),(oY-3));
		printf("  ");
		gotox((strlen(pOne)+oX),(oY-3));
		printf("  ");
	}
	
	k=strlen(pOne)-strlen(pTwo);
	if ((x==1)||(x==-2)) {
		gotox((oX-2+(k/2)),(oY));
		printf("->");
		gotox((strlen(pTwo)+oX+(k/2)),(oY));
		printf("<-");
		if (c==13) pun2();
	} else {
		gotox((oX-2+(k/2)),(oY));
		printf("  ");
		gotox((strlen(pTwo)+oX+(k/2)),(oY));
		printf("  ");
	}
	
	k=strlen(pOne)-strlen(ext);
	if ((x==2)||(x==-1)) {
		gotox((oX-2+(k/2)),(oY+3));
		printf("->");
		gotox((strlen(ext)+oX+(k/2)),(oY+3));
		printf("<-");
		if (c==13) {
			system("clear");
			gotox(66/2-2,14);
			printf("Bye!");
			getchar();
			exit(1);
			
		} 
		
	} else {
		gotox((oX-2+(k/2)),(oY+3));
		printf("  ");
		gotox((strlen(ext)+oX+(k/2)),(oY+3));
		printf("  ");
		}
}


int main()
{ 	
	

	

	   
	char c; int x,ic;
    x=0;
    Gmenu(66,29);
	printsnake(1,3);
	while (1){

	ss(ic,c);
	c=getchar();
	if (c=='w') x--;
	if (c=='s') x++;
	ic=x%3;

	}
	
}

  

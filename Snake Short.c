#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"conio3.h"
int M[16][16]={0}, dir=0, pX=5, pY=5, l=3;
void random(){
	int iX, iY;
	do{
		iX=(rand()%15)+1;
		iY=(rand()%15)+1;
	}while(M[iX][iY]!=0);
	M[iX][iY]=-1;
}
void printM(){
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			if(j==0) printf("%c",219);
			if(i==0){
				printf("%c%c",219,219);
			}
			if(i!=0){
				setcolor(YELLOW,BLACK);
				if(M[i][j]==-1) printf("%c ",254);				 
				else { setcolor(WHITE,BLACK); M[i][j]>0 ? printf("%c ", 254) : printf("  ");}
			}
		}
		printf("%c\n",219);
	}
	for(int i=0;i<=16;i++) printf("%c%c",219,219);
}
void gameover(){
	printf("\n\nGAME OVER!\n\n");
	system("PAUSE");
	exit(0);
}
void move(){
	for(int i=0, p=0;i<16;i++){
		for(int j=0;j<16;j++){
			if(M[i][j]>0&&p<=l) {M[i][j]--; p++;}
		}
	}
	if(dir==0) pY<15 ? pY++ : gameover();
	if(dir==1) pX<15 ? pX++ : gameover();
	if(dir==2) pY>0 ? pY-- : gameover();
	if(dir==3) pX>0 ? pX-- : gameover();
	if(M[pX][pY]>0) gameover();
	if(M[pX][pY]==-1){ l++; random(); }
	M[pX][pY]=l;
}
void direction(){
	delay(200);
	if(kbhit()){
		switch (getch()) { 
			case 72: if(dir!=1) dir=3; 
				break; 
			case 75: if(dir!=0) dir=2; 
				break; 
			case 77: if(dir!=2) dir=0; 
				break; 
			case 80: if(dir!=3) dir=1; 
				break;
		}
	}
}
int main(void){
	srand(time(NULL));
	random();
	while(1){
		printM();
		direction();
		move();
		clrscr();
	}
	return 0;
}

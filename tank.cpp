#include "Tank.h"
#include "levels.h"
#include "menu.h"
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include "kivlan.h"
#include "alpin.h"
#include "fikri.h"
#include "fadhil.h"
#include "naufal.h"
#include "fahri.h"
#define SPEED 5

#define SObjek 40

/*------------------------------------------------------------------------------------------------------*/

void Move_Place_XY(PP PlayerP) //modul memindahkan kordinat untuk penggambaran Tank
{
	switch(PlayerP->KEY)
	{
		case 72:
		{
			PlayerP->Top-=SPEED;
			PlayerP->Bottom-=SPEED;
			break;
		}
		case 80:
		{
			PlayerP->Top+=SPEED;
			PlayerP->Bottom+=SPEED;
			break;
		}
		case 75:
		{
			PlayerP->Left-=SPEED;
			PlayerP->Right-=SPEED;
			break;
		}
		case 77:
		{
			PlayerP->Left+=SPEED;
			PlayerP->Right+=SPEED;
			break;
		}
	}
}

/*------------------------------------------------------------------------------------------------------*/

void Hapus_Tank(PP PlayerP) //modul hapus dengan cara menggambar ulang dengan background
{
	int T = PlayerP->Top;
	int L = PlayerP->Left;
	
	setcolor(YELLOW);
	rectangle(L, T, L+SObjek-2, T+SObjek-2);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(L+1, T+1, YELLOW);
	setcolor(BLACK);
	rectangle(L, T, L+SObjek-2, T+SObjek-2);
	setcolor(WHITE);
}

/*------------------------------------------------------------------------------------------------------*/

void Tank(PP PlayerP)// menggambar Tank
{
	int T = PlayerP->Top;
	int L = PlayerP->Left;
	int R = PlayerP->Right;
	int B = PlayerP->Bottom;
	
	
	switch(PlayerP->KEY)
	{
		case 72://atas
		{
		//	ergebeh(T);
			
			if(T%2==0)
			{
				readimagefile("Images/TankT1.bmp",L,T,R,B);
			}
			else
			{
				readimagefile("Images/TankT2.bmp",L,T,R,B);
			}
			break;
		}
		case 80://bawah
		{
		//	ergebeh(B);
			
			if(T%2==0)
			{
				readimagefile("Images/TankB1.bmp",L,T,R,B);
			}
			else
			{
				readimagefile("Images/TankB2.bmp",L,T,R,B);
			}
			break;
		}
		case 75://kiri
		{
		//	ergebeh(L);
			
			if(L%2==0)
			{
				readimagefile("Images/TankL1.bmp",L,T,R,B);
			}
			else
			{
				readimagefile("Images/TankL2.bmp",L,T,R,B);
			}
			break;
		}
		case 77://kanan
		{
		//	ergebeh(R);
			
			if(L%2==0)
			{
				readimagefile("Images/TankR1.bmp",L,T,R,B);
			}
			else
			{
				readimagefile("Images/TankR2.bmp",L,T,R,B);
			}
			break;
		}
	}
}

/*------------------------------------------------------------------------------------------------------*/

void Count_Move(PP PlayerP)//count sebagai banyaknya gerak untuk memindahkan array sebuah Tank
{
	switch(PlayerP->KEY)
	{
		case 72:
		{
			PlayerP->countV-=1;
			if(PlayerP->countV==-8)
			{
				Map_Arena[PlayerP->i][PlayerP->j]=0;
				PlayerP->i-=1;
				Map_Arena[PlayerP->i][PlayerP->j]=PlayerP->ID;
				PlayerP->countV=0;
			}
			break;
		}
		case 80:
		{
			PlayerP->countV+=1;
			if(PlayerP->countV==8)
			{
				Map_Arena[PlayerP->i][PlayerP->j]=0;
				PlayerP->i+=1;
				Map_Arena[PlayerP->i][PlayerP->j]=PlayerP->ID;
				PlayerP->countV=0;
			}
			break;
		}
		case 75:
		{
			PlayerP->countH-=1;
			if(PlayerP->countH==-8)
			{
				Map_Arena[PlayerP->i][PlayerP->j]=0;
				PlayerP->j-=1;
				Map_Arena[PlayerP->i][PlayerP->j]=PlayerP->ID;
				PlayerP->countH=0;
			}
			break;
		}
		case 77:
		{
			PlayerP->countH+=1;
			if(PlayerP->countH==8)
			{
				Map_Arena[PlayerP->i][PlayerP->j]=0;
				PlayerP->j+=1;
				Map_Arena[PlayerP->i][PlayerP->j]=PlayerP->ID;
				PlayerP->countH=0;
			}
			break;
		}
	}
}

/*------------------------------------------------------------------------------------------------------*/

void Shift(PP PlayerP)//mengelompokan pemindahan kordinat, vertical dan horizontal
{
	Count_Move(PlayerP);
	Hapus_Tank(PlayerP);
	Move_Place_XY(PlayerP);
	Tank(PlayerP);
}

/*------------------------------------------------------------------------------------------------------*/

void Jalan_Tank(PP PlayerP)//prosedur utama untuk menjalankan Tank
{
	int countA, countB;
	
	if(PlayerP->KEY==72 or PlayerP->KEY==80)
	{
		countA = PlayerP->countH;
		countB = PlayerP->countV;
	}
	else if(PlayerP->KEY==75 or PlayerP->KEY==77)
	{
		countA = PlayerP->countV;
		countB = PlayerP->countH;
	}
	//program di bawah ini sebuah collision
	if(countA>0)//jika di suatu array kemudian melebihi suatu tempat
	{
		if(countB!=0 and Map_Arena[PlayerP->i][PlayerP->j]==0)//jika pindah dan kembali ke posisi awal
		{
			Shift(PlayerP);
		}
		else
		{
			switch(PlayerP->KEY)
			{
				case 72:
				{
					if(Map_Arena[PlayerP->i-1][PlayerP->j]==0 and Map_Arena[PlayerP->i-1][PlayerP->j+1]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 80:
				{
					if(Map_Arena[PlayerP->i+1][PlayerP->j]==0 and Map_Arena[PlayerP->i+1][PlayerP->j+1]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 75:
				{
					if(Map_Arena[PlayerP->i][PlayerP->j-1]==0 and Map_Arena[PlayerP->i+1][PlayerP->j-1]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 77:
				{
					if(Map_Arena[PlayerP->i][PlayerP->j+1]==0 and Map_Arena[PlayerP->i+1][PlayerP->j+1]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
			}
		}
	}
	else if(countA<0)//jika di suatu array kemudian kurang dari suatu tempat
	{
		if(countB!=0 and Map_Arena[PlayerP->i][PlayerP->j]==0)//jika pindah dan kembali ke posisi awal
		{
			Shift(PlayerP);
		}
		else
		{
			switch(PlayerP->KEY)
			{
				case 72:
				{
					if(Map_Arena[PlayerP->i-1][PlayerP->j-1]==0 and Map_Arena[PlayerP->i-1][PlayerP->j]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 80:
				{
					if(Map_Arena[PlayerP->i+1][PlayerP->j-1]==0 and Map_Arena[PlayerP->i+1][PlayerP->j]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 75:
				{
					if(Map_Arena[PlayerP->i][PlayerP->j-1]==0 and Map_Arena[PlayerP->i-1][PlayerP->j-1]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 77:
				{
					if(Map_Arena[PlayerP->i][PlayerP->j+1]==0 and Map_Arena[PlayerP->i-1][PlayerP->j+1]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
			}
		}
	}
	else if(countA==0)//berada tepat di 1 posisi/array
	{
		if(countB!=0 and Map_Arena[PlayerP->i][PlayerP->j]==0)//jika pindah dan kembali ke posisi awal
		{
			Shift(PlayerP);
		}
		else
		{
			switch(PlayerP->KEY)
			{
				case 72:
				{
					if(Map_Arena[PlayerP->i-1][PlayerP->j]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 80:
				{
					if(Map_Arena[PlayerP->i+1][PlayerP->j]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 75:
				{
					if(Map_Arena[PlayerP->i][PlayerP->j-1]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
				case 77:
				{
					if(Map_Arena[PlayerP->i][PlayerP->j+1]==0)
					{
						Shift(PlayerP);
					}
					break;
				}
			}
		}
	}
}

/*------------------------------------------------------------------------------------------------------*/

void Gerak_Tank(PP PlayerP)
{
//	countA=sebagai patokan apakah dia (-) ataupun (+)
//	countB=yang digunakan ketika Jalan_Tank
	int rotation;
	PlaySound(TEXT("Sounds/move.wav"), NULL, SND_ASYNC);
	switch(PlayerP->KEY)
	{
		case 72://atas
		{
			rotation=1;
			break;
		}
		case 80://bawah
		{
			rotation=2;
			break;
		}
		case 75://kiri
		{
			rotation=3;
			break;
		}
		case 77://kanan
		{
			rotation=4;
			break;
		}
	}
	if(PlayerP->ARAH!=rotation)		//rotasi
	{
		Hapus_Tank(PlayerP);
		Tank(PlayerP);
		PlayerP->ARAH = rotation;
	}
	else 
	{
		Jalan_Tank(PlayerP);
	}
}

/*------------------------------------------------------------------------------------------------------*/

void Developer(PP PlayerP)
{
	char arr[50];
//	settextstyle(4,HORIZ_DIR,1);
	outtextxy(1000,400,"Score");
/*	outtextxy(890,40,"DEVELOPER Menu");
	outtextxy(900,80,"POSH");
	outtextxy(950,80,"POSV");
	outtextxy(870,130,"BulletV");
	outtextxy(950,130,"BulletH");
	outtextxy(870,180,"Baris");
	outtextxy(950,180,"Kolom");
	outtextxy(870,230,"ElemenA");
	outtextxy(950,230,"ElemenB");
	outtextxy(870,280,"bulletb");
	outtextxy(950,280,"bulletk");
	outtextxy(950,330,"Score");
		setcolor(DARKGRAY);
		rectangle(889,99,976,114);
		rectangle(889,149,976,164);
		rectangle(889,199,976,214);
		rectangle(889,249,976,264);
		rectangle(889,299,976,314);
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(900,100,DARKGRAY);
		floodfill(900,150,DARKGRAY);
		floodfill(900,200,DARKGRAY);
		floodfill(900,250,DARKGRAY);
		floodfill(900,300,DARKGRAY);
		setcolor(BLACK);
		rectangle(889,99,976,116);
		rectangle(889,149,976,164);
		rectangle(889,199,976,216);
		rectangle(889,249,976,264);
		rectangle(889,299,976,314);
		setcolor(WHITE);
	sprintf(arr,"%d",PlayerP->posH);
	outtextxy(900,100,arr);
	sprintf(arr,"%d",PlayerP->posV);
	outtextxy(950,100,arr);
//	sprintf(arr,"%d",countBulletv);
//	outtextxy(900,150,arr);
//	sprintf(arr,"%d",countBulleth);
//	outtextxy(950,150,arr);
	sprintf(arr,"%d",PlayerP->i);
	outtextxy(900,200,arr);
	sprintf(arr,"%d",PlayerP->j);
	outtextxy(950,200,arr);
//	sprintf(arr,"%d",ElemenA);
//	outtextxy(900,250,arr);
//	sprintf(arr,"%d",PlayerP->ElemenB);
//	outtextxy(950,250,arr);
//	sprintf(arr,"%d",bulletb);
//	outtextxy(900,300,arr);
//	sprintf(arr,"%d",bulletk);
	outtextxy(950,300,arr);*/
	sprintf(arr,"%d",PlayerP->score);
	outtextxy(1000,450,arr);	
}
void GameOver(PP PlayerP){
	cleardevice();
	readimagefile("Gambar/GameOver.jpg",0,0,1200,700);
	free(PlayerP);
	if (getch()){
		GT();
	}
}
/*------------------------------------------------------------------------------------------------------*/
void ImpactAtas(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth){
				if (Map_Arena[bulletb-*ElemenA][bulletk]==0 || Map_Arena[bulletb-*ElemenA][bulletk]==4)
				{
					setcolor(BLACK);
					rectangle(*xBullet+14, *yBullet-20, *xBullet+17, *yBullet-SObjek);
					*yBullet-=SPEED;
					setcolor(WHITE);
					rectangle(*xBullet+14, *yBullet-20, *xBullet+17, *yBullet-SObjek);
					if(Map_Arena[bulletb-*ElemenA][bulletk]==4)
					{
						int T = (bulletb-*ElemenA), L = bulletk;
						readimagefile("Images/Water.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					}
					delay(SPEED);
				//	break;
				}
				else if(Map_Arena[bulletb-*ElemenA][bulletk]==1)
				{
					setcolor(BLACK);
					rectangle(*xBullet+14, *yBullet-20, *xBullet+17, *yBullet-SObjek);
					setcolor(WHITE);
					Map_Arena[bulletb-*ElemenA][bulletk]=0;
					int T = (bulletb-*ElemenA), L = bulletk;
					PlaySound(TEXT("Sounds/destroyed.wav"), NULL, SND_ASYNC);
					PlayerP->score+=50;
					setcolor(YELLOW);
					rectangle(L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					setfillstyle(SOLID_FILL,BLACK);
					floodfill((L*SObjek)+1,(T*SObjek)+1,YELLOW);
					setcolor(BLACK);
					rectangle(L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
				//	break;
				}
				else if(Map_Arena[bulletb-*ElemenA][bulletk]==2)
				{
					setcolor(BLACK);
					rectangle(*xBullet+14, *yBullet-20, *xBullet+17, *yBullet-SObjek);
					setcolor(WHITE);
					int T = (bulletb-*ElemenA), L = bulletk;
					Map_Arena[bulletb-*ElemenA][bulletk]=1;
					PlaySound(TEXT("Sounds/destroyed.wav"), NULL, SND_ASYNC);
					readimagefile("Images/Brick_Broken.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
				//	break;	
				}
				else if(Map_Arena[bulletb-*ElemenA][bulletk]==3)
				{
					setcolor(BLACK);
					rectangle(*xBullet+14, *yBullet-20, *xBullet+17, *yBullet-SObjek);
					setcolor(WHITE);
					int T = (bulletb-*ElemenA), L = bulletk;
					PlaySound(TEXT("Sounds/steel.wav"), NULL, SND_ASYNC);
					readimagefile("Images/Steel.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
				//	break;	
				}
				else if(Map_Arena[bulletb-*ElemenA][bulletk]==5)
				{
					bulletb = 0;
					bulletk = 0;
					*ElemenA = 0;
					*Tembak=0;
					GameOver(PlayerP);
				}
}

void ImpactBawah(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth){
				if (Map_Arena[bulletb+*ElemenA][bulletk]==0 || Map_Arena[bulletb+*ElemenA][bulletk]==4)
				{
					setcolor(BLACK);
					rectangle(*xBullet+14, *yBullet+20, *xBullet+17, *yBullet+SObjek);
					*yBullet+=SPEED;
					setcolor(WHITE);
					rectangle(*xBullet+14, *yBullet+20, *xBullet+17, *yBullet+SObjek);
					if(Map_Arena[bulletb+*ElemenA][bulletk]==4)
					{
						int T = (bulletb+*ElemenA), L = bulletk;
						readimagefile("Images/Water.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					}
					delay(SPEED);
					//break;
				}
				else if(Map_Arena[bulletb+*ElemenA][bulletk]==1 )
				{
					setcolor(BLACK);
					rectangle(*xBullet+14, *yBullet+20, *xBullet+17, *yBullet+SObjek);
					setcolor(WHITE);
					Map_Arena[bulletb+*ElemenA][bulletk]=0;
					PlaySound(TEXT("Sounds/destroyed.wav"), NULL, SND_ASYNC);
					PlayerP->score+=50;
					PlayerP->KEY = 80;
					int T = (bulletb+*ElemenA), L = bulletk;
					setcolor(YELLOW);
					rectangle(L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					setfillstyle(SOLID_FILL,BLACK);
					floodfill((L*SObjek)+1,(T*SObjek)+1,YELLOW);
					setcolor(BLACK);
					rectangle(L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
					//break;
				}
				else if(Map_Arena[bulletb+*ElemenA][bulletk]==2)
				{
					setcolor(BLACK);
					rectangle(*xBullet+14, *yBullet+20, *xBullet+17, *yBullet+SObjek);
					setcolor(WHITE);
					int T = (bulletb+*ElemenA), L = bulletk;
					Map_Arena[bulletb+*ElemenA][bulletk]=1;
					PlaySound(TEXT("Sounds/destroyed.wav"), NULL, SND_ASYNC);
					readimagefile("Images/Brick_Broken.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
					//break;	
				}
				else if(Map_Arena[bulletb+*ElemenA][bulletk]==3)
				{
					setcolor(BLACK);
					rectangle(*xBullet+14, *yBullet+20, *xBullet+17, *yBullet+SObjek);
					setcolor(WHITE);
					int T = (bulletb+*ElemenA), L = bulletk;
					PlaySound(TEXT("Sounds/steel.wav"), NULL, SND_ASYNC);
					readimagefile("Images/Steel.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
					//break;	
				}
				else if(Map_Arena[bulletb+*ElemenA][bulletk]==5){
					bulletb = 0;
					bulletk = 0;
					*ElemenA = 0;
					*Tembak=0;
					GameOver(PlayerP);
				}
}

void ImpactKiri(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth){
				if (Map_Arena[bulletb][bulletk-*ElemenA]==0 || Map_Arena[bulletb][bulletk-*ElemenA]==4)
				{
					setcolor(BLACK);
					rectangle(*xBullet-20, *yBullet+14, *xBullet-SObjek, *yBullet+17);
					*xBullet-=SPEED;
					setcolor(WHITE);
					rectangle(*xBullet-20, *yBullet+14, *xBullet-SObjek, *yBullet+17);
					if(Map_Arena[bulletb][bulletk-*ElemenA]==4)
					{
						int T = bulletb, L = bulletk-*ElemenA;
						readimagefile("Images/Water.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					}
					delay(SPEED);
					//break;
				}
				else if(Map_Arena[bulletb][bulletk-*ElemenA]==1)
				{
					setcolor(BLACK);
					rectangle(*xBullet-20, *yBullet+14, *xBullet-SObjek, *yBullet+17);
					setcolor(WHITE);
					Map_Arena[bulletb][bulletk-*ElemenA]=0;
					PlaySound(TEXT("Sounds/destroyed.wav"), NULL, SND_ASYNC);
					PlayerP->score+=50;
					PlayerP->KEY = 75;
					int T = bulletb, L = bulletk-*ElemenA;
					setcolor(YELLOW);
					rectangle(L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					setfillstyle(SOLID_FILL,BLACK);
					floodfill((L*SObjek)+1,(T*SObjek)+1,YELLOW);
					setcolor(BLACK);
					rectangle(L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
					//break;
				}
				else if(Map_Arena[bulletb][bulletk-*ElemenA]==2)
				{
					setcolor(BLACK);
					rectangle(*xBullet-20, *yBullet+14, *xBullet-SObjek, *yBullet+17);
					setcolor(WHITE);
					int T = bulletb, L = bulletk-*ElemenA;
					Map_Arena[bulletb][bulletk-*ElemenA]=1;
					PlaySound(TEXT("Sounds/destroyed.wav"), NULL, SND_ASYNC);
					readimagefile("Images/Brick_Broken.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
					//break;
				}
				else if(Map_Arena[bulletb][bulletk-*ElemenA]==3)
				{
					setcolor(BLACK);
					rectangle(*xBullet-20, *yBullet+14, *xBullet-SObjek, *yBullet+17);
					setcolor(WHITE);
					int T = bulletb, L = bulletk-*ElemenA;
					PlaySound(TEXT("Sounds/steel.wav"), NULL, SND_ASYNC);
					readimagefile("Images/Steel.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;
					//break;
				}
				else if(Map_Arena[bulletb][bulletk-*ElemenA]==5)
				{
					bulletb = 0;
					bulletk = 0;
					*ElemenA = 0;
					*Tembak=0;
					GameOver(PlayerP);
				}
}

void ImpactKanan(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth){
			if (Map_Arena[bulletb][bulletk+*ElemenA]==0 || Map_Arena[bulletb][bulletk+*ElemenA]==4)
				{
					setcolor(BLACK);
					rectangle(*xBullet+20, *yBullet+14, *xBullet+SObjek, *yBullet+17);
					*xBullet+=SPEED;
					setcolor(WHITE);
					rectangle(*xBullet+20, *yBullet+14, *xBullet+SObjek, *yBullet+17);
					if(Map_Arena[bulletb][bulletk+*ElemenA]==4)
					{
						int T = bulletb, L = bulletk+*ElemenA;
						readimagefile("Images/Water.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					}
					delay(SPEED);
				//	break;
				}
				else if(Map_Arena[bulletb][bulletk+*ElemenA]==1)
				{
					setcolor(BLACK);
					rectangle(*xBullet+20, *yBullet+14, *xBullet+SObjek, *yBullet+17);
					setcolor(WHITE);
					Map_Arena[bulletb][bulletk+*ElemenA]=0;
					PlaySound(TEXT("Sounds/destroyed.wav"), NULL, SND_ASYNC);
					PlayerP->score+=50;
					PlayerP->KEY = 77;
					int T = bulletb, L = bulletk+*ElemenA;
					setcolor(YELLOW);
					rectangle(L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					setfillstyle(SOLID_FILL,BLACK);
					floodfill((L*SObjek)+1,(T*SObjek)+1,YELLOW);
					setcolor(BLACK);
					rectangle(L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);

					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;					
					//break;
				}
				else if(Map_Arena[bulletb][bulletk+*ElemenA]==2)
				{
					setcolor(BLACK);
					rectangle(*xBullet+20, *yBullet+14, *xBullet+SObjek, *yBullet+17);
					int T = bulletb, L = bulletk+*ElemenA;
					Map_Arena[bulletb][bulletk+*ElemenA]=1;
					PlaySound(TEXT("Sounds/destroyed.wav"), NULL, SND_ASYNC);
					readimagefile("Images/Brick_Broken.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					setcolor(WHITE);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;				
					//break;
				}
				else if(Map_Arena[bulletb][bulletk+*ElemenA]==3)
				{
					setcolor(BLACK);
					rectangle(*xBullet+20, *yBullet+14, *xBullet+SObjek, *yBullet+17);
					int T = bulletb, L = bulletk+*ElemenA;
					PlaySound(TEXT("Sounds/steel.wav"), NULL, SND_ASYNC);
					readimagefile("Images/Steel.bmp",L*SObjek,T*SObjek,(L*SObjek)+SObjek-1,(T*SObjek)+SObjek-1);
					setcolor(WHITE);
					*Tembak=0;
					*countBulletv=0;
					*countBulleth=0;
					*ElemenA=0;				
					//break;
				}
				else if(Map_Arena[bulletb][bulletk+*ElemenA]==5)
				{
					bulletb = 0;
					bulletk = 0;
					*ElemenA = 0;
					*Tembak=0;
					GameOver(PlayerP);
				}	
}
void BulletImpact(PP Player,int Arah,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *isTembak,int *countBulletv,int *countBulleth){
	switch(Arah){
		case 1:{
			ImpactAtas(Player,bulletb,bulletk,ElemenA,xBullet,yBullet,isTembak,countBulletv,countBulleth);
			break;
		}
		case 2:{
			ImpactBawah(Player,bulletb,bulletk,ElemenA,xBullet,yBullet,isTembak,countBulletv,countBulleth);
			break;
		}
		case 3:{
			ImpactKiri(Player,bulletb,bulletk,ElemenA,xBullet,yBullet,isTembak,countBulletv,countBulleth);
			break;
		}
		case 4:{
			ImpactKanan(Player,bulletb,bulletk,ElemenA,xBullet,yBullet,isTembak,countBulletv,countBulleth);
			break;
		}
	}
}

void SetPosTembak(int Arah,PP PlayerP,int *countBulletv,int *countBulleth,int *bulletk,int *bulletb){
	
	switch(Arah){
		case 1:{
				*countBulletv=PlayerP->countV;
				*countBulleth=PlayerP->countH;
				if (PlayerP->countH<=(-4)){
					*bulletk=PlayerP->j-1;
				}
				else if(PlayerP->countH>4)
				{
					*bulletk=PlayerP->j+1;
				}
				else
				{
					*bulletk=PlayerP->j;
				}
				*bulletb=PlayerP->i-1;
			break;
		}
		case 2:{
				*countBulletv=PlayerP->countV;
				*countBulleth=PlayerP->countH;
				if (PlayerP->countH<=(-4))
				{
					*bulletk=PlayerP->j-1;
				}
				else if(PlayerP->countH>4)
				{
					*bulletk=PlayerP->j+1;
				}
				else
				{
					*bulletk=PlayerP->j;
				}
					*bulletb=PlayerP->i+1;
			break;
		}
		case 3:{
				*countBulletv=PlayerP->countV;
				*countBulleth=PlayerP->countH;
				if (PlayerP->countV<=(-4))
				{
					*bulletb=PlayerP->i-1;
				}
				else if(PlayerP->countV>4)
				{
					*bulletb=PlayerP->i+1;
				}
				else
				{
					*bulletb=PlayerP->i;
				}
				*bulletk=PlayerP->j-1;
			break;
		}
		case 4:{
				*countBulletv=PlayerP->countV;
				*countBulleth=PlayerP->countH;
				if (PlayerP->countV<=(-4))
				{
					*bulletb=PlayerP->i-1;
				}
				else if(PlayerP->countV>4)
				{
					*bulletb=PlayerP->i+1;
				}
				else
				{
					*bulletb=PlayerP->i;
				}
				*bulletk=PlayerP->j+1;
			break;
		}
	}
}


void Player(PP PlayerP,PP PlayerC)
{
	static int ARAHTEMBAKAN = 0, Tembak = 0;
	static int xBullet = 0, yBullet = 0,countBulletv = 0, countBulleth = 0, ElemenA = 0;
	static int  bulletb = 0, bulletk = 0, Tes = 0;
	static char arr[50];
	static bool tembak = false;

	Developer(PlayerP);
	if(kbhit())
	{
		PlayerP->KEY = getch();
		switch(PlayerP->KEY)
		{
			case 72:			//atas
			{
				Gerak_Tank(PlayerP);
				break;
			}
			case 80:			//bawah
			{
				Gerak_Tank(PlayerP);
				break;
			}
			case 75:			//kiri
			{
				Gerak_Tank(PlayerP);
				break;
			}
			case 77:			//kanan
			{
				Gerak_Tank(PlayerP);
				break;
			}
			case 32: //pilihan tembak sesuai arahnya
			{
				
				if(Tembak==0)
				{
					PlaySound(TEXT("Sounds/shoot_3.wav"), NULL, SND_ASYNC);
					tembak=true;
					switch(PlayerP->ARAH)
					{
						case 1:
						{
							xBullet = PlayerP->Left+4;
							yBullet = PlayerP->Top;
							ARAHTEMBAKAN=1;
							break;
						}
						case 2:
						{
							xBullet = PlayerP->Left+4;
							yBullet = PlayerP->Top+SObjek;
							ARAHTEMBAKAN=2;
							break;
						}
						case 3:
						{
							xBullet = PlayerP->Left;
							yBullet = PlayerP->Top+4;
							ARAHTEMBAKAN=3;
							break;
						}
						case 4:
						{
							xBullet = PlayerP->Left+SObjek;
							yBullet = PlayerP->Top+4;
							ARAHTEMBAKAN=4;
							break;
						}
					}
				}
				Tembak=1;
				break;
			}
		}	
	}
	if (Tes ==10)
		Tes = 0;
		
	if (Tes == 0)
		PlayerComp(PlayerC);	
	
	Tes++;
		
	if(Tembak==1)//program tembak
	{
		switch(ARAHTEMBAKAN)
		{
			case 1://ke atas
			{
				if (tembak==true){
					SetPosTembak(ARAHTEMBAKAN,PlayerP,&countBulletv,&countBulleth,&bulletk,&bulletb);
				}
				tembak=false;
				countBulletv-=1;
				if (countBulletv == 8 || countBulletv == -8)
				{
					countBulletv = 0;
					ElemenA+=1;
				}
				BulletImpact(PlayerP,ARAHTEMBAKAN,bulletb,bulletk,&ElemenA,&xBullet,&yBullet,&Tembak,&countBulletv,&countBulleth);
				break;
			}
			case 2://ke bawah
			{
				if (tembak==true)
				{
					SetPosTembak(ARAHTEMBAKAN,PlayerP,&countBulletv,&countBulleth,&bulletk,&bulletb);
				}
				tembak=false;
				countBulletv+=1;
				if (countBulletv == 8 || countBulletv == -8)
				{
					countBulletv = 0;
					ElemenA+=1;
				}
				BulletImpact(PlayerP,ARAHTEMBAKAN,bulletb,bulletk,&ElemenA,&xBullet,&yBullet,&Tembak,&countBulletv,&countBulleth);
				break;
			}
			case 3://ke kiri
			{
				if (tembak==true)
				{
					SetPosTembak(ARAHTEMBAKAN,PlayerP,&countBulletv,&countBulleth,&bulletk,&bulletb);
				}
				tembak=false;
				countBulleth-=1;
				if (countBulleth == 8 || countBulleth == -8)
				{
					countBulleth = 0;
					ElemenA+=1;
				}
				BulletImpact(PlayerP,ARAHTEMBAKAN,bulletb,bulletk,&ElemenA,&xBullet,&yBullet,&Tembak,&countBulletv,&countBulleth);
				break;
			}
			case 4://ke kanan
			{
				if (tembak==true)
				{
					SetPosTembak(ARAHTEMBAKAN,PlayerP,&countBulletv,&countBulleth,&bulletk,&bulletb);
				}
				tembak=false;
				countBulleth+=1;
				if (countBulleth == 8 || countBulleth == -8)
				{
					countBulleth = 0;
					ElemenA+=1;
				}
				BulletImpact(PlayerP,ARAHTEMBAKAN,bulletb,bulletk,&ElemenA,&xBullet,&yBullet,&Tembak,&countBulletv,&countBulleth);
				break;
			}
		}
	}
}
void PlayerComp (PP PlayerC){
	static int ARAHTEMBAKAN = 0, Tembak = 0;
	static int xBullet = 0, yBullet = 0,countBulletv = 0, countBulleth = 0, ElemenA = 0;
	static int  bulletb = 0, bulletk = 0;
	static char arr[50];
	static bool tembak = false;
	time_t t;
	srand((unsigned) time(&t));
	
	PlayerC->KEY = rand() % 5;
	if (PlayerC->KEY == 0){
		PlayerC->KEY = 72;
	}
	else if (PlayerC->KEY == 1){
		PlayerC->KEY = 80;
	}
	else if (PlayerC->KEY == 2){
		PlayerC->KEY = 75;
	}
	else if (PlayerC->KEY == 3){
		PlayerC->KEY = 77;
	}
	else if (PlayerC->KEY == 4){
		PlayerC->KEY = 32;
	}
	switch(PlayerC->KEY)
	{
		case 72:			//atas
		{
			Gerak_Tank(PlayerC);
			break;
		}
		case 80:			//bawah
		{
			Gerak_Tank(PlayerC);
			break;
		}
		case 75:			//kiri
		{
			Gerak_Tank(PlayerC);
			break;
		}
		case 77:			//kanan
		{
			Gerak_Tank(PlayerC);
			break;
		}
		case 32:
		{
		
				if(Tembak==0)
				{
					PlaySound(TEXT("Sounds/shoot_3.wav"), NULL, SND_ASYNC);
					tembak=true;
					switch(PlayerC->ARAH)
					{
						case 1:
						{
							xBullet = PlayerC->Left+4;
							yBullet = PlayerC->Top;
							ARAHTEMBAKAN=1;
							break;
						}
						case 2:
						{
							xBullet = PlayerC->Left+4;
							yBullet = PlayerC->Top+SObjek;
							ARAHTEMBAKAN=2;
							break;
						}
						case 3:
						{
							xBullet = PlayerC->Left;
							yBullet = PlayerC->Top+4;
							ARAHTEMBAKAN=3;
							break;
						}
						case 4:
						{
							xBullet = PlayerC->Left+SObjek;
							yBullet = PlayerC->Top+4;
							ARAHTEMBAKAN=4;
							break;
						}
					}
				}
				Tembak=1;
				break;	
		}	
	}
	if(Tembak==1)//program tembak
	{
		switch(ARAHTEMBAKAN)
		{
			case 1://ke atas
			{
				if (tembak==true){
					SetPosTembak(ARAHTEMBAKAN,PlayerC,&countBulletv,&countBulleth,&bulletk,&bulletb);
				}
				tembak=false;
				countBulletv-=1;
				if (countBulletv == 8 || countBulletv == -8)
				{
					countBulletv = 0;
					ElemenA+=1;
				}
				BulletImpact(PlayerC,ARAHTEMBAKAN,bulletb,bulletk,&ElemenA,&xBullet,&yBullet,&Tembak,&countBulletv,&countBulleth);
				break;
			}
			case 2://ke bawah
			{
				if (tembak==true)
				{
					SetPosTembak(ARAHTEMBAKAN,PlayerC,&countBulletv,&countBulleth,&bulletk,&bulletb);
				}
				tembak=false;
				countBulletv+=1;
				if (countBulletv == 8 || countBulletv == -8)
				{
					countBulletv = 0;
					ElemenA+=1;
				}
				BulletImpact(PlayerC,ARAHTEMBAKAN,bulletb,bulletk,&ElemenA,&xBullet,&yBullet,&Tembak,&countBulletv,&countBulleth);
				break;
			}
			case 3://ke kiri
			{
				if (tembak==true)
				{
					SetPosTembak(ARAHTEMBAKAN,PlayerC,&countBulletv,&countBulleth,&bulletk,&bulletb);
				}
				tembak=false;
				countBulleth-=1;
				if (countBulleth == 8 || countBulleth == -8)
				{
					countBulleth = 0;
					ElemenA+=1;
				}
				BulletImpact(PlayerC,ARAHTEMBAKAN,bulletb,bulletk,&ElemenA,&xBullet,&yBullet,&Tembak,&countBulletv,&countBulleth);
				break;
			}
			case 4://ke kanan
			{
				if (tembak==true)
				{
					SetPosTembak(ARAHTEMBAKAN,PlayerC,&countBulletv,&countBulleth,&bulletk,&bulletb);
				}
				tembak=false;
				countBulleth+=1;
				if (countBulleth == 8 || countBulleth == -8)
				{
					countBulleth = 0;
					ElemenA+=1;
				}
				BulletImpact(PlayerC,ARAHTEMBAKAN,bulletb,bulletk,&ElemenA,&xBullet,&yBullet,&Tembak,&countBulletv,&countBulleth);
				break;
			}
		}
	}
}

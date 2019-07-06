#include "tank.h"
#include "menu.h"
#include "kivlan.h"
#include "alpin.h"
#include "fikri.h"
#include "fadhil.h"
#include "naufal.h"
#include "fahri.h"
#include "levels.h"
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
int x=-1,y=-1,HovX=-1,HovY=-1;


//-----------------------------------FIXED XOSED---------------------------------------------------------//

void Draw_Stage() //menggambar isi map
{
	int L,T,i,j;
	T=MINMAP;
	
	readimagefile("gambar/RGB_Mode_12_v2.jpg",880,0,1200,700);
	
	for(i=0;i<17;i++)
	{
		L=MINMAP;
		for(j=0;j<22;j++)
		{
			switch(Map_Arena[i][j])
			{
				case 1:
				{
					readimagefile("Images/Brick_Broken.bmp",L,T,L+SObjek-1,T+SObjek-1);	
					break;
				}
				case 2://menggambar bata
				{
					readimagefile("Images/Brick.bmp",L,T,L+SObjek-1,T+SObjek-1);
					break;
				}
				case 3://menggambar baja
				{
					readimagefile("Images/Steel.bmp",L,T,L+SObjek-1,T+SObjek-1);
					break;
				}
				case 4://menggambar air
				{
					readimagefile("Images/Water.bmp",L,T,L+SObjek-1,T+SObjek-1);
					break;
				}
			}
			L+=SObjek;
		}
		T+=SObjek;
	}
	readimagefile("Images/Head.bmp",400,560,480,640);
}

/*------------------------------------------------------------------------------------------------------*/


//-------------------------------------------------------------------------------------------------------//

int About_US()
{
		readimagefile("gambar/About_US.jpg",0,0,1200,700);
	
	for (int i = 1; i < 1568; i=i+10)
	{
		if (kbhit())
		{
			break;
		}
	
	
		readimagefile("gambar/Credit.jpg",620,568-i,1110,2000-i);

	}
	

}


//-------------------------------------------------------------------------------------------------------//
int GT()
{
	cleardevice();
	readimagefile("gambar/logo1.jpg",0,0,1200,700);
	readimagefile("gambar/PlayV2.jpg",120,350,470,630);	
	int Kursor;
	int posisi = 1;
	boolean loop = true;
	
	while(loop)
	{
		Kursor = getch();
		switch(Kursor)
		{
			case 72	:
			{		
					if (posisi == 1)
					{	break;	}
					
					else if (posisi == 2)
					{
						posisi = posisi - 1;
						readimagefile("gambar/PlayV2.jpg",120,350,470,630);
						
					}
					else
					{
						posisi = posisi - 1;
						readimagefile("gambar/AboutV2.jpg",120,350,470,630);	
					}
					break;
			}
			
			case 80	:
			{
					if (posisi == 1)
					{
						posisi = posisi + 1;
						readimagefile("gambar/AboutV2.jpg",120,350,470,630);
					}
					
					else if (posisi == 2)
					{
						posisi = posisi + 1;
						readimagefile("gambar/ExitV2.jpg",120,350,470,630);
					}
					break;
			}
			
			case 13	:
			{
				loop = false;
				
				if (posisi == 1)
				{
					printf("Play");
					Play();
					//break;
				}
				else  if (posisi == 2)
				{
					printf("About");
					About_US();
					if (getch()){
						
						cleardevice();
						GT();
					}
					break;
				}
				else
				{
					exit(0);
					break;
				}
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------------//


int ergebeh (int X)
{
	if (X%3 == 1)
	{
		readimagefile("gambar/RGB_Mode_12_v2.jpg",880,0,1200,700);
	}
	
	else if(X%3 == 2)
	{
		readimagefile("gambar/RGB_Mode_22_v2.jpg",880,0,1200,700);
	}
	
	else 
	{
		readimagefile("gambar/RGB_Mode_32_v2.jpg",880,0,1200,700);
	}
}



//------------------------------------------------------------------------------------------------------//


void Intro()
{
	initwindow(WIDHTWINDOW, HEIGHTWINDOW, "Cisewu Tank Battle");
	PlaySound(TEXT("Sounds/present1.wav"), NULL, SND_ASYNC);
	readimagefile("Images/Opening.bmp",0,0,1200,700);
	delay(1500);
		for (int i=0;i<700;i+=1)
		{
			setcolor(LIGHTGRAY);
			rectangle(0,350-i,1200,350+i);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(1,350,LIGHTGRAY);
		}
	cleardevice();
	PlaySound(TEXT("Sounds/presented.wav"), NULL, SND_ASYNC);
	settextstyle(8,HORIZ_DIR,14);
	outtextxy(400,350,"Presented By Kelompok 6");
	delay(2000);
}

/*------------------------------------------------------------------------------------------------------*/

void Play()//modul utama mulai
{
	PP Player1,Player2;
	int i=0;
	Player1 = (PP) malloc(sizeof(Pemain));
	Player1->i = 15;//menentukan posisi sesuai array baris
	Player1->j = 8;//menentukan posisi sesuai array kolom
	Player1->Top = MINMAP+(Player1->i*SObjek);
	Player1->Left = MINMAP+(Player1->j*SObjek);
	Player1->Bottom = Player1->Top+SObjek-2;
	Player1->Right = Player1->Left+SObjek-2;
	Player1->KEY = 72;//defaultkey
	Player1->score = 0;
	Player1->ARAH = 1;
	Player1->countH = 0;
	Player1->countV = 0;
	Player1->ID = 5;
	
	Player2 = (PP) malloc(sizeof(Pemain));
	Player2->i = 2;//menentukan posisi sesuai array baris
	Player2->j = 11;//menentukan posisi sesuai array kolom
	Player2->Top = MINMAP+(Player2->i*SObjek);
	Player2->Left = MINMAP+(Player2->j*SObjek);
	Player2->Bottom = Player2->Top+SObjek-2;
	Player2->Right = Player2->Left+SObjek-2;
	Player2->KEY = 72;//defaultkey
	Player2->score = 0;
	Player2->ARAH = 1;
	Player2->countH = 0;
	Player2->countV = 0;
	Player2->ID = 6;
	
	Map_Arena[Player1->i][Player1->j] = Player1->ID;
	Map_Arena[Player2->i][Player2->j] = Player2->ID;
	cleardevice();
	PlaySound(TEXT("Sounds/opening.wav"), NULL, SND_ASYNC);
	Draw_Stage();
	while(true)
	{
		Player(Player1,Player2);
	//	PlayerComp(Player2);
	}
}

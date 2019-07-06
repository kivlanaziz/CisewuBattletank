//Tank.h

#ifndef tank_h
#define tank_h
#include "kivlan.h"
#include "alpin.h"
#include "fikri.h"
#include "fadhil.h"
#include "naufal.h"
#include "fahri.h"
//penggunaan menunjuk ke subvar dari struct "->" karena kelompok kami menggunakan pointer untuk sebuah player/pemain
/*typedef struct Pemain {
	//objek Tank
	int Left;
	int Top;
	int Right;
	int Bottom;
	//array Tank
	int i;//elemnt array baris
	int j;//elemnt array kolom
	int countH;
	int countV;
	int live;
	int score;
	char Nama;
	int state;
	int KEY;
	int ARAH;
};
typedef struct Pemain *PP;
*/
/*------------------------------------------------------------------------------------------------------*/

/*void Move_Place_XY(PP PlayerP);//modul memindahkan kordinat untuk penggambaran Tank			//fadhil

void Hapus_Tank(PP PlayerP); //modul hapus dengan cara menggambar ulang dengan background	//fadhil

void Draw_Stage();//menggambar isi map														//alpin

void Tank(PP PlayerP);// menggambar Tank													//fikri

void Count_Move(PP Player);//count sebagai banyaknya gerak untuk memindahkan array sebuah Tank //fadhil

void Shift(PP Player);//mengelompokan pemindahan kordinat, vertical dan horizontal			//fadhil

void Jalan_Tank(PP PlayerP);//prosedur utama untuk menjalankan Tank							//fadhil

void Gerak_Tank(PP PlayerP);																//fadhil

void Developer(PP PlayerP);																	//kivlan

void Player(PP PlayerP,PP PlayerC);//player utama											//barengan

void PlayerComp (PP PlayerC);																//Naufal

void SetPosTembak(int Arah,PP PlayerP,int *countBulletv,int *countBulleth,int *bulletk,int *bulletb); //Kivlan

void BulletImpact(PP Player,int Arah,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *isTembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactKanan(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactKiri(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactBawah(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactAtas(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan
*/
#endif



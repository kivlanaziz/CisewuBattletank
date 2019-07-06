#ifndef kivlan_h
#define kivlan_h
#include "tank.h"
typedef struct Pemain {
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
	int ID;
};
typedef struct Pemain *PP;
void Developer(PP PlayerP);

void SetPosTembak(int Arah,PP PlayerP,int *countBulletv,int *countBulleth,int *bulletk,int *bulletb); //Kivlan

void BulletImpact(PP Player,int Arah,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *isTembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactKanan(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactKiri(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactBawah(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactAtas(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void Player(PP PlayerP,PP PlayerC);//player utama

#endif

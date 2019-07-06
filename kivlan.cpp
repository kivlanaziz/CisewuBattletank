#ifndef kivlan_h
#define kivlan_h

void Developer(PP PlayerP);

void SetPosTembak(int Arah,PP PlayerP,int *countBulletv,int *countBulleth,int *bulletk,int *bulletb); //Kivlan

void BulletImpact(PP Player,int Arah,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *isTembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactKanan(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactKiri(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactBawah(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

void ImpactAtas(PP PlayerP,int bulletb,int bulletk,int *ElemenA,int *xBullet,int *yBullet,int *Tembak,int *countBulletv,int *countBulleth); //Kivlan

#endif

#ifndef fadhil_h
#define fadhil_h
#include "tank.h"
void Move_Place_XY(PP PlayerP);//modul memindahkan kordinat untuk penggambaran Tank

void Hapus_Tank(PP PlayerP); //modul hapus dengan cara menggambar ulang dengan background

void Count_Move(PP Player);//count sebagai banyaknya gerak untuk memindahkan array sebuah Tank

void Shift(PP Player);//mengelompokan pemindahan kordinat, vertical dan horizontal

void Jalan_Tank(PP PlayerP);//prosedur utama untuk menjalankan Tank

void Gerak_Tank(PP PlayerP);

#endif

#ifndef levels_h
#define levels_h

				//					   1 1 1 1 1 1 1 1 1 1 2 2 2
				//   1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2
static int Map_Arena[17][22]=  {{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, //1
					{3,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,3}, //2
					{3,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,3}, //3
					{3,4,4,4,4,0,0,0,3,0,0,0,0,3,0,0,0,4,4,4,4,3}, //4
					{3,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,3}, //5
					{3,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,3}, //6
					{3,0,0,0,0,4,4,0,0,2,0,0,0,0,0,4,4,0,0,0,0,3}, //7
					{3,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,3}, //8
					{3,3,3,3,3,0,0,0,2,0,0,0,0,2,0,0,0,3,3,3,3,3}, //9
					{3,0,0,0,0,0,0,0,2,2,0,0,0,2,0,0,0,0,0,0,0,3}, //10
					{3,0,0,0,0,2,2,0,0,2,2,2,2,0,0,2,2,0,0,0,0,3}, //11
					{3,0,0,0,0,2,2,0,0,0,0,0,0,0,0,2,2,0,0,0,0,3}, //12
					{3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,3}, //13
					{3,2,2,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,2,2,3}, //14
					{3,3,3,2,2,0,0,0,0,2,5,5,2,0,0,0,0,2,2,3,3,3}, //15
					{3,3,3,2,2,0,0,0,0,2,5,5,2,0,0,0,0,2,2,3,3,3}, //16
					{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}};//17		

static int Map_default[17][22]= {{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}, //1
					{3,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,3}, //2
					{3,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,3}, //3
					{3,4,4,4,4,0,0,0,3,0,0,0,0,3,0,0,0,4,4,4,4,3}, //4
					{3,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,3}, //5
					{3,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,3}, //6
					{3,0,0,0,0,4,4,0,0,2,0,0,0,0,0,4,4,0,0,0,0,3}, //7
					{3,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,3}, //8
					{3,3,3,3,3,0,0,0,2,0,0,0,0,2,0,0,0,3,3,3,3,3}, //9
					{3,0,0,0,0,0,0,0,2,2,0,0,0,2,0,0,0,0,0,0,0,3}, //10
					{3,0,0,0,0,2,2,0,0,2,2,2,2,0,0,2,2,0,0,0,0,3}, //11
					{3,0,0,0,0,2,2,0,0,0,0,0,0,0,0,2,2,0,0,0,0,3}, //12
					{3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,3}, //13
					{3,2,2,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,2,2,3}, //14
					{3,3,3,2,2,0,0,0,0,2,5,5,2,0,0,0,0,2,2,3,3,3}, //15
					{3,3,3,2,2,0,0,0,0,2,5,5,2,0,0,0,0,2,2,3,3,3}, //16
					{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}};//17		
					

#endif

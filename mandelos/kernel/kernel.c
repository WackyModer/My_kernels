#include "../include/stdlib.h"
 #include "../include/string.h"
#include "../include/video.h"
 #include "../include/stdio.h"
#include "../include/keyboard.h"
 #include "../include/math.h"
#include "../include/mandel.h"
//void test_gui();
#define PI 3.14159265

unsigned char* drivenumber = 0x062D;

void main() {
	//clear_screen();
	//int e = 90;
	while(1)
	{
		
		// for(int x = 0; x <= 320; x++){
		// 	for(int y = 0; y <= 200; y++){
		// 		unsigned char* loc = 0xa0000+320*y+x;
		// 		*loc = (int)(x+320)/20;
		// 		//*loc = 0x0f;
		// 	}
		// }
		// char buf[20];
		//scan(buf,10);

		//draw a circleee
		//unsigned char* loc = 0xa0000 + ((int)(cos(e*PI/180)*50)*320) + ((int)(sin(e*PI/180)*50+140)) + 320*100;
		//*loc = 0x0f;
		//ksleep(100);
		//e++;
		//if(e == 440){
		//	e = 0;
		//}
		//unsigned char* loc = 0xa0000+320*3+10;
		//*loc = 0x0f;
		render();
		get_key();
	}
}
/*
char* icotest[16] = {
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
};

void test_gui(){
	int coll = 15;
	int posl = 0;
	while(1)
	{
		posl = 0;
		coll = 15;
		for(int ex = 0; ex < 320; ex++)
		{
			posl++;
			if(posl == 20)
			{
				coll++;
				posl = 0;
			}
			for(int ey = 0; ey < 200; ey++)	
			{

				if(coll > 15){
					coll = 0;
				}
				//unsigned char* location = (unsigned char*)0xA0000 + (320 * ey) + ex+1;
				//*location = icotest[coll];

			}
		}
		//unused
		//changevidmode(0);
		sleep(5000);
	}
	/*
	for(int ex = 0; ex<2; ex++)
	{
		for(int ey = 0; ey<2; ey++)
		{
		}
	}*/
//}






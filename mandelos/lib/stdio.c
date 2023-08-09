#include "../include/keyboard.h"

#include "../include/video.h"

void checkinp(char* buf,int n)
{

char key=0;
int i=0;
char stat=1;

while(stat) // '\n is enter press key code'
	{
		key=get_key();
		//printchar(key,0x0a,0);
		if(key==0)continue;
		switch(key)
		{
			case '\n':
				break;
			case '<':
				break;
			case '>':

			default:
				
				break;






		}
		


	}



}

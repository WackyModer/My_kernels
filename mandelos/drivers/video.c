
#define CHAR_PER_LINE80
#define VIDEO_MEMORY 0xa0000
#define VIDEO_CONTROL_PIN 0x3D4
#define VIDEO_DATA_PIN 0x3D5

int cursor_pos=-1;


//read data from pin
unsigned char port_byte_read(unsigned short port ) {

unsigned char result ;
__asm__ ( "in %%dx,%%al":"=a"( result ):"d"( port ));
return result ;

}


//write data to pin
void port_byte_write(unsigned short port ,unsigned char data ) {

__asm__ ("out %%al,%%dx" : : "a"( data ) ,"d"( port ));
}


void clear_screen()
{


	char* screen=(char*)VIDEO_MEMORY;
	for (int i = 0; i < 64000; i++)
	   {
			char* screen=(char*)VIDEO_MEMORY+i;
	    	*screen =0x00;
	   }
}

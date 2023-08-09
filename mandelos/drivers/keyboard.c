#include "../include/video.h"
#include "../include/mandel.h"

int shiftispressed = 0;

double cposxk = 0;
double cposyk = 0;
double curzoom = 1;
int curiter = 50;

int get_key()
{

	 
	int keycode=0;
	char status=0;
	status = port_byte_read(0x64);

	if (status & 0x01) {
		keycode = port_byte_read(0x60);
  	}else{
    	return 2;
  	}

	// E which zooms in
	if (keycode == 0x12) {
		curzoom -= curzoom*0.25;
		changezoom(curzoom);
		return 1;
	}

	// Q which zooms out
	if (keycode == 0x10) {
		curzoom += curzoom*0.25;
		changezoom(curzoom);
		return 1;
	}

	// W which goes up
	if (keycode == 0x11) {
		cposyk -= curzoom*0.1;
		movecam(cposxk,cposyk);
		return 1;
	}

	// S which goes down
	if (keycode == 0x1F) {
		cposyk += curzoom*0.1;
		movecam(cposxk,cposyk);
		return 1;
	}
	
	// D which goes right
	if (keycode == 0x20) {
		cposxk += curzoom*0.1;
		movecam(cposxk,cposyk);
		unsigned char* loce = 0xa0000+0x140*2+10;
		*loce = 0x0e;
		return 1;
	}

	// A which goes left
	if (keycode == 0x1E) {
		cposxk -= curzoom*0.1;
		movecam(cposxk,cposyk);
		return 1;
	}

	// 1 which decreases iterations
	if (keycode == 0x02) {
		curiter -= 10;
		setiter(curiter);
		return 1;
	}

	// 2 which increases iterations
	if (keycode == 0x03) {
		curiter += 10;
		setiter(curiter);
		return 1;
	}

	if (keycode == 0x14) {
		setrender(0x00);
		return 1;
	}

	if (keycode == 0x15) {
		setrender(0x01);
		return 1;
	}


	return 0;
}
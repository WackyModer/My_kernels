#include "../include/math.h"
#include "../include/stdlib.h"

int maxiter = 100;

double zoom = 1;
long double cposx = 0;
long double cposy = 0;

long double zreal;
long double zimag;

long double xreal;
long double ximag;

int iter = 0;

char rendermode = 0x00;

void setiter(int iterr) {
    maxiter = iterr;
    return;
}

void setrender(char moed){
    rendermode = moed;
}

void changezoom(double newz) {
    zoom = newz;
    return;
}

void movecam(double cposxz, double cposyz) {
    cposx = cposxz;
    cposy = cposyz;
    return;
}

int mandelcalc(long double creal, long double cimag) {
    zreal = 0.0;
    zimag = 0.0;
    
    xreal = 1.0;
    ximag = 1.0;
    iter = 0;

    while ((zreal*zreal+zimag*zimag) < 4.0 && iter < maxiter) {
        xreal = zreal;
        ximag = zimag;

        zreal = (xreal*xreal - ximag*ximag) + creal;
        zimag = (xreal*ximag + ximag*xreal) + cimag;

        iter++;

        if (zreal == xreal && zimag == ximag) {
            return maxiter;
        }
        //return maxiter;
    }
    return iter;
}


void runmain() {
    for (int y = 0; y < 480; y++) {
        for (int x = 0; x < 640; x++) {
            unsigned char* bloc = 0xFD000000+(0x280*y*3)+x*3; //FD000000
            unsigned char* gloc = 0xFD000000+(0x280*y*3)+x*3+0x01;
            unsigned char* rloc = 0xFD000000+(0x280*y*3)+x*3+0x02;
			//*loc = (int)(x+320)/20;

            long double real = (x - 640 / 2.0) * 4.8*zoom / 640*3 - 0.75 + cposx;
            long double imag = (y - 480 / 2.0) * 3*zoom / 480*3 + cposy;
            
            int iterations = mandelcalc(real, imag);

            if (iterations == maxiter) {
                *rloc = 0;
                *gloc = 0;
                *bloc = 0;
            } else {
                if (rendermode) {
                    *rloc = (int)((sin(iterations*0.1)*0.5+0.5)*255);
                    *gloc = (int)((cos(iterations*0.1)*0.5+0.5)*255);
                    *bloc = 0xFF;
                } else{
                    *rloc = (unsigned char)255-iterations;
                    *gloc = (unsigned char)255-iterations;
                    *bloc = (unsigned char)255-iterations;
                }
                //*loc = iterations;
            }

        }
        if((y%2)) {
            if(get_key() == 0x01){
                return;
            }            
        }
    }
}

//function to render a frame
void render(){
    runmain();
    return;
}
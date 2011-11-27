#include <stdio.h>
#include <stdlib.h>
#include <complex.h>



int colors[]={ 7,  //white
	       3,  //yellow
	       2,  //green
	       6,  //cyan
	       4,  //blue
	       5,  //magenta
	       1,  //red
	       0}; //black


void f (double x, double y, unsigned d, unsigned a) {
	
	unsigned counter=1;
	double complex val=0+0*I;
	double complex add=x+y*I;
	while (counter<=d) {
		val=val*val+add;
		if(abs(val)>a){
			break;
		}
	counter++;
	}
	
	for (unsigned u=0; u<=7; ++u)
		if (counter>d-u*d/7) {
			printf("\033[4%dm",colors[u]);
			break;
		}
	putchar(' ');
}



int main (int argc, char **argv) {
	
	if (argc<3 || argc>5) {
		printf("Usage: %s width height [depth [accuracy]]\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	unsigned d; // depth
	if (argc>3) d=atoi(argv[3]);
	else        d=1000;
	
	unsigned a; // accuracy
	if (argc>4) a=atoi(argv[4]);
	else        a=4;
	
	double we=atoi(argv[1]),
	       he=atoi(argv[2]),
	       w=3/we,
	       h=2/he;
	
	for (double y=-1; y<=1; y+=h) {
		for (double x=-2; x<=1; x+=w)
			f(x,y,d,a);
		printf("\033[0m\n");
	}
	
	return EXIT_SUCCESS;
}

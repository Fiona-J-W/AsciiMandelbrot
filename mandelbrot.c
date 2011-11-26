#include <stdio.h>
#include <stdlib.h>



#define ACCURACY 9999999


int condition (double x, double y, unsigned a) {
	
	unsigned counter=1;
	double   imag=0,
		 real=0;
	
	while (counter<=a) {
		real=real*real-imag*imag+x;
		imag=2*real*imag+y;
		if (real*real+imag*imag>4) break;
		counter++;
	}
	
	if (counter>a) return 1;
	else           return 0;
}


int main (int argc, char **argv) {
	
	if (argc<3 || argc>4) {
		printf("Usage: %s width height [accuracy]\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	unsigned a; // accuracy
	if (argc==4) a=atoi(argv[3]);
	else         a=1000;
	
	double we=atoi(argv[1]),
	       he=atoi(argv[2]),
	       w=3/we,
	       h=2/he;
	
	for (double y=-1; y<=1; y+=h) {
		for (double x=-2; x<=1; x+=w)
			if (condition(x,y,a)) putchar('#');
			else                  putchar(' ');
		putchar('\n');
	}
	
	return EXIT_SUCCESS;
}

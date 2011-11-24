#include <stdio.h>
#include <stdlib.h>


int condition (double x, double y) {
	unsigned counter=1;
	double imag=0, real=0;
	while (counter<=100) {
		real=real*real-imag*imag+x;
		imag=2*real*imag+y;
		if (real*real+imag*imag>4) break;
		counter++;
	}
	if (counter>100) return 1;
	else             return 0;
}

int main (int argc, char **argv) {
	
	if (argc!=3) {
		printf("Usage: %s width height\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	double we=atoi(argv[1]),
	       he=atoi(argv[2]),
	       w=3/we,
	       h=2/he;
	
	for (double y=-1; y<=1; y+=h) {
		for (double x=-2; x<=1; x+=w)
			if (condition(x,y)) putchar('#');
			else                putchar(' ');
		putchar('\n');
	}
	
	return EXIT_SUCCESS;
}

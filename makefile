mandelbrot: mandelbrot.c
	gcc mandelbrot.c -o mandelbrot -Wall -pedantic -std=c99
clean:
	rm mandelbrot

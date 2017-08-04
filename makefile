CC=gcc

main: src/main.o src/engine.o src/term_1d_animate.o
	$(CC) src/main.o src/engine.o src/term_1d_animate.o

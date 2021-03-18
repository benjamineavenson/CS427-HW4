all: miller-rabin mod-exp
miller-rabin: miller-rabin.c mod-exp-function.c
	gcc -o miller-rabin miller-rabin.c mod-exp-function.c -lm;
mod-exp: mod-exp.c mod-exp-function.c
	gcc -o mod-exp mod-exp.c mod-exp-function.c
clean:
	rm miller-rabin; rm mod-exp;

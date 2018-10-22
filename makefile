all: driver.o sieve.o
	gcc -o driver.out driver.o sieve.o
	rm *.o

driver.o: driver.c sieve.c sieve.h
	gcc -c driver.c

sieve.o: sieve.c sieve.h
	gcc -c sieve.c

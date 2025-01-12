connectn.out: main.o connectn.o
	gcc -Wall -Werror -o connectn.out main.o connectn.o

main.o: main.c connectn.h
	gcc -Wall -Werror -c main.c

connectn.o: connectn.c connectn.h
	gcc -Wall -Werror -c connectn.c

clean:
	rm -f *.o *.out

nr ?= 4
nc ?= 4
ptw ?= 2

run: connectn.out
	./connectn.out $(nr) $(nc) $(ptw) 
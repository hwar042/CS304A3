# template Makefile
# refer to https://makefiletutorial.com/ for more info

# GCC optimisation level
OPT = -O1 				

# the default target: add here all the targets that should be built when make
# is called without parameter
# use with `make`
default: assignment

# use different targets for the different assignment tasks, see top of assignment specification
# below a pair of example targets that can be used for one task

# example target: building assignment
# will invoke the compiling target below, because it depends on 'assignment.o'
assignment: assignment.o 
	gcc $(OPT) -o assignment assignment.o

# example target: compiling assignment
assignment.o: assignment.c
	gcc $(OPT) -c assignment.c

# cleanup target
# use with 'make clean'
clean:
	rm -f *.o
	rm -f assignment


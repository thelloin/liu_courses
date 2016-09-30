#
# Makefile for Geometric_Object test compiling with GNU GCC g++
#
# LDFLAGS solves link kubrary problems för GCC 4 on Solaris.
#
CCC      = g++
#CCC      = gccfilter -a -c g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra -Werror
LDFLAGS  = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

geometric_object_test: geometric_object_test.o Geometric_Object.o Makefile
	${CCC} ${CCFLAGS} ${LDFLAGS} -o geometric_object_test \
		geometric_object_test.o Geometric_Object.o

geometric_object_test.o: Geometric_Object.h geometric_object_test.cc
	${CCC} ${CCFLAGS}  -c geometric_object_test.cc

Geometric_Object.o: Geometric_Object.h Geometric_Object.cc
	${CCC} ${CCFLAGS} -c Geometric_Object.cc

clean:
	@ \rm -f *.o *.gch core

zap: clean
	@ \rm -rf geometric_object_test *~

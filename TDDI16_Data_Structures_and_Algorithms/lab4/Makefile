#
# Makefile för bruteforcelösning och fast
#

CCC	= g++ -std=c++11 -Wall 
LFLAGS	= -L/usr/lib/x86_64-linux-gnu -lSDL -lm

all: brute fast

brute: brute.cc Point.o
	$(CCC) -o brute brute.cc Point.o $(LFLAGS)

fast: fast.cc Point.o
	$(CCC) -o fast fast.cc Point.o $(LFLAGS)

Point.o: Point.cc Point.h
	$(CCC) -c Point.cc

clean:
	@ \rm -rf *.o core

zap: clean
	@ \rm -f fast *~

#
# Makefile for Ordered_List tests
#
CCC     = g++
#CCC     = gccfilter -a -c g++
CCFLAGS = -std=c++11 -pedantic -Wall -Wextra 
#LDFLAGS = -L/sw/${GCC4_V}/lib -static-libstdc++

#all: ordered-list-test ordered-list-iterator-test

ordered-list-test: Ordered_List.h Ordered_List.tcc ordered-list-test.cc
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o ordered-list-test ordered-list-test.cc

ordered-list-iterator-test: Ordered_List.h Ordered_List.tcc ordered-list-iterator-test.cc
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o ordered-list-iterator-test ordered-list-iterator-test.cc

clean: 
	@ \rm -f *.o ordered-list-test ordered-list-iterator-test core

zap: clean
	@ clean -f
	@ \rm -rf *~

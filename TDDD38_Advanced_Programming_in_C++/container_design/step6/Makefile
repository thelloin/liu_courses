#
# Makefile for Container
#
# Module prog/gcc/4 must be loaded
#
TRACER = ../Tracer

CCC        = g++
CPPFLAGS   = -I$(TRACER)
CCFLAGS   += -std=c++11 -pedantic -Wall -Wextra

container-test: container-test.cc Container.h Container.tcc $(TRACER)/Tracer.h Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -o container-test container-test.cc
	./container-test

clean:
	@ \rm -f container-test *.gch core
zap: clean
	@ \rm -f *~

CC=g++
# Flaggorna till kompilatorn:
CFLAGS=-std=c++11 -Wall -Wextra -pedantic -g

all: main_smart_pointer_test.o smart_pointer.o
	$(CC) main_smart_pointer_test.o smart_pointer.o -o a.out

run:
	./a.out

main_smart_pointer_test.o: main_smart_pointer_test.cc
	$(CC) $(CFLAGS) -c main_smart_pointer_test.cc
smart_pointer.o: smart_pointer.cc smart_pointer.h
	$(CC) $(CFLAGS) -c smart_pointer.cc

clean:
	rm -rf *.o run

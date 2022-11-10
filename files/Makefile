CC = g++

all: output

output: main.o menu.o
	$(CC) main.o menu.o -o output

main.o: src/main.cpp
	$(CC) -c src/main.cpp

menu.o: src/menu.cpp include/menu.h
	$(CC) -c src/menu.cpp

distclean :
	rm *.o output
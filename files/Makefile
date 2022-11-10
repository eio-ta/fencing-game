CC = g++

all: output

output: main.o menu.o interaction.o
	$(CC) main.o menu.o interaction.o -o output

main.o: src/main.cpp
	$(CC) -c src/main.cpp

menu.o: src/menu.cpp include/menu.h
	$(CC) -c src/menu.cpp

interaction.o : src/interaction.cpp include/interaction.h
	$(CC) -c src/interaction.cpp

distclean :
	rm -f *.o output
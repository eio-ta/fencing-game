CC = g++

all: output

output: main.o menu.o interaction.o scene.o jeu.o
	$(CC) main.o menu.o interaction.o scene.o jeu.o -o output

main.o: src/main.cpp
	$(CC) -c src/main.cpp

menu.o: src/menu.cpp include/menu.h
	$(CC) -c src/menu.cpp

interaction.o : src/interaction.cpp include/interaction.h
	$(CC) -c src/interaction.cpp

scene.o : src/scene.cpp include/scene.h
	$(CC) -c src/scene.cpp

jeu.o : src/jeu.cpp include/jeu.h
	$(CC) -c src/jeu.cpp

distclean :
	rm -f *.o output
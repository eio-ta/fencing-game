CC = g++

all: output

output: main.o jeu.o conio.o interaction.o joueur.o menu.o scene.o
	$(CC) main.o jeu.o conio.o interaction.o joueur.o menu.o scene.o -o output

main.o: src/main.cpp
	$(CC) -c src/main.cpp

jeu.o : src/jeu.cpp include/jeu.h
	$(CC) -c src/jeu.cpp

conio.o : src/conio.cpp include/conio.h
	$(CC) -c src/conio.cpp

interaction.o : src/interaction.cpp include/interaction.h
	$(CC) -c src/interaction.cpp

joueur.o : src/joueur.cpp include/joueur.h
	$(CC) -c src/joueur.cpp

menu.o: src/menu.cpp include/menu.h
	$(CC) -c src/menu.cpp

scene.o : src/scene.cpp include/scene.h
	$(CC) -c src/scene.cpp

clean :
	rm -f *.o output
all : bin/affichage

bin/affichage: obj/main.o obj/game.o obj/complex.o obj/personnage.o
	g++ obj/main.o obj/game.o obj/personnage.o obj/complex.o -o bin/affichage -lSDL2 -lSDL2_image

obj/main.o: src/main.cpp src/terrain.h src/obstacle.h src/game.h src/complex.h src/personnage.h
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/game.o : src/game.cpp src/game.h src/complex.h src/personnage.h
	g++ -Wall -c src/game.cpp -o obj/game.o -lSDL2 -lSDL2_image

obj/terrain.o: src/terrain.cpp src/terrain.h src/obstacle.h
	g++ -Wall -c src/terrain.cpp -o obj/terrain.o -lSDL2 -lSDL2_image

obj/obstacle.o: src/obstacle.cpp src/obstacle.h
	g++ -Wall -c src/obstacle.cpp -o obj/obstacle.o 

obj/personnage.o: src/personnage.cpp src/personnage.h src/complex.h
	g++ -Wall -c src/personnage.cpp -o obj/personnage.o -lSDL2 -lSDL2_image

obj/complex.o: src/complex.cpp src/complex.h
	g++ -Wall -c src/complex.cpp -o obj/complex.o

clean: 
	rm -rf bin/* obj/*
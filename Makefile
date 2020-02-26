all : bin/affichage

bin/affichage: obj/main.o obj/game.o
	g++ obj/main.o obj/game.o -o bin/affichage -lSDL2 -lSDL2_image

obj/main.o: src/main.cpp src/terrain.h src/obstacle.h src/game.h
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/game.o : src/game.cpp src/game.h 
	g++ -Wall -c src/game.cpp -o obj/game.o -lSDL2 -lSDL2_image

obj/terrain.o: src/terrain.cpp src/terrain.h src/obstacle.h
	g++ -Wall -c src/terrain.cpp -o obj/terrain.o -lSDL2 -lSDL2_image

obj/obstacle.o: src/obstacle.cpp src/obstacle.h
	g++ -Wall -c src/obstacle.cpp -o obj/obstacle.o 

clean: 
	rm -rf bin/* obj/*
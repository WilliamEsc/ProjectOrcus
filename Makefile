all : bin/affichage

bin/affichage: obj/main.o obj/game.o obj/complex.o obj/personnage.o obj/texture.o obj/map.o obj/soin.o obj/text.o
	g++ obj/main.o obj/game.o obj/personnage.o obj/complex.o obj/texture.o obj/map.o obj/soin.o obj/text.o -o bin/affichage -lSDL2 -lSDL2_image -lSDL2_ttf

obj/main.o: src/main.cpp src/terrain.h src/obstacle.h src/game.h src/complex.h src/personnage.h src/map.h src/texture.h src/soin.h src/text.h
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/game.o : src/game.cpp src/game.h src/complex.h src/personnage.h src/map.h src/soin.h
	g++ -Wall -c src/game.cpp -o obj/game.o -lSDL2 -lSDL2_image

obj/terrain.o: src/terrain.cpp src/terrain.h src/obstacle.h
	g++ -Wall -c src/terrain.cpp -o obj/terrain.o -lSDL2 -lSDL2_image

obj/obstacle.o: src/obstacle.cpp src/obstacle.h
	g++ -Wall -c src/obstacle.cpp -o obj/obstacle.o 

obj/personnage.o: src/personnage.cpp src/personnage.h src/complex.h
	g++ -Wall -c src/personnage.cpp -o obj/personnage.o -lSDL2 -lSDL2_image

obj/complex.o: src/complex.cpp src/complex.h
	g++ -Wall -c src/complex.cpp -o obj/complex.o

obj/texture.o: src/texture.cpp src/texture.h 
	g++ -Wall -c src/texture.cpp -o obj/texture.o -lSDL2 -lSDL2_image -lSDL2_ttf

obj/text.o: src/text.cpp src/text.h
	g++ -Wall -c src/text.cpp -o obj/text.o -lSDL2 -lSDL2_ttf

obj/soin.o: src/soin.cpp src/soin.h 
	g++ -Wall -c src/soin.cpp -o obj/soin.o 

obj/map.o: src/map.cpp src/map.h src/texture.h
	g++ -Wall -c src/map.cpp -o obj/map.o -lSDL2 -lSDL2_image



clean: 
	rm -rf bin/* obj/*
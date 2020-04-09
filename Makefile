all : bin/affichage

bin/affichage: obj/main.o obj/game.o obj/complex.o obj/personnage.o obj/texture.o obj/map.o obj/objet.o obj/soin.o obj/balle.o obj/text.o
	g++ obj/main.o obj/game.o obj/personnage.o obj/complex.o obj/texture.o obj/map.o obj/objet.o obj/soin.o obj/balle.o obj/text.o -o bin/affichage -lSDL2 -lSDL2_image -lSDL2_ttf

obj/main.o: src/main.cpp src/terrain.h src/obstacle.h src/game.h src/complex.h src/personnage.h src/map.h src/texture.h src/objet.h src/soin.h src/text.h
	g++ -Wall -c src/main.cpp -o obj/main.o

obj/game.o : src/game.cpp src/game.h src/complex.h src/personnage.h src/map.h src/objet.h src/soin.h src/balle.h
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

obj/objet.o: src/objet.cpp src/objet.h
	g++ -Wall -c src/objet.cpp -o obj/objet.o -lSDL2 -lSDL2_ttf 

obj/soin.o: src/soin.cpp src/soin.h 
	g++ -Wall -c src/soin.cpp -o obj/soin.o 

obj/balle.o: src/balle.cpp src/balle.h 
	g++ -Wall -c src/balle.cpp -o obj/balle.o 

obj/map.o: src/map.cpp src/map.h src/texture.h
	g++ -Wall -c src/map.cpp -o obj/map.o -lSDL2 -lSDL2_image



clean: 
	rm -rf bin/* obj/*


# CORE = main.cpp game.cpp terrain.cpp obstacle.cpp 
# 	   personnage.cpp complex.cpp texture.cpp text.cpp
# 	   soin.cpp map.cpp

# FINAL_TARGET = affichage

# LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image 

# CC					= g++
# LD 					= g++
# LDFLAGS  			=
# CPPFLAGS 			= -Wall -ggdb   #-O2   # pour optimiser
# OBJ_DIR 			= obj
# SRC_DIR 			= src
# BIN_DIR 			= bin
# INCLUDE_DIR			= -Isrc 

# $(BIN_DIR)/$(FINAL_TARGET): $(SRC_DIR:%.cpp=$(OBJ_DIR)/%.o)
# 	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SDL)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	$(CC) -c $(CPPFLAGS) $(LIBS_SDL) $(INCLUDE_DIR) $< -o $@ 

# clean:
# 	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(FINAL_TARGET_TXT)

# $@ : Le nom de la cible 
# $< : Le nom de la première dépendance 
# $^ : La liste des dépendances
# $? : La liste des dṕendances plus récente que la cible 
# $* : Le nom du fichier sans suffixe 

CORE = core/Terrain.cpp core/Personnage.cpp core/Pacman.cpp core/Jeu.cpp core/Fantome.cpp core/object.cpp core/Soin.cpp core/Arme.cpp

SRCS_TXT = $(CORE) txt/txtJeu.cpp txt/winTxt.cpp txt/main_txt.cpp
SRCS_2 = $(CORE) mainRegression.cpp
FINAL_TARGET_TXT = pacman_txt
TEST_TARGET = regression_txt
#DEFINE_TXT = -DJEU_TXT

# SRCS_SDL = $(CORE) sdl2/sdlJeu.cpp sdl2/main_sdl.cpp
# FINAL_TARGET_SDL = pacman_sdl
# DEFINE_SDL = -DJEU_SDL

# ifeq ($(OS),Windows_NT)
# 	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw/SDL2-2.0.3/include \
# 						-Iextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/include/SDL2 \
# 						-Iextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/include/SDL2 \
# 						-Iextern/SDL2_mingw/SDL2_mixer-2.0.1/i686-w64-mingw32/include/SDL2

# 	LIBS_SDL = -Lextern \
# 			-Lextern/SDL2_mingw/SDL2-2.0.3/i686-w64-mingw32/lib \
# 			-Lextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/lib \
# 			-Lextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/lib \
# 			-Lextern/SDL2_mingw/SDL2_mixer-2.0.1/i686-w64-mingw32/lib \
# 			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

# else
# 	INCLUDE_DIR_SDL = -I/usr/include/SDL2
# 	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
# endif

CC					= g++
LD 					= g++
LDFLAGS  			=
CPPFLAGS 			= -Wall -ggdb   #-O2   # pour optimiser
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
INCLUDE_DIR			= -Isrc 
# INCLUDE_DIR			= -Isrc -Isrc/core -Isrc/sdl2 -Itxt

# default: make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SDL)

# make_dir:
# ifeq ($(OS),Windows_NT)
# 	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR) $(OBJ_DIR)\txt $(OBJ_DIR)\sdl2 $(OBJ_DIR)\core $(OBJ_DIR)\qt
# else
# 	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR) $(OBJ_DIR)/txt $(OBJ_DIR)/sdl2 $(OBJ_DIR)/core
# endif

all : bin/pacman_txt bin/regression_txt

$(BIN_DIR)/$(FINAL_TARGET_TXT): $(SRCS_TXT:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

$(BIN_DIR)/$(TEST_TARGET): $(SRCS_2:%.cpp=$(OBJ_DIR)/%.o)  
	$(LD) $+ -o $@ $(LDFLAGS)

# $(OBJ_DIR)/core/Fantome.o $(OBJ_DIR)/core/Personnage.o $(OBJ_DIR)/core/Pacman.o $(OBJ_DIR)/core/Terrain.o $(OBJ_DIR)/core/Arme.o $(OBJ_DIR)/core/object.o $(OBJ_DIR)/core/Soin.o   

# $(BIN_DIR)/$(FINAL_TARGET_SDL): $(SRCS_SDL:%.cpp=$(OBJ_DIR)/%.o)
# 	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SDL)

# $(OBJ_DIR)/mainRegression.o: src/mainRegression.cpp src/core/Fantome.h src/core/Personnage.h src/core/Arme.h src/core/Pacman.h src/core/Terrain.h
# 	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) $< -o $@

clean:
	rm -rf $(OBJ_DIR)/txt/*.o $(OBJ_DIR)/core/*.o $(BIN_DIR)/*

# clean:
# ifeq ($(OS),Windows_NT)
# 	del /f $(OBJ_DIR)\txt\*.o $(OBJ_DIR)\sdl2\*.o $(OBJ_DIR)\core\*.o $(BIN_DIR)\$(FINAL_TARGET_TXT).exe $(BIN_DIR)\$(FINAL_TARGET_SDL).exe
# else
# 	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SDL)
# endif

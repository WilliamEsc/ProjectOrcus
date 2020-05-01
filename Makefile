CXX = g++
OBJ = obj
SRC = src
BIN = bin

MAIN := main


POINTC := $(shell find $(SRC)/* -type f -name '*.cpp')
POINTH := $(shell find $(SRC)/* -type f -name '*.h')
POINTO := $(patsubst $(SRC)/%,$(OBJ)/%,$(POINTC))
POINTO := $(POINTO:.cpp=.o)

EXEC := Orcus

RM = rm

LIBS := -lSDL2 -lSDL2_image -lSDL2_ttf

OPT := -Wall -ggdb

all : dirs $(BIN)/$(EXEC)

dirs : 
	@mkdir -p $(OBJ) $(BIN)

clean: 
	$(RM) -rf $(OBJ) $(BIN)

run: dirs $(BIN)/$(EXEC)
	./$(BIN)/$(EXEC)

$(OBJ)/$(MAIN).o : $(SRC)/$(MAIN).cpp
	$(CXX) $(OPT) $< -c -o $@

$(OBJ)/%.o : $(SRC)/%.cpp $(SRC)/%.h
	$(CXX) $(OPT) $< -c -o $@

$(BIN)/$(EXEC) : $(POINTO)
	$(CXX) $(OPT) $^ -o "$@" $(LIBS)
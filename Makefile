all : bin/affichage

bin/affichage: main.o 

main.o: main.cpp def.h
	g++ -Wall 
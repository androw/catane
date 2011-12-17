test: Terrains Cartes Map Joueur.o Utils.o Jeux.o main.cpp
	g++ main.cpp ./Map/*.o ./Terrains/*.o ./Cartes/*.o ./Cartes/MPremieres/*.o Joueur.o Utils.o Jeux.o -o test
Terrains: ./Terrains/*
	cd ./Terrains/; make
Cartes: ./Cartes/*
	cd ./Cartes/; make
Map: ./Map/*
	cd ./Map/; make
Joueur.o: Joueur.h Joueur.cpp
	g++ -c Joueur.cpp
Utils.o: Utils.h Utils.cpp
	g++ -c Utils.cpp
Jeux.o: Jeux.h Jeux.cpp
	g++ -c Jeux.cpp

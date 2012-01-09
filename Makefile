test: Terrains Cartes Map ML_Joueur.o ML_Utils.o ML_Jeux.o main.cpp
	g++ main.cpp ./Map/*.o ./Terrains/*.o ./Cartes/*.o ./Cartes/MPremieres/*.o ML_Joueur.o ML_Utils.o ML_Jeux.o -o test
Terrains: ./Terrains/*
	cd ./Terrains/; make
Cartes: ./Cartes/*
	cd ./Cartes/; make
Map: ./Map/*
	cd ./Map/; make
ML_Joueur.o: ML_Joueur.h ML_Joueur.cpp
	g++ -c ML_Joueur.cpp
ML_Utils.o: ML_Utils.h ML_Utils.cpp
	g++ -c ML_Utils.cpp
ML_Jeux.o: ML_Jeux.h ML_Jeux.cpp
	g++ -c ML_Jeux.cpp

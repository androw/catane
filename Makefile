catane: ./Terrains/*.o ./Cartes/*.o ./Map/*.o ML_Joueur.o ML_Utils.o ML_Jeux.o main.cpp ./Cartes/MPremieres/*.o ./Cartes/Dev/*.o
	g++ -g -Wall main.cpp ./Map/*.o ./Terrains/*.o ./Cartes/*.o ./Cartes/MPremieres/*.o ./Cartes/Dev/*.o ML_Joueur.o ML_Utils.o ML_Jeux.o -o catane
./Terrains/*.o:
	cd ./Terrains/; make
./Cartes/*.o:
	cd ./Cartes/; make
./Map/*.o:
	cd ./Map/; make
ML_Joueur.o: ML_Joueur.h ML_Joueur.cpp
	g++ -c -g -Wall ML_Joueur.cpp
ML_Utils.o: ML_Utils.h ML_Utils.cpp
	g++ -c -g -Wall ML_Utils.cpp
ML_Jeux.o: ML_Jeux.h ML_Jeux.cpp
	g++ -c -g -Wall ML_Jeux.cpp
clean: Map-clean Cartes-clean Terrains-clean
	rm *.o; rm catane
Terrains-clean:
	cd ./Terrains/; make clean
Cartes-clean:
	cd ./Cartes/; make clean
Map-clean:
	cd ./Map/; make clean
./Cartes/MPremieres/*.o:
	cd ./Cartes/; make
./Cartes/Dev/*.o:
	cd ./Cartes/; make

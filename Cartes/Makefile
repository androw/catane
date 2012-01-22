all: ML_Carte.o ./Dev/*.o ./MPremieres/*.o
	
ML_Carte.o: ML_Carte.h ML_Carte.cpp
	g++ -c -g -Wall ML_Carte.cpp
./Dev/*.o:
	cd ./Dev/; make
./MPremieres/*.o:
	cd ./MPremieres/; make
Dev-clean:
	cd ./Dev/; make clean
MPremieres-clean:
	cd ./MPremieres/;make clean
clean: Dev-clean MPremieres-clean
	rm *.o

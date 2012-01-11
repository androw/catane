#include "ML_Terrain.h"

ML_Terrain::ML_Terrain() {
	valeur = 0;
	int i;
	for (i = 0; i<6; i++) {
			arrete[i] = NULL;
			noeud[i] = NULL;
	}
}

int ML_Terrain::getMax() {
	return MAX;
}

string ML_Terrain::getName() {
	return NAME;
}

void ML_Terrain::setArrete(int i , ML_Arrete * pa) {
	arrete[i] = pa;
}
ML_Arrete* ML_Terrain::getArrete(int i) {
	return arrete[i];
}

void ML_Terrain::setNoeud(int i , ML_Noeud * pa) {
	noeud[i] = pa;
}
ML_Noeud* ML_Terrain::getNoeud(int i) {
	return noeud[i];
}

int ML_Terrain::getValeur() {
	
	return valeur;
}

void ML_Terrain::setValeur(int a) {
	 valeur = a;
}

void ML_Terrain::setBrigand() {
	if (brigand == true) {
		brigand = false;
	}else {
		brigand = true;
	}
}
bool ML_Terrain::getBrigand() {
	return brigand;
}
	

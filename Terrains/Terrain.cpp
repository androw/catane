#include "Terrain.h"

Terrain::Terrain() {
	valeur = 0;
}

int Terrain::getMax() {
	return MAX;
}

string Terrain::getName() {
	return NAME;
}

void Terrain::setArrete(int i , Arrete * pa) {
	arrete[i] = pa;
}
Arrete* Terrain::getArrete(int i) {
	return arrete[i];
}

void Terrain::setNoeud(int i , Noeud * pa) {
	noeud[i] = pa;
}
Noeud* Terrain::getNoeud(int i) {
	return noeud[i];
}

int Terrain::getValeur() {
	
	return valeur;
}

int Terrain::setValeur(int a) {
	 valeur = a;
}

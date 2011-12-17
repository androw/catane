#include "Arrete.h"

Arrete::Arrete() {
	int i;
	for (i = 0; i<2; i++) {
		noeud[i] = NULL;
		noeud[i] = NULL;
	}
}

void Arrete::setNoeud(int i , Noeud * pa) {
	noeud[i] = pa;
}
Noeud* Arrete::getNoeud(int i) {
	return noeud[i];
}
Terrain* Arrete::getTerrain(int i) {
	return terrain[i];
}

void Arrete::setTerrain(int i, Terrain* pt) {
	terrain[i] = pt;
}

Joueur* Arrete::getJoueur() {
	return j;
}

void Arrete::setJoueur(Joueur* pj) {
	j = pj;
}

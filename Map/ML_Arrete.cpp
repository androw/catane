#include "ML_Arrete.h"

ML_Arrete::ML_Arrete() {
	int i;
	for (i = 0; i<2; i++) {
		noeud[i] = NULL;
		terrain[i] = NULL;
	}
	j = new ML_Joueur(0);
}

void ML_Arrete::setNoeud(int i , ML_Noeud * pa) {
	noeud[i] = pa;
}
ML_Noeud* ML_Arrete::getNoeud(int i) {
	return noeud[i];
}
ML_Terrain* ML_Arrete::getTerrain(int i) {
	return terrain[i];
}

void ML_Arrete::setTerrain(int i, ML_Terrain* pt) {
	terrain[i] = pt;
}

ML_Joueur* ML_Arrete::getJoueur() {
	return j;
}

void ML_Arrete::setJoueur(ML_Joueur* pj) {
	j = pj;
}
void ML_Arrete::addNoeud(ML_Noeud* pa) {
    if (noeud[0] == NULL || noeud[0] == pa) {
        noeud[0] = pa;
    } else if (noeud[0] == NULL || noeud[1] == pa) {
        noeud[1] = pa;
    }
}
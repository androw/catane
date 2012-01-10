#include "ML_Noeud.h"

ML_Noeud::ML_Noeud() {
	int i;
	for (i = 0; i<3; i++) {
		arrete[i] = NULL;
		terrain[i] = NULL;
	}
	j = new ML_Joueur(0);
	ville = false;
}

void ML_Noeud::setArrete(int i , ML_Arrete * pa) {
	arrete[i] = pa;
}

void ML_Noeud::setVille() {
	ville = true;
}

ML_Arrete* ML_Noeud::getArrete(int i) {
	return arrete[i];
}
ML_Terrain* ML_Noeud::getTerrain(int i) {
	return terrain[i];
}

void ML_Noeud::setTerrain(int i, ML_Terrain* pt) {
	terrain[i] = pt;
}

void ML_Noeud::addArrete(ML_Arrete * pa) {
	int i;
	for (i = 0; i<3; i++) {
		if (pa == arrete[i]) {
			return;
		} else if (arrete[i] == NULL) {
			arrete[i] = pa;
			return;
		}
	}
}
ML_Joueur* ML_Noeud::getJoueur() {
	return j;
}

void ML_Noeud::setJoueur(ML_Joueur* pj) {
	j = pj;
}

bool ML_Noeud::checkDist() {
	if (arrete[0] != NULL) {
        if ((arrete[0]->getNoeud(0) != NULL) && (arrete[0]->getNoeud(0) != NULL)) {
            if ((arrete[0]->getNoeud(0)->getJoueur() == NULL && arrete[0]->getNoeud(0) != this) || (arrete[0]->getNoeud(1)->getJoueur() == NULL && arrete[0]->getNoeud(1) != this)) {
                return false;
            }
        }
	}
	if (arrete[1] != NULL) {
        if ((arrete[0]->getNoeud(0) != NULL) && (arrete[0]->getNoeud(0) != NULL)) {
            if ((arrete[1]->getNoeud(0)->getJoueur() == NULL && arrete[1]->getNoeud(0) != this) || (arrete[1]->getNoeud(1)->getJoueur() == NULL && arrete[1]->getNoeud(1) != this)) {
                return false;
            }
        }
	}
	if (arrete[2] != NULL) {
        if ((arrete[0]->getNoeud(0) != NULL) && (arrete[0]->getNoeud(0) != NULL)) {
            if ((arrete[2]->getNoeud(0)->getJoueur() == NULL && arrete[2]->getNoeud(0) != this) || (arrete[2]->getNoeud(1)->getJoueur() == NULL && arrete[2]->getNoeud(1) != this)) {
                return false;
            }
        }
	}
	return true;
}

bool ML_Noeud::isVille() {
	return ville;
}

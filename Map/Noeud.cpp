#include "Noeud.h"

Noeud::Noeud() {
	int i;
	for (i = 0; i<3; i++) {
		arrete[i] = NULL;
		terrain[i] = NULL;
	}
	j = new Joueur(0);
	ville = false;
}

void Noeud::setArrete(int i , Arrete * pa) {
	arrete[i] = pa;
}

void Noeud::setVille() {
	ville = true;
}

Arrete* Noeud::getArrete(int i) {
	return arrete[i];
}
Terrain* Noeud::getTerrain(int i) {
	return terrain[i];
}

void Noeud::setTerrain(int i, Terrain* pt) {
	terrain[i] = pt;
}

void Noeud::addArrete(Arrete * pa) {
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
Joueur* Noeud::getJoueur() {
	return j;
}

void Noeud::setJoueur(Joueur* pj) {
	j = pj;
}

bool Noeud::checkDist() {
	if ((arrete[0]->getNoeud(0)->getJoueur() == NULL && arrete[0]->getNoeud(0) != this) || (arrete[0]->getNoeud(1)->getJoueur() == NULL && arrete[0]->getNoeud(1) != this)) {
		return false;
	}
	if ((arrete[1]->getNoeud(0)->getJoueur() == NULL && arrete[1]->getNoeud(0) != this) || (arrete[1]->getNoeud(1)->getJoueur() == NULL && arrete[1]->getNoeud(1) != this)) {
		return false;
	}
	if ((arrete[2]->getNoeud(0)->getJoueur() == NULL && arrete[2]->getNoeud(0) != this) || (arrete[2]->getNoeud(1)->getJoueur() == NULL && arrete[2]->getNoeud(1) != this)) {
		return false;
	}
	Noeud* inter;

	if (arrete[0]->getNoeud(0) != this) {
		inter = arrete[0]->getNoeud(0);
	} else {
		inter = arrete[0]->getNoeud(1);
	}
	if ((inter->getArrete(0)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(0)->getNoeud(0) != inter) || (inter->getArrete(0)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(0)->getNoeud(1) != inter)) {
		return false;
	}
	if ((inter->getArrete(1)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(1)->getNoeud(0) != inter) || (inter->getArrete(1)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(1)->getNoeud(1) != inter)) {
		return false;
	}
	if ((inter->getArrete(2)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(2)->getNoeud(0) != inter) || (inter->getArrete(2)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(2)->getNoeud(1) != inter)) {
		return false;
	}
		
	if (arrete[1]->getNoeud(0) != this) {
		inter = arrete[1]->getNoeud(0);
	} else {
		inter = arrete[1]->getNoeud(1);
	}
	if ((inter->getArrete(0)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(0)->getNoeud(0) != inter) || (inter->getArrete(0)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(0)->getNoeud(1) != inter)) {
		return false;
	}
	if ((inter->getArrete(1)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(1)->getNoeud(0) != inter) || (inter->getArrete(1)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(1)->getNoeud(1) != inter)) {
		return false;
	}
	if ((inter->getArrete(2)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(2)->getNoeud(0) != inter) || (inter->getArrete(2)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(2)->getNoeud(1) != inter)) {
		return false;
	}

	if (arrete[2]->getNoeud(0) != this) {
		inter = arrete[2]->getNoeud(0);
	} else {
		inter = arrete[2]->getNoeud(1);
	}
	if ((inter->getArrete(0)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(0)->getNoeud(0) != inter) || (inter->getArrete(0)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(0)->getNoeud(1) != inter)) {
		return false;
	}
	if ((inter->getArrete(1)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(1)->getNoeud(0) != inter) || (inter->getArrete(1)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(1)->getNoeud(1) != inter)) {
		return false;
	}
	if ((inter->getArrete(2)->getNoeud(0)->getJoueur() == NULL && inter->getArrete(2)->getNoeud(0) != inter) || (inter->getArrete(2)->getNoeud(1)->getJoueur() == NULL && inter->getArrete(2)->getNoeud(1) != inter)) {
		return false;
	}
	return true;
}

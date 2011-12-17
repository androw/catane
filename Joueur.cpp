#include "Joueur.h"

Joueur::Joueur(int pnb) {
	nb = pnb;
}

int Joueur::getNb() {
	return nb;
}

void Joueur::addRes(MPremiere* pm) {
	matPrem.push_back(pm);
}

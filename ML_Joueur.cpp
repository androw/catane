#include "ML_Joueur.h"

ML_Joueur::ML_Joueur(int pnb) {
	nb = pnb;
	score = 0;
}

int ML_Joueur::getNb() {
	return nb;
}

void ML_Joueur::addRes(ML_MPremiere* pm) {
	matPrem.push_back(pm);
}

ML_MPremiere* ML_Joueur::remRes(ML_MPremiere* pm) {
    int i;
    ML_MPremiere* m = NULL;
    for (i = 0; i<matPrem.size(); i++) {
        if (pm = matPrem.at(i)) {
            matPrem.erase(matPrem.begin()+i);
            return pm;
        }
    }
    return pm;
}

bool ML_Joueur::hasHe(ML_MPremiere* pm, int nb){
    int i;
    int acc = 0;
    for (i = 0; i<matPrem.size(); i++) {
        if (pm = matPrem.at(i)) {
            acc++;
        } 
    }
    if (acc >= nb) return true;
    return false;
}

void ML_Joueur::addScore() {
	score++;
}

void ML_Joueur::addArmee() {
	armee++;
}

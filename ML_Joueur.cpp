#include "ML_Joueur.h"

ML_Joueur::ML_Joueur(int pnb) {
	nb = pnb;
	score = 0;
    addRes(new ML_Argile());
    addRes(new ML_Argile());
    addRes(new ML_Bois());
    addRes(new ML_Bois());
    addRes(new ML_Argile());
    addRes(new ML_Argile());
    addRes(new ML_Bois());
    addRes(new ML_Bois());
    addRes(new ML_Laine());
    addRes(new ML_Laine());
    addRes(new ML_Ble());
    addRes(new ML_Ble());
}

int ML_Joueur::getNb() {
	return nb;
}

void ML_Joueur::addRes(ML_MPremiere* pm) {
	matPrem.push_back(pm);
}

ML_MPremiere* ML_Joueur::remRes(ML_MPremiere* pm) {
    unsigned int i;
    for (i = 0; i<matPrem.size(); i++) {
        if (pm == matPrem.at(i)) {
            matPrem.erase(matPrem.begin()+i);
            return pm;
        }
    }
    return pm;
}

bool ML_Joueur::hasHe(ML_MPremiere* pm, int nb){
    unsigned int i;
    int acc = 0;
    for (i = 0; i < matPrem.size(); i++) {
        if (pm == matPrem.at(i)) {
            acc++;
        } 
    }
    if (acc >= nb) return true;
    return false;
}

void ML_Joueur::addScore() {
	score++;
}

int ML_Joueur::getScore() {
	return score;
}

vector<ML_Dev*> ML_Joueur::getDev() {
	return dev;
}

vector<ML_MPremiere*> ML_Joueur::getMPrem() {
	return matPrem;
}

void ML_Joueur::addArmee() {
	armee++;
}

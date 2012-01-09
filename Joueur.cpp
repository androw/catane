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

MPremiere* Joueur::remRes(MPremiere* pm) {
    int i;
    MPremiere* m = NULL;
    for (i = 0; i<matPrem.size(); i++) {
        if (pm = matPrem.at(i)) {
            m = matPrem.at(i);
            matPrem.erase(matPrem.begin()+i);
            delete pm;
            return m;
        }
        
    }
    delete pm;
    return m;
}

bool Joueur::hasHe(MPremiere* pm, int nb){
    int i;
    int acc = 0;
    for (i = 0; i<matPrem.size(); i++) {
        if (pm = matPrem.at(i)) {
            acc++;
        }
        
    } 
    delete pm;
    if (acc >= nb) return true;
    return false;
}
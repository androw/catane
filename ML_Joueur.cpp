//MANSOURATI ET LORIN

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

int ML_Joueur::getArmee() {
	return armee;
}

void ML_Joueur::addRes(ML_MPremiere* pm) {
	matPrem.push_back(pm);
}

void ML_Joueur::remScore() {
	score--;
}

ML_MPremiere* ML_Joueur::remRes(ML_MPremiere* pm) {
    unsigned int i;
    for (i = 0; i<matPrem.size(); i++) {
        if (*pm == *(matPrem.at(i))) {
            pm = matPrem.at(i);
            matPrem.erase(matPrem.begin()+i);
            return pm;
        }
    }
    return pm;
}

bool ML_Joueur::hasHe(ML_MPremiere* pm, int nb){
    unsigned int i;
    
    if (pm == NULL) {
        return false;
    }
    int acc = 0;
    for (i = 0; i < matPrem.size(); i++) {
        if (*pm == *(matPrem.at(i))) {
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

void ML_Joueur::minArmee() {
	armee--;
}

void ML_Joueur::addDev(ML_Dev* pm) {
	dev.push_back(pm);
}

ML_Dev* ML_Joueur::remDev(ML_Dev* pm) {
    long unsigned int i;
    for (i = 0; i<dev.size(); i++) {
        if ((*pm).getName() == (*(dev.at(i))).getName()) {
            pm = dev.at(i);
            dev.erase(dev.begin()+i);
            return pm;
        }
    }
    return pm;
}

bool ML_Joueur::hasHeDev(ML_Dev* pm, int nb){
    
    if (pm == NULL) return false;
    
    long unsigned int i;
    int acc = 0;
    for (i = 0; i < dev.size(); i++) {
        if ((*pm).getName() == (*(dev.at(i))).getName()) {
            acc++;
        } 
    }
    if (acc >= nb) return true;
    return false;
}

void ML_Joueur::afficherCarteMP(){

unsigned int i;

if(matPrem.size() != 0) {
cout<<endl;
cout<<"Carte du joueur (ressource) :"<<endl; 
    for (i = 0; i<matPrem.size(); i++) {
         cout<<"|"<<(*(matPrem.at(i))).getName()<<"|";

    }
cout<<endl;
}
}

void ML_Joueur::afficherCarteDev(){

unsigned int i;

if(dev.size() != 0) {
cout<<endl;
cout<<"Carte du joueur (Devellopement) :"<<endl; 
    for (i = 0; i<dev.size(); i++) {
         cout<<"|"<<(*(dev.at(i))).getName()<<"|";
    }
cout<<endl;
}
}

void ML_Joueur::suppLastMP(){
    matPrem.pop_back();
    
}


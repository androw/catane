#include "Jeux.h"

using namespace std;

Jeux::Jeux() {
	nbjoueur = 4;
}

Jeux::Jeux(int p) {
	nbjoueur = p;
}

void Jeux::init() {
	int i;
	for (i = 1; i<= nbjoueur; i++) {
		cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
		cout<<""<<endl;
	}
}

bool Jeux::distribRes(){
	int de = lancerDe()+lancerDe();
	int i,j;
	if (de != 7) {
		for (i = 0; i<7 ; i++) {
			for (j = 0; j<7 ; j++) {
				if (map.getTerrain(i, j) != NULL) {
				if (map.getTerrain(i, j)->getValeur() == de) {
					int k;
					MPremiere* m = NULL;
					if (map.getTerrain(i, j)->getName() == "Colline"){
						m = new Argile();
						if (res[0] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[0]++;
						}
					} else if (map.getTerrain(i, j)->getName() == "Foret"){
						m = new Bois();
						if (res[1] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[1]++;
						}
					} else if (map.getTerrain(i, j)->getName() == "Montagne"){
						m = new Minerai();
						if (res[2] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[2]++;
						}
					} else if (map.getTerrain(i, j)->getName() == "Paturages"){
						m = new Laine();
						if (res[3] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[3]++;
						}
					} else if (map.getTerrain(i, j)->getName() == "TCultivable"){
						m = new Ble();
						if (res[4] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[4]++;
						}
					}
					for (k = 0; k<6; k++) {
						if (m != NULL && map.getTerrain(i, j)->getNoeud(k) != NULL) {
							if (map.getTerrain(i, j)->getNoeud(k)->getJoueur() != NULL) {
								map.getTerrain(i, j)->getNoeud(k)->getJoueur()->addRes(m);
							}
						}
					}
				}
				}
			}
		}
		return false;
	} else {
		return true;
	}
}

bool Jeux::initEchange() {
    return false;
}

bool Jeux::echange(Joueur* j1, Joueur* j2, MPremiere* m1, MPremiere* m2, int nb1, int nb2) {
    if (!(j1->hasHe(m1, nb1)) || !(j2->hasHe(m2, nb2))) return false;
    partEchange(j1, j2, m1, nb1);
    partEchange(j2, j1, m2, nb2);
    return true;
}

void Jeux::partEchange(Joueur* j1, Joueur* j2, MPremiere* m, int nb) {
    int i;
    for (i = 0; i<nb; i++) {
        j2->addRes(j1->remRes(m));
    }
}

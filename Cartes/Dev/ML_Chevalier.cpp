#include "ML_Chevalier.h"

ML_Chevalier::ML_Chevalier() {
	MAX = 14;
}

void ML_Chevalier::use(ML_Joueur* j, ML_Jeux* m) {
	int x = 3;
	int y = 3;
	//IL FAUT DEMANDER CES VALEURS ICI PAS EN PARAM de la fonction

	j->addArmee();
	m->setBrigand(x,y);

	int tab1[4];
	int choix;
	for(int i=0; i>4;i++) {
		tab1[i] = 0;
	}

	tab[0] = m->getMap().getTerrain(x, y)->getNoeud(0)->getJoueur();
	tab[1] = m->getMap().getTerrain(x, y)->getNoeud(1)->getJoueur();
	tab[2] = m->getMap().getTerrain(x, y)->getNoeud(2)->getJoueur();
	tab[3] = m->getMap().getTerrain(x, y)->getNoeud(3)->getJoueur();
	tab[4] = m->getMap().getTerrain(x, y)->getNoeud(4)->getJoueur();
	tab[5] = m->getMap().getTerrain(x, y)->getNoeud(5)->getJoueur();

	if( nbOcc(tab,1) > 1) {
		tab1[0] = 1;
		j++;
	}else if( nbOcc(tab,2) > 1) {
		tab1[1] = 2;
		j++;
	}else if( nbOcc(tab,3) > 1) {
		tab1[2]=3;
		j++;
	}else if( nbOcc(tab,4) > 1) {
		tab1[3]=4;
		j++;
	}

	if(nbOcc(tab1,1) != 0 || nbOcc(tab1,2) != 0 || nbOcc(tab1,3) != 0 || nbOcc(tab1,4) != 0 ) {
		do {
			cout<<"A quel joueur voulez vous prendre les cartes ?"<<endl;
			cin>>choix;
		}while(nbOcc(tab1,choix) = 1);
		if(tab[choix-1]->getDev().size() > 1) {
				j->addRes(tab[choix-1]->getMPrem().back());
				tab[choix-1]->getMPrem().pop_back();
				j->addRes(tab[choix-1]->getMPrem().back());
				tab[choix-1]->getMPrem().pop_back();
		}
		if(tab[choix-1]->getDev().size() == 1) {
				j->addRes(tab[choix-1]->getMPrem().back());
				tab[choix-1]->getMPrem().pop_back();
		}
		if(tab[choix-1]->getDev().size() == 0) {
				cout<<"Pas de carte"<<endl;
		}
	}
}

int ML_Chevalier::nbOccJ(ML_Joueur tab[],  int y) {
	int acc = 0;
	int i;
	for (i = 0; i<4;i++) {
		if (tab[i].getNb() == y) {
			acc++;
		}
	}
return acc;
}

int ML_Chevalier::nbOccN(ML_Joueur tab[],  int y) {
	int acc = 0;
	int i;
	for (i = 0; i<6;i++) {
		if (tab[i].getNb() == y) {
			acc++;
		}
	}
return acc;
}	



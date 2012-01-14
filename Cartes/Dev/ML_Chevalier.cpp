#include "ML_Chevalier.h"

ML_Chevalier::ML_Chevalier() {
	MAX = 14;
}

void ML_Chevalier::use(ML_Joueur* j, ML_Jeux* m) {
	int x = 3;
	int y = 3;
	int i = 0;
	do{	
	cout<<" ou voulez vous mettre le brigand?"<<endl;
	cout<<"x?"<<endl;
	cin>>x;
	cout<<"y?"<<endl;
	cin>>y;
	}while((x == m->getXBrigand() && y == m->getYBrigand()) || ((x == 3 && (y<1 || y>5)) || ((x == 2 || x == 4) && (y<1 || y>4)) || ((x == 1 || x == 5) && (y<2 || y>4))) );

	

	j->addArmee();
	m->setBrigand(x,y);

	ML_Joueur * tab1[4];
	int choix;
	for(int i=0; i>4;i++) {
		tab1[i] = new ML_Joueur(0);
	}

	tab[0] = m->getMap().getTerrain(x, y)->getNoeud(0)->getJoueur();
	tab[1] = m->getMap().getTerrain(x, y)->getNoeud(1)->getJoueur();
	tab[2] = m->getMap().getTerrain(x, y)->getNoeud(2)->getJoueur();
	tab[3] = m->getMap().getTerrain(x, y)->getNoeud(3)->getJoueur();
	tab[4] = m->getMap().getTerrain(x, y)->getNoeud(4)->getJoueur();
	tab[5] = m->getMap().getTerrain(x, y)->getNoeud(5)->getJoueur();


		for( i=0;i>6;i++) {
			if (tab[i]->getNb() == 1 && tab[i]->getNb() != j->getNb()) {
				tab1[0] = tab[i];
				i = 5;
			}	
		}
		for( i=0;i>6;i++) {
			if (tab[i]->getNb() == 2 && tab[i]->getNb() != j->getNb()) {
				tab1[1] = tab[i];
				i = 5;
			}	
		}
		for( i=0;i>6;i++) {
			if (tab[i]->getNb() == 3 && tab[i]->getNb() != j->getNb()) {
				tab1[2] = tab[i];
				i = 5;
			}	
		}
		for( i=0;i>6;i++) {
			if (tab[i]->getNb() == 4 && tab[i]->getNb() != j->getNb()) {
				tab1[3] = tab[i];
				i = 5;
			}	
		}	


	if(tab1[0]->getNb() != 0 || tab1[1]->getNb() != 0 || tab1[2]->getNb() != 0 || tab1[3]->getNb() != 0 ) {
		do {
			cout<<"A quel joueur voulez vous prendre les cartes ?"<<endl;
			cin>>choix;
		}while(tab1[choix - 1]->getNb() != 0);
		if(tab1[choix-1]->getDev().size() > 1) {
				j->addRes(tab1[choix-1]->getMPrem().back());
				tab1[choix-1]->getMPrem().pop_back();
				j->addRes(tab1[choix-1]->getMPrem().back());
				tab1[choix-1]->getMPrem().pop_back();
		}
		if(tab1[choix-1]->getDev().size() == 1) {
				j->addRes(tab1[choix-1]->getMPrem().back());
				tab1[choix-1]->getMPrem().pop_back();
		}
		if(tab1[choix-1]->getDev().size() == 0) {
				cout<<"Pas de carte"<<endl;
		}
	}
}




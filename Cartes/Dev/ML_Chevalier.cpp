#include "ML_Chevalier.h"

ML_Chevalier::ML_Chevalier() {
	MAX = 14;
}

void ML_Chevalier::use(ML_Joueur* j, ML_Map* m,int x, int y) {
	j->addArmee();
	setBrigand(x,y);
	ML_Joueur * tab1[4];
	int choix;
	for(int i=0; i>4;i++) {
		tab1[i] = 0;
	}
	tab[0] = m->t[x][y]->getNoeud(0)->getJoueur();
	tab[1] = m->t[x][y]->getNoeud(1)->getJoueur();
	tab[2] = m->t[x][y]->getNoeud(2)->getJoueur();
	tab[3] = m->t[x][y]->getNoeud(3)->getJoueur();
	tab[4] = m->t[x][y]->getNoeud(4)->getJoueur();
	tab[5] = m->t[x][y]->getNoeud(5)->getJoueur();

	if( nbOcc(tab,1) > 1) {
		tab[0]=1;
		j++;
	}else if( nbOcc(tab,2) > 1) {
		tab[1]=2;
		j++;
	}else if( nbOcc(tab,3) > 1) {
		tab[2]=3;
		j++;
	}else if( nbOcc(tab,4) > 1) {
		tab[3]=4;
		j++;
	}

	if(nbOcc(tab1,1) != 0 || nbOcc(tab1,2) != 0 || nbOcc(tab1,3) != 0 || nbOcc(tab1,4) != 0 ) {
		do {
			cout<<"a quel joueur voulez vous prendre les cartes?"<<endl;
			cin>>choix;
		}while(nbOcc(tab1,choix) = 1);

			if(tab[choix-1]->getDev().size() > 1) {

				j->addRes(tab[choix-1]->getDev().back);
				tab[choix-1]->getDev().pop_back;
				j->addRes(tab[choix-1]->getDev().back);
				tab[choix-1]->getDev().pop_back;
			}
			if(tab[choix-1]->getDev().size() == 1) {

				j->addRes(tab[choix-1]->getDev().back);
				tab[choix-1]->getDev().pop_back;

			}
			if(tab[choix-1]->getDev().size() == 0) {

				cout<<"pas de carte ^^"<<endl;

			}
		
	}


	
}

int ML_Chevalier::nbOccJ(ML_Joueur tab[],  int y) {
	int acc = 0;
	for (i = 0; i<4;i++) {
		if (tab[i].getNb() == y) {
			acc++;
		}
	}
return acc;
}

int ML_Chevalier::nbOccN(ML_Joueur tab[],  int y) {
	int acc = 0;
	for (i = 0; i<6;i++) {
		if (tab[i].getNb() == y) {
			acc++;
		}
	}
return acc;
}	



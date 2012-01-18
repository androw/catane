#include "ML_Jeux.h"

using namespace std;

ML_Jeux::ML_Jeux() {
	nbjoueur = 4;
	armee = 0;
	for (int i=0; i< 5; i++) {
		res[i] = 0;
		dev[i] = 0;
	}
	for (int i=0; i< 4; i++) {
		joueur[i] = new ML_Joueur(i+1);
	} 
    int i;
    for (i = 1; i < 6; i++) {
		if(map.getTerrain(3, i)->getName() == "Desert") {
			xBrigand = 3;
			yBrigand = i;
		}
	}
	for (i = 1; i < 5; i++) {
		if(map.getTerrain(2,i)->getName() == "Desert") {
			xBrigand = 2;
			yBrigand = i;
		}
		if(map.getTerrain(4,i)->getName() == "Desert") {
			xBrigand = 4;
			yBrigand = i;
		}
	}
	for (i = 2; i < 5; i++) {
		if(map.getTerrain(1, i)->getName() == "Desert") {
			xBrigand = 1;
			yBrigand = i;
		}
		if(map.getTerrain(5, i)->getName() == "Desert") {
			xBrigand = 5;
			yBrigand = i;
		}
	}
}

ML_Jeux::ML_Jeux(int p) {
	nbjoueur = p;
	armee = 0;
	
	for (int i=0; i< 5; i++) {
		res[i] = 0;
		dev[i] = 0;
	}
	for (int i=0; i< p; i++) {
		joueur[i] = new ML_Joueur(i+1);
	} 
	int i;
	for (i = 1; i < 6; i++) {
		if(map.getTerrain(3, i)->getName() == "Desert") {
			xBrigand = 3;
			yBrigand = i;
		}
	}
	for (i = 1; i < 5; i++) {
		if(map.getTerrain(2,i)->getName() == "Desert") {
			xBrigand = 2;
			yBrigand = i;
		}
		if(map.getTerrain(4,i)->getName() == "Desert") {
			xBrigand = 4;
			yBrigand = i;
		}
	}
	for (i = 2; i < 5; i++) {
		if(map.getTerrain(1, i)->getName() == "Desert") {
			xBrigand = 1;
			yBrigand = i;
		}
		if(map.getTerrain(5, i)->getName() == "Desert") {
			xBrigand = 5;
			yBrigand = i;
		}
	}
}

void ML_Jeux::init() {
	int i;
	int x,y,xx,yy,xxx,yyy;
	int choix = 0;

	cout<<"Initialisation de la Partie"<<endl;

	for (i = 1; i<= nbjoueur; i++) {
            do{
			map.afficher();
			cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
			cout<<"Placez votre colonie : x?"<<endl;
			cin>>x;
			cout<<"Placez votre colonie : y?"<<endl;
			cin>>y;
			cout<<"Placez votre colonie : x'?"<<endl;
			cin>>xx;
			cout<<"Placez votre colonie : y'?"<<endl;
			cin>>yy;
			cout<<"Placez votre colonie : x''?"<<endl;
			cin>>xxx;
			cout<<"Placez votre colonie : y''?"<<endl;
			cin>>yyy;
		}while(!(placerColonie(x,y,xx,yy,xxx,yyy,i,true)));
        
		do{
			map.afficher();
			cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
			cout<<"Placez votre route : x?"<<endl;
			cin>>x;
			cout<<"Placez votre route : y?"<<endl;
			cin>>y;
			cout<<"Placez votre route : x'?"<<endl;
			cin>>xx;
			cout<<"Placez votre route : y'?"<<endl;
			cin>>yy;
		}while(!(placerRoute(x,y,xx,yy,i)));
		
		cout<<endl;
	}
	for (i = nbjoueur; i>= 1; i--) {
        do{
			map.afficher();
			cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
			cout<<"Placez votre colonie : x?"<<endl;
			cin>>x;
			cout<<"Placez votre colonie : y?"<<endl;
			cin>>y;
			cout<<"Placez votre colonie : x'?"<<endl;
			cin>>xx;
			cout<<"Placez votre colonie : y'?"<<endl;
			cin>>yy;
			cout<<"Placez votre colonie : x''?"<<endl;
			cin>>xxx;
			cout<<"Placez votre colonie : y''?"<<endl;
			cin>>yyy;
		}while(!(placerColonie(x,y,xx,yy,xxx,yyy,i,true)));

		do{
			map.afficher();
			cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
			cout<<"Placez votre route : x?"<<endl;
			cin>>x;
			cout<<"Placez votre route : y?"<<endl;
			cin>>y;
			cout<<"Placez votre route : x'?"<<endl;
			cin>>xx;
			cout<<"Placez votre route : y'?"<<endl;
			cin>>yy;
		}while(!(placerRoute(x,y,xx,yy,i)));

		cout<<endl;
	}
	//AJOUTER LES RESSOURCE EN FONCTION DES COLONIES PLACZE
	cout<<"Initialisation finie. Debut de la partie."<<endl;
	bool victory = false;
	do {
	for (i = 1; (i<= nbjoueur && !victory); i++) {
		do {
			do{
				
				map.afficher();
				distribRes();
				joueur[i-1]->afficherCarteMP();
				cout<<"Au joueur "<<i<<" de jouer !"<<endl;
				cout<<"1. Placez une route ?"<<endl; //OK
				cout<<"2. Placez une colonie ?"<<endl; //OK
				cout<<"3. Placez une ville ?"<<endl; //OK
				cout<<"4. Faire un échange entre joueurs ?"<<endl;
				cout<<"5. Faire un échange avec un port ?"<<endl;
				cout<<"6. Faire un échange avec la banque ?"<<endl; //OK
				cout<<"7. Achat d'une carte développement ?"<<endl;
				cout<<"8. Finir tour"<<endl; //OK
				cin>>choix;
			}while(choix < 0 || choix > 8);
			if (choix == 1) {addRoute(i);}
			else if (choix == 2) {addColonie(i);}
			else if (choix == 3) {addVille(i);}
			else if (choix == 6) {trade(i);}
		}while (choix != 8);
		if (joueur[i-1]->getScore() == 10) {victory = true;}
	}
	} while (!victory);
}

ML_Map ML_Jeux::getMap() {
	return map;
}

void ML_Jeux::refreshArmee() {
	if (armee != 0) joueur[armee-1]->remScore();
	int max = 0;
	int j;
	int i;
	for (i = 0; i<nbjoueur; i++) {
		if (joueur[i]->getArmee() > max) {
			j = i;
		}
	}
	joueur[j]->addScore();
	armee = j+1;
}	

void ML_Jeux::trade(int j){
	int insell;
	int inbuy;
	do {
		cout<<"0. Argile 1. Bois 2. Minerai 3. Laine 4. Ble"<<endl;
		cout<<"De quelle ressource (x4) voulez vous vous débarassez ?"<<endl;
		cin>>insell;
		cout<<"Quelle ressource (x4) souhaitez vous acquérir ?"<<endl;
		cin>>inbuy;
	} while (0 <= insell && insell <= 4 && 0 <= inbuy && inbuy <= 4);
	ML_MPremiere* m = NULL;
	if (insell == 0) {
		m = new ML_Argile();
	} else if (insell == 1) {
		m = new ML_Bois();
	} else if (insell == 2) {
		m = new ML_Minerai();
	} else if (insell == 3) {
		m = new ML_Laine();
	} else if (insell == 4) {
		m = new ML_Ble();
	}
	if (!(joueur[j-1]->hasHe(m, 4))) {
		cout<<"Vous n'avez pas les ressources nécessaires"<<endl;
		delete m;
		return;}

	ML_MPremiere* mn = NULL;
	if (inbuy == 0) {
		mn = new ML_Argile();
	} else if (inbuy == 1) {
		mn = new ML_Bois();
	} else if (inbuy == 2) {
		mn = new ML_Minerai();
	} else if (inbuy == 3) {
		mn = new ML_Laine();
	} else if (inbuy == 4) {
		mn = new ML_Ble();
	}
	if (res[inbuy] >= mn->getMax()) {
		cout<<"Plus de carte disponible, échange annulé"<<endl;
		delete m;
		delete mn;
	} else {
		res[inbuy]++;
		res[insell] = res[insell] - 4;
		delete joueur[j-1]->remRes(m);
		delete joueur[j-1]->remRes(m);
		delete joueur[j-1]->remRes(m);
		delete joueur[j-1]->remRes(m);
		joueur[j-1]->addRes(mn);
	}
	delete m;	
}

bool ML_Jeux::distribRes(){
	int de = lancerDe()+lancerDe();
	cout<<"Les dés ont fait "<<de<<"."<<endl;
	int i,j;
	if (de != 7) {
		for (i = 0; i<7 ; i++) {
			for (j = 0; j<7 ; j++) {
				if (map.getTerrain(i, j) != NULL) {
				if (map.getTerrain(i, j)->getValeur() == de && !(map.getTerrain(i, j)->getBrigand())) {
					int k;
					ML_MPremiere* m = NULL;
					cout<<"Distrib de "<<map.getTerrain(i, j)->getName()<<endl;
                    			for (k = 0; k<6;k++) {
					if (map.getTerrain(i, j)->getNoeud(k) != NULL) {
					if (map.getTerrain(i, j)->getNoeud(k)->getJoueur() != NULL) {
					if (map.getTerrain(i, j)->getNoeud(k)->getJoueur()->getNb() != 0) {
					if (map.getTerrain(i, j)->getName() == "Colline"){
						m = new ML_Argile();
						if (res[0] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[0]++;
						}
					} else if (map.getTerrain(i, j)->getName() == "Foret"){
						m = new ML_Bois();
						cout<<"DISTRIB BOIS"<<endl;
						if (res[1] >= m->getMax()) {
							cout<<"PLUS DE BOIS"<<endl;
							delete m;
							m = NULL;	
						} else {
							cout<<"ENCORE DE BOIS"<<endl;
							res[1]++;
						}
					} else if (map.getTerrain(i, j)->getName() == "Montagne"){
						m = new ML_Minerai();
						if (res[2] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[2]++;
						}
					} else if (map.getTerrain(i, j)->getName() == "Paturages"){
						m = new ML_Laine();
						if (res[3] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[3]++;
						}
					} else if (map.getTerrain(i, j)->getName() == "TCultivable"){
						m = new ML_Ble();
						if (res[4] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
							res[4]++;
						}
					}
                        		if (m != NULL) {
						if (map.getTerrain(i, j)->getNoeud(k)->isVille()) {
							map.getTerrain(i, j)->getNoeud(k)->getJoueur()->addRes(m);
							map.getTerrain(i, j)->getNoeud(k)->getJoueur()->addRes(m);
						} else {
							map.getTerrain(i, j)->getNoeud(k)->getJoueur()->addRes(m);
						}
					}
					}
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

bool ML_Jeux::initEchange() {
    return false;
}

bool ML_Jeux::echange(ML_Joueur* j1, ML_Joueur* j2, ML_MPremiere* m1, ML_MPremiere* m2, int nb1, int nb2) {
    	if (!(j1->hasHe(m1, nb1)) || !(j2->hasHe(m2, nb2))) return false;
    	partEchange(j1, j2, m1, nb1);
    	partEchange(j2, j1, m2, nb2);
	delete m1;
	delete m2;
    	return true;
}

void ML_Jeux::partEchange(ML_Joueur* j1, ML_Joueur* j2, ML_MPremiere* m, int nb) {
    int i;
    for (i = 0; i<nb; i++) {
        j2->addRes(j1->remRes(m));
    }
}

void ML_Jeux::addColonie(int j){
	int x;
	int y;
	int xx;
	int yy;
	int xxx;
	int yyy;
	cout<<"Placez votre colonie : x ?"<<endl;
	cin>>x;
	cout<<"Placez votre colonie : y ?"<<endl;
	cin>>y;
	cout<<"Placez votre colonie : x' ?"<<endl;
	cin>>xx;
	cout<<"Placez votre colonie : y' ?"<<endl;
	cin>>yy;
	cout<<"Placez votre colonie : x'' ?"<<endl;
	cin>>xxx;
	cout<<"Placez votre colonie : y'' ?"<<endl;
	cin>>yyy;
	if (placerColonie(x, y, xx , yy , xxx, yyy, j, false)) {
		cout<<"Colonie placée"<<endl;
	} else {
		cout<<"Impossible de placer une colonie ici."<<endl;
	}
}

bool ML_Jeux::placerColonie(int x,int y,int xx ,int yy ,int xxx ,int yyy,int j, bool b) {
	ML_MPremiere* arg = new ML_Argile();
	ML_MPremiere* boi = new ML_Bois();
	ML_MPremiere* lai = new ML_Laine();
	ML_MPremiere* ble = new ML_Ble();
	if( x<7 && xx<7 && xxx<7 && y<7 && yy<7 && yyy<7 && x>=0 && xx>=0 && xxx>=0 && y>=0 && yy>=0 && yyy>=0) {
		if( map.getNoeud(x,y,xx,yy,xxx,yyy) != NULL) {
			if(map.getNoeud(x,y,xx,yy,xxx,yyy)->getJoueur()->getNb() == 0 && joueur[j-1]->hasHe(arg, 1) && joueur[j-1]->hasHe(boi, 1) && joueur[j-1]->hasHe(lai, 1) && joueur[j-1]->hasHe(ble, 1) && (map.getNoeud(x,y,xx,yy,xxx,yyy)->checkDist()) && (b || map.getNoeud(x,y,xx,yy,xxx,yyy)->hasRoute(j)))  {
				delete map.getNoeud(x,y,xx,yy,xxx,yyy)->getJoueur();
				map.getNoeud(x,y,xx,yy,xxx,yyy)->setJoueur(joueur[j-1]);
				delete joueur[j-1]->remRes(boi);
				res[1]--;
				delete joueur[j-1]->remRes(arg);
				res[0]--;
				delete joueur[j-1]->remRes(lai);
				res[3]--;
				delete joueur[j-1]->remRes(ble);
				res[4]--;
				joueur[j-1]->addScore();
				delete arg;
				delete boi;
				delete lai;
				delete ble;
				return true;
			}
		}
	}
	delete arg;
    delete boi;
    delete lai;
    delete ble;
    return false;
}

void ML_Jeux::addRoute(int j){
	int x;
	int y;
	int xx;
	int yy;
	cout<<"Placez votre route : x ?"<<endl;
	cin>>x;
	cout<<"Placez votre route : y ?"<<endl;
	cin>>y;
	cout<<"Placez votre route : x' ?"<<endl;
	cin>>xx;
	cout<<"Placez votre route : y' ?"<<endl;
	cin>>yy;
	if (placerRoute(x, y, xx , yy , j)) {
		cout<<"Route placée"<<endl;
	} else {
		cout<<"Impossible de placer une route ici."<<endl;
	}
}

bool ML_Jeux::placerRoute(int x,int y,int xx ,int yy ,int j){
	ML_MPremiere* arg = new ML_Argile();
	ML_MPremiere* boi = new ML_Bois();
	if( x<7 && xx<7 && y<7 && yy<7 && x>=0 && xx>=0 && y>=0 && yy>=0 ) {
		if( map.getArrete(x,y,xx,yy,true) != NULL) {
			if(map.getArrete(x,y,xx,yy,true)->getJoueur()->getNb() == 0 && joueur[j-1]->hasHe(arg, 1) && joueur[j-1]->hasHe(boi, 1)) {
                		if (map.getArrete(x,y,xx,yy,true)->getNoeud(0) != NULL && map.getArrete(x,y,xx,yy,true)->getNoeud(1) != NULL) {
                    			if((map.getArrete(x,y,xx,yy,true)->getNoeud(0)->getJoueur()->getNb() == j ||  map.getArrete(x,y,xx,yy,true)->getNoeud(1)->getJoueur()->getNb() == j) || map.getArrete(x,y,xx,yy,true)->getNoeud(0)->getArrete(0)->getJoueur()->getNb() == j || map.getArrete(x,y,xx,yy,true)->getNoeud(0)->getArrete(1)->getJoueur()->getNb() || map.getArrete(x,y,xx,yy,true)->getNoeud(0)->getArrete(2)->getJoueur()->getNb() == j || map.getArrete(x,y,xx,yy,true)->getNoeud(1)->getArrete(0)->getJoueur()->getNb() == j || map.getArrete(x,y,xx,yy,true)->getNoeud(1)->getArrete(1)->getJoueur()->getNb() || map.getArrete(x,y,xx,yy,true)->getNoeud(1)->getArrete(2)->getJoueur()->getNb() == j) {
                        			if (!((map.getArrete(x,y,xx,yy,true)->getNoeud(0)->getJoueur()->getNb() != j && map.getArrete(x,y,xx,yy,true)->getNoeud(0)->getJoueur()->getNb() != 0) || (map.getArrete(x,y,xx,yy,true)->getNoeud(1)->getJoueur()->getNb() != j && map.getArrete(x,y,xx,yy,true)->getNoeud(1)->getJoueur()->getNb() != 0))) {
                            				delete map.getArrete(x,y,xx,yy,true)->getJoueur();
                            				map.getArrete(x,y,xx,yy,true)->setJoueur(joueur[j-1]);
                            				delete joueur[j-1]->remRes(boi);
                            				res[1]--;
                            				delete joueur[j-1]->remRes(arg);
                            				res[0]--;
                            				delete arg;
                            				delete boi;
                            				return true;
                        			}
                    			}
                		}
			}
		}
	}	
    delete arg;
    delete boi;
    return false;
}

void ML_Jeux::addVille(int j){
	int x;
	int y;
	int xx;
	int yy;
	int xxx;
	int yyy;
	cout<<"Placez votre colonie : x ?"<<endl;
	cin>>x;
	cout<<"Placez votre colonie : y ?"<<endl;
	cin>>y;
	cout<<"Placez votre colonie : x' ?"<<endl;
	cin>>xx;
	cout<<"Placez votre colonie : y' ?"<<endl;
	cin>>yy;
	cout<<"Placez votre colonie : x'' ?"<<endl;
	cin>>xxx;
	cout<<"Placez votre colonie : y'' ?"<<endl;
	cin>>yyy;
	if (placerVille(x, y, xx , yy , xxx, yyy, j)) {
		cout<<"Colonie envoluée en ville"<<endl;
	} else {
		cout<<"Impossible d'évoluer ici."<<endl;
	}
}

bool ML_Jeux::placerVille(int x,int y,int xx ,int yy ,int xxx ,int yyy,int j) {
	ML_MPremiere* min = new ML_Minerai();
	ML_MPremiere* ble = new ML_Ble();
	if( x<7 && xx<7 && xxx<7 && y<7 && yy<7 && yyy<7 && x>=0 && xx>=0 && xxx>=0 && y>=0 && yy>=0 && yyy>=0) {
		if( map.getNoeud(x,y,xx,yy,xxx,yyy) != NULL) {
			if(map.getNoeud(x,y,xx,yy,xxx,yyy)->getJoueur()->getNb() == j && joueur[j-1]->hasHe(min, 3) && joueur[j-1]->hasHe(ble, 2)) {
				map.getNoeud(x,y,xx,yy,xxx,yyy)->setVille();
				delete joueur[j-1]->remRes(ble);
				delete joueur[j-1]->remRes(ble);
				res[4]--;
				res[4]--;
				delete joueur[j-1]->remRes(min);
				delete joueur[j-1]->remRes(min);
				delete joueur[j-1]->remRes(min);
				res[2]--;
				res[2]--;
				res[2]--;
				joueur[j-1]->addScore();
				delete ble;
				delete min;
				return true;
			}
		}
	}
    delete ble;
    delete min;
    return false;

}

void ML_Jeux::setBrigand(int x, int y) {
	map.getTerrain(xBrigand, yBrigand)->setBrigand();
	map.getTerrain(x,y)->setBrigand();
	xBrigand = x;
	yBrigand = y;
}

int ML_Jeux::getXBrigand(){
	return xBrigand;
}

int ML_Jeux::getYBrigand(){
	return yBrigand;
}

int* ML_Jeux::getRes(){
	return res;
}

ML_Joueur** ML_Jeux::getJoueur(){
	return joueur;
}
	

	

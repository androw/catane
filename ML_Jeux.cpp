//MANSOURATI ET LORIN

#include "ML_Jeux.h"

using namespace std;

ML_Jeux::ML_Jeux() {
	nbjoueur = 4;
	armee = 0;
	armeemax = 0;
	route =0;
	routemax = 0;
	for (int i=0; i<5; i++) {
		res[i] = 0;
		dev[i]=0;
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
	armeemax = 0;
	route =0;
	routemax = 0;
        for (int i=0; i<5; i++) {
                res[i] = 0;
                dev[i]=0;
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
	distribResInit();
	cout<<"Initialisation finie. Debut de la partie."<<endl;
	bool victory = false;
	do {
	for (i = 1; (i<= nbjoueur && !victory); i++) {
		maxL();
		if (distribRes()){
                    map.afficher();
                    cout<<"Au joueur "<<i<<" de placer le Brigand !"<<endl;
					ML_Dev * m = new ML_Chevalier();
					m->use(joueur[i-1],this);
					delete m; 
                    BrigandActive();
		}
		do {
			do{
				map.afficher();
				cout<<"L'armee la plus grande est d�tenue par "<<armee<<"."<<endl;
				cout<<"La route la plus grande est d�tenue par "<<route<<"."<<endl;
				joueur[i-1]->afficherCarteMP();
				joueur[i-1]->afficherCarteDev();
				cout<<"Au joueur "<<i<<" de jouer !"<<endl;
				cout<<"1. Placez une route ?"<<endl; //OK
				cout<<"2. Placez une colonie ?"<<endl; //OK
				cout<<"3. Placez une ville ?"<<endl; //OK
				cout<<"4. Faire un echange entre joueurs ?"<<endl; //OK
				cout<<"5. Faire un echange avec un port ?"<<endl; //OK
				cout<<"6. Faire un echange avec la banque ?"<<endl; //OK
				cout<<"7. Achat d'une carte developpement ?"<<endl; //OK
				cout<<"8. Utiliser une carte developpement ?"<<endl;
				cout<<"9. Finir tour"<<endl; //OK
				cin>>choix;
			}while(choix < 0 || choix > 9);
			if (choix == 1) {addRoute(i);}
			else if (choix == 2) {addColonie(i);}
			else if (choix == 3) {addVille(i);}
			else if (choix == 4) {echange(joueur[i-1]);}
			else if (choix == 5) {tradePort(joueur[i-1]);}
			else if (choix == 6) {trade(i);}
			else if (choix == 7) {tradeDev(i);}
			else if (choix == 8) {useCard(joueur[i-1]);}
		}while (choix != 9);
		if (joueur[i-1]->getScore() == 10) {victory = true;}
	}
	} while (!victory);
}

ML_Map ML_Jeux::getMap() {
	return map;
}

void ML_Jeux::refreshArmee() {
	int i,j;
	for (i = 0; i < nbjoueur; i++) {
                if (joueur[i]->getArmee() > max) {
                        max = joueur[i]->getArmee();
                        j = i;
                }
        }
	if (max != armeemax) {
		if (armee != 0) joueur[armee-1]->remScore();
		int max = 0;
		joueur[j]->addScore();
		armee = j+1;
	}
}	

void ML_Jeux::trade(int j){
	int insell;
	int inbuy;
	do {
		cout<<"0. Argile 1. Bois 2. Minerai 3. Laine 4. Ble"<<endl;
		cout<<"De quelle ressource (x4) voulez vous vous débarassez ?"<<endl;
		cin>>insell;
		cout<<"Quelle ressource (x1) souhaitez vous acquérir ?"<<endl;
		cin>>inbuy;
	} while (0 > insell || insell > 4 || 0 > inbuy || inbuy > 4);
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





void ML_Jeux::tradeDev(int j){

		ML_MPremiere* m1 = NULL;

		ML_MPremiere* m2 = NULL;

		ML_MPremiere* m3 = NULL;

		m1 = new ML_Minerai();

		m2 = new ML_Laine();

		m3 = new ML_Ble();

	if (!(joueur[j-1]->hasHe(m1, 1))) {
		cout<<"Vous n'avez pas les ressources nécessaires"<<endl;
		delete m1;
		return;}
	if (!(joueur[j-1]->hasHe(m2, 1))) {
		cout<<"Vous n'avez pas les ressources nécessaires"<<endl;
		delete m2;
		return;}
	if (!(joueur[j-1]->hasHe(m3, 1))) {
		cout<<"Vous n'avez pas les ressources nécessaires"<<endl;
		delete m3;
		return;}

	ML_Dev* mn = NULL;

	int inbuy = rand()%5;

	if (inbuy == 0) {
		mn = new ML_Chevalier();
	} else if (inbuy == 1) {
		mn = new ML_PVictoire();
	} else if (inbuy == 2) {
		mn = new ML_Progres1();
	} else if (inbuy == 3) {
		mn = new ML_Progres2();
	} else if (inbuy == 4) {
		mn = new ML_Progres3();
	}
	if (dev[inbuy] >= mn->getMax()) {
		cout<<"Plus de carte disponible, échange annulé"<<endl;
		delete m1;
		delete m2;
		delete m3;
		delete mn;
	} else {
		dev[inbuy]++;
		res[2] = res[2] - 1;
		res[3] = res[3] - 1;
		res[4] = res[4] - 1;
		delete joueur[j-1]->remRes(m1);
		delete joueur[j-1]->remRes(m2);
		delete joueur[j-1]->remRes(m3);
		joueur[j-1]->addDev(mn);
	}
	
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
                    for (k = 0; k<6;k++) {
					ML_MPremiere* m = NULL;
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
						if (res[1] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
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
					} else if (map.getTerrain(i, j)->getName() == "Paturage"){
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

bool ML_Jeux::echange(ML_Joueur* j1) {
    
    unsigned int i;
	int j;
	int choix1,choix2;
	choix2 = 0;

	do{
		cout<<"A Quel joueur proposez vous un échange ?"<<endl;
		cin>>j;
	}while( j<1 || j>nbjoueur);

	vector<ML_MPremiere*> matPrem1;
	vector<ML_MPremiere*> matPrem2;

	do{
		cout<<"Quelles Ressources voulez vous donner ?"<<endl;
		do{
			cout<<"0. Argile 1. Bois 2. Minerai 3. Laine 4. Ble"<<endl;
			cin>>choix1;
		} while (0 > choix1 || choix1 > 4 );

		ML_MPremiere* m = NULL;

		if (choix1 == 0) {
			m = new ML_Argile();
		} else if (choix1 == 1) {
			m = new ML_Bois();
		} else if (choix1 == 2) {
			m = new ML_Minerai();
		} else if (choix1 == 3) {
			m = new ML_Laine();
		} else if (choix1 == 4) {
			m = new ML_Ble();
		}

		if((j1->hasHe(m,1))) {
			matPrem1.push_back(m);
			cout<<"ajouter une autre ressource : 0.Oui 1.Non 2.annuller?"<<endl;
			cin>>choix2;
            if(choix2 == 2) {
                return false;
            }
		}else {cout<<"Vous n'avez pas cette ressource"<<endl;}

	}while(choix2 !=1 );

	choix2 = 0;

	do{
		cout<<"Quelles Ressources voulez vous prendre ?"<<endl;
		do{
			cout<<"0. Argile 1. Bois 2. Minerai 3. Laine 4. Ble"<<endl;
			cin>>choix1;
		} while (0 > choix1 || choix1 > 4 );

		ML_MPremiere* m = NULL;

		if (choix1 == 0) {
			m = new ML_Argile();
		} else if (choix1 == 1) {
			m = new ML_Bois();
		} else if (choix1 == 2) {
			m = new ML_Minerai();
		} else if (choix1 == 3) {
			m = new ML_Laine();
		} else if (choix1 == 4) {
			m = new ML_Ble();
		}

		if((joueur[j-1]->hasHe(m,1))) {
			matPrem2.push_back(m);
			cout<<"ajouter une autre ressource : 0.Oui 1.Non 2.annuller?"<<endl;
			cin>>choix2;
            if(choix2 == 2) {
                return false;
            }
		}else {cout<<"Vous n'avez pas cette ressource"<<endl;}

	}while(choix2 !=1);

	
	for (i = 0; i < matPrem2.size(); i++) {
        	j1->addRes(matPrem2.at(i));
            joueur[j-1]->remRes(matPrem2.at(i));
        
    	}
    
    for (i = 0; i < matPrem1.size(); i++) {
        joueur[j-1]->addRes(matPrem1.at(i));
        j1->remRes(matPrem1.at(i));
        
    }


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
			if(map.getNoeud(x,y,xx,yy,xxx,yyy)->getJoueur()->getNb() == j && joueur[j-1]->hasHe(min, 3) && joueur[j-1]->hasHe(ble, 2) && (!map.getNoeud(x,y,xx,yy,xxx,yyy)->isVille())) {
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
	
void ML_Jeux::tradePort(ML_Joueur* j){
	int x;
	int y;
	do {
		cout<<"Avec quel port voulez vous �changer ?"<<endl;
		cout<<"x ?"<<endl;
		cin>>x;
		cout<<"y ?"<<endl;
                cin>>y;
	} while (x<0 || x >= 7 || y<0 || y >= 7);
	
	ML_Terrain* t = map.getTerrain(x, y);
	if (t != NULL) {
		if (t->getName().find("Port") == string::npos) {
			cout<<"Ceci n'est pas un port."<<endl;
			return;
		}
		
		bool isHere = false;
		for (int i; i<6; i++) {
			if (t->getArrete(i) != NULL) {
				if (t->getArrete(i)->getJoueur()->getNb() == j->getNb()) isHere = true;
			}
		}
		if (!isHere) {cout<<"Vous n'avez pas de colonie sur ce port."<<endl; return;}
		
		if (t->getName().find("?") != string::npos) {
            cout<<"Port g�n�rique, 3 ressources contre une."<<endl;
            tradePortGen(j);
			return;
         } else {
			cout<<"Port sp�cifique, 2 ressources contre une."<<endl;
            tradePortOther(j,t);
			return;
		}
	} else {
		cout<<"Ceci n'est pas un port."<<endl;
		return;
	}
}

void ML_Jeux::tradePortGen(ML_Joueur* j) {
	int insell;
	int inbuy;
	do {
		cout<<"0. Argile 1. Bois 2. Minerai 3. Laine 4. Ble"<<endl;
		cout<<"De quelle ressource (x3) voulez vous vous débarassez ?"<<endl;
		cin>>insell;
		cout<<"Quelle ressource (x1) souhaitez vous acquérir ?"<<endl;
		cin>>inbuy;
	} while (0 > insell || insell > 4 || 0 > inbuy || inbuy > 4);
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
	if (!(j->hasHe(m, 3))) {
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
		return;
	} else {
		res[inbuy]++;
		res[insell] = res[insell] - 3;
		delete j->remRes(m);
		delete j->remRes(m);
		delete j->remRes(m);
		j->addRes(mn);
	}
	delete m;	
}

void ML_Jeux::tradePortOther(ML_Joueur* j, ML_Terrain* t) {
	int inbuy;
	int insell;
	do {
		cout<<"0. Argile 1. Bois 2. Minerai 3. Laine 4. Ble"<<endl;
		cout<<"Quelle ressource (x1) souhaitez vous acquérir ?"<<endl;
		cin>>inbuy;
	} while (0 > inbuy || inbuy > 4);
	
	ML_MPremiere* m = NULL;
	
	if (t->getName().find("Arg") != string::npos) {
		m = new ML_Argile();
		insell = 0;
	} else if (t->getName().find("Bois") != string::npos) {
		m = new ML_Bois();
		insell = 1;
	} else if (t->getName().find("Min") != string::npos) {
		m = new ML_Minerai();
		insell = 2;
	} else if (t->getName().find("Lai") != string::npos) {
		m = new ML_Laine();
		insell = 3;
	} else if (t->getName().find("Ble") != string::npos) {
		m = new ML_Ble();
		insell = 4;
	}
	if (!(j->hasHe(m, 2))) {
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
		return;
	} else {
		res[inbuy]++;
		res[insell] = res[insell] - 2;
		delete j->remRes(m);
		delete j->remRes(m);
		j->addRes(mn);
	}
	delete m;	
}

void ML_Jeux::distribResInit(){
	int i,j;
	for (i = 0; i<7 ; i++) {
			for (j = 0; j<7 ; j++) {
				if (map.getTerrain(i, j) != NULL) {
					int k;
                    for (k = 0; k<6;k++) {
					ML_MPremiere* m = NULL;
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
						if (res[1] >= m->getMax()) {
							delete m;
							m = NULL;	
						} else {
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
					} else if (map.getTerrain(i, j)->getName() == "Paturage"){
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

void ML_Jeux::useCard(ML_Joueur * jj){
    
    int choix;
    ML_Dev* m = NULL;
    
    if(jj->getDev().size() > 0) {
        
        do{
            cout<<"Quelle Carte voulez vous utiliser ?"<<endl;
            cout<<"0. Chevalier 1. Point Victoire 2. Progres 1: Placer 2 routes 3. Progres 2 : 2 ressources  4. Progres 3 : prendre resource de tout les joueur 5. Annuler"<<endl;
            cin>>choix;
            
                
                if (choix == 0) {
                    m = new ML_Chevalier();
                } else if (choix == 1) {
                    m = new ML_PVictoire();
                } else if (choix == 2) {
                    m = new ML_Progres1();
                } else if (choix == 3) {
                    m = new ML_Progres2();
                } else if (choix == 4) {
                    m = new ML_Progres3();
                }
            
            if(choix != 5 && (jj->hasHeDev(m, 1))) {
                m->use(jj,this);
                jj->remDev(m);
                delete m;
            }
            
        } while ( !(jj->hasHeDev(m, 1)) && choix != 5);
    }else { cout<<"Vous n'avez pas cette Carte"<<endl;}
    
}

void ML_Jeux::BrigandActive() {
    int i;
    int j;
    for (i=1; i<nbjoueur+1;i++) {
        int choix;
        ML_MPremiere* m = NULL;
        if(joueur[i-1]->getMPrem().size() > 7) {
            int nbCartes = joueur[i-1]->getMPrem().size();
            nbCartes = nbCartes / 2;
            for (j = 0; j< nbCartes;j++) {
                do {
                    do{
                        cout<<"0. Argile 1. Bois 2. Minerai 3. Laine 4. Ble"<<endl;
                        cout<<"joueur"<<joueur[i-1]->getNb()<<" : Quelle ressource (x1) souhaitez vous enlever (la moiti� de vos cartes)?"<<endl;
                        cin>>choix;
                    } while (choix < 0 || choix >4);
                    if (choix == 0) {
                        m = new ML_Argile();
                    } else if (choix == 1) {
                        m = new ML_Bois();
                    } else if (choix == 2) {
                        m = new ML_Minerai();
                    } else if (choix == 3) {
                        m = new ML_Laine();
                    } else if (choix == 4) {
                        m = new ML_Ble();
                    }
                } while(!(joueur[i-1]->hasHe(m,1)));
                joueur[i-1]->remRes(m);
                dev[0]--;
            }
        }
    }
}

int ML_Jeux::getNbJ() {
    return nbjoueur;
}

int ML_Jeux::maxLrec(int acc, ML_Arrete* a, vector<ML_Arrete*>* v) {
	if (!seek(v, a)) {
		v->push_back(a);
		acc++;
		int tab[6];
		for (int i = 0; i<6; i++) {
			tab[i] = 0;
		}
		int j = a->getJoueur()->getNb();
		if (a->getNoeud(0) != NULL) {
			if (a->getNoeud(0)->getJoueur()->getNb() == 0 || a->getNoeud(0)->getJoueur()->getNb() == j) {
			if (a->getNoeud(0)->getArrete(0) != NULL) {
				if (a->getNoeud(0)->getArrete(0)->getJoueur()->getNb() == j) tab[0] = maxLrec(acc, a->getNoeud(0)->getArrete(0), v);
			}
			if (a->getNoeud(0)->getArrete(1) != NULL) {
				if (a->getNoeud(0)->getArrete(1)->getJoueur()->getNb() == j) tab[1] = maxLrec(acc, a->getNoeud(0)->getArrete(1), v);
			}
			if (a->getNoeud(0)->getArrete(2) != NULL) {
				if (a->getNoeud(0)->getArrete(2)->getJoueur()->getNb() == j) tab[2] = maxLrec(acc, a->getNoeud(0)->getArrete(2), v);
			}
			}
		}
		if (a->getNoeud(1) != NULL) {
			if (a->getNoeud(1)->getJoueur()->getNb() == 0 || a->getNoeud(1)->getJoueur()->getNb() == j) {
			if (a->getNoeud(1)->getArrete(0) != NULL) {
				if (a->getNoeud(1)->getArrete(0)->getJoueur()->getNb() == j) tab[3] = maxLrec(acc, a->getNoeud(1)->getArrete(0), v);
			}
			if (a->getNoeud(1)->getArrete(1) != NULL) {
				if (a->getNoeud(1)->getArrete(1)->getJoueur()->getNb() == j) tab[4] = maxLrec(acc, a->getNoeud(1)->getArrete(1), v);
			}
			if (a->getNoeud(1)->getArrete(2) != NULL) {
				if (a->getNoeud(1)->getArrete(2)->getJoueur()->getNb() == j) tab[5] = maxLrec(acc, a->getNoeud(1)->getArrete(2), v);
			}
			}
		}
		int max = acc;
		for (int i = 0; i<6; i++) {
			if (tab[i] > max) max = tab[i];
		}
		return max;
	} else {
		return acc;
	}
}

void ML_Jeux::maxL() {
	vector<ML_Arrete*>* v = new vector<ML_Arrete*>;
	int i,j,k;
	int max = 0;
	int jo = 0;
	for (i = 0; i<7 ; i++) {
		for (j = 0; j<7 ; j++) {
			if (map.getTerrain(i, j) != NULL) {
				for (k = 0; k<6; k++) {
					if (map.getTerrain(i, j)->getArrete(k) != NULL) {
						if (map.getTerrain(i, j)->getArrete(k)->getJoueur()->getNb() != 0) {
							int inter = maxLrec(1, map.getTerrain(i, j)->getArrete(k), v);
							if (inter > max) {
								max = inter;
								jo = map.getTerrain(i, j)->getArrete(k)->getJoueur()->getNb();
							}
						}
					}
				}
			}
		}
	}
	if (route != 0) joueur[route-1]->remScore();
	joueur[jo-1]->addScore();
	route = jo;
}


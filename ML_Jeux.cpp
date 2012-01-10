#include "ML_Jeux.h"

using namespace std;

ML_Jeux::ML_Jeux() {
	nbjoueur = 4;
	for (int i=0; i< 4; i++) {
		joueur[i] = new ML_Joueur(i+1);
	} 
}

ML_Jeux::ML_Jeux(int p) {
	nbjoueur = p;
}

void ML_Jeux::init() {
	int i;
	int x,y,xx,yy,xxx,yyy;
	int choix = 0;
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
		}while(!(placerColonie(x,y,xx,yy,xxx,yyy,i)));
        
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
		}while(!(placerColonie(x,y,xx,yy,xxx,yyy,i)));

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

	for (i = 1; i<= nbjoueur; i++) {

		do{
			do{
				map.afficher();
				cout<<"Au joueur "<<i<<" de jouer !"<<endl;
				cout<<"1.placez une route ?"<<endl;
				cout<<"2.placez une Colonie?"<<endl;
				cout<<"3.placez une Ville?"<<endl;
				cout<<"4.faire une échange entre joueurs?"<<endl;
				cout<<"5.faire une échange avec un port?"<<endl;
				cout<<"6.finir tour"<<endl;
				cin>>choix;
			}while(choix<0 || choix >7);
		}while(!(joueur[i]->getScore() == 10));
	}
}

ML_Map ML_Jeux::getMap() {
	return map;
}

bool ML_Jeux::distribRes(){
	int de = lancerDe()+lancerDe();
	int i,j;
	if (de != 7) {
		for (i = 0; i<7 ; i++) {
			for (j = 0; j<7 ; j++) {
				if (map.getTerrain(i, j) != NULL) {
				if (map.getTerrain(i, j)->getValeur() == de) {
					int k;
					ML_MPremiere* m = NULL;
                    for (k = 0; k<6;k++) {
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
                        if (m != NULL && map.getTerrain(i, j)->getNoeud(k) != NULL) {
							if (map.getTerrain(i, j)->getNoeud(k)->getJoueur() != NULL) {
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

bool ML_Jeux::placerColonie(int x,int y,int xx ,int yy ,int xxx ,int yyy,int j) {
	ML_MPremiere* arg = new ML_Argile();
	ML_MPremiere* boi = new ML_Bois();
	ML_MPremiere* lai = new ML_Laine();
	ML_MPremiere* ble = new ML_Ble();
	if( x<7 && xx<7 && xxx<7 && y<7 && yy<7 && yyy<7 && x>=0 && xx>=0 && xxx>=0 && y>=0 && yy>=0 && yyy>=0) {
		if( map.getNoeud(x,y,xx,yy,xxx,yyy) != NULL) {
			if(map.getNoeud(x,y,xx,yy,xxx,yyy)->getJoueur()->getNb() == 0 && joueur[j-1]->hasHe(arg, 1) && joueur[j-1]->hasHe(boi, 1) && joueur[j-1]->hasHe(lai, 1) && joueur[j-1]->hasHe(ble, 1) && map.getNoeud(x,y,xx,yy,xxx,yyy)->checkDist())  {
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


bool ML_Jeux::placerRoute(int x,int y,int xx ,int yy ,int j){
	ML_MPremiere* arg = new ML_Argile();
	ML_MPremiere* boi = new ML_Bois();

	if( x<7 && xx<7 && y<7 && yy<7 && x>=0 && xx>=0 && y>=0 && yy>=0 ) {
		if( map.getArrete(x,y,xx,yy) != NULL) {
			if(map.getArrete(x,y,xx,yy)->getJoueur()->getNb() == 0 && joueur[j-1]->hasHe(arg, 1) && joueur[j-1]->hasHe(boi, 1)) {
                if (map.getArrete(x,y,xx,yy)->getNoeud(0) != NULL && map.getArrete(x,y,xx,yy)->getNoeud(1) != NULL) {
                    if((map.getArrete(x,y,xx,yy)->getNoeud(0)->getJoueur()->getNb() == j ||  map.getArrete(x,y,xx,yy)->getNoeud(1)->getJoueur()->getNb() == j)) {
                        cout<<"Help"<<endl;
                        if (!((map.getArrete(x,y,xx,yy)->getNoeud(0)->getJoueur()->getNb() != j && map.getArrete(x,y,xx,yy)->getNoeud(0)->getJoueur()->getNb() != 0) || (map.getArrete(x,y,xx,yy)->getNoeud(1)->getJoueur()->getNb() != j && map.getArrete(x,y,xx,yy)->getNoeud(1)->getJoueur()->getNb() != 0))) {
                            delete map.getArrete(x,y,xx,yy)->getJoueur();
                            map.getArrete(x,y,xx,yy)->setJoueur(joueur[j-1]);
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

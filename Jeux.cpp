#include "Jeux.h"

using namespace std;

Jeux::Jeux() {
	nbjoueur = 4;
	for (int i=0; i< 4; i++) {
		joueur[i] = new Joueur(i+1);
	} 
}

Jeux::Jeux(int p) {
	nbjoueur = p;
}

void Jeux::init() {
	int i;
	int x,y,xx,yy,xxx,yyy;
	for (i = 1; i<= nbjoueur; i++) {
		
		do{
			map.afficher();
			cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
			cout<<"placez votre route . x?"<<endl;
			cin>>x;
			cout<<"placez votre route . y?"<<endl;
			cin>>y;
			cout<<"placez votre route . x'?"<<endl;
			cin>>xx;
			cout<<"placez votre route . y'?"<<endl;
			cin>>yy;
		}while(!(placerRoute(x,y,xx,yy,i)));

		do{
			map.afficher();
			cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
			cout<<"placez votre route . x?"<<endl;
			cin>>x;
			cout<<"placez votre route . y?"<<endl;
			cin>>y;
			cout<<"placez votre route . x'?"<<endl;
			cin>>xx;
			cout<<"placez votre route . y'?"<<endl;
			cin>>yy;
			cout<<"placez votre route . x''?"<<endl;
			cin>>xxx;
			cout<<"placez votre route . y''?"<<endl;
			cin>>yyy;
		}while(!(placerColonie(x,y,xx,yy,xxx,yyy,i)));
		
		cout<<""<<endl;
	}
	for (i = 1; i<= nbjoueur; i++) {

		do{
			map.afficher();
			cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
			cout<<"placez votre route . x?"<<endl;
			cin>>x;
			cout<<"placez votre route . y?"<<endl;
			cin>>y;
			cout<<"placez votre route . x'?"<<endl;
			cin>>xx;
			cout<<"placez votre route . y'?"<<endl;
			cin>>yy;
		}while(!(placerRoute(x,y,xx,yy,i)));

		do{
			map.afficher();
			cout<<"Au joueur "<<i<<" de placer ses premiers jetons !"<<endl;
			cout<<"placez votre route . x?"<<endl;
			cin>>x;
			cout<<"placez votre route . y?"<<endl;
			cin>>y;
			cout<<"placez votre route . x'?"<<endl;
			cin>>xx;
			cout<<"placez votre route . y'?"<<endl;
			cin>>yy;
			cout<<"placez votre route . x''?"<<endl;
			cin>>xxx;
			cout<<"placez votre route . y''?"<<endl;
			cin>>yyy;
		}while(!(placerColonie(x,y,xx,yy,xxx,yyy,i)));
		
		cout<<""<<endl;
	}
}

Map Jeux::getMap() {
	return map;
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

bool Jeux::placerColonie(int x,int y,int xx ,int yy ,int xxx ,int yyy,int j) {

	if( x<7 && xx<7 && xxx<7 && y<7 && yy<7 && yyy<7 && x>=0 && xx>=0 && xxx>=0 && y>=0 && yy>=0 && yyy>=0) {
		if( map.getNoeud(x,y,xx,yy,xxx,yyy) != NULL) {
			if(map.getNoeud(x,y,xx,yy,xxx,yyy)->getJoueur()->getNb() == 0 ) {
				delete map.getNoeud(x,y,xx,yy,xxx,yyy)->getJoueur();
				map.getNoeud(x,y,xx,yy,xxx,yyy)->setJoueur(joueur[j-1]);
				return true;
			}else {return false;
			}
		}else {return false;
		}
	
	}else {
		return false;
	}				

}


bool Jeux::placerRoute(int x,int y,int xx ,int yy ,int j){


	if( x<7 && xx<7 && y<7 && yy<7 && x>=0 && xx>=0 && y>=0 && yy>=0 ) {
		if( map.getArrete(x,y,xx,yy) != NULL) {
			if(map.getArrete(x,y,xx,yy)->getJoueur()->getNb() == 0) {
				delete map.getArrete(x,y,xx,yy)->getJoueur();
				map.getArrete(x,y,xx,yy)->setJoueur(joueur[j-1]);
				return true;
			}else {return false;
			}
		}else {return false;
		}
	
	}else {
		return false;
	}

} 

bool Jeux::placerVille(int x,int y,int xx ,int yy ,int xxx ,int yyy,int j) {

	if( x<7 && xx<7 && xxx<7 && y<7 && yy<7 && yyy<7 && x>=0 && xx>=0 && xxx>=0 && y>=0 && yy>=0 && yyy>=0) {
		if( map.getNoeud(x,y,xx,yy,xxx,yyy) != NULL) {
			if(map.getNoeud(x,y,xx,yy,xxx,yyy)->getJoueur()->getNb() == j) {
				map.getNoeud(x,y,xx,yy,xxx,yyy)->setVille();
				return true;
			}else {return false;
			}
		}else {return false;
		}
	
	}else {
		return false;
	}				

}

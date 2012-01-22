//MANSOURATI ET LORIN

#include "ML_Progres1.h"

ML_Progres1::ML_Progres1() {
	MAX = 2;
    name = "Progres1";
}

void ML_Progres1::use(ML_Joueur* j, ML_Jeux* m) {
    int x,xx,y,yy;
    j->addRes(new ML_Argile());
    j->addRes(new ML_Bois());
    j->addRes(new ML_Argile());
    j->addRes(new ML_Bois());
    do{
        m->getMap().afficher();
        cout<<"Au joueur "<<j->getNb()<<" de placer sa route !"<<endl;
        cout<<"Placez votre route : x ?"<<endl;
        cin>>x;
        cout<<"Placez votre route : y ?"<<endl;
        cin>>y;
        cout<<"Placez votre route : x' ?"<<endl;
        cin>>xx;
        cout<<"Placez votre route : y' ?"<<endl;
        cin>>yy;
    }while(!(m->placerRoute(x,y,xx,yy,j->getNb())));
    
    do{
        m->getMap().afficher();
        cout<<"Au joueur "<<j->getNb()<<" de placer sa route !"<<endl;
        cout<<"Placez votre route : x ?"<<endl;
        cin>>x;
        cout<<"Placez votre route : y ?"<<endl;
        cin>>y;
        cout<<"Placez votre route : x' ?"<<endl;
        cin>>xx;
        cout<<"Placez votre route : y' ?"<<endl;
        cin>>yy;
    }while(!(m->placerRoute(x,y,xx,yy,j->getNb())));
}

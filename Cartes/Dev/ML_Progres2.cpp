//MANSOURATI ET LORIN

#include "ML_Progres2.h"

ML_Progres2::ML_Progres2() {
	MAX = 2;
    name = "Progres2";
}

void ML_Progres2::use(ML_Joueur* j, ML_Jeux* m) {
    
    int choix;
    // Carte permettant d'avoir 2 fois la ressource voulue.
    
    do{
        cout<<"Au joueur "<<j->getNb()<<" de décider quelle carte il souhaite obtenir 2 fois !"<<endl;
        cout<<"1. Argile?"<<endl;
        cout<<"2. Laine?"<<endl;
        cout<<"3. Minerai?"<<endl;
        cout<<"4. Bois?"<<endl;
        cout<<"5. Ble?"<<endl;
        cin>>choix;
    }while(choix<0 || choix >6);

    
    if(choix == 1) {
        j->addRes(new ML_Argile());
        j->addRes(new ML_Argile());
        m->getRes()[0]++;
        m->getRes()[0]++;
    }else if(choix == 2) {
        j->addRes(new ML_Laine());
        j->addRes(new ML_Laine());
        m->getRes()[3]++;
        m->getRes()[3]++;
    }else if(choix == 3) {
        j->addRes(new ML_Minerai());
        j->addRes(new ML_Minerai());
        m->getRes()[2]++;
        m->getRes()[2]++;
    }else if(choix == 4) {
        j->addRes(new ML_Bois());
        j->addRes(new ML_Bois());
        m->getRes()[1]++;
        m->getRes()[1]++;
    }else if(choix == 5) {
        j->addRes(new ML_Ble());
        j->addRes(new ML_Ble());
        m->getRes()[4]++;
        m->getRes()[4]++;
    }
}

#include "ML_Progres3.h"

ML_Progres3::ML_Progres3() {
	MAX = 2;
    name = "Progres3";
}

void ML_Progres3::use(ML_Joueur* j, ML_Jeux* m) {
    
    int choix;
    
    do{
        cout<<"Au joueur "<<j->getNb()<<" de dŽcider quelle ressource veut il que tout le monde lui donne!"<<endl;
        cout<<"1.Argile?"<<endl;
        cout<<"2.laine?"<<endl;
        cout<<"3.Minerai?"<<endl;
        cout<<"4.Bois?"<<endl;
        cout<<"5.Ble?"<<endl;
        cin>>choix;
    }while(choix<0 || choix >6);
    
    for (int i = 0;i<4;i++) {
        
        if(choix == 1) {
            do{
                j->addRes(m->getJoueur()[i]->remRes(new ML_Argile()));
            }while (m->getJoueur()[i]->hasHe(new ML_Argile(),1));

        }else if(choix == 2) {
            do{
                j->addRes(m->getJoueur()[i]->remRes(new ML_Laine()));
            }while (m->getJoueur()[i]->hasHe(new ML_Laine(),1));

        }else if(choix == 3) {
            do{
                j->addRes(m->getJoueur()[i]->remRes(new ML_Minerai()));
            }while (m->getJoueur()[i]->hasHe(new ML_Minerai(),1));

        }else if(choix == 4) {
            do{
                j->addRes(m->getJoueur()[i]->remRes(new ML_Bois()));
            }while (m->getJoueur()[i]->hasHe(new ML_Bois(),1));

        }else if(choix == 5) {
            do{
                j->addRes(m->getJoueur()[i]->remRes(new ML_Ble()));
            }while (m->getJoueur()[i]->hasHe(new ML_Ble(),1));

        }
            
    }
    

}



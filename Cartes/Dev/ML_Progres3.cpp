//MANSOURATI ET LORIN

#include "ML_Progres3.h"

ML_Progres3::ML_Progres3() {
	MAX = 2;
    name = "Progres3";
}

void ML_Progres3::use(ML_Joueur* j, ML_Jeux* m) {
    
    int choix;
    //on parcours tout les jeux des joueurs ˆ part celui qui utilise la carte et on donne les ressources des joueurs qui correspondent au choix du joueur qui joue la carte.
    
    do{
        cout<<"Au joueur "<<j->getNb()<<" de demander la ressource qu'il souhaite"<<endl;
        cout<<"1. Argile?"<<endl;
        cout<<"2. Laine?"<<endl;
        cout<<"3. Minerai?"<<endl;
        cout<<"4. Bois?"<<endl;
        cout<<"5. Ble?"<<endl;
        cin>>choix;
    }while(choix<0 || choix >6);
    
    for (int i = 0;i<m->getNbJ();i++) {


	if (i + 1 != (j->getNb())) {
			
        
        if(choix == 1) {


            while (m->getJoueur()[i]->hasHe(new ML_Argile(),1)){
                j->addRes(m->getJoueur()[i]->remRes(new ML_Argile()));
            };

        }else if(choix == 2) {
            while (m->getJoueur()[i]->hasHe(new ML_Laine(),1)){
                j->addRes(m->getJoueur()[i]->remRes(new ML_Laine()));
            }

        }else if(choix == 3) {
            while (m->getJoueur()[i]->hasHe(new ML_Minerai(),1)){
                j->addRes(m->getJoueur()[i]->remRes(new ML_Minerai()));
            }

        }else if(choix == 4) {
            while (m->getJoueur()[i]->hasHe(new ML_Bois(),1)){
                j->addRes(m->getJoueur()[i]->remRes(new ML_Bois()));
            }

        }else if(choix == 5) {
            while (m->getJoueur()[i]->hasHe(new ML_Ble(),1)){
                j->addRes(m->getJoueur()[i]->remRes(new ML_Ble()));
            }

        }
            
    }
    
  }
}



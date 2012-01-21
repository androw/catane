//MANSOURATI ET LORIN

#include "ML_PVictoire.h"

ML_PVictoire::ML_PVictoire() {
	MAX = 5;
    name = "PVictoire";
}

void ML_PVictoire::use(ML_Joueur* j, ML_Jeux* m) {
	j->addScore();
}
	


#include "ML_PVictoire.h"

ML_PVictoire::ML_PVictoire() {
	MAX = 5;
}

void ML_PVictoire::use(ML_Joueur* j, ML_Map* m) {
	j->addScore();
}
	


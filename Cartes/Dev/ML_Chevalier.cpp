#include "ML_Chevalier.h"

ML_Chevalier::ML_Chevalier() {
	MAX = 14;
}

void ML_Chevalier::use(ML_Joueur* j, ML_Map* m) {
	j->addArmee();
}

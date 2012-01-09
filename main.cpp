#include "./Map/ML_Map.h"
#include "ML_Jeux.h"

#include <ctime>

int main () {
	srand(time(NULL));
	ML_Jeux letsplay;
	letsplay.init();
	letsplay.distribRes();

	letsplay.getMap().afficher();


	return 0;
}

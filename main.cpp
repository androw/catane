#include "./Map/Map.h"
#include "Jeux.h"

#include <ctime>

int main () {
	srand(time(NULL));
	Jeux letsplay;
	letsplay.init();
	letsplay.distribRes();

	letsplay.getMap().afficher();


	return 0;
}

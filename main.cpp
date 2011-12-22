#include "./Map/Map.h"
#include "Jeux.h"

#include <ctime>

int main () {
	srand(time(NULL));
	Jeux letsplay;
	
	letsplay.distribRes();
	Map map;
	//map.afficher();
	
	if(map.getNoeud(1,2,1,3,2,2) == NULL) {
		cout<<" c'est NULL "<<endl;
	}

	return 0;
}

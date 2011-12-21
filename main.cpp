#include "./Map/Map.h"
#include "Jeux.h"

#include <ctime>

int main () {
	srand(time(NULL));
	Jeux letsplay;
	
	letsplay.distribRes();
	Map map;
	map.afficher();

<<<<<<< HEAD

=======
	if (map.getTerrain(2, 3)->getNoeud(0)->getTerrain(2) == NULL) cout<<"YESSSS"<<endl;

	if(map.getNoeud(2,3,2,4,1,4) == NULL) {
		cout<<"NULL"<<endl;
	}
>>>>>>> acfc94858c74e62475678b571ff91e9b02aacd79
	return 0;
}

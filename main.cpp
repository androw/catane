#include "./Map/Map.h"
#include "Jeux.h"

#include <ctime>

int main () {
	srand(time(NULL));
	Jeux letsplay;
	
	letsplay.distribRes();
	Map map;
	map.afficher();
	if(map.getArrete(2,3,2,4) == NULL) {
		cout<<"NULL"<<endl;
	}
	return 0;
}

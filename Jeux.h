#ifndef JEUX_H
#define JEUX_H

#include <iostream>

#include "Utils.h"
#include "./Map/Map.h"
#include "./Cartes/MPremieres/MPremieres.h"

class Jeux {
	private:
		Map map;
		int res[5];
		int nbjoueur;
	public:
		Jeux();
		Jeux(int);
		bool distribRes();
		void init();
        bool initEchange(Joueur* j1, Joueur* j2);
        void echange(Joueur*, Joueur*, MPremiere*, int);
};



#endif

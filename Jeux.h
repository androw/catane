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
        bool initEchange();
        bool echange(Joueur*, Joueur*, MPremiere*, MPremiere*, int, int);
        void partEchange(Joueur*, Joueur*, MPremiere*, int);
};



#endif

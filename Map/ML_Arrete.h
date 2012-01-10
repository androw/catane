#ifndef ARRETE_H
#define ARRETE_H

#include "../Terrains/ML_Terrain.h"
#include "ML_Noeud.h"
#include "../ML_Joueur.h"

class ML_Arrete {
	protected:
		ML_Noeud * noeud[2];
		ML_Terrain * terrain[2];
		ML_Joueur * j;
	public:
		ML_Arrete();
		void setNoeud(int, ML_Noeud *);
        ML_Noeud* getNoeud(int);
        void addNoeud(ML_Noeud*);
		ML_Terrain * getTerrain(int);
		void setTerrain(int, ML_Terrain*);
		ML_Joueur* getJoueur();
		void setJoueur(ML_Joueur* pj);
};
#endif

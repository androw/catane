#ifndef ML_NOEUD_H
#define ML_NOEUD_H

#include "../Terrains/ML_Terrain.h"
#include "ML_Arrete.h"
#include "../ML_Joueur.h"

class ML_Noeud {
	protected:
		ML_Arrete* arrete[3];
		ML_Terrain* terrain[3];
		ML_Joueur* j;
		bool ville;
	public:
		ML_Noeud();
		void setArrete(int, ML_Arrete*);
		ML_Arrete* getArrete(int);
		ML_Terrain* getTerrain(int);
		void setTerrain(int, ML_Terrain*);
		void addArrete(ML_Arrete*);
		ML_Joueur* getJoueur();
		void setJoueur(ML_Joueur*);
		bool checkDist();
		void setVille();
		bool isVille();
        bool hasRoute(int);
};
#endif

#ifndef NOEUD_H
#define NOEUD_H

#include "../Terrains/Terrain.h"
#include "Arrete.h"
#include "../Joueur.h"

class Noeud {
	protected:
		Arrete * arrete[3];
		Terrain * terrain[3];
		Joueur * j;
		bool ville;
	public:
		Noeud();
		void setArrete(int, Arrete *);
		Arrete* getArrete(int);
		Terrain * getTerrain(int);
		void setTerrain(int, Terrain*);
		void addArrete(Arrete *);
		Joueur* getJoueur();
		void setJoueur(Joueur* pj);
		bool checkDist();
		void setVille();
};
#endif

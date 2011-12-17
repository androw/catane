#ifndef ARRETE_H
#define ARRETE_H

#include "../Terrains/Terrain.h"
#include "Noeud.h"
#include "../Joueur.h"

class Arrete {
	protected:
		Noeud * noeud[2];
		Terrain * terrain[2];
		Joueur * j;
	public:
		Arrete();
		void setNoeud(int, Noeud *);
		Noeud* getNoeud(int);
		Terrain * getTerrain(int);
		void setTerrain(int, Terrain*);
		Joueur* getJoueur();
		void setJoueur(Joueur* pj);
};
#endif

#ifndef TERRAIN_H
#define TERRAIN_H

#include <cstring>
#include <iostream>


using namespace std;

class Arrete;
class Noeud;

class Terrain {
	protected:
		int MAX;
		int valeur;
		string NAME;
		Arrete * arrete[6];
		Noeud * noeud[6];
	public:
		Terrain();
		int getMax();
		string getName();
		void setArrete(int, Arrete *);
		Arrete* getArrete(int);
		void setNoeud(int, Noeud *);
		Noeud* getNoeud(int);
		int getValeur();
		int setValeur(int);
};

#include "../Map/Arrete.h"
#include "../Map/Noeud.h"

#endif

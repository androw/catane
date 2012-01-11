#ifndef ML_TERRAIN_H
#define ML_TERRAIN_H

#include <cstring>
#include <iostream>


using namespace std;

class ML_Arrete;
class ML_Noeud;

class ML_Terrain {
	protected:
		int MAX;
		int valeur;
		string NAME;
		ML_Arrete * arrete[6];
		ML_Noeud * noeud[6];
		bool brigand;
	public:
		ML_Terrain();
		int getMax();
		string getName();
		void setArrete(int, ML_Arrete *);
		ML_Arrete* getArrete(int);
		void setNoeud(int, ML_Noeud *);
		ML_Noeud* getNoeud(int);
		int getValeur();
		void setValeur(int);
		void setBrigand();
		bool getBrigand();
};

#include "../Map/ML_Arrete.h"
#include "../Map/ML_Noeud.h"
#include "ML_Port.h"

#endif

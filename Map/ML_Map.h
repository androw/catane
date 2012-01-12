#ifndef ML_MAP_H
#define ML_MAP_H

#include <cstdlib>
#include <iostream>
#include <ctime>


class ML_Terrain;
class ML_Noeud;
class ML_Arrete;

class ML_Map {
	protected:
		ML_Terrain * t[7][7];
		int nbt[6];
		int nbint[18];
		ML_Terrain* random();
		
	public:
		ML_Map();
		void addPorts();
		void addMers();
		void afficher();
		void createArrete();
		void createNoeud();
		ML_Terrain* getTerrain(int, int);
		ML_Arrete* getArrete(int, int, int, int,bool);
		ML_Noeud* getNoeud(int, int, int, int, int, int);
		void valeur();
		void createnbint();
};

#include "ML_Arrete.h"
#include "ML_Noeud.h"
#include "../Terrains/ML_Terrain.h"
#include "../Terrains/ML_Terrains.h"

#endif

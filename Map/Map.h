#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "../Terrains/Terrain.h"
#include "../Terrains/Terrains.h"

#include "Arrete.h"
#include "Noeud.h"

class Map {
	protected:
		Terrain * t[7][7];
		int nbt[6];
		int nbint[18];
		Terrain* random();
		
	public:
		Map();
		void addPorts();
		void addMers();
		void afficher();
		void createArrete();
		void createNoeud();
		Terrain* getTerrain(int, int);
		Arrete* getArrete(int, int, int, int);
		Noeud* getNoeud(int, int, int, int, int, int);
		void valeur();
		void createnbint();
};
#endif

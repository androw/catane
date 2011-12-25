#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>

#include "./Cartes/Dev/Dev.h"
#include "./Cartes/MPremieres/MPremiere.h"

using namespace std;

class Joueur {
	protected:
		vector<MPremiere*> matPrem;
		vector<Dev*> dev;
		int nb;
		
	public:
		Joueur(int);
		int getNb();
		void addRes(MPremiere*);
        MPremiere* remRes(MPremiere*);
        bool hasHe(MPremiere*, int);
        
		
};
#endif

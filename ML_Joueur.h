#ifndef ML_JOUEUR_H
#define ML_JOUEUR_H

#include <vector>


#include "./Cartes/MPremieres/ML_MPremiere.h"

using namespace std;

class ML_Dev;

class ML_Joueur {
	protected:
		vector<ML_MPremiere*> matPrem;
		vector<ML_Dev*> dev;
		int nb;
		int armee;
		int score;
	public:
		ML_Joueur(int);
		int getNb();
		void addRes(ML_MPremiere*);
        	ML_MPremiere* remRes(ML_MPremiere*);
        	bool hasHe(ML_MPremiere*, int);
        	void addScore();
		void addArmee();
};

#include "./Cartes/Dev/ML_Dev.h"
#endif

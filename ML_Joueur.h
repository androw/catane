//MANSOURATI ET LORIN

#ifndef ML_JOUEUR_H
#define ML_JOUEUR_H

#include <vector>


#include "./Cartes/MPremieres/ML_MPremiere.h"
#include "./Cartes/MPremieres/ML_MPremieres.h"


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
        void minArmee();
		int getScore();
		vector<ML_Dev*> getDev();
		vector<ML_MPremiere*> getMPrem();
       	void addDev(ML_Dev*);
       	ML_Dev* remDev(ML_Dev*);
       	bool hasHeDev(ML_Dev*, int);
		void remScore();
		int getArmee();
		void afficherCarteMP();
		void afficherCarteDev();
        void suppLastMP();

};

#include "./Cartes/Dev/ML_Dev.h"


#endif

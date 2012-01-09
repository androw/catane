#ifndef ML_JEUX_H
#define ML_JEUX_H

#include <iostream>

#include "ML_Utils.h"
#include "ML_Joueur.h"
#include "./Map/ML_Map.h"
#include "./Cartes/MPremieres/ML_MPremieres.h"

class ML_Jeux {
	private:
		ML_Map map;
		int res[5];
		int nbjoueur;
		ML_Joueur* joueur[4];
	public:
		ML_Jeux();
		ML_Jeux(int);
		bool distribRes();
		void init();
		ML_Map getMap();
        	bool initEchange();
        	bool echange(ML_Joueur*, ML_Joueur*, ML_MPremiere*, ML_MPremiere*, int, int);
        	void partEchange(ML_Joueur*, ML_Joueur*, ML_MPremiere*, int);
		bool placerColonie(int,int,int,int,int,int,int);
		bool placerVille(int,int,int,int,int,int,int);
		bool placerRoute(int,int,int,int,int); 
};



#endif

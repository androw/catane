#ifndef ML_CHEVALIER_H
#define ML_CHEVALIER_H

#include "ML_Dev.h"



class ML_Chevalier : public ML_Dev {
	protected:
		ML_Joueur * tab[6];
	public:
		ML_Chevalier();
		void use(ML_Joueur*, ML_Jeux*);

};

#endif

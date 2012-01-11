#ifndef ML_DEV_H
#define ML_DEV_H

#include "../ML_Carte.h"
#include "../../ML_Joueur.h"
#include "../../ML_Jeux.h"


class ML_Map;

class ML_Dev : public ML_Carte {
	public:
		virtual void use(ML_Joueur*, ML_Jeux*) = 0;
};

#include "../../Map/ML_Map.h"

#endif

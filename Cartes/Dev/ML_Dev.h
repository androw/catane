#ifndef ML_DEV_H
#define ML_DEV_H

#include "../ML_Carte.h"
#include "../../ML_Joueur.h"



class ML_Map;
class ML_Jeux;

class ML_Dev : public ML_Carte {
    protected:
    string name;
    
	public:
    virtual void use(ML_Joueur*, ML_Jeux*) = 0;
    string getName();
};

#include "../../ML_Jeux.h"
#include "../../Map/ML_Map.h"

#endif

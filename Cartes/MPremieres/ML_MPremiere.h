#ifndef ML_MPREMIERE_H
#define ML_MPREMIERE_H

#include <cstring>
#include <iostream>
#include "../ML_Carte.h"

using namespace std;

class ML_MPremiere : public ML_Carte {
	protected:
    	string name;
	public:
    	ML_MPremiere();
	ML_MPremiere(string name);
};
#endif

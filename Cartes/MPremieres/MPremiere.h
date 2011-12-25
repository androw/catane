#ifndef MPREMIERE_H
#define MPREMIERE_H

#include <cstring>
#include <iostream>
#include "../Carte.h"

using namespace std;

class MPremiere : public Carte {
	protected:
    string name;
	public:
    MPremiere();
	MPremiere(string name);
};
#endif

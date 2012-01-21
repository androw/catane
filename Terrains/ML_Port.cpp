//MANSOURATI ET LORIN

#include "ML_Port.h"

ML_Port::ML_Port(string s) {
	NAME = "Port" + s ;
	spec = ML_MPremiere(s);
	MAX = 9;
}

void ML_Port::setSpec(string s) {
	spec = s;
}

ML_MPremiere ML_Port::getSpec(){
	return spec;
}

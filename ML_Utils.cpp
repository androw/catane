//MANSOURATI ET LORIN

#include "ML_Utils.h"

int lancerDe() {
	return rand()%6+1;
}

bool seek(vector<ML_Arrete*>* v, ML_Arrete* a) {
	for (unsigned int i = 0; i<v->size(); i++) {
			if (v->at(i) == a) return true;
	}
	return false;
}

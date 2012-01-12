#include "ML_MPremiere.h"

ML_MPremiere::ML_MPremiere(string pname) {
	MAX = 19;
   	name = pname;
}

ML_MPremiere::ML_MPremiere() {
	MAX = 19;
   	name = "";
}

string ML_MPremiere::getName(){
	return name;
}

bool ML_MPremiere::operator==(ML_MPremiere& p){
	return (name == p.getName());
}

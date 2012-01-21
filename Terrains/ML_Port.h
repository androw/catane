//MANSOURATI ET LORIN

#ifndef ML_PORT_H
#define ML_PORT_H

#include "ML_Terrain.h"

class ML_Port : public ML_Terrain {
	protected:
		ML_MPremiere spec;
	public:
		ML_Port(string);
		void setSpec(string);
		ML_MPremiere getSpec();
	
};
#endif

#ifndef ML_PROGRES_H
#define ML_PROGRES_H

#include "ML_Dev.h"

class ML_Progres : public ML_Dev {
	protected:
	public:
		ML_Progres();
		void use(ML_Joueur*, ML_Map*);

};
#endif

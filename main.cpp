//MANSOURATI ET LORIN

#include "./Map/ML_Map.h"
#include "ML_Jeux.h"

#include <ctime>

int main () {
	srand(time(NULL));
	int j;
	do {
	cout<<"Combien de joueurs etes vous ? (1-4)"<<endl;
	cin>>j;
	} while (j<=1 && j>4);
	ML_Jeux letsplay(j);
	letsplay.init();
	return 0;
}

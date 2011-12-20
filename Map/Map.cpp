#include "Map.h"
using namespace std;

Map::Map() {
	int i,j;
	for (i = 0; i<6; i++) {
		nbt[i] = 0;
	}

	for (i = 0; i<7; i++) {
		for (j = 0; j<7; j++) {
			t[j][i] = NULL;
		}
	}
	for (i = 1; i < 6; i++) {
		t[3][i] = Map::random();
	}
	for (i = 1; i < 5; i++) {
		t[2][i] = Map::random();
		t[4][i] = Map::random();
	}
	for (i = 2; i < 5; i++) {
		t[1][i] = Map::random();
		t[5][i] = Map::random();
	}
	
	Map::addPorts();
	Map::addMers();
	Map::createArrete();
	Map::createNoeud();

	for (i = 0; i<12; i++) {
		nbtint[i] = 2;
	}
	nbtint[0] = 0;
	nbtint[1] = 1;
	nbtint[6] = 0;
	nbtint[11] = 1;
	for (i = 1; i < 6; i++) {
		if(t[3][i]->getName() != "Desert") {
		t[3][i]->setValeur(randomInt());
		}
	}
	for (i = 1; i < 5; i++) {
		if(t[2][i]->getName() != "Desert" ) {
		t[2][i]->setValeur(randomInt());
		}
		if(t[4][i]->getName() != "Desert") {
		t[4][i]->setValeur(randomInt());
		}
	}
	for (i = 2; i < 5; i++) {
		if(t[1][i]->getName() != "Desert") {
		t[1][i]->setValeur(randomInt());
		}
		if(t[5][i]->getName() != "Desert") {
		t[5][i]->setValeur(randomInt());
		}
	}
}

Terrain* Map::random() {
	Terrain * t;
	int random = rand()%6;
	if(random == 0) {
		t = new Colline();
		if(nbt[0] < t->getMax()) {
			nbt[0]++;
			return t;
		}
	}else if(random == 1) {
		t = new Desert();
		if(nbt[1] < t->getMax()) {
			nbt[1]++;
			return t;
		}
	}else if(random == 2) {
		t = new Foret();
		if(nbt[2] < t->getMax()) {
			nbt[2]++;
			return t;
		}
	}else if(random == 3) {
		t = new Montagne();
		if(nbt[3] < t->getMax()) {
			nbt[3]++;
			return t;
		}
	}else if(random == 4) {
		t = new Paturage();
		if(nbt[4] < t->getMax()) {
			nbt[4]++;
			return t;
		}
	}else if(random == 5) {
		t = new TCultivable();
		if(nbt[5] < t->getMax()) {
			nbt[5]++;
			return t;
		}
	}
	return Map::random();	
}

int Map::randomInt() {
	int random = rand()%13;
	if(random == 0) {
		if(nbtint[0] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl; //c'est juste pour tester si ça fonctionne bien pour chaques chiffres.
			nbtint[0]--;
			return random+1;
		}
	}else if(random == 1) {
		if(nbtint[1] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[1]--;
			return random+1;
		}
	}else if(random == 2) {
		if(nbtint[2] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[2]--;
			return random+1;
		}
	}else if(random == 3) {
		if(nbtint[3] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[3]--;
			return random+1;
		}
	}else if(random == 4) {
		if(nbtint[4] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[4]--;
			return random+1;
		}
	}else if(random == 5) {
		if(nbtint[5] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[5]--;
			return random+1;
		}
	}
	 else if(random == 6) {
		if(nbtint[6] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[6]--;
			return random+1;
		}
	}
	else if(random == 7) {
		if(nbtint[7] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[7]--;
			return random+1;
		}
	}
	else if(random == 11) {
		if(nbtint[11] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[11]--;
			return random+1;
		}
	}
	else if(random == 8) {
		if(nbtint[8] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[8]--;
			return random+1;
		}
	}
	else if(random == 9) {
		if(nbtint[9] != 0) {
				//cout<<random+1<<":"<<nbtint[random]<<endl;
			nbtint[9]--;
			return random+1;
		}
	}
	else if(random == 10) {
		if(nbtint[10] != 0) {
		//cout<<"11:"<<nbtint[10]<<endl;
			nbtint[10]--;
			return random+1;
		}
	}
	return randomInt();	
}

void Map::addPorts() {
	t[4][0] = new Port();
	t[2][0] = new Port();
	t[6][1] = new Port();
	t[0][1] = new Port();
	t[6][3] = new Port();
	t[0][3] = new Port();
	t[5][5] = new Port();
	t[1][5] = new Port();
	t[3][6] = new Port();
}

void Map::addMers() {
	t[3][0] = new Mer();
	t[1][1] = new Mer();
	t[0][2] = new Mer();
	t[0][4] = new Mer();
	t[2][5] = new Mer();
	t[4][5] = new Mer();
	t[6][4] = new Mer();
	t[6][2] = new Mer();
	t[5][1] = new Mer();
}

void Map::afficher() {



	cout<<"                          *         *         *         *           "<<endl;
	cout<<"                        *   *     *~~~*     *   *     *~~~*            "<<endl;
	cout<<"                      *       * *~~~~~~~* *       * *~~~~~~~*       "<<endl;
	cout<<"                     *         *~~~~~~~~~*         *~~~~~~~~~*         "<<endl;
	cout<<"                     *";       

		for(int j=1; j<5; j++) {
			if(t[0][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[0][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~*";
			}else if(t[0][j]->getName() == "Colline") {
				cout<<" Colline"<<t[0][j]->getValeur()<<"*";

			}else if(t[0][j]->getName() == "TCultivable") {
				cout<<" TCulti  *";

			} else if(t[0][j]->getName() == "Port") {
				cout<<" Port    *";

			}else if(t[0][j]->getName() == "Foret") {
				cout<<" Foret   *";

			}else if(t[0][j]->getName() == "Montagne") {
				cout<<"Montagne *";

			}else if(t[0][j]->getName() == "Paturage") {
				cout<<"Paturage *";

			}else if(t[0][j]->getName() == "Desert") {
				cout<<" Desert  *";

			}
		}
cout<<endl;
	cout<<"                     *         *~~~~~~~~~*         *~~~~~~~~~*         "<<endl; 
	cout<<"                    *~*       * *~~~~~~~* *       * *~~~~~~~* *       "<<endl;
	cout<<"                  *~~~~~*   *     *~~~*     *   *     *~~~*     *   "<<endl;
	cout<<"                *~~~~~~~~~*";

		for(int j=2; j<5; j++) {
			if(t[1][j]->getValeur() <10) {
			cout<<"    "<<t[1][j]->getValeur()<<"    *";
			}else {
			cout<<"    "<<t[1][j]->getValeur()<<"   *";
			}
		}
cout<<"         *";
cout<<endl;

	cout<<"                *";       

		for(int j=1; j<6; j++) {
			if(t[1][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[1][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~*";
			}else if(t[1][j]->getName() == "Colline") {
				cout<<" Colline *";

			}else if(t[1][j]->getName() == "TCultivable") {
				cout<<" TCulti  *";

			} else if(t[1][j]->getName() == "Port") {
				cout<<" Port    *";

			}else if(t[1][j]->getName() == "Foret") {
				cout<<" Foret   *";

			}else if(t[1][j]->getName() == "Montagne") {
				cout<<"Montagne *";

			}else if(t[1][j]->getName() == "Paturage") {
				cout<<"Paturage *";

			}else if(t[1][j]->getName() == "Desert") {
				cout<<" Desert  *";

			}
		}
cout<<endl;
	cout<<"                *~~~~~~~~~*         *         *         *         *"<<endl; 
	cout<<"               * *~~~~~~~* *       * *       * *       * *       *~*"<<endl;
	cout<<"             *     *~~~*     *   *     *   *     *   *     *   *~~~~~*"<<endl;
	cout<<"           *         *";
		

		for(int j=1; j<5; j++) {
			if(t[2][j]->getValeur() <10) {
			cout<<"    "<<t[2][j]->getValeur()<<"    *";
			}else {
			cout<<"    "<<t[2][j]->getValeur()<<"   *";
			}
		}
cout<<"~~~~~~~~~*";
cout<<endl;
	cout<<"           *";


      

		for(int j=0; j<6; j++) {
			if(t[2][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[2][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~*";
			}else if(t[2][j]->getName() == "Colline") {
				cout<<" Colline *";

			}else if(t[2][j]->getName() == "TCultivable") {
				cout<<" TCulti  *";

			} else if(t[2][j]->getName() == "Port") {
				cout<<" Port    *";

			}else if(t[2][j]->getName() == "Foret") {
				cout<<" Foret   *";

			}else if(t[2][j]->getName() == "Montagne") {
				cout<<"Montagne *";

			}else if(t[2][j]->getName() == "Paturage") {
				cout<<"Paturage *";

			}else if(t[2][j]->getName() == "Desert") {
				cout<<" Desert  *";

			}
		}
cout<<endl;
	cout<<"           *         *         *         *         *         *~~~~~~~~~*"<<endl;
	cout<<"         *~~~*     *   *     *   *     *   *     *   *     *   *~~~~~*   *"<<endl;
	cout<<"       *~~~~~~~* *       * *       * *       * *       * *       *~*       *"<<endl;
	cout<<"      *~~~~~~~~~*";

		for(int j=1; j<6; j++) {
			if(t[3][j]->getValeur() <10) {
			cout<<"    "<<t[3][j]->getValeur()<<"    *";
			}else {
			cout<<"    "<<t[3][j]->getValeur()<<"   *";
			}
		}
cout<<"         *";
cout<<endl; 
	cout<<"      *";


		for(int j=0; j<7; j++) {
			if(t[3][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[3][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~*";
			}else if(t[3][j]->getName() == "Colline") {
				cout<<" Colline *";

			}else if(t[3][j]->getName() == "TCultivable") {
				cout<<" TCulti  *";

			} else if(t[3][j]->getName() == "Port") {
				cout<<" Port    *";

			}else if(t[3][j]->getName() == "Foret") {
				cout<<" Foret   *";

			}else if(t[3][j]->getName() == "Montagne") {
				cout<<"Montagne *";

			}else if(t[3][j]->getName() == "Paturage") {
				cout<<"Paturage *";

			}else if(t[3][j]->getName() == "Desert") {
				cout<<" Desert  *";

			}
		}

cout<<endl;
	cout<<"      *~~~~~~~~~*         *         *         *         *         *         *"<<endl;
	cout<<"        *~~~~~*   *     *   *     *   *     *   *     *   *     *~~~*     *"<<endl;
	cout<<"          *~*       * *       * *       * *       * *       * *~~~~~~~* *"<<endl;
	cout<<"           *         *";

		for(int j=1; j<5; j++) {
			if(t[4][j]->getValeur() <10) {
			cout<<"    "<<t[4][j]->getValeur()<<"    *";
			}else {
			cout<<"    "<<t[4][j]->getValeur()<<"   *";
			}
		}
cout<<"~~~~~~~~~*";
cout<<endl;
	cout<<"           *"; 

		for(int j=0; j<6; j++) {
			if(t[4][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[4][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~*";
			}else if(t[4][j]->getName() == "Colline") {
				cout<<" Colline *";

			}else if(t[4][j]->getName() == "TCultivable") {
				cout<<" TCulti  *";

			} else if(t[4][j]->getName() == "Port") {
				cout<<" Port    *";

			}else if(t[4][j]->getName() == "Foret") {
				cout<<" Foret   *";

			}else if(t[4][j]->getName() == "Montagne") {
				cout<<"Montagne *";

			}else if(t[4][j]->getName() == "Paturage") {
				cout<<"Paturage *";

			}else if(t[4][j]->getName() == "Desert") {
				cout<<" Desert  *";

			}
		}
cout<<endl;
	cout<<"           *         *         *         *         *         *~~~~~~~~~*"<<endl;
	cout<<"             *     *~~~*     *   *     *   *     *   *     *   *~~~~~*"<<endl;
	cout<<"               * *~~~~~~~* *       * *       * *       * *       *~*"<<endl;
	cout<<"                *~~~~~~~~~*";

		for(int j=2; j<5; j++) {
			if(t[5][j]->getValeur() <10) {
			cout<<"    "<<t[5][j]->getValeur()<<"    *";
			}else {
			cout<<"    "<<t[5][j]->getValeur()<<"   *";
			}
		}
cout<<"         *";
cout<<endl; 
	cout<<"                *";

		for(int j=1; j<6; j++) {
			if(t[5][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[5][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~*";
			}else if(t[5][j]->getName() == "Colline") {
				cout<<" Colline *";

			}else if(t[5][j]->getName() == "TCultivable") {
				cout<<" TCulti  *";

			} else if(t[5][j]->getName() == "Port") {
				cout<<" Port    *";

			}else if(t[5][j]->getName() == "Foret") {
				cout<<" Foret   *";

			}else if(t[5][j]->getName() == "Montagne") {
				cout<<"Montagne *";

			}else if(t[5][j]->getName() == "Paturage") {
				cout<<"Paturage *";

			}else if(t[5][j]->getName() == "Desert") {
				cout<<" Desert  *";

			}
		}

	cout<<endl;
	cout<<"                *~~~~~~~~~*         *         *         *         *"<<endl;
	cout<<"                  *~~~~~*   *     *~~~*     *   *     *~~~*     *   "<<endl;
	cout<<"                    *~*       * *~~~~~~~* *       * *~~~~~~~* *       "<<endl;
	cout<<"                     *         *~~~~~~~~~*         *~~~~~~~~~*         "<<endl; 
	cout<<"                     *";


		for(int j=1; j<5; j++) {
			if(t[6][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[6][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~*";
			}else if(t[6][j]->getName() == "Colline") {
				cout<<" Colline *";

			}else if(t[6][j]->getName() == "TCultivable") {
				cout<<" TCulti  *";

			} else if(t[6][j]->getName() == "Port") {
				cout<<" Port    *";

			}else if(t[6][j]->getName() == "Foret") {
				cout<<" Foret   *";

			}else if(t[6][j]->getName() == "Montagne") {
				cout<<"Montagne *";

			}else if(t[6][j]->getName() == "Paturage") {
				cout<<"Paturage *";

			}else if(t[6][j]->getName() == "Desert") {
				cout<<" Desert  *";

			}
		}


cout<<endl;
	cout<<"                     *         *~~~~~~~~~*         *~~~~~~~~~*         "<<endl;
	cout<<"                      *       * *~~~~~~~* *       * *~~~~~~~*       "<<endl;
	cout<<"                        *   *     *~~~*     *   *     *~~~*          "<<endl;
	cout<<"                          *         *         *         *         "<<endl;












	
}

					
void Map::createArrete() {
	int i;
	int j;
	for (i = 0; i<7; i++) {
		for (j = 0; j<7; j++) {
			if (t[i][j] != NULL) {
				if (i%2 == 1) {
				if (i-1 >= 0 && j-1 >= 0 && t[i][j]->getArrete(3) == NULL) {
					if (t[i-1][j-1] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i-1][j-1]);
							t[i][j]->setArrete(3, a);
							t[i-1][j-1]->setArrete(5-3, a);
					}else {
						t[i][j]->setArrete(3, NULL);
					}
				}
				if (i-1 >= 0 && t[i][j]->getArrete(0) == NULL) {
					if (t[i-1][j] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i-1][j]);
							t[i][j]->setArrete(3, a);
							t[i-1][j]->setArrete(5-0, a);
					} else {
						t[i][j]->setArrete(0, NULL);
					}
				}
				if (i+1 < 7 && t[i][j]->getArrete(2) == NULL) {
					if (t[i+1][j] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i+1][j]);
							t[i][j]->setArrete(2, a);
							t[i+1][j]->setArrete(5-2, a);
					} else {
						t[i][j]->setArrete(2, NULL);
					}
				}
				if (i+1 < 7 && j-1 >= 0 && t[i][j]->getArrete(5) == NULL) {
					if (t[i+1][j-1] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i+1][j-1]);
							t[i][j]->setArrete(5, a);
							t[i+1][j-1]->setArrete(5-5, a);
					} else {
						t[i][j]->setArrete(5 , NULL);
					}
				}
				} else {
				if (i-1 >= 0 && t[i][j]->getArrete(3) == NULL) {
					if (t[i-1][j] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i-1][j]);
							t[i][j]->setArrete(3, a);
							t[i-1][j]->setArrete(5-3, a);
					}else {
						t[i][j]->setArrete(3, NULL);
					}
				}
				if (i-1 >= 0 && j+1 < 7 && t[i][j]->getArrete(0) == NULL) {
					if (t[i-1][j+1] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i-1][j+1]);
							t[i][j]->setArrete(3, a);
							t[i-1][j+1]->setArrete(5-0, a);
					} else {
						t[i][j]->setArrete(0, NULL);
					}
				}
				if (i+1 < 7 && j+1 < 7 && t[i][j]->getArrete(2) == NULL) {
					if (t[i+1][j+1] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i+1][j+1]);
							t[i][j]->setArrete(2, a);
							t[i+1][j+1]->setArrete(5-2, a);
					} else {
						t[i][j]->setArrete(2, NULL);
					}
				}
				if (i+1 < 7 && t[i][j]->getArrete(5) == NULL) {
					if (t[i+1][j] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i+1][j]);
							t[i][j]->setArrete(5, a);
							t[i+1][j]->setArrete(5-5, a);
					} else {
						t[i][j]->setArrete(5 , NULL);
					}
				}
				}
				if (j-1 >= 0 && t[i][j]->getArrete(4) == NULL) {
					if (t[i][j-1] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i][j-1]);
							t[i][j]->setArrete(4, a);
							t[i][j-1]->setArrete(5-4, a);
					} else {
						t[i][j]->setArrete(4, NULL);
					}
				}
				if (j+1 < 7 && t[i][j]->getArrete(1) == NULL) {
					if (t[i][j+1] != NULL) {
							Arrete * a = new Arrete();
							a->setTerrain(0, t[i][j]);
							a->setTerrain(1, t[i][j+1]);
							t[i][j]->setArrete(1, a);
							t[i][j+1]->setArrete(5-1, a);
					} else {
						t[i][j]->setArrete(1, NULL);
					}
				}
			}
		}
	}
}	

void Map::createNoeud() {
	int i;
	int j;
	for (i = 0; i<7; i++) {
		for (j = 0; j<7; j++) {
			if (t[i][j] != NULL) { //Coin 0
				if (i%2 == 0) {
				if( i-1 >= 0 && j+1 < 7 && t[i][j]->getNoeud(0) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(0, t[i][j]);
					a->addArrete(t[i][j]->getArrete(0));
					a->addArrete(t[i][j]->getArrete(3));
					t[i][j]->setNoeud(0,a);
					if (t[i-1][j+1] != NULL) {
						a->setTerrain(1, t[i-1][j+1]);
						a->addArrete(t[i-1][j+1]->getArrete(2));
						t[i-1][j+1]->setNoeud(2,a);
					}
					if (t[i][j+1] != NULL) {
						a->setTerrain(1, t[i][j+1]);
						a->addArrete(t[i][j+1]->getArrete(3));
						t[i][j+1]->setNoeud(4,a);
					}	
				}else {
					t[i][j]->setNoeud(0,NULL);
				}
				} else {
				if( i-1 >= 0 && j+1 < 7 && t[i][j]->getNoeud(0) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(0, t[i][j]);
					a->addArrete(t[i][j]->getArrete(0));
					a->addArrete(t[i][j]->getArrete(3));
					t[i][j]->setNoeud(0,a);
					if (t[i-1][j] != NULL) {
						a->setTerrain(1, t[i-1][j]);
						a->addArrete(t[i-1][j]->getArrete(2));
						t[i-1][j]->setNoeud(2,a);
					}
					if (t[i][j+1] != NULL) {
						a->setTerrain(1, t[i][j+1]);
						a->addArrete(t[i][j+1]->getArrete(3));
						t[i][j+1]->setNoeud(4,a);
					}	
				}else {
					t[i][j]->setNoeud(0,NULL);
				}
				}
			}else if (t[i][j] != NULL) { //Coin 1
				if (i%2 == 1) {
				if( i+1 < 7 && j+1 < 7 && t[i][j]->getNoeud(1) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(1));
					a->addArrete(t[i][j]->getArrete(2));
					t[i][j]->setNoeud(0,a);
					if (t[i+1][j] != NULL) {
						a->setTerrain(1, t[i+1][j]);
						a->addArrete(t[i+1][j]->getArrete(0));
						t[i+1][j]->setNoeud(2,a);
					}
					if (t[i][j+1] != NULL) {
						a->setTerrain(2, t[i][j+1]);
						a->addArrete(t[i][j+1]->getArrete(5));
						t[i][j+1]->setNoeud(4,a);
					}	
				}else {
					t[i][j]->setNoeud(1,NULL);
				} 
				} else {
				if( i+1 < 7 && j+1 < 7 && t[i][j]->getNoeud(1) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(1));
					a->addArrete(t[i][j]->getArrete(2));
					t[i][j]->setNoeud(0,a);
					if (t[i+1][j+1] != NULL) {
						a->setTerrain(1, t[i+1][j+1]);
						a->addArrete(t[i+1][j+1]->getArrete(0));
						t[i+1][j+1]->setNoeud(2,a);
					}
					if (t[i][j+1] != NULL) {
						a->setTerrain(2, t[i][j+1]);
						a->addArrete(t[i][j+1]->getArrete(5));
						t[i][j+1]->setNoeud(4,a);
					}	
				}else {
					t[i][j]->setNoeud(1,NULL);
				} 
				}
			}else if (t[i][j] != NULL) { //Coin 2
				if (i%2 == 1) {
				if( i+1 < 7 && j-1 >= 0 && t[i][j]->getNoeud(2) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(2));
					a->addArrete(t[i][j]->getArrete(5));
					t[i][j]->setNoeud(0,a);
					if (t[i+1][j-1] != NULL) {
						a->setTerrain(1, t[i+1][j-1]);
						a->addArrete(t[i+1][j-1]->getArrete(1));
						t[i+1][j-1]->setNoeud(0,a);
					}
					if (t[i+1][j] != NULL) {
						a->setTerrain(2, t[i+1][j]);
						a->addArrete(t[i+1][j]->getArrete(4));
						t[i+1][j]->setNoeud(4,a);
					}	
				}else {
					t[i][j]->setNoeud(2,NULL);
				} 
				} else {
				if( i+1 < 7 && j-1 >= 0 && t[i][j]->getNoeud(2) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(2));
					a->addArrete(t[i][j]->getArrete(5));
					t[i][j]->setNoeud(0,a);
					if (t[i+1][j] != NULL) {
						a->setTerrain(1, t[i+1][j]);
						a->addArrete(t[i+1][j]->getArrete(1));
						t[i+1][j]->setNoeud(0,a);
					}
					if (t[i+1][j+1] != NULL) {
						a->setTerrain(2, t[i+1][j+1]);
						a->addArrete(t[i+1][j+1]->getArrete(4));
						t[i+1][j+1]->setNoeud(4,a);
					}	
				}else {
					t[i][j]->setNoeud(2,NULL);
				} 
				}
			}else if (t[i][j] != NULL) { //Coin 3
				if (i%2 == 0) {
				if( i-1 >= 0 && j+1 < 7 && j-1 >= 0 && t[i][j]->getNoeud(3) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(0));
					a->addArrete(t[i][j]->getArrete(3));
					t[i][j]->setNoeud(0,a);
					if (t[i-1][j] != NULL) {
						a->setTerrain(1, t[i-1][j]);
						a->addArrete(t[i-1][j]->getArrete(1));
						t[i-1][j]->setNoeud(1,a);
					}
					if (t[i][j+1] != NULL) {
						a->setTerrain(2, t[i][j+1]);
						a->addArrete(t[i][j+1]->getArrete(4));
						t[i][j+1]->setNoeud(4,a);
					}	
				}else {
					t[i][j]->setNoeud(3,NULL);
				} 
				} else {
				if( i-1 >= 0 && j+1 < 7 && j-1 >= 0 && t[i][j]->getNoeud(3) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(0));
					a->addArrete(t[i][j]->getArrete(3));
					t[i][j]->setNoeud(0,a);
					if (t[i-1][j-1] != NULL) {
						a->setTerrain(1, t[i-1][j-1]);
						a->addArrete(t[i-1][j-1]->getArrete(1));
						t[i-1][j-1]->setNoeud(1,a);
					}
					if (t[i-1][j] != NULL) {
						a->setTerrain(2, t[i-1][j]);
						a->addArrete(t[i-1][j]->getArrete(4));
						t[i-1][j]->setNoeud(4,a);
					}	
				}else {
					t[i][j]->setNoeud(3,NULL);
				}
				}
			}else if (t[i][j] != NULL) { //Coin 4
				if (i%2 == 0) {
				if( i-1 >= 0 && j-1 >= 0  && t[i][j]->getNoeud(4) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(3));
					a->addArrete(t[i][j]->getArrete(4));
					t[i][j]->setNoeud(0,a);
					if (t[i-1][j] != NULL) {
						a->setTerrain(1, t[i-1][j]);
						a->addArrete(t[i-1][j]->getArrete(5));
						t[i-1][j]->setNoeud(2,a);
					}
					if (t[i][j-1] != NULL) {
						a->setTerrain(2, t[i][j-1]);
						a->addArrete(t[i][j-1]->getArrete(0));
						t[i][j-1]->setNoeud(0,a);
					}	
				}else {
					t[i][j]->setNoeud(4,NULL);
				} 
				} else {
				if( i-1 >= 0 && j-1 >= 0  && t[i][j]->getNoeud(4) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(3));
					a->addArrete(t[i][j]->getArrete(4));
					t[i][j]->setNoeud(0,a);
					if (t[i-1][j-1] != NULL) {
						a->setTerrain(1, t[i-1][j-1]);
						a->addArrete(t[i-1][j-1]->getArrete(5));
						t[i-1][j-1]->setNoeud(2,a);
					}
					if (t[i][j-1] != NULL) {
						a->setTerrain(2, t[i][j-1]);
						a->addArrete(t[i][j-1]->getArrete(0));
						t[i][j-1]->setNoeud(0,a);
					}	
				}else {
					t[i][j]->setNoeud(4,NULL);
				}
				}
			}else if (t[i][j] != NULL) { //Coin 5
				if (i%2 == 1) {
				if( i+1 < 7 && j-1 >= 0 && i-1 >= 0 && t[i][j]->getNoeud(5) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(5));
					a->addArrete(t[i][j]->getArrete(4));
					t[i][j]->setNoeud(0,a);
					if (t[i][j-1] != NULL) {
						a->setTerrain(1, t[i][j-1]);
						a->addArrete(t[i][j-1]->getArrete(2));
						t[i][j-1]->setNoeud(1,a);
					}
					if (t[i+1][j-1] != NULL) {
						a->setTerrain(2, t[i+1][j-1]);
						a->addArrete(t[i+1][j-1]->getArrete(3));
						t[i+1][j-1]->setNoeud(3,a);
					}	
				}else {
					t[i][j]->setNoeud(5,NULL);
				} 
				} else {
				if( i+1 < 7 && j-1 >= 0 && i-1 >= 0 && t[i][j]->getNoeud(5) == NULL) {
					Noeud * a = new Noeud();
					a->setTerrain(1, t[i][j]);
					a->addArrete(t[i][j]->getArrete(5));
					a->addArrete(t[i][j]->getArrete(4));
					t[i][j]->setNoeud(0,a);
					if (t[i][j-1] != NULL) {
						a->setTerrain(1, t[i][j-1]);
						a->addArrete(t[i][j-1]->getArrete(2));
						t[i][j-1]->setNoeud(1,a);
					}
					if (t[i+1][j] != NULL) {
						a->setTerrain(2, t[i+1][j]);
						a->addArrete(t[i+1][j]->getArrete(3));
						t[i+1][j]->setNoeud(3,a);
					}	
				}else {
					t[i][j]->setNoeud(5,NULL);
				}
				}
			}
		}
	}
}	

Terrain* Map::getTerrain(int pi, int pj) {
	if(t[pi][pj] == NULL) {
		return NULL;
	}
	return t[pi][pj];
}
		
Arrete* Map::getArrete(int i, int j, int x, int y) {
	int it;
	for (it = 0; i< 6; it++) {
		if (t[i][j]->getArrete(it)->getTerrain(0) == t[i][j]) {
			if (t[i][j]->getArrete(it)->getTerrain(1) == t[x][y]) return t[i][j]->getArrete(it);
		} else if (t[i][j]->getArrete(it)->getTerrain(1) == t[i][j]){
			if (t[i][j]->getArrete(it)->getTerrain(0) == t[x][y]) return t[i][j]->getArrete(it);
		}
	}
	return NULL;
} 

Noeud* Map::getNoeud(int i, int j, int x, int y,int xx, int yy) {
	int it;
	for (it = 0; i< 6; it++) {
		if (t[i][j]->getNoeud(it)->getTerrain(0) == t[i][j]) {
			if (t[i][j]->getNoeud(it)->getTerrain(1) == t[x][y]) {
				if (t[i][j]->getNoeud(it)->getTerrain(2) == t[xx][yy]) {
					return t[i][j]->getNoeud(it);
				}
			}
		} else if (t[i][j]->getNoeud(it)->getTerrain(0) == t[i][j]) {
			if (t[i][j]->getNoeud(it)->getTerrain(2) == t[x][y]) {
				if (t[i][j]->getNoeud(it)->getTerrain(1) == t[xx][yy]) {
					return t[i][j]->getNoeud(it);
				}
			}
		}else if (t[i][j]->getNoeud(it)->getTerrain(0) == t[x][y]) {
				if (t[i][j]->getNoeud(it)->getTerrain(1) == t[xx][yy]){
					return t[i][j]->getNoeud(it);
				}
			}
		else if (t[i][j]->getNoeud(it)->getTerrain(0) == t[xx][yy]) {
				if (t[i][j]->getNoeud(it)->getTerrain(1) == t[x][y]){
					return t[i][j]->getNoeud(it);
				}
			}
		else if (t[i][j]->getNoeud(it)->getTerrain(0) == t[x][y]) {
				if (t[i][j]->getNoeud(it)->getTerrain(2) == t[xx][yy]){
					return t[i][j]->getNoeud(it);
				}
			}
		else if (t[i][j]->getNoeud(it)->getTerrain(0) == t[xx][yy]) {
				if (t[i][j]->getNoeud(it)->getTerrain(2) == t[x][y]){
					return t[i][j]->getNoeud(it);
				}
		}
		
	}
	return NULL;
} 




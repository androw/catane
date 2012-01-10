#include "ML_Map.h"
using namespace std;

ML_Map::ML_Map() {
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
		t[3][i] = ML_Map::random();
	}
	for (i = 1; i < 5; i++) {
		t[2][i] = ML_Map::random();
		t[4][i] = ML_Map::random();
	}
	for (i = 2; i < 5; i++) {
		t[1][i] = ML_Map::random();
		t[5][i] = ML_Map::random();
	}
	
	ML_Map::addPorts();
	ML_Map::addMers();
	ML_Map::createArrete();
	ML_Map::createNoeud();
	createnbint();
	valeur();
	
	
	
}

void ML_Map::createnbint() {
	nbint[0] = 5;
	nbint[1] = 2;
	nbint[2] = 6;
	nbint[3] = 3;
	nbint[4] = 8;
	nbint[5] = 10;
	nbint[6] = 9;
	nbint[7] = 12;
	nbint[8] = 11;
	nbint[9] = 4;
	nbint[10] = 8;
	nbint[11] = 10;
	nbint[12] = 9;
	nbint[13] = 4;
	nbint[14] = 5;
	nbint[15] = 6;
	nbint[16] = 3;
	nbint[17] = 11;
}

ML_Terrain* ML_Map::random() {
	ML_Terrain * t;
	int random = rand()%6;
	if(random == 0) {
		t = new ML_Colline();
		if(nbt[0] < t->getMax()) {
			nbt[0]++;
			return t;
		}
	}else if(random == 1) {
		t = new ML_Desert();
		if(nbt[1] < t->getMax()) {
			nbt[1]++;
			return t;
		}
	}else if(random == 2) {
		t = new ML_Foret();
		if(nbt[2] < t->getMax()) {
			nbt[2]++;
			return t;
		}
	}else if(random == 3) {
		t = new ML_Montagne();
		if(nbt[3] < t->getMax()) {
			nbt[3]++;
			return t;
		}
	}else if(random == 4) {
		t = new ML_Paturage();
		if(nbt[4] < t->getMax()) {
			nbt[4]++;
			return t;
		}
	}else if(random == 5) {
		t = new ML_TCultivable();
		if(nbt[5] < t->getMax()) {
			nbt[5]++;
			return t;
		}
	}
	return ML_Map::random();	
}


void ML_Map::valeur() {
	int random = rand()%6;
	int i = 0;
	int x;
	int y;
	if(random == 0) {
		if( t[1][2]->getName() != "Desert" ) {
			t[1][2]->setValeur(nbint[i]);
			i++;
		}
		
		x = 1;
		y = 2;
	}else if (random == 1) {
		if( t[1][4]->getName() != "Desert" ) {
			t[1][4]->setValeur(nbint[i]);
			i++;
		}
		x = 1;
		y = 4;
	}else if (random == 2) {
		if( t[3][1]->getName() != "Desert" ) {
			t[3][1]->setValeur(nbint[i]);
			i++;
		}
		x = 3;
		y = 1;
	}else if (random == 3) {
		if( t[3][5]->getName() != "Desert" ) {
			t[3][5]->setValeur(nbint[i]);
			i++;
		}
		x = 3;
		y = 5;
	}else if (random == 4) {
		if( t[5][2]->getName() != "Desert" ) {
			t[5][2]->setValeur(nbint[i]);
			i++;
		}
		x = 5;
		y = 2;
	}else if (random == 5) {
		if( t[5][4]->getName() != "Desert" ) {
			t[5][4]->setValeur(nbint[i]);
			i++;
		}
		x = 5;
		y = 4;
	}
	int xinit = x;
	int yinit = y;
	
	while(x != 3 || y != 3) {


		if( t[x][y-1]!= NULL && t[x][y-1]->getName() != "Port" && t[x][y-1]->getName() != "Mer" && t[x][y-1]->getValeur() == 0 && ((x == 1 && y == 4) || (x == 1 && y == 3 && (xinit !=1 || yinit != 2))  || (x == 2 && y == 3 && (xinit !=1 || yinit != 2)) || (x == 2 && y == 4 && xinit ==1 && yinit == 4) || (x == 3 && y == 4 && xinit ==1 && yinit == 4 ) )) {
			y--;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"gauche"<<endl;
			}
			
		}else if( t[x+1][y-1]!= NULL && x%2 == 1 && t[x+1][y-1]->getName() != "Port" && t[x+1][y-1]->getName() != "Mer" && t[x+1][y-1]->getValeur() == 0 && ((x == 1 && y == 2) || (x == 2 && y == 1 && (xinit !=3 || yinit != 1))  || (x == 2 && y == 2 && (xinit !=3 || yinit != 1)) || (x == 1 && y == 3 && xinit ==1 && yinit == 2) || (x == 2 && y == 3 && xinit ==1 && yinit == 2 ) )) {
			x++;
			y--;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"gauche bas"<<endl;
			}
			
		}else if( t[x+1][y]!= NULL && x%2 == 0 && t[x+1][y]->getName() != "Port" && t[x+1][y]->getName() != "Mer" && t[x+1][y]->getValeur() == 0 && ((x == 1 && y == 2) || (x == 2 && y == 1 && (xinit !=3 || yinit != 1))  || (x == 2 && y == 2 && (xinit !=3 || yinit != 1)) || (x == 1 && y == 3 && xinit ==1 && yinit == 2) || (x == 2 && y == 3 && xinit ==1 && yinit == 2 ) ) ) {
			x++;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//<<"gauche bas"<<endl;
			}
			
		}else if( t[x+1][y+1]!= NULL && x%2 == 0 && t[x+1][y+1]->getName() != "Port" && t[x+1][y+1]->getName() != "Mer" && t[x+1][y+1]->getValeur() == 0 && ((x == 3 && y == 1) || (x == 4 && y == 1 && (xinit !=5 || yinit != 2))  || (x == 3 && y == 2 && (xinit !=5 || yinit != 2)) || (x == 2 && y == 1 && xinit ==3 && yinit == 1) || (x == 2 && y == 2 && xinit ==3 && yinit == 1 ) )) {
			x++;
			y++;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"droit bas"<<endl;
			}
			
		}else if( t[x+1][y]!= NULL && x%2 == 1 && t[x+1][y]->getName() != "Port" && t[x+1][y]->getName() != "Mer" && t[x+1][y]->getValeur() == 0 && ((x == 3 && y == 1) || (x == 4 && y == 1 && (xinit !=5 || yinit != 2))  || (x == 3 && y == 2 && (xinit !=5 || yinit != 2)) || (x == 2 && y == 1 && xinit ==3 && yinit == 1) || (x == 2 && y == 2 && xinit ==3 && yinit == 1 ) )) {
			x++;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"droit bas"<<endl;
			}
			
		}else if( t[x][y+1]->getName() != "Port" && t[x][y+1]->getName() != "Mer" && t[x][y+1]->getValeur() == 0 && ((x == 5 && y == 2) || (x == 5 && y == 3 && (xinit !=5 || yinit != 4))  || (x == 4 && y == 2 && (xinit !=5 || yinit != 4)) || (x == 4 && y == 1 && xinit ==5 && yinit == 2) || (x == 3 && y == 2 && xinit ==5 && yinit == 2 ) )) {
			y++;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"droit"<<endl;
			}
			
		}else if( t[x-1][y+1]!= NULL && x%2 == 0 && t[x-1][y+1]->getName() != "Port" && t[x-1][y+1]->getName() != "Mer" && t[x-1][y+1]->getValeur() == 0 && ((x == 5 && y == 4) || (x == 4 && y == 4 && (xinit !=3 || yinit != 5))  || (x == 4 && y == 3 && (xinit !=3 || yinit != 5)) || (x == 5 && y == 3 && xinit ==5 && yinit == 4) || (x == 4 && y == 2 && xinit ==5 && yinit == 4 ) )) {
			x--;
			y++;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"droit haut"<<endl;
			}
			
		}else if( t[x-1][y]!= NULL && x%2 == 1 && t[x-1][y]->getName() != "Port" && t[x-1][y]->getName() != "Mer" && t[x-1][y]->getValeur() == 0 && ((x == 5 && y == 4) || (x == 4 && y == 4 && (xinit !=3 || yinit != 5))  || (x == 4 && y == 3 && (xinit !=3 || yinit != 5)) || (x == 5 && y == 3 && xinit ==5 && yinit == 4) || (x == 4 && y == 2 && xinit ==5 && yinit == 4 ) )) {
			x--;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"droit haut"<<endl;
			}
			
		}else if( t[x-1][y-1]!= NULL && x%2 == 1 && t[x-1][y-1]->getName() != "Port" && t[x-1][y-1]->getName() != "Mer" && t[x-1][y-1]->getValeur() == 0  && ((x == 3 && y == 5) || (x == 2 && y == 4 && (xinit !=1 || yinit != 4))  || (x == 3 && y == 4 && (xinit !=1 || yinit != 4)) || (x == 4 && y == 4 && xinit ==3 && yinit == 5) || (x == 4 && y == 3 && xinit ==3 && yinit == 5 ) ) ) {
			x--;
			y--;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"gauche haut"<<endl;
			}
			
		}else if( t[x-1][y]!= NULL && x%2 == 0 && t[x-1][y]->getName() != "Port" && t[x-1][y]->getName() != "Mer" && t[x-1][y]->getValeur() == 0 && ((x == 3 && y == 5) || (x == 2 && y == 4 && (xinit !=1 || yinit != 4))  || (x == 3 && y == 4 && (xinit !=1 || yinit != 4)) || (x == 4 && y == 4 && xinit ==3 && yinit == 5) || (x == 4 && y == 3 && xinit ==3 && yinit == 5 ) ) ) {
			x--;
			if( t[x][y]->getName() != "Desert" ) {
				t[x][y]->setValeur(nbint[i]);
				i++;
				//cout<<"gauche haut"<<endl;
			}
			
		}

	}
		
		
}

void ML_Map::addPorts() {
	t[4][0] = new ML_Port("Laine");
	t[2][0] = new ML_Port("?");
	t[6][1] = new ML_Port("Ble");
	t[0][1] = new ML_Port("?");
	t[6][3] = new ML_Port("Minerai");
	t[0][3] = new ML_Port("Bois");
	t[5][5] = new ML_Port("?");
	t[1][5] = new ML_Port("?");
	t[3][6] = new ML_Port("Argile");
}

void ML_Map::addMers() {
	t[3][0] = new ML_Mer();
	t[1][1] = new ML_Mer();
	t[0][2] = new ML_Mer();
	t[0][4] = new ML_Mer();
	t[2][5] = new ML_Mer();
	t[4][5] = new ML_Mer();
	t[6][4] = new ML_Mer();
	t[6][2] = new ML_Mer();
	t[5][1] = new ML_Mer();
}

void ML_Map::afficher() {



	cout<<"                          *         *         *         *           "<<endl;
	cout<<"                        *   *     *~~~*     *   *     *~~~*            "<<endl;
	//cout<<"                      *       * *~~~~~~~* *       * *~~~~~~~*       "<<endl;
	cout<<"                     *  (0,1)  *~~(0,2)~~*  (0,3)  *~~(0,4)~~*         "<<endl;
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

			} else if(t[0][j]->getName() == "PortBle") {
				cout<<" PortBle *";

			} else if(t[0][j]->getName() == "Port?") {
				cout<<" Port(?) *";

			} else if(t[0][j]->getName() == "PortMinerai") {
				cout<<" PortMin *";

			} else if(t[0][j]->getName() == "PortBois") {
				cout<<" PortBois*";

			} else if(t[0][j]->getName() == "PortLaine") {
				cout<<" PortLai *";

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
	cout<<"                     *         "<<getNoeud(0,2,0,1,1,2)->getJoueur()->getNb()<<"~~~~~~~~~"<<getNoeud(0,2,0,3,1,3)->getJoueur()->getNb()<<"         "<<getNoeud(0,3,0,4,1,4)->getJoueur()->getNb()<<"~~~~~~~~~*         "<<endl; 

		cout<<"                   *~~~*     "<<getArrete(1,2,0,1)->getJoueur()->getNb()<<"   "<<getArrete(1,2,0,2)->getJoueur()->getNb()<<"~~~~~"<<getArrete(1,3,0,2)->getJoueur()->getNb()<<"   "<<getArrete(1,3,0,3)->getJoueur()->getNb()<<" <== "<<getArrete(1,4,0,3)->getJoueur()->getNb()<<"   "<<getArrete(1,4,0,4)->getJoueur()->getNb()<<"~~~~~*   *       "<<endl;


	//cout<<"                  *~~~~~*   *     *~~~*     *   *     *~~~*     *   "<<endl;
	cout<<"                *~~~~~~~~~"<<getNoeud(1,2,1,1,0,1)->getJoueur()->getNb();

		for(int j=2; j<5; j++) {
			if(t[1][j]->getValeur() <10  && t[1][j]->getBrigand() == false) {
			cout<<"    "<<t[1][j]->getValeur()<<"    "<<getNoeud(1,j,1,j+1,0,j)->getJoueur()->getNb();
			}else if(t[1][j]->getValeur() >=10  && t[1][j]->getBrigand() == false){
			cout<<"    "<<t[1][j]->getValeur()<<"   "<<getNoeud(1,j,1,j+1,0,j)->getJoueur()->getNb();
			}else if(t[1][j]->getValeur() >= 10  && t[1][j]->getBrigand() == true){
			cout<<"    "<<t[1][j]->getValeur()<<"[B]"<<getNoeud(1,j,1,j+1,0,j)->getJoueur()->getNb();
			}else{
			cout<<"    "<<t[1][j]->getValeur()<<"[B] "<<getNoeud(1,j,1,j+1,0,j)->getJoueur()->getNb();
			}
		}
cout<<"         *";
cout<<endl;
cout<<"                *";       

		for(int j=1; j<6; j++) {
			if(t[1][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[1][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~"<<getArrete(1,j,1,j+1)->getJoueur()->getNb();
			}else if(t[1][j]->getName() == "Colline") {
				cout<<" Colline "<<getArrete(1,j,1,j+1)->getJoueur()->getNb();

			}else if(t[1][j]->getName() == "TCultivable") {
				cout<<" TCulti  "<<getArrete(1,j,1,j+1)->getJoueur()->getNb();

			} else if(t[1][j]->getName() == "PortArgile") {
				cout<<" PortArg *";

			}else if(t[1][j]->getName() == "PortBle") {
				cout<<" PortBle *";

			} else if(t[1][j]->getName() == "Port?") {
				cout<<"<=Port(?)*";

			} else if(t[1][j]->getName() == "PortMinerai") {
				cout<<" PortMin *";

			} else if(t[1][j]->getName() == "PortBois") {
				cout<<" PortBois*";

			} else if(t[1][j]->getName() == "PortLaine") {
				cout<<" PortLai *";

			}else if(t[1][j]->getName() == "Foret") {
				cout<<" Foret   "<<getArrete(1,j,1,j+1)->getJoueur()->getNb();

			}else if(t[1][j]->getName() == "Montagne") {
				cout<<"Montagne "<<getArrete(1,j,1,j+1)->getJoueur()->getNb();

			}else if(t[1][j]->getName() == "Paturage") {
				cout<<"Paturage "<<getArrete(1,j,1,j+1)->getJoueur()->getNb();

			}else if(t[1][j]->getName() == "Desert") {
				cout<<" Desert  "<<getArrete(1,j,1,j+1)->getJoueur()->getNb();

			}
		}
cout<<endl;

	cout<<"                *~~~~~~~~~"<<getNoeud(1,1,1,1+1,2,1)->getJoueur()->getNb();

		for(int j=2; j<5; j++) {
			if(t[1][j]->getValeur() <10) {
			cout<<"  "<<"(1,"<<j<<")"<<"  "<<getNoeud(1,j,1,j+1,2,j)->getJoueur()->getNb();
			}else {
			cout<<"  "<<"(1,"<<j<<")"<<"  "<<getNoeud(1,j,1,j+1,2,j)->getJoueur()->getNb();
			}
		}
cout<<"         *"<<endl;
 
	//cout<<"               * *~~~~~~~* *       * *       * *       * *       *~*"<<endl;

	cout<<"             *     *~~~"<<getArrete(2,1,1,1)->getJoueur()->getNb();

			for(int j=2; j<5; j++) {

				cout<<"     "<<getArrete(2,j-1,1,j)->getJoueur()->getNb()<<"   "<<getArrete(2,j,1,j)->getJoueur()->getNb();

			}
	
	cout<<"     "<<getArrete(2,4,3,5)->getJoueur()->getNb()<<"   *~~~~~*"<<endl;

	cout<<"           *         "<<getNoeud(2,0,2,1,1,1)->getJoueur()->getNb();
		



		for(int j=1; j<5; j++) {
			if(t[2][j]->getValeur() <10  && t[2][j]->getBrigand() == false) {
			cout<<"    "<<t[2][j]->getValeur()<<"    "<<getNoeud(2,j,2,j+1,1,j+1)->getJoueur()->getNb();
			}else if(t[2][j]->getValeur() >= 10  && t[2][j]->getBrigand() == false){
			cout<<"    "<<t[2][j]->getValeur()<<"   "<<getNoeud(2,j,2,j+1,1,j+1)->getJoueur()->getNb();
			}else if(t[2][j]->getValeur() >= 10  && t[2][j]->getBrigand() == true){
			cout<<"    "<<t[2][j]->getValeur()<<"[B]"<<getNoeud(2,j,2,j+1,1,j+1)->getJoueur()->getNb();
			}else{
			cout<<"    "<<t[2][j]->getValeur()<<"[B] "<<getNoeud(2,j,2,j+1,1,j+1)->getJoueur()->getNb();
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
				cout<<" Colline "<<getArrete(2,j,2,j+1)->getJoueur()->getNb();

			}else if(t[2][j]->getName() == "TCultivable") {
				cout<<" TCulti  "<<getArrete(2,j,2,j+1)->getJoueur()->getNb();

			} else if(t[2][j]->getName() == "PortArgile") {
				cout<<" PortArg *";

			}else if(t[2][j]->getName() == "PortBle") {
				cout<<" PortBle *";

			} else if(t[2][j]->getName() == "Port?") {
				cout<<" Port(?) "<<getArrete(2,j,2,j+1)->getJoueur()->getNb();

			} else if(t[2][j]->getName() == "PortMinerai") {
				cout<<" PortMin *";

			} else if(t[2][j]->getName() == "PortBois") {
				cout<<" PortBois*";

			} else if(t[2][j]->getName() == "PortLaine") {
				cout<<" PortLai *";

			}else if(t[2][j]->getName() == "Foret") {
				cout<<" Foret   "<<getArrete(2,j,2,j+1)->getJoueur()->getNb();

			}else if(t[2][j]->getName() == "Montagne") {
				cout<<"Montagne "<<getArrete(2,j,2,j+1)->getJoueur()->getNb();

			}else if(t[2][j]->getName() == "Paturage") {
				cout<<"Paturage "<<getArrete(2,j,2,j+1)->getJoueur()->getNb();

			}else if(t[2][j]->getName() == "Desert") {
				cout<<" Desert  "<<getArrete(2,j,2,j+1)->getJoueur()->getNb();

			}
		}
cout<<endl;

	cout<<"           *     \\\\  "<<getNoeud(2,0,2,0+1,3,0+1)->getJoueur()->getNb();
			for(int j=1; j<5; j++) {
				if(t[2][j]->getValeur() <10) {
				cout<<"  "<<"(2,"<<j<<")"<<"  "<<getNoeud(2,j,2,j+1,3,j+1)->getJoueur()->getNb();
				}else {
				cout<<"  "<<"(2,"<<j<<")"<<"  "<<getNoeud(2,j,2,j+1,3,j+1)->getJoueur()->getNb();
				}
			}	

	cout<<"~~~~~~~~~*"<<endl;

	
	cout<<"         *~~~*";

			for(int j=1; j<6; j++) {

				cout<<"     "<<getArrete(3,j,2,j-1)->getJoueur()->getNb()<<"   "<<getArrete(3,j,2,j)->getJoueur()->getNb();

			}
	cout<<"~~~~~*   *"<<endl;

	//cout<<"       *~~~~~~~* *       * *       * *       * *       * *       *~*       *"<<endl;
	cout<<"      *~~~~~~~~~"<<getNoeud(3,0,3,0+1,2,0)->getJoueur()->getNb();



		for(int j=1; j<6; j++) {
			if(t[3][j]->getValeur() <10  && t[3][j]->getBrigand() == false) {
			cout<<"    "<<t[3][j]->getValeur()<<"    "<<getNoeud(3,j,3,j+1,2,j)->getJoueur()->getNb();
			}else if(t[3][j]->getValeur() >= 10  && t[3][j]->getBrigand() == false){
			cout<<"    "<<t[3][j]->getValeur()<<"   "<<getNoeud(3,j,3,j+1,2,j)->getJoueur()->getNb();
			}else if(t[3][j]->getValeur() >= 10  && t[3][j]->getBrigand() == true){
			cout<<"    "<<t[3][j]->getValeur()<<"[B]"<<getNoeud(3,j,3,j+1,2,j)->getJoueur()->getNb();
			}else{
			cout<<"    "<<t[3][j]->getValeur()<<"[B] "<<getNoeud(3,j,3,j+1,2,j)->getJoueur()->getNb();
			}
		}
cout<<"         *";
cout<<endl; 
	cout<<"      *";


		for(int j=0; j<7; j++) {
			if(t[3][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[3][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~"<<getArrete(3,j,3,j+1)->getJoueur()->getNb();
			}else if(t[3][j]->getName() == "Colline") {
				cout<<" Colline "<<getArrete(3,j,3,j+1)->getJoueur()->getNb();

			}else if(t[3][j]->getName() == "TCultivable") {
				cout<<" TCulti  "<<getArrete(3,j,3,j+1)->getJoueur()->getNb();

			} else if(t[3][j]->getName() == "PortArgile") {
				cout<<"<=PortArg*";

			}else if(t[3][j]->getName() == "PortBle") {
				cout<<" PortBle *";

			} else if(t[3][j]->getName() == "Port?") {
				cout<<" Port(?) *";

			} else if(t[3][j]->getName() == "PortMinerai") {
				cout<<" PortMin *";

			} else if(t[3][j]->getName() == "PortBois") {
				cout<<" PortBois*";

			} else if(t[3][j]->getName() == "PortLaine") {
				cout<<" PortLai *";

			}else if(t[3][j]->getName() == "Foret") {
				cout<<" Foret   "<<getArrete(3,j,3,j+1)->getJoueur()->getNb();

			}else if(t[3][j]->getName() == "Montagne") {
				cout<<"Montagne "<<getArrete(3,j,3,j+1)->getJoueur()->getNb();

			}else if(t[3][j]->getName() == "Paturage") {
				cout<<"Paturage "<<getArrete(3,j,3,j+1)->getJoueur()->getNb();

			}else if(t[3][j]->getName() == "Desert") {
				cout<<" Desert  "<<getArrete(3,j,3,j+1)->getJoueur()->getNb();

			}
		}

cout<<endl;
	cout<<"      *~~~~~~~~~"<<getNoeud(3,0,3,0+1,4,0)->getJoueur()->getNb();
			for(int j=1; j<6; j++) {
				if(t[3][j]->getValeur() <10) {
				cout<<"  "<<"(3,"<<j<<")"<<"  "<<getNoeud(3,j,3,j+1,4,j)->getJoueur()->getNb();
				}else {
				cout<<"  "<<"(3,"<<j<<")"<<"  "<<getNoeud(3,j,3,j+1,4,j)->getJoueur()->getNb();
				}
			}
	

	cout<<"         *"<<endl;


	//cout<<"        *~~~~~*   *     *   *     *   *     *   *     *   *     *~~~*     *"<<endl;

	cout<<"         *~~~*";

			for(int j=1; j<6; j++) {

				cout<<"     "<<getArrete(3,j,4,j-1)->getJoueur()->getNb()<<"   "<<getArrete(3,j,4,j)->getJoueur()->getNb();

			}
	cout<<"~~~~~*   *"<<endl;



	cout<<"           *         "<<getNoeud(4,0,4,0+1,3,0+1)->getJoueur()->getNb();



		for(int j=1; j<5; j++) {
			if(t[4][j]->getValeur() <10  && t[4][j]->getBrigand() == false) {
			cout<<"    "<<t[4][j]->getValeur()<<"    "<<getNoeud(4,j,4,j+1,3,j+1)->getJoueur()->getNb();
			}else if(t[4][j]->getValeur() >= 10  && t[4][j]->getBrigand() == false){
			cout<<"    "<<t[4][j]->getValeur()<<"   "<<getNoeud(4,j,4,j+1,3,j+1)->getJoueur()->getNb();
			}else if(t[4][j]->getValeur() >= 10  && t[4][j]->getBrigand() == true){
			cout<<"    "<<t[4][j]->getValeur()<<"[B]"<<getNoeud(4,j,4,j+1,3,j+1)->getJoueur()->getNb();
			}else{
			cout<<"    "<<t[4][j]->getValeur()<<"[B] "<<getNoeud(4,j,4,j+1,3,j+1)->getJoueur()->getNb();
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
				cout<<" Colline "<<getArrete(4,j,4,j+1)->getJoueur()->getNb();

			}else if(t[4][j]->getName() == "TCultivable") {
				cout<<" TCulti  "<<getArrete(4,j,4,j+1)->getJoueur()->getNb();

			} else if(t[4][j]->getName() == "PortBle") {
				cout<<" PortBle *";

			} else if(t[4][j]->getName() == "PortArgile") {
				cout<<" PortArg *";

			}else if(t[4][j]->getName() == "Port?") {
				cout<<" Port(?) *";

			} else if(t[4][j]->getName() == "PortMinerai") {
				cout<<" PortMin *";

			} else if(t[4][j]->getName() == "PortBois") {
				cout<<" PortBois*";

			} else if(t[4][j]->getName() == "PortLaine") {
				cout<<"PortLai=>"<<getArrete(4,j,4,j+1)->getJoueur()->getNb();

			}else if(t[4][j]->getName() == "Foret") {
				cout<<" Foret   "<<getArrete(4,j,4,j+1)->getJoueur()->getNb();

			}else if(t[4][j]->getName() == "Montagne") {
				cout<<"Montagne "<<getArrete(4,j,4,j+1)->getJoueur()->getNb();

			}else if(t[4][j]->getName() == "Paturage") {
				cout<<"Paturage "<<getArrete(4,j,4,j+1)->getJoueur()->getNb();

			}else if(t[4][j]->getName() == "Desert") {
				cout<<" Desert  "<<getArrete(4,j,4,j+1)->getJoueur()->getNb();

			}
		}
cout<<endl;




	cout<<"           *         "<<getNoeud(4,0,4,0+1,5,0+1)->getJoueur()->getNb();
			for(int j=1; j<5; j++) {
				if(t[4][j]->getValeur() <10) {
				cout<<"  "<<"(4,"<<j<<")"<<"  "<<getNoeud(4,j,4,j+1,5,j+1)->getJoueur()->getNb();
				}else {
				cout<<"  "<<"(4,"<<j<<")"<<"  "<<getNoeud(4,j,4,j+1,5,j+1)->getJoueur()->getNb();
				}
			}	

	cout<<"~~~~~~~~~*"<<endl;

	cout<<"             *     *~~~"<<getArrete(4,1,5,1)->getJoueur()->getNb();

			for(int j=2; j<5; j++) {

				cout<<"     "<<getArrete(4,j-1,5,j)->getJoueur()->getNb()<<"   "<<getArrete(4,j,5,j)->getJoueur()->getNb();

			}
	
	cout<<"     "<<getArrete(4,5-1,5,5)->getJoueur()->getNb()<<"   *~~~~~*"<<endl;

	//cout<<"               * *~~~~~~~* *       * *       * *       * *       *~*"<<endl;

	cout<<"                *~~~~~~~~~"<<getNoeud(5,1,5,1+1,4,1)->getJoueur()->getNb();



		for(int j=2; j<5; j++) {
			if(t[5][j]->getValeur() <10  && t[5][j]->getBrigand() == false) {
			cout<<"    "<<t[5][j]->getValeur()<<"    "<<getNoeud(5,j,5,j+1,4,j)->getJoueur()->getNb();
			}else if(t[5][j]->getValeur() >= 10  && t[5][j]->getBrigand() == false){
			cout<<"    "<<t[5][j]->getValeur()<<"   "<<getNoeud(5,j,5,j+1,4,j)->getJoueur()->getNb();
			}else if(t[5][j]->getValeur() >= 10  && t[5][j]->getBrigand() == true){
			cout<<"    "<<t[5][j]->getValeur()<<"[B]"<<getNoeud(5,j,5,j+1,4,j)->getJoueur()->getNb();
			}else{
			cout<<"    "<<t[5][j]->getValeur()<<"[B] "<<getNoeud(5,j,5,j+1,4,j)->getJoueur()->getNb();
			}
		}
cout<<"         *";
cout<<endl; 
	cout<<"                *";

		for(int j=1; j<6; j++) {
			if(t[5][j] == NULL) {
				cout<<" Vide    *";

			}else if(t[5][j]->getName() == "Mer") {
				cout<<"~~~~~~~~~"<<getArrete(5,j,5,j+1)->getJoueur()->getNb();
			}else if(t[5][j]->getName() == "Colline") {
				cout<<" Colline "<<getArrete(5,j,5,j+1)->getJoueur()->getNb();

			}else if(t[5][j]->getName() == "TCultivable") {
				cout<<" TCulti  "<<getArrete(5,j,5,j+1)->getJoueur()->getNb();

			} else if(t[5][j]->getName() == "PortBle") {
				cout<<" PortBle *";

			}else if(t[5][j]->getName() == "PortArgile") {
				cout<<" PortArg *";

			}else if(t[5][j]->getName() == "Port?") {
				cout<<"<=Port(?)*";

			} else if(t[5][j]->getName() == "PortMinerai") {
				cout<<" PortMin *";

			} else if(t[5][j]->getName() == "PortBois") {
				cout<<" PortBois*";

			} else if(t[5][j]->getName() == "PortLaine") {
				cout<<" PortLai *";

			}else if(t[5][j]->getName() == "Foret") {
				cout<<" Foret   "<<getArrete(5,j,5,j+1)->getJoueur()->getNb();

			}else if(t[5][j]->getName() == "Montagne") {
				cout<<"Montagne "<<getArrete(5,j,5,j+1)->getJoueur()->getNb();

			}else if(t[5][j]->getName() == "Paturage") {
				cout<<"Paturage "<<getArrete(5,j,5,j+1)->getJoueur()->getNb();

			}else if(t[5][j]->getName() == "Desert") {
				cout<<" Desert  "<<getArrete(5,j,5,j+1)->getJoueur()->getNb();

			}
		}

	cout<<endl;
	cout<<"                *~~~~~~~~~"<<getNoeud(5,1,5,1+1,6,1)->getJoueur()->getNb();

		for(int j=2; j<5; j++) {
			if(t[5][j]->getValeur() <10) {
			cout<<"  "<<"(5,"<<j<<")"<<"  "<<getNoeud(5,j,5,j+1,6,j)->getJoueur()->getNb();
			}else {
			cout<<"  "<<"(5,"<<j<<")"<<"  "<<getNoeud(5,j,5,j+1,6,j)->getJoueur()->getNb();
			}
		}
cout<<"         *";
cout<<endl; 

	//cout<<"                  *~~~~~*   *     *~~~*     *   *     *~~~*     *   "<<endl;
	cout<<"                   *~~~*     "<<getArrete(5,2,6,1)->getJoueur()->getNb()<<"   "<<getArrete(5,2,6,2)->getJoueur()->getNb()<<"~~~~~"<<getArrete(5,3,6,2)->getJoueur()->getNb()<<"   "<<getArrete(5,3,6,3)->getJoueur()->getNb()<<" ==> "<<getArrete(5,4,6,3)->getJoueur()->getNb()<<"   "<<getArrete(5,4,6,4)->getJoueur()->getNb()<<"~~~~~*   *       "<<endl;
	

	cout<<"                     *         "<<getNoeud(5,2,6,1,6,2)->getJoueur()->getNb()<<"~~~~~~~~~"<<getNoeud(5,3,6,2,6,3)->getJoueur()->getNb()<<"         "<<getNoeud(5,4,6,3,6,4)->getJoueur()->getNb()<<"~~~~~~~~~*         "<<endl; 
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

			} else if(t[6][j]->getName() == "PortBle") {
				cout<<" PortBle *";

			} else if(t[6][j]->getName() == "Port?") {
				cout<<" Port(?) *";

			} else if(t[6][j]->getName() == "PortMinerai") {
				cout<<" PortMin *";

			}else if(t[6][j]->getName() == "PortArgile") {
				cout<<" PortArg *";

			} else if(t[6][j]->getName() == "PortBois") {
				cout<<" PortBois*";

			} else if(t[6][j]->getName() == "PortLaine") {
				cout<<" PortLai *";

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
	cout<<"                     *  (6,1)  *~~(6,2)~~*  (6,3)  *~~(6,4)~~*         "<<endl;
	//cout<<"                      *       * *~~~~~~~* *       * *~~~~~~~*       "<<endl;
	cout<<"                        *   *     *~~~*     *   *     *~~~*          "<<endl;
	cout<<"                          *         *         *         *         "<<endl;


	
}

					
void ML_Map::createArrete() {
	int i;
	int j;
	for (i = 0; i<7; i++) {
		for (j = 0; j<7; j++) {
			if (t[i][j] != NULL) {
				if (i%2 == 1) {
				if (i-1 >= 0 && j-1 >= 0 && t[i][j]->getArrete(3) == NULL) {
					if (t[i-1][j-1] != NULL) {
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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
							ML_Arrete * a = new ML_Arrete();
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

void ML_Map::createNoeud() {
	int i;
	int j;
	for (i = 0; i<7; i++) {
		for (j = 0; j<7; j++) {
			if (t[i][j] != NULL) {
				if (i%2 == 0) {
					if(i-1 >= 0 && j+1 < 7 && t[i][j]->getNoeud(0) == NULL) {
						ML_Noeud * a = new ML_Noeud();
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
							a->setTerrain(2, t[i][j+1]);
							a->addArrete(t[i][j+1]->getArrete(3));
							t[i][j+1]->setNoeud(4,a);
						}	
					}
					if( i+1 < 7 && j+1 < 7 && t[i][j]->getNoeud(1) == NULL) {
						ML_Noeud * a = new ML_Noeud();
						a->setTerrain(0, t[i][j]);
						a->addArrete(t[i][j]->getArrete(1));
						a->addArrete(t[i][j]->getArrete(2));
						t[i][j]->setNoeud(1,a);
						if (t[i+1][j+1] != NULL) {
							a->setTerrain(1, t[i+1][j+1]);
							a->addArrete(t[i+1][j+1]->getArrete(0));
							t[i+1][j+1]->setNoeud(3,a);
						}
						if (t[i][j+1] != NULL) {
							a->setTerrain(2, t[i][j+1]);
							a->addArrete(t[i][j+1]->getArrete(5));
							t[i][j+1]->setNoeud(5,a);
						}	
					}
					if( i+1 < 7 && j+1 < 7 && t[i][j]->getNoeud(2) == NULL) {
						ML_Noeud * a = new ML_Noeud();
						a->setTerrain(0, t[i][j]);
						a->addArrete(t[i][j]->getArrete(2));
						a->addArrete(t[i][j]->getArrete(5));
						t[i][j]->setNoeud(2,a);
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
					}
					if( i-1 >= 0 && j+1 < 7 && j-1 >= 0 && t[i][j]->getNoeud(3) == NULL) {
						ML_Noeud * a = new ML_Noeud();
						a->setTerrain(0, t[i][j]);
						a->addArrete(t[i][j]->getArrete(0));
						a->addArrete(t[i][j]->getArrete(3));
						t[i][j]->setNoeud(3,a);
						if (t[i-1][j] != NULL) {
							a->setTerrain(1, t[i-1][j]);
							a->addArrete(t[i-1][j]->getArrete(1));
							t[i-1][j]->setNoeud(1,a);
						}
						if (t[i-1][j+1] != NULL) {
							a->setTerrain(2, t[i-1][j+1]);
							a->addArrete(t[i-1][j+1]->getArrete(4));
							t[i-1][j+1]->setNoeud(5,a);
						}	
					}
					if( i-1 >= 0 && j-1 >= 0  && t[i][j]->getNoeud(4) == NULL) {
						ML_Noeud * a = new ML_Noeud();
						a->setTerrain(0, t[i][j]);
						a->addArrete(t[i][j]->getArrete(3));
						a->addArrete(t[i][j]->getArrete(4));
						t[i][j]->setNoeud(4,a);
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
					}
				if( i+1 < 7 && j-1 >= 0 && t[i][j]->getNoeud(5) == NULL) {
					ML_Noeud * a = new ML_Noeud();
					a->setTerrain(0, t[i][j]);
					a->addArrete(t[i][j]->getArrete(5));
					a->addArrete(t[i][j]->getArrete(4));
					t[i][j]->setNoeud(5,a);
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
				}
				} else {
				if( i-1 >= 0 && j+1 < 7 && t[i][j]->getNoeud(0) == NULL) {
					ML_Noeud * a = new ML_Noeud();
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
						a->setTerrain(2, t[i][j+1]);
						a->addArrete(t[i][j+1]->getArrete(3));
						t[i][j+1]->setNoeud(4,a);
					}	
				}
				if( i+1 < 7 && j+1 < 7 && t[i][j]->getNoeud(1) == NULL) {
					ML_Noeud * a = new ML_Noeud();
					a->setTerrain(0, t[i][j]);
					a->addArrete(t[i][j]->getArrete(1));
					a->addArrete(t[i][j]->getArrete(2));
					t[i][j]->setNoeud(1,a);
					if (t[i+1][j] != NULL) {
						a->setTerrain(1, t[i+1][j]);
						a->addArrete(t[i+1][j]->getArrete(0));
						t[i+1][j]->setNoeud(3,a);
					}
					if (t[i][j+1] != NULL) {
						a->setTerrain(2, t[i][j+1]);
						a->addArrete(t[i][j+1]->getArrete(5));
						t[i][j+1]->setNoeud(5,a);
					}	
				}
				if( i+1 < 7 && j-1 >= 0 && t[i][j]->getNoeud(2) == NULL) {
					ML_Noeud * a = new ML_Noeud();
					a->setTerrain(0, t[i][j]);
					a->addArrete(t[i][j]->getArrete(2));
					a->addArrete(t[i][j]->getArrete(5));
					t[i][j]->setNoeud(2,a);
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
				} 
				if( i-1 >= 0 && j+1 < 7 && j-1 >= 0 && t[i][j]->getNoeud(3) == NULL) {
					ML_Noeud * a = new ML_Noeud();
					a->setTerrain(0, t[i][j]);
					a->addArrete(t[i][j]->getArrete(0));
					a->addArrete(t[i][j]->getArrete(3));
					t[i][j]->setNoeud(3,a);
					if (t[i-1][j-1] != NULL) {
						a->setTerrain(1, t[i-1][j-1]);
						a->addArrete(t[i-1][j-1]->getArrete(1));
						t[i-1][j-1]->setNoeud(1,a);
					}
					if (t[i-1][j] != NULL) {
						a->setTerrain(2, t[i-1][j]);
						a->addArrete(t[i-1][j]->getArrete(4));
						t[i-1][j]->setNoeud(5,a);
					}	
				}
				if( i-1 >= 0 && j-1 >= 0  && t[i][j]->getNoeud(4) == NULL) {
					ML_Noeud * a = new ML_Noeud();
					a->setTerrain(0, t[i][j]);
					a->addArrete(t[i][j]->getArrete(3));
					a->addArrete(t[i][j]->getArrete(4));
					t[i][j]->setNoeud(4,a);
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
				}
				if( i+1 < 7 && j-1 >= 0 && i-1 >= 0 && t[i][j]->getNoeud(5) == NULL) {
					ML_Noeud * a = new ML_Noeud();
					a->setTerrain(0, t[i][j]);
					a->addArrete(t[i][j]->getArrete(5));
					a->addArrete(t[i][j]->getArrete(4));
					t[i][j]->setNoeud(5,a);
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
				} 
				}
			}
		}
	}
}	


ML_Terrain* ML_Map::getTerrain(int pi, int pj) {
	if(t[pi][pj] == NULL) {
		return NULL;
	}
	return t[pi][pj];
}
		
ML_Arrete* ML_Map::getArrete(int i, int j, int x, int y) {
	int it;
	for (it = 0; it< 6; it++) {
		if (t[i][j]->getArrete(it) != NULL) {
		if (t[i][j]->getArrete(it)->getTerrain(0) == t[i][j]) {
			if (t[i][j]->getArrete(it)->getTerrain(1) == t[x][y]) return t[i][j]->getArrete(it);
		} else if (t[i][j]->getArrete(it)->getTerrain(1) == t[i][j]){
			if (t[i][j]->getArrete(it)->getTerrain(0) == t[x][y]) return t[i][j]->getArrete(it);
		}
		}
	}
	return NULL;
} 

ML_Noeud* ML_Map::getNoeud(int i, int j, int x, int y,int xx, int yy) {
	int it;
	for (it = 0; it< 6; it++) {
		if (t[i][j]->getNoeud(it) != NULL) {
		if (t[i][j]->getNoeud(it)->getTerrain(0) == t[i][j]) {
			if (t[i][j]->getNoeud(it)->getTerrain(1) == t[x][y]) {
				if (t[i][j]->getNoeud(it)->getTerrain(2) == t[xx][yy]) {
					return t[i][j]->getNoeud(it);
				}
			}else if (t[i][j]->getNoeud(it)->getTerrain(2) == t[x][y]) {
				if (t[i][j]->getNoeud(it)->getTerrain(1) == t[xx][yy]) {
					return t[i][j]->getNoeud(it);
				}
			}
		}else if (t[i][j]->getNoeud(it)->getTerrain(1) == t[i][j]) {
			if (t[i][j]->getNoeud(it)->getTerrain(0) == t[x][y]) {
                        if (t[i][j]->getNoeud(it)->getTerrain(2) == t[xx][yy]) {
                                        return t[i][j]->getNoeud(it);
                                }
                        }else if (t[i][j]->getNoeud(it)->getTerrain(2) == t[x][y]) {
                                if (t[i][j]->getNoeud(it)->getTerrain(0) == t[xx][yy]) {
                                        return t[i][j]->getNoeud(it);
                                }
                        }
		}else if (t[i][j]->getNoeud(it)->getTerrain(2) == t[i][j]) {
                        if (t[i][j]->getNoeud(it)->getTerrain(0) == t[x][y]) {
                                if (t[i][j]->getNoeud(it)->getTerrain(1) == t[xx][yy]) {
                                        return t[i][j]->getNoeud(it);
                                }
                        }else if (t[i][j]->getNoeud(it)->getTerrain(1) == t[x][y]) {
                                if (t[i][j]->getNoeud(it)->getTerrain(0) == t[xx][yy]) {
                                        return t[i][j]->getNoeud(it);
                                }
                        }
		}
		}
	}
	return NULL;
} 




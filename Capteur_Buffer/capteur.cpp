#include "capteur.h"
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Capteur::Capteur (){
	nb=0;
	val=0;
};

float Capteur::read(){

	ifstream fichier("capteur.txt", ios::app);

	if(fichier.bad()) cout << "too bad" << endl;
	else
	{
		string line;
		for(int i=0; i<=nb; i++)
			getline(fichier, line);

		val=stoi(line);
		nb++;
	}

	return val;
};


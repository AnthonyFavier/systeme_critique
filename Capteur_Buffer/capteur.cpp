#include "capteur.h"
#include <stdlib.h>

capteur::capteur (){
	nb=0;
	val=0;
};

float capteur::read(){
	val=random() % 100;
	return val;
};


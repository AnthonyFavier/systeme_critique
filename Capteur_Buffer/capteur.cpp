#include "capteur.h"
#include <stdlib.h>

Capteur::Capteur (){
	nb=0;
	val=0;
};

float Capteur::read(){
	val=random() % 100;
	return val;
};


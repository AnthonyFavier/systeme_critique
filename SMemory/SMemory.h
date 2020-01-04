#ifndef DEF_SMEMORY
#define DEF_SMEMORY

#include <fstream>
#include <string>
#include <iostream>
#include "../Capteur_Buffer/circular_buffer.h"

using namespace std;

class SMemory
{
public:
	// constructeur
	SMemory();
	// sauvegarde le buffer dans la mémoire stable
	int save(Circular_Buffer* buff);
	// recupère le buffer sauvegardé dans la mémoire
	Circular_Buffer* recover();
private:
	// nom du fichier mémoire stable
	string filename;
};

#endif

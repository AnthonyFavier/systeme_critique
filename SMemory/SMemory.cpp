#include "SMemory.h"

SMemory::SMemory(){}

int SMemory::save(Circular_Buffer* buff)
{
	ofstream fichier("saved_data");

	float* tab;

	if(fichier.bad()) return 1;
	else
	{
		tab=buff->get();
		for(int i=0; i<TAILLE_BUFF; i++)
			fichier << tab[i] << endl;
		fichier << endl;
	}

	fichier.close();

	return 0;
}

Circular_Buffer SMemory::recover()
{
	Circular_Buffer buff;
	return buff;
}

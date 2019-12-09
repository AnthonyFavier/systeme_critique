#include "SMemory.h"

SMemory::SMemory(){}

int SMemory::save(float buff[TAILLE_BUFF])
{
	ofstream fichier("saved_data");

	if(fichier.bad()) return 1;
	else
	{
		for(int i=0; i<TAILLE_BUFF; i++)
			fichier << buff[i] << endl;
		fichier << endl;
	}

	fichier.close();

	return 0;
}

float* SMemory::recover()
{
	float* val=NULL;

	return val;
}

#include "SMemory.h"

SMemory::SMemory()
{
	filename="saved_data";
}

int SMemory::save(Circular_Buffer* buff)
{
	ofstream fichier(filename);

	float* tab;

	if(fichier.bad()) return -1;
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

Circular_Buffer* SMemory::recover()
{
	ifstream fichier(filename);

	Circular_Buffer* buff=new Circular_Buffer();

	if(fichier)
	{
		string line;
		float f;
		for(int i=0; i<10; i++)
		{
			getline(fichier, line);
			f=atof(line.c_str());
			buff->put(f);
		}
	}
	else
		cout << "ERREUR:Impossible lire memoire stable!" << endl;

	return buff;
}

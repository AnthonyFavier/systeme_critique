#include "SMemory.h"

SMemory::SMemory()
{
	filename="stable_memory.mem";
}

int SMemory::save(Circular_Buffer* buff)
{
	ofstream fichier(filename);

	if(fichier.bad()) return -1;
	else
	{
		// on écrit les nombres qui compose le buffer
		// ainsi que le numéro de la case courante (free)
		float* tab=buff->get();
		int free=buff->getFree();

		for(int i=0; i<TAILLE_BUFF; i++)
			fichier << tab[i] << endl;
		fichier << free << endl;
	}

	fichier.close();

	return 0;
}

Circular_Buffer* SMemory::recover()
{
	ifstream fichier(filename);

	Circular_Buffer* buff=new Circular_Buffer();

	if(fichier.bad()) cout << "ERREUR:Impossible lire memoire stable!" << endl;
	else
	{
		string line;
		float f;
		int free;

		// on lit les valeurs et on les ajoute au buffer
		for(int i=0; i<10; i++)
		{
			getline(fichier, line);
			f=atof(line.c_str());
			buff->put(f);
		}
		// on récupère le numéro de la case courante
		// pour initialiser correctement le buffer
		getline(fichier, line);
		free=atoi(line.c_str());
		buff->setFree(free);
	}

	return buff;
}

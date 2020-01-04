#include "watchdog.h"

Watchdog::Watchdog()
{
	compteur_=0;
}

void Watchdog::set()
{
	// incremente en verifiant si depasse valeur max
	if(++compteur_>COMPT_MAX)
		compteur_=0;
}

int Watchdog::read()
{
	return compteur_;
}

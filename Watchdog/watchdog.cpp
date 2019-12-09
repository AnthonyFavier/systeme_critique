#include "watchdog.h"

Watchdog::Watchdog()
{
	m_compteur=0;
}

void Watchdog::set()
{
	if(++m_compteur>COMPT_MAX)
		m_compteur=0;
}

int Watchdog::read()
{
	return m_compteur;
}

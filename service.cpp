#include <iostream>
#include "service.h"

using namespace std;

Service::service(char spec_mode, Watchdog* spec_wd, Capteur* spec_cp, Smemory* spec_sm)
{
	mode_=spec_mode;
	WD_=spec_wd;
	CP_=spec_cp;
	ME_=spec_sm;
};

void Service::run(float* compt)
{
	//1.Ecriture i'm alive
	WD_->set();
	
	//2.Lecture Capteur
	valeur_capteur_=CP->read();

	//3.Calcul des valeur de sortie sur les n dernières valeurs
	res_=calcul(valeur_capteur, PcBUF);

	//4.Affichage
	cout<<res_<<endl;
	
	//5.Stockage infos capteur sur le disque (memoire stable)
	pCBUF_->put(valeur_capteur);
	
}

float Service::calcul(float val; Circular_Buffer* buf)
{
	float buffer[10]=buf->get();
	for (i=0;i<10; i++)
	{
		res_=res_+buffer[i]:
	}
	res_=res_+val;
	res_=res_/10;

	return res_;
}

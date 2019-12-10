#include <iostream>
#include "service.h"

using namespace std;

Service::Service(char spec_mode, Watchdog* spec_wd, Capteur* spec_cp, SMemory* spec_sm, Circular_Buffer* spec_buff)
{
	mode_=spec_mode;
	WD_=spec_wd;
	CP_=spec_cp;
	ME_=spec_sm;
	pCBUF_=spec_buff;
}

void Service::run()
{
	switch(mode_)
	{
		case 'P':
			runPrimary();
			break;
		case 'B':
			runBackup();
			break;
	}
}

float Service::calcul(Circular_Buffer* buf)
{
	//moyenne sur les valeurs du buffer
	float* buffer=buf->get();
	for (int i=0;i<10; i++)
	{
		res_=res_+buffer[i];
	}
	res_=res_/10;

	return res_;
}

void Service::runPrimary()
{
	//////////////////////////BEFORE////////////////////////

	//1.Ecriture i'm alive
	WD_->set();
	
	//////////////////////////PROCEED//////////////////////
	//2.Lecture Capteur
	valeur_capteur_=CP_->read();
	cout<<"valeur capteur: "<<valeur_capteur_<<endl;

	//Stocker dans buffer
	pCBUF_->put(valeur_capteur_);
	pCBUF_->print();

	//3.Calcul des valeur de sortie sur les n dernières valeurs
	res_=calcul(pCBUF_);

	//4.Affichage
	cout<<"moyenne arithmetique: "<<res_<<endl;
	
	////////////////////////////AFTER////////////////////////
	//5.Stockage infos capteur sur le disque (memoire stable)
	ME_->save(pCBUF_);
}

void Service::runBackup()
{

	//1.Lecture watchdog
	cout<<"lecture watchdog : "<<WD_->read()<<endl;

	//2.Si primary dead, alors
	
}

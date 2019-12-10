#include <iostream>
#include "service.h"

using namespace std;

Service::Service(char spec_mode, Watchdog* spec_wd, Capteur* spec_cp, SMemory* spec_sm, Circular_Buffer* spec_buff, mutex* spec_mutex)
{
	le_mutex_=spec_mutex;
	mode_=spec_mode;
	WD_=spec_wd;
	CP_=spec_cp;
	ME_=spec_sm;
	pCBUF_=spec_buff;
	
	timeout_=0;
	ancien_watchdog_=-1;
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
	le_mutex_->unlock();
	
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
	timeout_+=1;

	if (le_mutex_->try_lock()||(timeout_==2))
	{
		int valeur_watchdog=WD_->read();
		cout<<"lecture watchdog : "<<valeur_watchdog<<endl;

		//2.Si primary dead, alors
		if (valeur_watchdog==ancien_watchdog_)
		{
			cout << "Recouvrement" << endl;
			delete pCBUF_;
			pCBUF_=ME_->recover();
			mode_='P';
		}

		ancien_watchdog_=valeur_watchdog;
		timeout_=0;
	}
	
}

#include <iostream>
#include "service.h"

using namespace std;

Service::Service(char spec_mode, Watchdog* spec_wd, Capteur* spec_cp, SMemory* spec_sm, Circular_Buffer* spec_buff, mutex* spec_mutex, int id)
{
	le_mutex_=spec_mutex;
	mode_=spec_mode;
	WD_=spec_wd;
	CP_=spec_cp;
	ME_=spec_sm;
	pCBUF_=spec_buff;
	
	timeout_=0;
	ancien_watchdog_=-1;
	id_=id;
	filename_="Runs/resultats.txt";

	ofstream fichier(filename_);
        fichier.close();

	delay_=1000000;
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
	float acc=0;
	for (int i=0;i<10; i++)
	{
		acc=acc+buffer[i];
	}
	acc=acc/10;

	return acc;
}

void Service::runPrimary()
{	
	//////////////////////////BEFORE////////////////////////
	//1.Ecriture i'm alive
	WD_->set();
	le_mutex_->unlock();


	//////////////////////////PROCEED//////////////////////
	float v;
	bool probleme=false;

	//2.Lecture Capteur
	valeur_capteur_=CP_->read();
	cout<<endl<<"valeur capteur: "<<valeur_capteur_<<endl;

	//Stocker dans buffer
	pCBUF_->put(valeur_capteur_);
	pCBUF_->print();

	//3.Calcul des valeur de sortie sur les n dernières valeurs
	float v1=calcul(pCBUF_);
	float v2=calcul(pCBUF_);


	////////////////////////////AFTER////////////////////////
	if(v1==v2)
		v=v1;
	else
	{
		// Vote majoritaire
		float v3=calcul(pCBUF_);
		cout << "v3=" << v3 << endl;
		if(v3==v1 || v3==v2)
			v=v3;
		else
			probleme=true;
	}

	if(!probleme)
	{
		cout << "=>";
		if(id_==0)
			cout << "Simplex";
		else
			cout << "Duplex";
		cout<<"-moyenne arithmetique: "<<v<<endl;
		saveRes(v);
	}

	//5.Stockage infos capteur sur le disque (memoire stable)
	if(ME_->save(pCBUF_)==-1) 
		cout << "Probleme de sauvegarde !" << endl;
}

void Service::runBackup()
{
	timeout_++;

	if (le_mutex_->try_lock()||(timeout_==11))
	{
		//1.Lecture watchdog
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

int Service::saveRes(float v)
{
	ofstream fichier(filename_, ios::app);

        if(fichier.bad()) return -1;
        else
        {
                fichier << v << endl;
        }

        fichier.close();
	return 0;
}

int Service::getDelay()
{
	if(mode_=='P')
		return delay_;
	else
		return delay_/10;
}

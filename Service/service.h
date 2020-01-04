#ifndef DEF_SERVICE
#define DEF_SERVICE

#include <iostream>
#include <pthread.h>
#include <mutex>
#include <signal.h>

#include "../Watchdog/watchdog.h"
#include "../Capteur_Buffer/capteur.h"
#include "../SMemory/SMemory.h"
#include "../Capteur_Buffer/circular_buffer.h"

using namespace std;

class Service 
{
protected:
	int timeout_; 		// timeout en période pour concidèrer le primaire dead
	mutex* le_mutex_; 	// mutex pour synchroniser utilisation du watchdog
	float valeur_capteur_;	// valeur lu du capteur
	int ancien_watchdog_; 	// valeur précédente du watchdog
        char mode_;          	// primary / backup
	char initial_mode_;  	// mode initial du service
	int id_; 		// id (différencie les tests d'injection de fautes)
	string filename_; 	// nom du fichier où enregistrer les résultats
	int delay_; 		// periode d'execution du service primairz

        Watchdog* WD_;		// pointeur (reference) sur (adresse du) watchdog
        Capteur* CP_;		// pointeur (reference) sur (adresse du) capteur
        SMemory* ME_;		// pointeur (reference) sur (adresse de) memoire stable
        Circular_Buffer* pCBUF_;// pointeur sur un buffer circulaire

public:
        Service (char, Watchdog*, Capteur*, SMemory*, Circular_Buffer*, mutex*, int) ; 
        void run (); 			    // run global appelé par le processeur
	void runPrimary(); 		    // appelé par run() en fonction de mode_
	void runBackup(); 		    // appelé par run() en fonction de mode_
	float calcul(Circular_Buffer* buf); // calcul la moyenne du buffer tournant
	int saveRes(float v); 		    // sauvegarde calcul dans le fichier filename_
	int getDelay(); 		    // accesseur pour la période
	char getMode(); 		    // accesseur pour le mode
};

#endif

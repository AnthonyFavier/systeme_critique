#include <pthread.h>
#include "Watchdog/watchdog.h"
#include "Capteur_Buffer/capteur.h"
#include "SMemory/SMemory.h"
#include "Capteur_Buffer/circular_buffer.h"

class Service {

protected:
	float valeur_capteur_;
	float res_;
        char mode_;          // primary / backup
        int i_;
        Watchdog* WD_;    // pointeur (reference) sur (adresse du) watchdog
        Capteur* CP_;        // pointeur (reference) sur (adresse du) capteur
        SMemory* ME_;    // pointeur (reference) sur (adresse de) memoire stable
        Circular_Buffer* pCBUF_;    // pointeur sur un buffer circulaire


public:
        Service (char, Watchdog*, Capteur*, SMemory*, Circular_Buffer*) ;
        void run () ;
	float calcul(Circular_Buffer* buf);
};



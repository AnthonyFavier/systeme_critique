#include <pthread.h>
#include "watchdog.h"
#include "capteur.h"
#include "Smemory.h"
#include "circular_buffer.h"

class Service {

protected:
	float valeur_capteur_;
	float res_;
        char mode_;          // primary / backup
        int i_;
        watchdog* WD_;    // pointeur (reference) sur (adresse du) watchdog
        capteur* CP_;        // pointeur (reference) sur (adresse du) capteur
        Smemory* ME_;    // pointeur (reference) sur (adresse de) memoire stable
        Circular_Buffer* pCBUF_;    // pointeur sur un buffer circulaire


public:
        service (char, watchdog*, capteur*, Smemory*) ;
        void run (float*) ;
};



#include <pthread.h>
#include "watchdog.h"
#include "capteur.h"
#include "Smemory.h"
#include "Circular_Buffer.h"

class service {

protected:
        char mode;          // primary / backup
        int i;
        watchdog* WD;    // pointeur (reference) sur (adresse du) watchdog
        capteur* CP;        // pointeur (reference) sur (adresse du) capteur
        Smemory* ME;    // pointeur (reference) sur (adresse de) memoire stable
        Circular_Buffer* pCBUF;    // pointeur sur un buffer circulaire

public:
        service (char, watchdog*, capteur*, Smemory*) ;
        void run (float*) ;
};



#include "service.h"
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
	Watchdog* W = new Watchdog();
	Capteur* C = new Capteur();
	SMemory* SM = new SMemory();
	Circular_Buffer* B = new Circular_Buffer();

	Service* S = new Service('P', W, C, SM, B);

	while(true)
	{
		S->run();
		usleep(100000);
	}

	delete W;
	delete C;
	delete SM;
	delete B;
	delete S;

	return 0;
}

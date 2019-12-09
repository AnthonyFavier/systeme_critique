#include <iostream>
#include <unistd.h>

#include "watchdog.h"

using namespace std;

int main()
{
	Watchdog watchdog;

	for(int i=0; i<20; i++)
	{
		watchdog.set();
		cout << watchdog.read() << endl;

		usleep(1000000);
	}

	return 0;
}

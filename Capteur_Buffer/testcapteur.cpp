#include <iostream>
using namespace std;

#include "capteur.h"

int main() 
{
	int i;
	Capteur C;

	for (i=0; i<10; i++) 
		cout << "V["  << i << "] = " << C.read()<< endl;

	return 0;
}


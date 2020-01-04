#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#include "circular_buffer.h"


int main() 
{
	Circular_Buffer CBUF;

	int i;
	for (i=0; i<15; i++) CBUF.put((float) i);

	float* T;
	T=CBUF.get();
	for (i=0; i<10; i++) cout << *T++ << endl;

	return 0;
}

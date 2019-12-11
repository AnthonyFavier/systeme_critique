#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <mutex>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>
#include "../Service/service.h"
using namespace std;


/* Definition de la procedure de traitement de requete  */

int tid_FD, tid_IM;

std::mutex* M=new std::mutex();
Watchdog* W = new Watchdog();
Capteur* C = new Capteur();
SMemory* SM = new SMemory();
Circular_Buffer* B = new Circular_Buffer();

Service* srv1 = new Service('P', W, C, SM, B, M);
Service* srv2 = new Service('B', W, C, SM, B, M);

void * processeur1(void *args)
{
	int damocles=0;
	while(true)
	{
		srv1->run();
		usleep(1000000);
		damocles+=1;
		if (damocles==-1)
		{
			cout<<"Even you Brutus..."<<endl;
			break;
		}
	}
}

void * processeur2(void *args)
{
	usleep(500000);
	while(true)
	{
        	srv2->run();
		usleep(1000000);
	}
}

sig_t bye()
{
	printf("\n######################################################\n######################################################\n####### How have you dared ctr-c me mortal ?! ########\n######################################################\n######################################################\n\n");
	exit(0);
}

////////////////////////////////////////////////////////////////////
main()
{

pthread_attr_t *thread_attributes;
pthread_t *thread;

signal(SIGINT, (sig_t)bye);


/* creation du thread Server1 */
tid_FD = 1;

thread_attributes=(pthread_attr_t *)malloc(sizeof(pthread_attr_t));
thread=(pthread_t *)malloc(sizeof(pthread_t));

pthread_attr_init(thread_attributes);
if (pthread_create(thread, thread_attributes, processeur1,(void *) NULL) != 0)
        perror ("Thread_Server-> Failure detector thread pb!");

/* creation du thread Server 2 */
tid_IM=2;
thread_attributes=(pthread_attr_t *)malloc(sizeof(pthread_attr_t));
thread=(pthread_t *)malloc(sizeof(pthread_t));
pthread_attr_init(thread_attributes);
if (pthread_create(thread, thread_attributes, processeur2,(void *) NULL) != 0)
        perror ("Thread_Server-> Image mgt thread pb!");

while (1) { }  /* DOES NOTHING */ ;
} 
///////////////////////////////////////////////////////////////////





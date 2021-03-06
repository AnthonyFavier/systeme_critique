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

// defini quand est ce que la faute par crash est injectée
int damocles;

pthread_attr_t *thread_attributes1;
pthread_t *thread1;

void * processeur1(void* args)
{
	cout<<"Bonjour1"<<endl;
	Service* srv1=(Service*)args;
	while(true)
	{
		srv1->run();
		usleep(srv1->getDelay());
	}
}

void * processeur2(void* args)
{
	Service* srv2=(Service*)args;
	while(true)
	{
        	srv2->run();
		usleep(srv2->getDelay());
	}
}

void * fault_injection(void *args)
{
	usleep(damocles*1000000);
	pthread_cancel(*thread1);
	
	//pthread_kill(*thread1, SIGUSR1); // Si check exterieur
	// car actuellement on check watchdog et bascule en primary au meme endroit
}

// autre thread check watchdog
// while(1)
// if(sv1->getMode()=='P' && srv2->getMode()=='B')
// 	// check watchdog
// 	// *contenu de runBackup*
// 	// si pas bon
// 		// srv->recouvrement();
// usleep(srv2->getDelay())

sig_t bye()
{
	printf("\n######################################################\n######################################################\n####### How have you dared ctr-c me mortal ?! ########\n######################################################\n######################################################\n\n");
	exit(0);
}

////////////////////////////////////////////////////////////////////
main(int argc, char** argv)
{
	// verif arguments
	if(argc!=2)
	{
		cout << "Erreur argument!!!" << endl;
		return -1;
	}

	// ecriture du pid
	ofstream fichier("pid");
	pid_t pid=getpid();
	fichier << pid;
	fichier.close();

	// injection fault
	srand(time(NULL));
	damocles=rand()%18+1;
	cout << "damo=" << damocles << endl;
	
	mutex* M=new mutex();
	Watchdog* W = new Watchdog();
	Capteur* C = new Capteur();
	SMemory* SM = new SMemory();
	Circular_Buffer* B = new Circular_Buffer();

	int argint=atoi(argv[1]);

	Service* srv1 = new Service('P', W, C, SM, B, M, argint);
	Service* srv2 = new Service('B', W, C, SM, B, M, argint);

	pthread_attr_t *thread_attributes;
	pthread_t *thread;

	signal(SIGINT, (sig_t)bye);

	// creation du thread Primary //
	thread_attributes1=(pthread_attr_t *)malloc(sizeof(pthread_attr_t));
	thread1=(pthread_t *)malloc(sizeof(pthread_t));
	pthread_attr_init(thread_attributes1);
	if (pthread_create(thread1, thread_attributes1, processeur1,(void*) srv1) != 0)
		perror ("Thread_Server-> Thread1 pb!");

	// creation du thread Backup //
	thread_attributes=(pthread_attr_t *)malloc(sizeof(pthread_attr_t));
	thread=(pthread_t *)malloc(sizeof(pthread_t));
	pthread_attr_init(thread_attributes);
	if (pthread_create(thread, thread_attributes, processeur2,(void*) srv2) != 0)
		perror ("Thread_Server-> Thread2 pb!");

	// creation du thread Fault injection //
	thread_attributes=(pthread_attr_t *)malloc(sizeof(pthread_attr_t));
	thread=(pthread_t *)malloc(sizeof(pthread_t));
	pthread_attr_init(thread_attributes);
	if (pthread_create(thread, thread_attributes, fault_injection,(void *) NULL) != 0)
		perror ("Thread_Server-> Thread FI pb!");

	while (1) 
	{ 
		usleep(100000);
	} ;
} 
///////////////////////////////////////////////////////////////////


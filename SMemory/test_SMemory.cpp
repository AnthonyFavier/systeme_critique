#include <iostream>

#include "SMemory.h"

using namespace std;

int main()
{
	SMemory smemory;
	Circular_Buffer* buff=new Circular_Buffer();

	cout << "1er save" << endl;
	float f;
	f=0,0;
	for(int i=0; i<10; i++)
	{
		buff->put(f);
		f+=1.5;
	}
	cout << "fin put" << endl;
	if(smemory.save(buff)==-1)
		cout << "OHOHOHOHO" << endl;

	cout << "2eme save" << endl;
	for(int i=0; i<10; i++)
	{
		buff->put(f);
		f+=1.5;
	}
	if(smemory.save(buff)==-1)
		cout << "DEUXIEME PROBLEMMMEE" << endl;

	cout << "recover" << endl;
	Circular_Buffer* buff2=new Circular_Buffer();
	buff2=smemory.recover();
	buff2->print();


	delete buff;
	delete buff2;

	return 0;
}


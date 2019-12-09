#include <iostream>

#include "SMemory.h"

using namespace std;

int main()
{
	SMemory smemory;

	float buff[10];
	float f;
	f=0,0;
	for(int i=0; i<10; i++)
	{
		buff[i]=f;
		f+=1.5;
	}
	smemory.save(buff);

	for(int i=0; i<10; i++)
	{
		buff[i]=f;
		f+=1.5;
	}
	smemory.save(buff);


	return 0;
}


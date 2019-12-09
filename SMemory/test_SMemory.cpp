#include <iostream>

#include "SMemory.h"

using namespace std;

int main()
{
	SMemory smemory;
	Circular_Buffer* buff;

	float f;
	f=0,0;
	for(int i=0; i<10; i++)
	{
		buff->put(f);
		f+=1.5;
	}
	smemory.save(buff);

	for(int i=0; i<10; i++)
	{
		buff->put(f);
		f+=1.5;
	}
	smemory.save(buff);


	return 0;
}


#include <iostream>
#include "Circular_Buffer.h"
using namespace std;

// Attributes
//	float Buffer[10]
//	int free;

// Methods
Circular_Buffer::Circular_Buffer (){
	int i;
	for (i=0; i<10 ; i++) Buffer[i]=0.0;;
	free=0;
};

void Circular_Buffer::put (float x){ // Adding a new float into the buffer
	Buffer[free]=x;
	free=(free+1)%10;;
};

float* Circular_Buffer::get (){ // Returning the buffer
	return Buffer;
};

void Circular_Buffer::print() {
	cout << "Buffer: ";
	int i;
	for (i=0; i<10; i++) cout << " "<< Buffer[i] ;
	cout << endl;
}


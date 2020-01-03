#include <iostream>
#include "circular_buffer.h"
using namespace std;

// Methods
Circular_Buffer::Circular_Buffer ()
{
	int i;
	for (i=0; i<TAILLE_BUFF ; i++) buffer_[i]=0.0;
	free_=0;	
}

void Circular_Buffer::put (float x) // Adding a new float into the buffear
{
	buffer_[free_]=x;
	free_=(free_+1)%TAILLE_BUFF;
}

float* Circular_Buffer::get () // Returning the buffer
{
	return buffer_;
}

int Circular_Buffer::getFree()
{
	return free_;
}

void Circular_Buffer::setFree(int free)
{
	free_=free;
}

void Circular_Buffer::print() 
{
	cout << "Buffer: ";
	int i;
	for (i=0; i<TAILLE_BUFF; i++) cout << " "<< buffer_[i] ;
	cout << endl;
}


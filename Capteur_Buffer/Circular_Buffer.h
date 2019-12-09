#ifndef BUFFER
#define BUFFER

class  Circular_Buffer {

protected:
	float Buffer[10];
	int free;
public:
	Circular_Buffer ();

	void put (float);
	float* get ();
	void print();
};

#endif



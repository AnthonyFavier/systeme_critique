#ifndef BUFFER
#define BUFFER

class  Circular_Buffer 
{
protected:
	float buffer_[10];
	int free_;
public:
	Circular_Buffer ();

	void put (float);
	float* get ();
	void print();
};

#endif



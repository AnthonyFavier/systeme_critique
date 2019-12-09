#ifndef BUFFER
#define BUFFER

#define TAILLE_BUFF 10

class  Circular_Buffer 
{
private:
	float buffer_[10];
	int free_;
public:
	Circular_Buffer ();

	void put (float);
	float* get ();
	void print();
};

#endif



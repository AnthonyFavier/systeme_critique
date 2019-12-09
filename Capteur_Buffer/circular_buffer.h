#ifndef BUFFER
#define BUFFER

#define TAILLE_BUFF 10

class  Circular_Buffer 
{
protected:
	float buffer_[TAILLE_BUFF];
	int free_;
public:
	Circular_Buffer ();

	void put (float);
	float* get ();
	void print();
};

#endif



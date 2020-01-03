#ifndef BUFFER
#define BUFFER

#define TAILLE_BUFF 10

class  Circular_Buffer 
{
private:
	float buffer_[TAILLE_BUFF];
	int free_;
public:
	Circular_Buffer ();

	void put(float);
	float* get();
	int getFree();
	void setFree(int free);
	void print();
};

#endif



#ifndef CAPTEUR
#define CAPTEUR

class capteur {
protected:
	int nb;
	float val;
public:
	capteur ();
	float read();
};

#endif


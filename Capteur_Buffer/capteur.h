#ifndef CAPTEUR
#define CAPTEUR

class Capteur {
protected:
	int nb;
	float val;
public:
	Capteur();
	float read();
};

#endif


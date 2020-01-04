#ifndef DEF_WATCHDOG
#define DEF_WATCHDOG

// valeur max du compteur
#define COMPT_MAX 10

class Watchdog
{
public:
	Watchdog();
	void set(); // incrémente le compteur
	int read(); // getter pour compteur_
private:
	int compteur_;
};

#endif

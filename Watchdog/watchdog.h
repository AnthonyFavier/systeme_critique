#ifndef DEF_WATCHDOG
#define DEF_WATCHDOG

#define COMPT_MAX 10

class Watchdog
{
public:
	Watchdog();
	void set();
	int read();
private:
	int compteur_;
};

#endif

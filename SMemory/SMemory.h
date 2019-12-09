#include <fstream>

using namespace std;

#define TAILLE_BUFF 10

class SMemory
{
public:
	SMemory();
	int save(float buff[TAILLE_BUFF]);
	float* recover();
};

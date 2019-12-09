#include <fstream>
#include "../Capteur_Buffer/circular_buffer.h"

using namespace std;

#define TAILLE_BUFF 10

class SMemory
{
public:
	SMemory();
	int save(Circular_Buffer* buff);
	Circular_Buffer recover();
};

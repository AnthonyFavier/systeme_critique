#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char** argv)
{
	int n=100;
	string cmd;
	string line="erreur";
	for(int i=0; i<n; i++)
	{
		cout << endl << "######################################" << endl;
		cout << "RUN=" << i << "/" << n << endl;
		cout << "######################################" << endl << endl;

		// Lance le systeme
		cmd="./systeme ";
		cmd.append(to_string(i));
		cmd.append(" &");
		system(cmd.c_str());

		usleep(2000000);

		// lecture pid
		ifstream fichier("pid");
		if(fichier.bad()) cout << "Failed to open file" << endl;
		else
		{
			getline(fichier, line);
			fichier.close();
		}

		usleep(18000000);

		// kill systeme
		cmd="kill " + line;
		system(cmd.c_str());
	}
}


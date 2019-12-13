#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string gr_filename="Runs/goldenrun.txt";
        ifstream gr_fichier(gr_filename);

	string bm_filename="Runs/benchmark.txt";
        ofstream bm_fichier(bm_filename);	




	for (int i=0; i<100; i++)
	{
		cout<<"checking run "<<i<<endl;
		string extension=to_string(i);
		string filename="Runs/resultatsid"+extension+".txt";
        	ifstream fichier(filename);
		bool etat=true;

		if(fichier) 
		{
			string line;
			string line_gr;
			int free;

			for(int j=1; j<40; j++)
			{
				getline(fichier, line);
				getline(gr_fichier, line_gr);

				cout<<line<<" vs. "<<line_gr<<endl;

				if (!(line==line_gr))
				{
					etat=false;
				}
			}

			if (etat) {bm_fichier<<i<<" : c'est OK"<<endl;}
			else {bm_fichier<<i<<" : PAS OK OSCOOOUR"<<endl;}
		}
		else
		{
			cout<<"Pas sur qu'il existe le run, recommence"<<endl;
		}


	}

        return 1;
}


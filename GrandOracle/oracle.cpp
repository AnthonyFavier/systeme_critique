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

	int succes=0;


	for (int i=0; i<100; i++)
	{
		ifstream gr_fichier(gr_filename);

		cout<<"[check run "<<i<<"]"<<endl;
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

				if (!(line==line_gr))
				{
					etat=false;
				}
			}

			if (etat) 
			{
				bm_fichier<<i<<" : c'est OK"<<endl;
				succes++;
			}
			else {bm_fichier<<i<<" : PAS OK OSCOOOUR"<<endl;}
		}
		else
		{
			cout<<"Pas sur qu'il existe le run, recommence"<<endl;
		}

		gr_fichier.close();
	}
	float couverture=succes/100.0;
	cout<<"couverture : on a eu "<<succes<<" succes sur 100 run, soit un taux de c="<<couverture<<endl;
	cout<<"IMPRESSIONNANT !"<<endl;

        return 1;
}


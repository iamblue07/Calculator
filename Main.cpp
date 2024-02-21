#include <fstream>
#include <vector>
#include "Parsare.h"
#include "Verificare.h"
#include "Calculator.h"
#include "Abstract.h"
using namespace std;

int main(int argc, char* argv[])
{

	if (argc >= 2)
	{
		vector<string> ecuatii;
		for (int i = 1; i < argc; i++)
		{
			ecuatii.push_back(string(argv[i]));
		}
		Verificare v;
		for (int i = 0; i < ecuatii.size(); i++)
		{
			string ec = ecuatii[i];
			//start apel calculator
			v.setEcuatie(ec);
			v.verificareEcuatie();

			if (v.getCheck() == 1)
			{
				cout << "Ecuatia contine erori de sintaxa!" << endl;
			}
			else
			{
				ec = v.getEcuatie();
				v.setEcuatie("");
				Parsare p;
				p.setS(ec);
				int x = 0;
				int y = p.getS().length();
				string rezultat;
				p.parse(p.getS(), x, y);
				rezultat = p.getS();
				if (rezultat[0] == '[')
				{
					rezultat.erase(0, 1);
					rezultat.erase(rezultat.length() - 1, 1);
				}
				p.setS("");
				cout << rezultat << endl;
				cout << ec << endl;
			}
			//Stop apel calculator
		}
	}
	else
	{
		ScrieriConsola* a = new Abstract;
		Verificare v;
		a->textinitial();
		int okmeniu = 1;
		while (okmeniu == 1)
		{
			int optmeniu1;
			a->meniu1();
			cin >> optmeniu1;
			cin.get();
			if (optmeniu1 == 1)
			{
				a->numefis();
				string denumire_citire;
				getline(cin, denumire_citire);
				ifstream fin(denumire_citire);
				int okfis = 1;
				if (fin.fail() == 1)
				{
					a->eroarefis();
					okfis = 0;
					fin.close();
				}
				while (okfis == 1)
				{
					if (fin.eof() == 1)
					{
						okfis = 0;
						a->fisierparcurs();
					}
					else
					{
						a->meniu2();
						int optfis;
						cin >> optfis;
						if (optfis == 1)
						{
							string ec;
							getline(fin, ec);
							//Start Apel calculator
							v.setEcuatie(ec);
							v.verificareEcuatie();

							if (v.getCheck() == 1)
							{
								a->erori();
							}
							else
							{
								ec = v.getEcuatie();
								v.setEcuatie("");
								Parsare p;
								p.setS(ec);
								int x = 0;
								int y = p.getS().length();
								string rezultat;
								p.parse(p.getS(), x, y);
								rezultat = p.getS();
								if (rezultat[0] == '[')
								{
									rezultat.erase(0, 1);
									rezultat.erase(rezultat.length() - 1, 1);
								}
								p.setS("");
								cout << "Rezultatul ecuatiei:" << endl << ec << endl << "Este: " << rezultat << endl;
								ec = rezultat;
							}
							//Stop Apel Calculator
							a->salvarefis();
							int optsalvare;
							cin.get();
							cin >> optsalvare;
							if (optsalvare == 1)
							{
								string denumire_salvare;
								a->denumirefissalvare();
								cin.get();
								getline(cin, denumire_salvare);
								ofstream fout(denumire_salvare, ios::binary | ios::app);
								int lungimerez = ec.length();
								fout.write((char*)&lungimerez, sizeof(lungimerez));
								fout.write(ec.c_str(), lungimerez+1);
								a->successalvare();
								fout.close();
							}
						}
						else
						{
							fin.close();
							okfis = 0;
						}

					}
				}

			}

			if (optmeniu1 == 2)
			{
				a->intrEc();
				string ec;
				getline(cin, ec);
				//Apel calculator
				v.setEcuatie(ec);
				v.verificareEcuatie();

				if (v.getCheck() == 1)
				{
					a->erori();
				}
				else
				{
					ec = v.getEcuatie();
					v.setEcuatie("");
					Parsare p;
					p.setS(ec);
					int x = 0;
					int y = p.getS().length();
					string rezultat;
					p.parse(p.getS(), x, y);
					rezultat = p.getS();
					if (rezultat[0] == '[')
					{
						rezultat.erase(0, 1);
						rezultat.erase(rezultat.length() - 1, 1);
					}
					p.setS("");
					cout << "Rezultatul ecuatiei:" << endl << ec << endl << "Este: " << rezultat << endl;
					ec = rezultat;
				}
				//Stop Apel Calculator
				a->salvarefis();
				int ks;
				cin >> ks;
				if (ks == 1)
				{
					string denumire_salvare;
					a->denumirefissalvare();
					cin.get();
					getline(cin, denumire_salvare);
					ofstream fout(denumire_salvare, ios::binary | ios::app);
					int lungimerez = ec.length();
					fout.write((char*)&lungimerez, sizeof(lungimerez));
					fout.write(ec.c_str(), lungimerez + 1);
					a->successalvare();
					fout.close();
				}



			}

			if (optmeniu1 == 3)
			{
				a->denumirefisbinar();
				string denumire;
				getline(cin, denumire);
				a->afisareContinut(denumire);
			}

			if (optmeniu1 != 1 && optmeniu1 != 2 && optmeniu1 != 3)
			{
				okmeniu = 0;
			}
		}


	}
}
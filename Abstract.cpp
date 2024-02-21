#include "Abstract.h"
#include <fstream>
void Abstract::meniu1()
{
	cout << "1-Cititi o ecuatie din fisier." << endl;
	cout << "2-Cititi o ecuatie de la tastatura." << endl;
	cout << "3-Cititi rezultatele salvate intr-un fisier binar." << endl;
	cout << "Alt numar - Inchideti programul." << endl;
}
void Abstract::meniu2()
{
	cout << "1-Cititi din fisier." << endl;
	cout << "Alt numar - Inchideti fisierul." << endl;
}
void Abstract::numefis()
{
	cout << "Introduceti numele fisierului din care cititi." << endl;
}
void Abstract::eroarefis()
{
	cout << "Acest fisier nu exista." << endl;
}
void Abstract::salvarefis()
{
	cout << "Doriti salvarea rezultatului intr-un fisier binar?" << endl;
	cout << "1 - Da." << endl << "Alt numar - Nu." << endl;
}
void Abstract::successalvare()
{
	cout << "Rezultatul a fost salvat cu succes!" << endl;
}
void Abstract::fisierparcurs()
{
	cout << "Fisierul este gol/Ati parcurs toate ecuatiile din fisier." << endl << endl;
}
void Abstract::denumirefissalvare()
{
	cout << "Introduceti numele fisierului binar." << endl;
}
void Abstract::textinitial()
{
	cout << "Va rugam NUMERELE NEGATIVE se fie scrise INTRE PARANTEZE astfel: (-3) sau (-4.32). Multumim de intelegere!" << endl;
	cout << "Calculatorul are o precizie de 6 zecimale." << endl;
	cout << endl;
	cout << "MENIU" << endl;

}
void Abstract::afisareContinut(const string& numeFisier)
{
	ifstream fisierBinar(numeFisier, ios::binary);

	if (!fisierBinar.is_open()) {
		cerr << "Eroare la deschiderea fisierului binar." << endl;
		return;
	}

	cout << "Continutul fisierului binar:\n";
	while (!fisierBinar.eof())
	{
		int lungime = 0;
		fisierBinar.read((char*)&lungime, sizeof(lungime));
		char* rez = new char[lungime + 1];
		fisierBinar.read(rez, lungime + 1);
		string s = rez;
		delete[] rez;
		cout << s << endl;
	}
	fisierBinar.close();
}
void Abstract::denumirefisbinar()
{
	cout << "Introduceti numele fisierului din care doriti sa cititi:" << endl;
}
void Abstract::erori()
{
	cout << "Ecuatia contine erori de sintaxa!" << endl;
}
void Abstract::intrEc()
{
	cout << "Introduceti o ecuatie." << endl;

}
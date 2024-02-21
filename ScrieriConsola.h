#pragma once
#include "ScrieriConsola.h"
#include "Verificare.h"
using namespace std;
class ScrieriConsola : public Verificare
{
public:
	virtual void meniu1() = 0;
	virtual void meniu2() = 0;
	virtual void numefis() = 0;
	virtual void salvarefis() = 0;
	virtual void successalvare() = 0;
	virtual void eroarefis() = 0;
	virtual void fisierparcurs() = 0;
	virtual void denumirefissalvare() = 0;
	virtual void textinitial() = 0;
	virtual void afisareContinut(const string& numeFisier) = 0;
	virtual void denumirefisbinar() = 0;
	virtual void erori() = 0;
	virtual void intrEc() = 0;
};
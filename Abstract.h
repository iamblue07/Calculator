#pragma once
#include <iostream>
#include "ScrieriConsola.h"
class Abstract : public ScrieriConsola
{
public:
	void meniu1() override;
	void meniu2() override;
	void numefis() override;
	void salvarefis() override;
	void successalvare() override;
	void eroarefis() override;
	void fisierparcurs() override;
	void denumirefissalvare() override;
	void textinitial() override;
	void afisareContinut(const string& numeFisier) override;
	void denumirefisbinar() override;
	void erori() override;
	void intrEc() override;
};
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Verificare {
private:
    string ecuatie;
    static int check;
    static const string text;


public:
    Verificare();
    Verificare(string _ecuatie);
    void setEcuatie(const string& ec);
    string getEcuatie();
    string getText();
    int getCheck() const;
    void stergeSpatii();
    void inlocuiesteParanteze();
    void ParantezeDreptePentruNumereNegative();
    void CaractereAdmise();
    void OperatoriConsecutivi();
    void ImpartireLaZero();
    void NumereCuMultePuncte();
    void verificareParanteze();
    void verificareEcuatie();
    friend ostream& operator<<(ostream& cout, const Verificare& v);
    friend istream& operator>>(istream& cin, Verificare& v);
    Verificare& operator=(const Verificare& alt_obiect);
    bool operator==(const Verificare& alt_obiect);
};


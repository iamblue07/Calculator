#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Calculator
{
private:
    string ecuatie;

public:
    Calculator();
    Calculator(string _ecuatie);
    void gaseste_operatorii(string s, int& n1, int& n2, int& n3);
    double ConversieStringInFloat(string s);
    string rezolvaEcuatie();
    string getEcuatie() const;
    void setEcuatie(const string& _ecuatie);
    friend ostream& operator<<(ostream& cout, const Calculator& calculator);
    friend istream& operator>>(istream& cin, Calculator& calculator);
    Calculator operator+(const Calculator& alt_obiect);
    Calculator operator-(const Calculator& alt_obiect);
};



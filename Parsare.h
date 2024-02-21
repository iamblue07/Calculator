#pragma once
#include <string>
#include "Calculator.h"
using namespace std;
class Parsare
{
private:
    string s;


public:

    Parsare();
    Parsare(string _s);
    int check_existenta_paranteze(string str, int& poz_desc, int& poz_inc);
    string parse(string& s, int& par_desc, int& par_inc);
    string& getS();
    void setS(string value);
    friend istream& operator>>(istream& input, Parsare& p);
    friend ostream& operator<<(ostream& output, const Parsare& p);
    Parsare operator*(const Parsare& alt_obiect);
    Parsare operator/(const Parsare& alt_obiect);
    ~Parsare();
};








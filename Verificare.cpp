#include "Verificare.h"

Verificare::Verificare()
{
    ecuatie = "";
}
Verificare::Verificare(string _ecuatie)
{
    this->ecuatie = _ecuatie;
}
void Verificare::setEcuatie(const string& ec)
{
    ecuatie = ec;
}
string Verificare::getEcuatie()
{
    return this->ecuatie;
}
string Verificare::getText()
{
    return this->text;
}
int Verificare::getCheck() const
{
    return check;
}
void Verificare::stergeSpatii()
{
    int i = 0;
    while (i < ecuatie.length())
    {
        if (ecuatie[i] == ' ')
        {
            ecuatie.erase(i, 1);
        }
        else
        {
            i++;
        }
    }
}
void Verificare::inlocuiesteParanteze()
{
    int i = 0;
    while (i < ecuatie.length())
    {
        if (ecuatie[i] == '[')
        {
            ecuatie[i] = '(';
        }
        if (ecuatie[i] == ']')
        {
            ecuatie[i] = ')';
        }
        i++;
    }
}
void Verificare::ParantezeDreptePentruNumereNegative()
{
    int i = 0;
    int ok = 0;
    while (i < ecuatie.length())
    {
        if (ecuatie[i] == '(' && ecuatie[i + 1] == '-')
        {
            ecuatie[i] = '[';
            ok = 1;
        }
        if (ecuatie[i] == ')' && ok == 1)
        {
            ecuatie[i] = ']';
            ok = 0;
        }
        i++;
    }
}
void Verificare::CaractereAdmise()
{
    int i = 0;
    while (i < ecuatie.length())
    {
        char c = ecuatie[i];
        if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '#' || c == '(' || c == ')' || c == '.'))
        {
            check = 1;
            return;
        }
        i++;
    }
}
void Verificare::OperatoriConsecutivi()
{
    int i = 0;
    while (i < ecuatie.length() - 1)
    {
        if ((ecuatie[i] == '+' || ecuatie[i] == '-' || ecuatie[i] == '*' || ecuatie[i] == '/' || ecuatie[i] == '^' || ecuatie[i] == '#' || ecuatie[i] == '.') &&
            (ecuatie[i + 1] == '+' || ecuatie[i + 1] == '-' || ecuatie[i + 1] == '*' || ecuatie[i + 1] == '/' || ecuatie[i + 1] == '^' || ecuatie[i + 1] == '#' || ecuatie[i + 1] == '.'))
        {
            check = 1;
            return;
        }
        i++;
    }
}
void Verificare::ImpartireLaZero()
{
    int i = 0;
    while (i < ecuatie.length() - 1)
    {
        if (ecuatie[i] == '/' && ecuatie[i + 1] == '0')
        {
            check = 1;
            return;
        }
        i++;
    }
}

void Verificare::NumereCuMultePuncte()
{
    int i = 0;
    int countPunct = 0;
    while (i < ecuatie.length())
    {
        if (ecuatie[i] == '.')
        {
            countPunct++;
            if (countPunct > 1)
            {
                check = 1;
            }
        }
        if (ecuatie[i] == '+' || ecuatie[i] == '-' || ecuatie[i] == '*' || ecuatie[i] == '/' || ecuatie[i] == '^' || ecuatie[i] == '#' || ecuatie[i] == '(' || ecuatie[i] == ')' || ecuatie[i] == '[' || ecuatie[i] == ']' || ecuatie[i] == ' ')
        {
            countPunct = 0;
        }
        i++;
    }
}

void Verificare::verificareParanteze()
{
    int i = 0;
    int parantezaDeschisa = 0;
    while (i < ecuatie.length())
    {
        if (ecuatie[i] == '(')
        {
            parantezaDeschisa++;
        }
        else if (ecuatie[i] == ')')
        {
            parantezaDeschisa--;
            if (parantezaDeschisa < 0)
            {
                check = 1;
                return;
            }
        }
        i++;
    }
    if (parantezaDeschisa > 0)
    {
        check = 1;
    }
}
void Verificare::verificareEcuatie()
{
    check = 0;
    stergeSpatii();
    inlocuiesteParanteze();
    CaractereAdmise();
    OperatoriConsecutivi();
    ImpartireLaZero();
    NumereCuMultePuncte();
    verificareParanteze();
    ParantezeDreptePentruNumereNegative();
}
ostream& operator<<(ostream& cout, const Verificare& v)
{
    cout << "Ecuatie: " << v.ecuatie << "\nCheck: " << v.check;
    return cout;
}
istream& operator>>(istream& cin, Verificare& v)
{
    cout << v.text << " ";
    getline(cin, v.ecuatie);
    return cin;
}
Verificare& Verificare::operator=(const Verificare& alt_obiect)
{
    if (this != &alt_obiect)
    {
        this->ecuatie = alt_obiect.ecuatie;
    }
    return *this;
}
bool Verificare::operator==(const Verificare& alt_obiect)
{
    return this->ecuatie == alt_obiect.ecuatie;
}
int Verificare::check = 0;
const string Verificare::text = "Introduceti o ecuatie sau tastati exit:";


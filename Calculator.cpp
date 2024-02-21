#include "Calculator.h"

Calculator::Calculator()
{
    ecuatie = "";
}
Calculator::Calculator(string _ecuatie)
{
    this->ecuatie = _ecuatie;
}
void Calculator::gaseste_operatorii(string s, int& n1, int& n2, int& n3)
{
    n1 = -1; n2 = -1; n3 = -1;
    int pas = 0;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '#')
        {
            if (pas == 0)
            {
                n1 = i;
                pas++;
            }
            else if (pas == 1)
            {
                n2 = i;
                pas++;
            }
            else if (pas == 2)
            {
                n3 = i;
                pas++;
            }
        }
        i++;
    }
}
double Calculator::ConversieStringInFloat(string s)
{
    double rezultat = 0.0f;
    double fractie = 0.1f;
    int i = 0;
    if (s[i] == '-')
    {
        i++;
        rezultat = rezultat * (-1);
    }
    while (s[i] >= '0' && s[i] <= '9') {
        rezultat = rezultat * 10.0f + (s[i] - '0');
        i++;
    }
    if (s[i] == '.') {
        i++;
        while (s[i] >= '0' && s[i] <= '9') {
            rezultat = rezultat + (s[i] - '0') * fractie;
            fractie *= 0.1f;
            i++;
        }
    }
    return rezultat;
}
string Calculator::rezolvaEcuatie()
{

    int pozitieOperator = -1;
    int n1, n2, n3;
    int semn_nr1 = 1, semn_nr2 = 1;
    string aux1, aux2;
    gaseste_operatorii(ecuatie, n1, n2, n3);
    if (n1 != -1 && n2 != -1 && n3 != -1)
    {
        pozitieOperator = n2;
        if (ecuatie[n1] == '-')
        {
            aux1 = ecuatie.substr(n1 + 1, pozitieOperator - n1 - 2);
            semn_nr1 = -1;
        }
        else
        {
            aux1 = ecuatie.substr(n1 + 1, pozitieOperator - n1 - 2);
            semn_nr1 = 1;
        }
        if (ecuatie[n3] == '-')
        {
            aux2 = ecuatie.substr(n3 + 1, ecuatie.length() - n3 - 2);
            semn_nr2 = -1;
        }
        else
        {
            aux2 = ecuatie.substr(n3 + 1, ecuatie.length() - n3 - 2);
            semn_nr2 = 1;
        }
    }
    if (n1 != -1 && n2 == -1 && n3 == -1)
    {
        pozitieOperator = n1;
        aux1 = ecuatie.substr(0, pozitieOperator);
        aux2 = ecuatie.substr(pozitieOperator + 1, ecuatie.length() - pozitieOperator - 1);
    }
    if (n1 == 1 && n2 != -1 && n3 == -1)
    {
        pozitieOperator = n2;
        if (ecuatie[n1] == '-')
        {
            semn_nr1 = -1;
            aux1 = ecuatie.substr(n1 + 1, pozitieOperator - n1 - 2);
        }
        else
        {
            semn_nr1 = 1;
            aux1 = ecuatie.substr(n1 + 1, pozitieOperator - n1 - 2);
        }
        aux2 = ecuatie.substr(pozitieOperator + 1, ecuatie.length() - pozitieOperator - 1);
    }
    if (n1 != -1 && n2 != -1 && n3 == -1 && ecuatie[n2 - 1] == '[')
    {
        pozitieOperator = n1;
        aux1 = ecuatie.substr(0, pozitieOperator);
        if (ecuatie[n2] == '-')
        {
            semn_nr2 = -1;
            aux2 = ecuatie.substr(n2 + 1, ecuatie.length() - n2 - 2);
        }
        else
        {
            semn_nr2 = 1;
            aux2 = ecuatie.substr(n2 + 1, ecuatie.length() - n2 - 2);
        }
    }


    double nr1 = ConversieStringInFloat(aux1);
    double nr2 = ConversieStringInFloat(aux2);


    double rezultat = 0;
    char operatie = ecuatie[pozitieOperator];

    
    if (ecuatie[pozitieOperator] == '+')
        rezultat = nr1 * semn_nr1 + nr2 * semn_nr2;
    if (ecuatie[pozitieOperator] == '-')
        rezultat = nr1 * semn_nr1 - nr2 * semn_nr2;
    if (ecuatie[pozitieOperator] == '*')
    {
        if (nr1 == 0) rezultat = 0;
        else rezultat = nr1 * semn_nr1 * nr2 * semn_nr2;
    }
    if (ecuatie[pozitieOperator] == '/')
        if (nr2 != 0)
        {
            rezultat = (nr1 * semn_nr1) / (nr2 * semn_nr2);
        }
        else
        {
            cout << "Nu se poate realiza o impartire la 0." << endl;
        }
    if (ecuatie[pozitieOperator] == '^')
        rezultat = pow(nr1 * semn_nr1, nr2 * semn_nr2);
    if (ecuatie[pozitieOperator] == '#')
        if (semn_nr2 == 1)
        {
            rezultat = pow(nr2, 1.0f / (nr1 * semn_nr1));
        }
        else
        {
            cout << "Valoarea din radical nu poate fi negativa." << endl;
        }

    string rez = "";
    if (rezultat < 0)
    {
        rez += '[';
        rez += to_string(rezultat);
        rez += ']';
    }
    else
        rez = to_string(rezultat);
    return rez;
}
string Calculator::getEcuatie() const {
    return ecuatie;
}
void Calculator::setEcuatie(const string& _ecuatie) {
    ecuatie = _ecuatie;
}
ostream& operator<<(ostream& cout, const Calculator& calculator) {
    cout << "Ecuatie: " << calculator.ecuatie;
    return cout;
}
istream& operator>>(istream& cin, Calculator& calculator)
{
    cout << "Scrieti o ecuatie:" << endl;
    getline(cin, calculator.ecuatie);
    return cin;
}
Calculator Calculator::operator+(const Calculator& alt_obiect)
{
    string rezultat = "(" + ecuatie + ")+(" + alt_obiect.ecuatie + ")";
    return Calculator(rezultat);
}
Calculator Calculator:: operator-(const Calculator& alt_obiect)
{
    string rezultat = "(" + ecuatie + ")-(" + alt_obiect.ecuatie + ")";
    return Calculator(rezultat);
}


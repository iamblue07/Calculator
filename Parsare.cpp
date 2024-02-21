#include "Parsare.h"

Parsare::Parsare()
{
    this->s = "";
}
Parsare::Parsare(string _s)
{
    this->s = _s;
}
int Parsare::check_existenta_paranteze(string str, int& poz_desc, int& poz_inc)
{
    int i = 0;
    int check = 0;
    while (i < str.length())
    {
        if (str[i] == '(')
        {
            poz_desc = i;
            poz_inc = -1;
            check = 1;
        }
        if (str[i] == ')' && check == 1)
        {
            poz_inc = i;
            check = 2;
        }
        i++;
    }
    if (check == 0)
    {
        poz_desc = 0;
        poz_inc = str.length() - 1;
    }
    return check;
}
string Parsare::parse(string& s, int& par_desc, int& par_inc)
{
    int x = 0;
    int y = s.length() - 1;
    if (check_existenta_paranteze(s, x, y) != 0)
    {
        string aux = s.substr(x + 1, y - x - 1);
        int x_aux = 0;
        int y_aux = aux.length() - 1;
        parse(aux, x_aux, y_aux);
        x_aux = 0;
        y_aux = 0;
        s.replace(x, y - x + 1, aux);
        x = 0;
        y = s.length() - 1;
        parse(s, x, y);
    }
    else
    {
        int exista_radical = 0, exista_putere = 0, exista_inmultire_sau_impartire = 0, exista_adunare_sau_scadere = 0;
        int i = x;
        while (i <= y)
        {
            if (s[i] == '#')
                exista_radical++;
            if (s[i] == '^')
                exista_putere++;
            if (s[i] == '*' || s[i] == '/')
                exista_inmultire_sau_impartire++;
            if (s[i] == '+' || (s[i] == '-' && s[i - 1] != '['))
                exista_adunare_sau_scadere++;
            i++;
        }
        i = x;
        y = s.length() - 1;
        while (exista_radical != 0)
        {
            if (s[i] == '#')
            {
                int index_nr1 = i - 1;
                while (index_nr1 > x &&
                    ((s[index_nr1] >= '0' && s[index_nr1] <= '9') ||
                        s[index_nr1] == '.' ||
                        s[index_nr1] == ']' ||
                        (index_nr1 > 0 && s[index_nr1 - 1] == '[' && s[index_nr1] == '-')))
                {
                    index_nr1--;
                }
                int index_nr2 = i + 1;
                while (index_nr2 <= y &&
                    ((s[index_nr2] >= '0' && s[index_nr2] <= '9') ||
                        s[index_nr2] == '.' ||
                        s[index_nr2] == ']' ||
                        s[index_nr2] == '[' ||
                        (s[index_nr2 - 1] == '[' && s[index_nr2] == '-')))

                {
                    index_nr2++;
                }
                if (index_nr1 == 0)
                {
                    string ecuatie_elementara = s.substr(index_nr1, index_nr2 - index_nr1);
                    Calculator calcul_elementar;
                    calcul_elementar.setEcuatie(ecuatie_elementara);
                    s.replace(index_nr1, index_nr2 - index_nr1, calcul_elementar.rezolvaEcuatie());
                    i = x;
                    y = s.length() - 1;
                    exista_radical--;
                    calcul_elementar.setEcuatie("");
                }
                else
                {
                    string ecuatie_elementara;
                    if (s[index_nr1] == '[')
                        ecuatie_elementara = s.substr(index_nr1, index_nr2 - index_nr1);
                    else
                        ecuatie_elementara = s.substr(index_nr1 + 1, index_nr2 - index_nr1 - 1);
                    Calculator calcul_elementar;
                    calcul_elementar.setEcuatie(ecuatie_elementara);
                    if (s[index_nr1] == '[')
                        s.replace(index_nr1, index_nr2 - index_nr1, calcul_elementar.rezolvaEcuatie());
                    else
                        s.replace(index_nr1 + 1, index_nr2 - index_nr1 - 1, calcul_elementar.rezolvaEcuatie());
                    i = x;
                    y = s.length() - 1;
                    calcul_elementar.setEcuatie("");
                    exista_radical--;
                }
            }
            else
            {
                i++;
            }
        }
        i = x;
        while (exista_putere != 0)
        {
            if (s[i] == '^')
            {
                int index_nr1 = i - 1;
                while (index_nr1 > x &&
                    ((s[index_nr1] >= '0' && s[index_nr1] <= '9') ||
                        s[index_nr1] == '.' ||
                        s[index_nr1] == ']' ||
                        (index_nr1 > 0 && s[index_nr1 - 1] == '[' && s[index_nr1] == '-')))
                {
                    index_nr1--;
                }
                int index_nr2 = i + 1;
                while (index_nr2 <= y &&
                    ((s[index_nr2] >= '0' && s[index_nr2] <= '9') ||
                        s[index_nr2] == '.' ||
                        s[index_nr2] == ']' ||
                        s[index_nr2] == '[' ||
                        (s[index_nr2 - 1] == '[' && s[index_nr2] == '-')))

                {
                    index_nr2++;
                }
                if (index_nr1 == 0)
                {
                    string ecuatie_elementara = s.substr(index_nr1, index_nr2 - index_nr1);
                    Calculator calcul_elementar;
                    calcul_elementar.setEcuatie(ecuatie_elementara);
                    s.replace(index_nr1, index_nr2 - index_nr1, calcul_elementar.rezolvaEcuatie());
                    i = x;
                    y = s.length() - 1;
                    calcul_elementar.setEcuatie("");
                    exista_putere--;
                }
                else
                {
                    string ecuatie_elementara;
                    if (s[index_nr1] == '[')
                        ecuatie_elementara = s.substr(index_nr1, index_nr2 - index_nr1);
                    else
                        ecuatie_elementara = s.substr(index_nr1 + 1, index_nr2 - index_nr1 - 1);
                    Calculator calcul_elementar;
                    calcul_elementar.setEcuatie(ecuatie_elementara);
                    if (s[index_nr1] == '[')
                        s.replace(index_nr1, index_nr2 - index_nr1, calcul_elementar.rezolvaEcuatie());
                    else
                        s.replace(index_nr1 + 1, index_nr2 - index_nr1 - 1, calcul_elementar.rezolvaEcuatie());
                    i = x;
                    y = s.length() - 1;
                    calcul_elementar.setEcuatie("");
                    exista_putere--;
                }

            }
            else
            {
                i++;
            }
        }
        i = x;
        while (exista_inmultire_sau_impartire != 0)
        {
            if (s[i] == '*' || s[i] == '/')
            {
                int index_nr1 = i - 1;
                while (index_nr1 > x &&
                    ((s[index_nr1] >= '0' && s[index_nr1] <= '9') ||
                        s[index_nr1] == '.' ||
                        s[index_nr1] == ']' ||
                        (index_nr1 > 0 && s[index_nr1 - 1] == '[' && s[index_nr1] == '-')))
                {
                    index_nr1--;
                }
                int index_nr2 = i + 1;
                while (index_nr2 <= y &&
                    ((s[index_nr2] >= '0' && s[index_nr2] <= '9') ||
                        s[index_nr2] == '.' ||
                        s[index_nr2] == ']' ||
                        s[index_nr2] == '[' ||
                        (s[index_nr2 - 1] == '[' && s[index_nr2] == '-')))

                {
                    index_nr2++;
                }
                if (index_nr1 == 0)
                {
                    string ecuatie_elementara = s.substr(index_nr1, index_nr2 - index_nr1);
                    Calculator calcul_elementar;
                    calcul_elementar.setEcuatie(ecuatie_elementara);
                    s.replace(index_nr1, index_nr2 - index_nr1, calcul_elementar.rezolvaEcuatie());
                    i = x;
                    y = s.length() - 1;
                    exista_inmultire_sau_impartire--;
                    calcul_elementar.setEcuatie("");
                }
                else
                {
                    string ecuatie_elementara;
                    if (s[index_nr1] == '[')
                        ecuatie_elementara = s.substr(index_nr1, index_nr2 - index_nr1);
                    else
                        ecuatie_elementara = s.substr(index_nr1 + 1, index_nr2 - index_nr1 - 1);
                    Calculator calcul_elementar;
                    calcul_elementar.setEcuatie(ecuatie_elementara);
                    if (s[index_nr1] == '[')
                        s.replace(index_nr1, index_nr2 - index_nr1, calcul_elementar.rezolvaEcuatie());
                    else
                        s.replace(index_nr1 + 1, index_nr2 - index_nr1 - 1, calcul_elementar.rezolvaEcuatie());
                    i = x;
                    y = s.length() - 1;
                    exista_inmultire_sau_impartire--;
                    calcul_elementar.setEcuatie("");
                }


            }
            else
            {
                i++;
            }
        }
        i = x;
        while (exista_adunare_sau_scadere != 0)
        {
            if (s[i] == '+' || (s[i] == '-' && s[i - 1] != '['))
            {
                int index_nr1 = i - 1;
                while (index_nr1 > x &&
                    ((s[index_nr1] >= '0' && s[index_nr1] <= '9') ||
                        s[index_nr1] == '.' ||
                        s[index_nr1] == ']' ||
                        (index_nr1 > 0 && s[index_nr1 - 1] == '[' && s[index_nr1] == '-')))
                {
                    index_nr1--;
                }
                int index_nr2 = i + 1;
                while (index_nr2 <= y &&
                    ((s[index_nr2] >= '0' && s[index_nr2] <= '9') ||
                        s[index_nr2] == '.' ||
                        s[index_nr2] == ']' ||
                        s[index_nr2] == '[' ||
                        (s[index_nr2 - 1] == '[' && s[index_nr2] == '-')))

                {
                    index_nr2++;
                }
                if (index_nr1 == 0)
                {
                    string ecuatie_elementara = s.substr(index_nr1, index_nr2 - index_nr1);
                    Calculator calcul_elementar;
                    calcul_elementar.setEcuatie(ecuatie_elementara);
                    s.replace(index_nr1, index_nr2 - index_nr1, calcul_elementar.rezolvaEcuatie());
                    i = x;
                    y = s.length() - 1;
                    exista_adunare_sau_scadere--;
                    calcul_elementar.setEcuatie("");
                }
                else
                {
                    string ecuatie_elementara;
                    if (s[index_nr1] == '[')
                        ecuatie_elementara = s.substr(index_nr1, index_nr2 - index_nr1);
                    else
                        ecuatie_elementara = s.substr(index_nr1 + 1, index_nr2 - index_nr1 - 1);
                    Calculator calcul_elementar;
                    calcul_elementar.setEcuatie(ecuatie_elementara);
                    if (s[index_nr1] == '[')
                        s.replace(index_nr1, index_nr2 - index_nr1, calcul_elementar.rezolvaEcuatie());
                    else
                        s.replace(index_nr1 + 1, index_nr2 - index_nr1 - 1, calcul_elementar.rezolvaEcuatie());
                    i = x;
                    y = s.length() - 1;
                    exista_adunare_sau_scadere--;
                    calcul_elementar.setEcuatie("");
                }

            }
            else
            {
                i++;
            }
        }

        return s;
    }

    return s;
}
string& Parsare::getS()
{
    return s;
}
void Parsare::setS(string value)
{
    s = value;
}
istream& operator>>(istream& input, Parsare& p)
{
    getline(input, p.s);
    return input;
}
ostream& operator<<(ostream& output, const Parsare& p)
{
    output << p.s;
    return output;
}
Parsare Parsare::operator*(const Parsare& alt_obiect)
{
    string rezultat = "(" + s + ")*(" + alt_obiect.s + ")";
    return Parsare(rezultat);
}
Parsare Parsare::operator/(const Parsare& alt_obiect)
{
    string rezultat = "(" + s + ")/(" + alt_obiect.s + ")";
    return Parsare(rezultat);
}
Parsare::~Parsare() {}



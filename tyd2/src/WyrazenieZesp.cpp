#include "WyrazenieZesp.hh"

/*!
 * Realizuje wypisanie znakow arytmetycznych.
 * Argumenty:
 *    WyrZ - wyrazenie zespolone,
 * Zwraca:
 *    Brak
 */
void Wyswietl(WyrazenieZesp  WyrZ)
{
    Wyswietl(WyrZ.Arg1);
    switch(WyrZ.Op)
    {
        case Op_Dodaj:
        cout << "+";
        break;

        case Op_Odejmij:
        cout << "-";
        break;

        case Op_Mnoz:
        cout << "*";
        break;

        case Op_Dziel:
        cout << "/";
        break;
    }
    Wyswietl(WyrZ.Arg2);
}


/*!
 * Realizuje przeciazenie operacji wyjscia.
 * Argumenty:
 *    WyrZ - wyrazenie zespolone,
 *    wyj - do realizacji przeciazenia,
 * Zwraca:
 *    Strumien wyjscia
 */
ostream & operator << (ostream & wyj, WyrazenieZesp WyrZ)
{
    wyj << WyrZ.Arg1;
    switch (WyrZ.Op)
    {
        case Op_Dodaj:
        wyj << "+";
        break;

        case Op_Odejmij:
        wyj << "-";
        break;

        case Op_Mnoz:
        wyj << "*";
        break;

        case Op_Dziel:
        wyj << "/";
        break;
    }
    wyj<<WyrZ.Arg2; 

return wyj;  
}

/*!
 * Realizuje wykonanie dzialan arytmetycznych.
 * Argumenty:
 *    WyrZ - wyrazenie zespolone
 * Zwraca:
 *    Wynik wyrazenia.
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    switch (WyrZ.Op)
    {
        case Op_Dodaj:
        return WyrZ.Arg1 + WyrZ.Arg2;
        break;

        case Op_Odejmij:
        return WyrZ.Arg1 - WyrZ.Arg2;
        break;

        case Op_Mnoz:
        return WyrZ.Arg1 * WyrZ.Arg2;
        break;

        case Op_Dziel:
        return WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }
    return WyrZ.Arg1;
}

// Zakomentowany fragment kodu, to czesc programu potrzebna przy realizacji tygodnia 1 //

/*!
 * Realizuje wczytanie wyrazen arytmetycznych.
 * Argumenty:
 *    WyrZ - wyrazenie zespolone
 * Zwraca:
 *    Wczytane wyrazenie zespolone.
 */
 /*           int Wczytaj (WyrazenieZesp WyrZ)
            {
                int i=0;
                char Znak;
                while (Wczytaj(WyrZ.Arg1)==(-1))
                {
                    i++;
                    if (i>2)
                    break;
                }

                cin >> Znak;
                switch(Znak)
                {
                    case '+':
                    WyrZ.Op=Op_Dodaj;
                    break;

                    case '-':
                    WyrZ.Op=Op_Odejmij;
                    break;

                    case '*':
                    WyrZ.Op=Op_Mnoz;
                    break;

                    case '/':
                    WyrZ.Op=Op_Dziel;
                    break;
                }

                while (Wczytaj(WyrZ.Arg2)==(-1))
                {
                    i++;
                    if (i>2)
                    break;
                }
                return 1;
            }
 */
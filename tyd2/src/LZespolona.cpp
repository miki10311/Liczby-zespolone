#include "LZespolona.hh"


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}



/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}



/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.im * Skl2.re) + (Skl1.re * Skl2.im);
  return Wynik;
}



/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik=Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
  return Wynik;
}


/*!
 * Realizuje fragment dzielenia dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2)
{
  LZespolona  Wynik;

  assert(Skl1.re!=0 || Skl1.im!=0);
  Wynik.re = Skl1.re/Skl2;
  Wynik.im = Skl1.im/Skl2;
  return Wynik;
}


/*!
 * Realizuje sprzezenie urojonych czesci liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Sprzezenie liczby zespolonej.
 */
LZespolona Sprzezenie(LZespolona Skl1)
{
  Skl1.im=Skl1.im *(-1);
  return Skl1;
}

/*!
 * Realizuje modul liczby zespolonej do kwadratu.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Modul liczby zespolonej do kwadratu.
 */
double Modul2(LZespolona Skl1)
{
  return Skl1.re*Skl1.re + Skl1.im*Skl1.im;
}


/*!
 * Realizuje poprawne wyswietlenie liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Brak
 */
void Wyswietl(LZespolona Skl1)
{
cout << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i" << ")";
}


/*!
 * Realizuje przeciazenie operacji wyjscia.
 * Argumenty:
 *    Skl - liczba zespolona,
 *    wyj - strumien do realizacji przeciazenia,
 * Zwraca:
 *    Strumien wyjscia.
 */
ostream & operator << (ostream &wyj, LZespolona Skl)
{
  wyj << "(" << Skl.re << showpos << Skl.im << noshowpos << "i" << ")";
  return wyj;
}


/*!
 * Realizuje przeciazenie operacji wejscia i sprawdzenie wczytywanego ciagu znakow.
 * Argumenty:
 *    Skl - liczba zespolona,
 *    wej - strumien do realizacji przeciazenia,
 * Zwraca:
 *    Strumien wejscia.
 */
istream & operator >> (istream & wej, LZespolona &Skl)
{
  char Znak;
  
  wej >> Znak;
  if (Znak != '(')
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    wej.setstate(ios_base::badbit);   // ustawienie statusu bledu 
    return wej;
  }

  wej >> Skl.re;
  if (wej.bad())
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    return wej;
  }

  wej >> Skl.im;
  if (wej.bad())
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    return wej;
  }

  wej >> Znak;
  if (Znak != 'i')
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    wej.setstate(ios_base::badbit);   // ustawienie statusu bledu 
    return wej;
  }

  wej >> Znak;
  if (Znak != ')')
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    wej.setstate(ios_base::badbit);
    return wej;
  }

  return wej;
}



// Zakomentowany fragment kodu, to czesc programu potrzebna przy realizacji tygodnia 1 //

/*!
 * Realizuje sprawdzenie poprawnosci wczytanej liczby zespolonej.
 * Argumenty:
 *    Liczba - liczba zespolona,
 * Zwraca:
 *    Liczbe, ktora jest komunikatem o bledzie, albo o poprawnosci.
 */
 /*     int Wczytaj(LZespolona &Skl1)
        {
          char Znak;
          LZespolona Liczba;

          cin >> Znak;
          if (Znak != '(')
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          cin >> Liczba.re;
          if (cin.bad())
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          cin >> Liczba.im;
          if (cin.bad())
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          cin >> Znak;
          if (Znak != 'i')
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          cin >> Znak;
          if (Znak != ')')
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          return 1;
        }
 */


/*!
 * Realizuje porownanie wprowadzonej liczby zespolonej z poprawnym wynikiem.
 * Argumenty:
 *    Skl1 - pierwsza liczba zespolona,
 *    Skl2 - druga liczba zespolona,
 * Zwraca:
 *    Komunikat o bledzie, albo o poprawnosci.
 */
bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(abs(Skl1.re-Skl2.re)<EPS && abs(Skl1.im-Skl2.im)<EPS )
    return true;      // mialem tutaj duzo bledow przy danych zmiennoprzecinkowych
                      // wiec wprowadzilem zakres poprawnosci jako stala

  return false;
}
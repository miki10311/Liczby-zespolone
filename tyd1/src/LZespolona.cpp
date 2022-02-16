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
cout << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";
}




/*!
 * Realizuje sprawdzenie poprawnosci wczytanej liczby zespolonej.
 * Argumenty:
 *    Liczba - liczba zespolona,
 * Zwraca:
 *    Komunikat o bledzie, albo o poprawnosci.
 */
int Wczytaj(LZespolona &Skl1)
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
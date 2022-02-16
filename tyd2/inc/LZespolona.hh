#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#define EPS 0.1             // stała definiujaca dokladnosc rownan

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Zapowiedzi definicji przeciazen operatorow
 */

bool operator == (LZespolona Skl1, LZespolona Skl2);

ostream &operator << (ostream &wyj, LZespolona Skl);
istream &operator >> (istream &wej, LZespolona &Skl);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double  Skl2);


LZespolona Sprzezenie(LZespolona);
double Modul2(LZespolona);
void Wyswietl(LZespolona);
int Wczytaj(LZespolona&);

#endif

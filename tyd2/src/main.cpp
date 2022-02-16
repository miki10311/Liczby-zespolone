#include <iostream>
#include <limits>
#include "BazaTestu.hh"
#include "WyrazenieZesp.hh"
#include "Statystyka.hh"


#define SZANS 3             // stala definiujaca ilosc szans blednego zapisu liczby zespolonej

using namespace std;


int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp    WyrZ_PytanieTestowe;
  LZespolona wynik;
  LZespolona Odp;
  StatystykaTestu stat={0,0};


  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) 
  {
    cout << ":? Podaj wynik operacji:" << WyrZ_PytanieTestowe << endl;
    Odp = Oblicz(WyrZ_PytanieTestowe);

    for (int i=0; i<SZANS;)
    {
      cout << "Twoja odpowiedz:";
      cin >> wynik;
      if (cin.bad())
      {
        cout << "Liczba dopuszczalnych bledow przy zapisie liczby zespolonej: "<< SZANS << endl;
        i++;
      }
      else
      {
        break;
      }

      cin.clear(); 
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      //  usuwa wszystko z strumienia wejsciowego
    }

    if (wynik==Odp)
    {
      cout << ":) Odpowiedz poprawna" << endl;
      stat.poprawna++;
      stat.wszystkie++;
    }
    else
    {
      cout << ":( Blad. Prawidlowym wynikiem jest: " << Odp << endl;
      stat.wszystkie++;
    }
  }

  
  cout << endl;
  cout << " Koniec testu ." << endl;
  cout << endl;


  Wyswietl(stat);
}

#include <iostream>
#include "Statystyka.hh"

using namespace std;

void Wyswietl(StatystykaTestu StartTestu)
{
    cout << "Ilosc dobrych odpowiedzi:" << StartTestu.poprawna << endl;
    cout << "Ilosc blednych odpowiedzi:" << StartTestu.wszystkie-StartTestu.poprawna << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi:" << StartTestu.poprawna*100.0/StartTestu.wszystkie << "%" << endl;
}
#include <iostream>
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <cstdlib>

using namespace std;
/*!
 * Realizuje wyswietlanie wyrażenia zespolonego
 * Argumenty:
 *    WyrZ - Wyrazenie zespolone skladajace się z:
 *         Arg1 - pierwszej liczby zespolonej
 *         Op   - operatora liczbowego
 *         Arg2 - drugiej liczby zespolonej
 * Zwraca:
 *    ------------------------------------
 */
void Wyswietl(WyrazenieZesp WyrZ)
{
    cout << '(' << WyrZ.Arg1 << ')';
    switch (WyrZ.Op)
    {
    case Op_Dodaj: // dodawanie
    {
        cout << "+";
    }
    break;
    case Op_Odejmij: // odejmowanie
    {
        cout << "-";
    }
    break;
    case Op_Mnoz: // mnozenie
    {
        cout << "*";
    }
    break;
    case Op_Dziel: //dzielenie
    {
        cout << "/";
    }
    break;

    default:
        break;
    }

    cout << '(' << WyrZ.Arg2 << ')' << endl;
}
/*!
 * Realizuje obliczanie wyrażenia zespolonego
 * Argumenty:
 *    WyrZ - Wyrazenie zespolone skladajace się z:
 *         Arg1 - pierwszej liczby zespolonej
 *         Op   - operatora liczbowego
 *         Arg2 - drugiej liczby zespolonej
 * Zwraca:
 *    Liczbe zespoloną
 */
LZespolona Oblicz(WyrazenieZesp WyrZ)
{
    switch (WyrZ.Op)
    {
    case Op_Dodaj: // dodawanie
    {
        LZespolona Wynik;
        Wynik = WyrZ.Arg1 + WyrZ.Arg2;
        return Wynik;
    }
    break;
    case Op_Odejmij: // odejmowanie
    {
        LZespolona Wynik;
        Wynik = WyrZ.Arg1 - WyrZ.Arg2;
        return Wynik;
    }
    break;
    case Op_Mnoz: // mnozenie
    {
        LZespolona Wynik;
        Wynik = WyrZ.Arg1 * WyrZ.Arg2;
        return Wynik;
    }
    break;
    case Op_Dziel: //dzielenie
    {
        LZespolona Wynik;
        if (WyrZ.Arg2==0)
        {
            cerr<<"Nie wolno dzielic przez 0 !" << endl;
            cout<<"Twoja odpowiedz:";
            cin>>WyrZ.Arg2;
        }
        Wynik = WyrZ.Arg1 / WyrZ.Arg2;
        return Wynik;
    }
    break;

default:
    cerr << "Niepoprawne dzialanie";
    exit(0);
    break;
}
}

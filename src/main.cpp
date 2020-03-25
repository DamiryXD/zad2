#include <iostream>
#include <limits>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"


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

  WyrazenieZesp   WyrZ_PytanieTestowe; 
  LZespolona Arg1; // odpowiedz uzytkownika
  float lp=0,ln=0; // lp- liczba poprawnych, ln- liczba niepoprawnych
  int liczbaprob=3;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout<<"Podaj wynik operacji:"; Wyswietl(WyrZ_PytanieTestowe);
    cout<<endl<<"Twoja odpowiedz:";
    cin>>Arg1;
    while (!cin)
    {
      if (liczbaprob==1)
      {
      liczbaprob=3; cin.clear(); // usuniecie flagi
      cin.ignore(numeric_limits<streamsize>::max(),'\n'); // usuniecie bufora
      break;}
      cerr<<"Blad formatu liczby zespolonej"<<endl; liczbaprob--;
      cout<<"Liczba pozostałych prob:"<<liczbaprob;
      cin.clear(); // usuniecie flagi
      cin.ignore(numeric_limits<streamsize>::max(),'\n'); // usuniecie bufora
      cout<<endl<<"Twoja odpowiedz:"; cin>>Arg1;
    }
    
    if (Arg1==Oblicz(WyrZ_PytanieTestowe)) // porównanie dwóch struktur z przeciążonym operatorem
    {
      cout<<"Odpowiedz poprawna."<<endl;
      lp++; // dodanie liczby poprawnych odpowiedzi
    }
    else 
    {
      cout<<"Blad. Prawidlowym wynikiem jest:"<<Oblicz(WyrZ_PytanieTestowe)<<endl;
      ln++; // dodanie liczby blednych odpowiedzi
    }
    
  }

  
  cout <<endl;
  cout <<"Koniec testu" << endl;
  cout<<"Liczba dobrych odpowiedzi:"<<lp<<endl;
  cout<<"Liczba blednych odpowiedzi:"<<ln<<endl;
  cout<<"Wynik procentowy poprawnych odpowiedzi:"<< ((lp/(ln+lp))*100)<<"%"<<endl;

  
  cout << endl;

}

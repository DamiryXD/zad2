#include <iostream>
#include <fstream>
#include "LZespolona.hh"
#include <cmath>
#include <string.h>



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator+(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

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
 *    Różnice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator-(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia,
 *    Skl2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Sume iloczyn skladnikow przekazanych jako parametry.
 */
LZespolona operator*(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
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
LZespolona operator/(LZespolona Skl1, LZespolona Skl2) // do dokonczenia
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re - Skl1.im * Skl2.im) / sqrt(Skl2.re * Skl2.re + Skl2.im * Skl2.im); // minus ponieważ i^2= -1
  Wynik.im = (Skl1.re * Skl2.im + Skl1.im * Skl2.re) / sqrt(Skl2.re * Skl2.re + Skl2.im * Skl2.im);
  return Wynik;
}
/*!
 * Realizuje wczytanie liczby zespolonej.
 * Argumenty:
 *    StrWe - strumien wejscia,
 *    &Lz - Struktura danych typi Liczba zespolona przechowująca część rzeczywistą i urojoną liczby zespolonej.
 * Zwraca:
 *  Strumien wejscia.
 */
std::istream &operator>>(std::istream &StrWe, LZespolona &Lz)
{
  char LewyNawias,PrawyNawias,CzescUrojona;
  StrWe >> LewyNawias;
  StrWe >> Lz.re;
  StrWe >> Lz.im;
  StrWe >> CzescUrojona;
  StrWe >> PrawyNawias;
  //printf("Lz.re: %f, Lz.im: %f, LewyNawias: %c,PrawyNawias: %c,Czesc Urojona:%c",Lz.re,Lz.im,LewyNawias,PrawyNawias,CzescUrojona);
  if (LewyNawias!='(' || PrawyNawias!=')' || CzescUrojona!='i')
  {
    StrWe.setstate(std::istream::badbit);
  }
  return StrWe;
}
/*!
 * Realizuje wyświetlenie liczby zespolonej.
 * Argumenty:
 *    StrWy - strumien wyjscia ,
 *    &Lz - Struktura danych typi Liczba zespolona przechowująca część rzeczywistą i urojoną liczby zespolonej.
 * Zwraca:
 *   Strumien wyjscia.
 */
std::ostream &operator<<(std::ostream &StrWy, const LZespolona &Lz)
{
  return StrWy << Lz.re << std::showpos << Lz.im << std::noshowpos << 'i';
}

std::istream &operator >> (std::istream &StrmWe,Operator & WczytSym)
{
  Operator TabTypOp[] = {Op_Dodaj,Op_Odejmij,};
  const char TabSymOp[] = "+-", *wSymOP;
  wSymOP=(const char*)malloc(sizeof(const char));
  char CzytSymOp = 'x';
  StrmWe >> CzytSymOp;
  if ((wSymOP = strchr(wSymOP, CzytSymOp)) == nullptr)
  {
    StrmWe.setstate(std::ios::failbit);
  }
  else
  {
    WczytSym = TabTypOp[wSymOP - TabSymOp];
  }
  return StrmWe;
}
/*!
 * Realizuje porowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Arg1 - pierwsza liczba zespolona
 *    Arg2 - druga liczba zespolona
 * Zwraca:
 *   Wartość Prawda bądź Fałsz w zależności czy struktury są sobie równe.
 */
bool operator == (LZespolona Arg1, LZespolona Arg2)
{
  if (Arg1.re==Arg2.re && Arg1.im== Arg2.im) return true;
  else return false;
}
/*!
 * Realizuje porowanie liczby zespolonej z calkowita
 * Argumenty:
 *    Arg1 - liczba zespolona
 *    i    - liczba calkowita
 * Zwraca:
 *   Wartość Prawda bądź Fałsz w zależności czy dane liczby są sobie równe.
 */
bool operator == (LZespolona Arg1,int i)
{
  if (Arg1.re == i && Arg1.im == i) return true;
  else return false;
}


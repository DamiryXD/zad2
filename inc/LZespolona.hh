#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH


/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel};

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
std::istream & operator >> (std::istream & StrWe,LZespolona& Lz);
std::ostream & operator << (std::ostream & StrWy,const LZespolona &Lz);
std::istream & operator >> (std::istream &StrmWe,Operator &WczytSym);
bool operator == (LZespolona Arg1, LZespolona Arg2);
bool operator == (LZespolona Arg1,int i);






#endif

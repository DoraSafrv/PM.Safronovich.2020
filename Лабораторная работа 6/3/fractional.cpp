
#include "fractional.h"
void read(Fractional& fractional, std::istream& ist) {
    ist >> fractional.numerator >> fractional.denominator;
}

void write(const Fractional& fractional, std::ostream& ost) {
    ost << fractional.numerator << "/" << fractional.denominator;
}

Fractional Fractional::operator+(const Fractional& rhs) {
    int a = this->numerator,
        b = this->denominator,
        c = rhs.numerator,
        d = rhs.denominator;

    Fractional result(a * d + b * c, b * d);
    return result;
}

Fractional Fractional::operator*(const Fractional& rhs) {
    int a = this->numerator,
        b = this->denominator,
        c = rhs.numerator,
        d = rhs.denominator;

    Fractional result(a * c, b * d);
    return result;
}
Fractional Fractional::operator-(const Fractional& rhs) {
    int a = this->numerator,
        b = this->denominator,
        c = rhs.numerator,
        d = rhs.denominator;

    Fractional result(a * d - b * c, b * d);
    return result;
}
Fractional Fractional::operator/(const Fractional& rhs) {
    int a = this->numerator,
        b = this->denominator,
        c = rhs.numerator,
        d = rhs.denominator;

    Fractional result(a*d,b*c);
    return result;
}
Fractional Fractional::operator=(const Fractional& rhs)
 {
    this->denominator = rhs.denominator;
    this->numerator = rhs.numerator;
    return *this;
}
  bool Fractional::operator<(const Fractional& rhs) {
    int a = this->numerator,
        b = this->denominator,
        c = rhs.numerator,
        d = rhs.denominator;
       int chis = a * d - b*c;
       int znam = b*d;
       if ((chis < 0 || znam < 0) && (chis*znam<0)) 
       return true;
       return false;
}
  bool Fractional::operator>(const Fractional& rhs) {
      int a = this->numerator,
          b = this->denominator,
          c = rhs.numerator,
          d = rhs.denominator;
      int chis = a * d - b * c;
      int znam = b * d;
      if ((chis > 0 && znam > 0) || (chis*znam>0))
          return true;
      return false;

  }
  bool Fractional::operator==(const Fractional& rhs) {
      int a = this->numerator,
          b = this->denominator,
          c = rhs.numerator,
          d = rhs.denominator;
      int chis = a * d - b * c;
      int znam = b * d;
      if (chis==0)
          return true;
      return false;

  }
 /* Fractional* Fractional::a(Fractional& rhs)
  {
      return nullptr;
  }*/
  Fractional::Fractional()
      : numerator(0), denominator(1) {
  };

Fractional::Fractional(int _num, int _den)
    : numerator(_num), denominator(_den) {
};
void Fractional:: a(Fractional *a,int n)
{
 for (int i = 0; i < n ; i++)
 {
     if (i == n) break;
     if ((i+1) % 2 == 0) a[i] = a[i] + a[i+1];
   
 }
}
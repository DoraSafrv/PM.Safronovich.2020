#ifndef FRACTIONAL_H // если имя FRACTIONAL_H ещё не определено
#define FRACTIONAL_H // определить имя FRACTIONAL_H
#include <iostream>
class Fractional {
public:
  friend void read(Fractional& data, std::istream& ist);
  friend void write(const Fractional& data, std::ostream& ost);

  Fractional();
  Fractional(int _num, int _den);

  Fractional operator+(const Fractional& rhs);
  Fractional operator*(const Fractional& rhs);
  Fractional operator-(const Fractional& rhs);
  Fractional operator/(const Fractional& rhs);
  Fractional operator=(const Fractional& rhs);
  bool operator<(const Fractional& rhs);
  bool operator>(const Fractional& rhs);
  bool operator==(const Fractional& rhs);
  void a(Fractional *a, int n);
protected:
  int numerator, denominator;
};

#endif // если  имя FRACTIONAL_H уже определено, повторно не определять

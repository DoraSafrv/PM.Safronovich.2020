#ifndef FRACTIONAL_H // ���� ��� FRACTIONAL_H ��� �� ����������
#define FRACTIONAL_H // ���������� ��� FRACTIONAL_H
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

#endif // ����  ��� FRACTIONAL_H ��� ����������, �������� �� ����������

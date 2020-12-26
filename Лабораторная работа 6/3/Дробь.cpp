/* 2. Определить класс «Дробь» – Fraction в виде пары (m,n) . 

Класс должен содержать несколько конструкторов. 

Реализовать методы для сложения, вычитания, умножения и деления дробей. 

Перегрузить операции сложения, вычитания, умножения, деления,
присваивания и операции отношения. 

Создать массив объектов и передать его в функцию,
которая изменяет каждый элемент массива с четным индексом
путем добавления следующего за ним элемента массива.
*/


#include <iostream>
using namespace std;

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
    void a(Fractional* a, int n);
protected:
    int numerator, denominator;
};

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

    Fractional result(a * d, b * c);
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
    int chis = a * d - b * c;
    int znam = b * d;
    if ((chis < 0 || znam < 0) && (chis * znam < 0))
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
    if ((chis > 0 && znam > 0) || (chis * znam > 0))
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
    if (chis == 0)
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
void Fractional::a(Fractional* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n) break;
        if ((i + 1) % 2 == 0) a[i] = a[i] + a[i + 1];

    }
}

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "rus");
    Fractional a(1, 2), b(4, 3), c, d;
   
    cout << "Сложение дробей 1 " << endl;
    write(a + b, std::cout);
    std::cout << std::endl;
    cout << endl;

    cout << "Сложение дробей 2 " << endl;
    cout << "введите числитель и знаменатель первой дроби" << endl;
    read(c, std::cin);
    cout << "введите числитель и знаменатель второй дроби" << endl;
    read(d, std::cin);
    write(c + d, std::cout); cout << endl;

    cout << "Умножение дробей 1" << endl; 
    write(a * b, std::cout);
    std::cout << std::endl;
    cout << endl;

    cout<< "Умножение дробей 2" << endl;
    cout << "введите числитель и знаменатель первой дроби" << endl;
    read(c, std::cin);
    cout << "введите числитель и знаменатель второй дроби" << endl;
    read(d, std::cin);
    write(c * d, std::cout);
    std::cout << std::endl;
    cout << endl;

    cout << "Вычитание дробей 1 " << endl;
    write(a - b, std::cout);
    std::cout << std::endl;
    cout << endl;
    cout<< "Вычитание дробей 2 " << endl;
    cout << "введите числитель и знаменатель первой дроби" << endl;
    read(c, std::cin);
    cout << "введите числитель и знаменатель второй дроби" << endl;
    read(d, std::cin);
    write(c - d, std::cout);
    std::cout << std::endl;
    cout << endl;

    cout << "деление  дробей 1 " << endl;
    write(a / b, std::cout);
    std::cout << std::endl;
    cout << endl;

    cout << "Деление дробей 2" << endl;
    cout << "введите числитель и знаменатель первой дроби" << endl;
    read(c, std::cin);
    cout << "введите числитель и знаменатель второй дроби" << endl;
    read(d, std::cin);
    write(c / d, std::cout);
    std::cout << std::endl;
    cout << endl;

    cout << "Присвание дроби 1 " << endl;
    write(a = b, std::cout);
    std::cout << std::endl;
    cout << endl;

    cout << "Присвание дроби 2 " << endl;
    cout<<"введите числитель и знаменатель первой дроби" << endl;
    read(c, std::cin);
    cout << "введите числитель и знаменатель второй дроби" << endl;
    read(d, std::cin); cout <<"результат"<<endl;
    write(c=d, std::cout);
    std::cout << std::endl;
    cout << endl;

    cout << "Cравнение  дробей" << endl
    << "введите числитель и знаменатель первой дроби" << endl;
    read(c, std::cin);
    cout<< "введите числитель и знаменатель второй дроби" << endl;
    read(d, std::cin);
    if (c < d) cout << "первая дробь меньше второй"<<endl;
    else if (c > d) cout << "первая дробь больше второй"<<endl;
    else if (c == d) cout << "первая дробь равна второй"<<endl;
    cout << endl;

    cout << "Количество дробей в массиве: ";
    int n;
    cin >> n;
    cout << "Массив дробей" << endl;
    Fractional* A = new Fractional[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Введите числитель и знаменатель" << endl;
        read(c, std::cin);
        A[i] = c;
    }
    for (int i = 0; i < n - 1; i++) {
        if ((i + 1) % 2 == 0) {
            A[i] = A[i] + A[i + 1];
        }
    }
   for (int i = 0; i < n; i++)
   {
     write(A[i], std::cout);
     cout << ' ';
   }
}

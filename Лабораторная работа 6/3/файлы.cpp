#include <iostream>
#include <fstream>
using namespace std;

class Fraction
{
private:
    int chis;
    int znam;
public:
    Fraction() { chis = 0; znam = 0; }
    Fraction(int c, int z) { chis = c; znam = z; }
    Fraction(const Fraction& ob);  // ����������� �����
    void Enter();
    void Show(std::ostream&);
    Fraction operator = (Fraction);
    Fraction operator + (Fraction);
    Fraction operator - (Fraction);
    Fraction operator * (Fraction);
    Fraction operator / (Fraction);
    bool operator != (Fraction);
    bool operator > (Fraction);
    bool operator < (Fraction);
    bool operator == (Fraction);
    int NOD(Fraction);   // ���������� ����� ��������
    int NOD_int(int, int); // ��� ��� ������������� � ������ ��������
    int NOK_int(int, int); // ��� ��� �������
    int NOK(Fraction); // ���������� ����� �������
    friend std::istream& operator >> (std::istream&, Fraction&);
    friend std::ostream& operator << (std::ostream&, Fraction&);
};

std::istream& operator >>(std::istream& infile, Fraction& f2)
{
    infile >> f2.chis >> f2.znam;
    return infile;

}

std::ostream& operator << (std::ostream& onfile, Fraction& f2)
{
    onfile << f2.chis << "/" << f2.znam << std::endl;
    return onfile;
}

bool Fraction::operator !=(Fraction f2) // ���������� �� �����
{
    int z = NOK_int(this->znam, f2.znam); // ������� ���
    this->chis = this->chis * (z / this->znam); // �������� ���������
    f2.chis = f2.chis * (z / f2.znam);  // �������� �����������
    if (this->chis != f2.chis) // ���� ����������� �� �����
        return 1;
    else
        return 0;

}

bool Fraction::operator == (Fraction f2)
{
    if (this->znam == f2.znam && this->chis == f2.chis) // ���� ����������� � ��������� �����, �� � ����� �����
        return 1;
    else
    {
        int z = NOK_int(this->znam, f2.znam); //������� ���
        this->chis = this->chis * (z / this->znam);
        f2.chis = f2.chis * (z / f2.znam);
        if (this->chis == f2.chis) // ���� ��������� �����
            return 1;
        else
            return 0;
    }

    return 0;
}

bool Fraction::operator<(Fraction f2)
{

    if (this->znam != f2.znam && this->chis != f2.chis) // ���� ������ ����������� � ���������
    {
        int z = NOK_int(this->znam, f2.znam); // ���
        this->chis = this->chis * (z / this->znam); // �������� � ������ �����������
        f2.chis = f2.chis * (z / f2.znam);
        if (this->chis < f2.chis)
            return 1;
        else
            return 0;
    }

    if (this->znam == f2.znam) // ���� � ������ ���������� �����������
    {
        if (this->chis < f2.chis)
            return 1;
        else
            return 0;
    }
    if (this->chis == f2.chis) // ���� ���������� ���������
    {
        if (this->znam < f2.znam)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

bool Fraction::operator>(Fraction f2)
{

    if (this->znam != f2.znam && this->chis != f2.chis)
    {
        int z = NOK_int(this->znam, f2.znam);
        this->chis = this->chis * (z / this->znam);
        f2.znam = f2.znam * (z / f2.znam);
        if (this->chis > f2.chis)
            return 1;
        else
            return 0;
    }

    if (this->znam == f2.znam)
    {
        if (this->chis > f2.chis)
            return 1;
        else
            return 0;
    }
    if (this->chis == f2.chis)
    {
        if (this->znam < f2.znam)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}


Fraction Fraction ::operator*(Fraction f2) // ��������� ��������� �� ���������, �����������
{                                          // �� �����������
    this->chis = this->chis * f2.chis;
    this->znam = this->znam * f2.znam;
    return *this;

}

Fraction Fraction ::operator / (Fraction f2) // �������
{
    this->chis = this->chis * f2.znam; // ��������� ������ �� ����������� ������
    this->znam = this->znam * f2.chis; // ����������� ������ �� ��������� ������
    return *this;
}

Fraction Fraction::operator+(Fraction f2)
{
    int z = NOK_int(this->znam, f2.znam); // ���
    this->chis = this->chis * (z / this->znam);
    f2.chis = f2.chis * (z / f2.znam);
    this->chis = this->chis + f2.chis;
    this->znam = z;
    return *this;
}

Fraction Fraction::operator - (Fraction f2)
{
    int z = NOK_int(this->znam, f2.znam);
    this->chis = this->chis * (z / this->znam);
    f2.chis = f2.chis * (z / f2.znam);
    this->chis = this->chis - f2.chis;
    this->znam = z;
    return *this;
}

Fraction Fraction:: operator = (Fraction f2)
{
    this->chis = f2.chis;
    this->znam = f2.znam;
    return *this;
}

int Fraction::NOD_int(int x, int y) // ������� �������� �� ���������� ���
{
    while (x && y)
        if (x >= y)
            x %= y;
        else
            y %= x;
    return x | y;
}

int Fraction::NOD(Fraction f2)
{
    while (this->znam && f2.znam)
        if (this->znam >= f2.znam)
            this->znam %= f2.znam;
        else
            f2.znam %= this->znam;
    return this->znam | f2.znam;
}

int Fraction::NOK(Fraction f2)
{
    return this->znam / NOD_int(this->znam, f2.znam) * f2.znam;

}

int Fraction::NOK_int(int x, int y)
{
    return x / NOD_int(x, y) * y;
}

Fraction::Fraction(const Fraction& ob) // ����������� �����
{
    this->chis = ob.chis;
    this->znam = ob.znam;
}

void Fraction::Enter() // ���� ������ 
{
    std::cout << "������� ��������� ����� " << std::endl;
    std::cin >> chis;
    std::cout << "������� ����������� " << std::endl;
    std::cin >> znam;
}

void Fraction::Show(std::ostream& out) // �����
{
    out << chis << "/" << znam << " ";
}

int main()
{
    system("chcp 1251");
    Fraction f1;
    int m, n;
    int size;

    Fraction* frac;
    try {
        std::ifstream in;
        in.open("in.txt");
        if (!in.is_open()) {
            throw std::exception("���� �� ������.\n");
        }
        std::ofstream out;
        out.open("result.txt");
        if (!out.is_open()) {
            throw std::exception("���� �� ������.\n");
        }
        //cout << "���������� ������: ";
        in >> size;
        if (size <= 0) {
            throw std::exception("����������� ����������\n");
        }
        frac = new Fraction[size];

        for (int i = 0; i < size; i++)
        {
            in >> frac[i];
        }

        for (int i = 0; i < size; i++)
        {
            frac[i].Show(cout);
            frac[i].Show(out);

            cout << ";  ";
            out << ";  ";
        }
        cout << "\n�����: ";
        out << "\n�����: ";
        for (int i = 1; i < size; i += 2)
        {
            if (i != size - 1)
            {
                frac[i] = frac[i] + frac[i + 1];
            }
        }
        cout << endl;
        out << endl;

        for (int i = 0; i < size; i++)
        {
            frac[i].Show(cout);
            frac[i].Show(out);
            cout << ";   ";
            out << ";   ";
        }
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
 
    return (0);
}
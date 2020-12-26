#include <iostream>
#include <string.h>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;


class abiturient
{
	string lastname, name, otch, adr;
	int marks[5];
	int sum;
	
public:
	abiturient();
	void setname(string a)
	{
		name = a;
	};
	void setlastname(string a)
	{
		lastname = a;
	};
	void setotch(string a)
	{
		otch = a;
	};
	void setadr(string a) {
		adr = a;
	};
	void setmarks(int* a)
	{
		sum = 0;
		for (int i = 0; i < 5; i++)
		{
			this->marks[i] = a[i];
			sum += marks[i];
		}
	};
	int* getmarks()
	{
		return marks;
	};
	int getsum()
	{
		return sum;
	}
	void show(std::ostream& out) // ��� ��������� �������� �� ������� � � ����
	{
		out << "���: " << lastname << " " << name << " " << otch << endl;
	};
	friend istream& operator>>(istream& in, abiturient& data) {
		in >> data.name >> data.otch >> data.lastname;
		in.get();
		getline(in, data.adr);
		data.sum = 0;
		for (int i = 0; i < 5; i++) {
			in >> data.marks[i];
			data.sum += data.marks[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, abiturient& data) {
		out << "���: " << data.lastname << " " << data.name << " " << data.otch << endl;
		out << "������: ";
		for (int i = 0; i < 5; i++) {
			out<< data.marks[i]<<" ";
		}
		out << ", �����: " << data.sum;
	}
};




abiturient::abiturient()
{
	int sum = 0;
	lastname = " ";
	name = " ";
	otch = " ";
	adr = " ";
}



int main()
{
	try {
		system("chcp 1251");
		setlocale(LC_ALL, "rus");
		int n, s = 0;
		std::ifstream in; // ��� ��� ������ �� �����
		in.open("in.txt");
		if (!in.is_open()) {
			throw std::exception("���� �� ������.\n");
		}
		std::ofstream out; // ��� ��� ����� � ����, ���� ��� ����� ��������� �������������
		out.open("result.txt");
		if (!out.is_open()) {
			throw std::exception("���� �� ������.\n");
		}

		//cout << "������� ���-�� ������������: ";
		in >> n; // ���������� � ����� � ������ ������
		while (n < 0)
		{
			cout << "������ ������� �����������\n";
			cout << "������� ���-�� ������������: ";
			cin >> n;
		}

		abiturient* a = new abiturient[n];

		string lastname, name, otch, adr;
		int marks[5];
		for (int i = 0; i < n; i++) // ���� �� �����
		{
			in >> a[i];
		}
		int deterbal;
		cout << "������� �������� ����� ������: ";
		cin >> deterbal;
		while (deterbal < 1)
		{
			cout << "������ ������� �����������\n";
			cout << "������� �������� ����� ������: ";
			cin >> deterbal;
		}

		int polr;
		cout << "������� ������������� ����: ";
		cin >> polr;
		while (polr < 1)
		{
			cout << "������ ������� �����������\n";
			cout << "������� ������������� ����: ";
			cin >> polr;
		}

		int N;
		cout << "������� ���-�� ������������ � ����� ������� ������:";
		cin >> N;
		while (N < 1)
		{
			cout << "������ ������� �����������\n";
			cout << "������� ���-�� ������������ � ����� ������� ������:";
			cin >> N;
		}
		cout << endl;

		cout << "������ ������������ � ����. ��������:" << endl;
		out << "������ ������������ � ����. ��������:" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (a[i].getmarks()[j] < 5)
				{
					a[i].show(cout);
					a[i].show(out);
					break;
				}

			}

		}
		cout << endl;
		out << endl;

		cout << "������ ������������, ����� ������ � ������� ������ ��������: " << endl;
		out << "������ ������������, ����� ������ � ������� ������ ��������: " << endl;

		for (int i = 0; i < n; i++)
		{
			if (a[i].getsum() < deterbal)
			{
				a[i].show(cout);
				a[i].show(out);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (a[j].getsum() < a[j + 1].getsum())
				{
					abiturient sum2;
					sum2 = a[j];
					a[j] = a[j + 1];
					a[j + 1] = sum2;
				}
			}
		}
		cout << endl;
		out << endl;

		cout << "������ N ������������ ������� ����� ������� ����:\n";
		out << "������ N ������������ ������� ����� ������� ����:\n";
		for (int i = 0; i < N; i++)
		{
			a[i].show(cout);
			a[i].show(out);
		}
		cout << endl;
		out << endl;

		cout << "������ ������������ � ������������� ������:\n";
		out << "������ ������������ � ������������� ������:\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				s += a[i].getmarks()[j];
			}
			if (s > polr) {
				a[i].show(cout);
				a[i].show(out);
			}
			s = 0;
		}
	}
	catch (std::exception& e) {
		cout << e.what();
	}
	
	system("pause");
	return (0);
}
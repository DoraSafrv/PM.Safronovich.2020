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
	void show(std::ostream& out) // это позволяет выводить на консоль и в файл
	{
		out << "ФИО: " << lastname << " " << name << " " << otch << endl;
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
		out << "ФИО: " << data.lastname << " " << data.name << " " << data.otch << endl;
		out << "Оценки: ";
		for (int i = 0; i < 5; i++) {
			out<< data.marks[i]<<" ";
		}
		out << ", сумма: " << data.sum;
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
		std::ifstream in; // это для вывода из файла
		in.open("in.txt");
		if (!in.is_open()) {
			throw std::exception("Файл не открыт.\n");
		}
		std::ofstream out; // это для ввода в файл, файл для ввода создается автоматически
		out.open("result.txt");
		if (!out.is_open()) {
			throw std::exception("Файл не открыт.\n");
		}

		//cout << "Введите кол-во абитуриентов: ";
		in >> n; // количество в файле в первой строке
		while (n < 0)
		{
			cout << "данные введены некорректно\n";
			cout << "Введите кол-во абитуриентов: ";
			cin >> n;
		}

		abiturient* a = new abiturient[n];

		string lastname, name, otch, adr;
		int marks[5];
		for (int i = 0; i < n; i++) // ввод из файла
		{
			in >> a[i];
		}
		int deterbal;
		cout << "Введите заданное число баллов: ";
		cin >> deterbal;
		while (deterbal < 1)
		{
			cout << "данные введены некорректно\n";
			cout << "Введите заданное число баллов: ";
			cin >> deterbal;
		}

		int polr;
		cout << "Введите полупроходной балл: ";
		cin >> polr;
		while (polr < 1)
		{
			cout << "данные введены некорректно\n";
			cout << "Введите полупроходной балл: ";
			cin >> polr;
		}

		int N;
		cout << "Введите кол-во абитуриентов с самым высоким баллом:";
		cin >> N;
		while (N < 1)
		{
			cout << "данные введены некорректно\n";
			cout << "Введите кол-во абитуриентов с самым высоким баллом:";
			cin >> N;
		}
		cout << endl;

		cout << "Список абитуриентов с неуд. оценками:" << endl;
		out << "Список абитуриентов с неуд. оценками:" << endl;
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

		cout << "список абитуриентов, сумма баллов у которых меньше заданной: " << endl;
		out << "список абитуриентов, сумма баллов у которых меньше заданной: " << endl;

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

		cout << "список N абитуриентов имеющих самый высокий балл:\n";
		out << "список N абитуриентов имеющих самый высокий балл:\n";
		for (int i = 0; i < N; i++)
		{
			a[i].show(cout);
			a[i].show(out);
		}
		cout << endl;
		out << endl;

		cout << "список абитуриентов с полупроходным баллом:\n";
		out << "список абитуриентов с полупроходным баллом:\n";
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
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <string>
using namespace std;
class abiturient
{
	string fam, ima, otch, adres;
	int marks[5] ;
	int sum;
	bool f ;
public:
	
	abiturient();
	void setima(string a);
	void setfam(string a);
	void setotch(string a);
	void setadres(string a);
	void setozenki(int* a);
	void setf(bool a);
	
	bool getf();
	int* getozenki();
	int getsum();

	void show();

};
abiturient::abiturient()
{  
	int sum=0;
    bool f=true;
	fam = " ";
	ima = " ";
	otch = " ";
	adres = " ";
}
void abiturient::setfam(string a)
{
	fam = a;
}
void abiturient::setima(string a)
{  /* int n=ima.size();
    cin.getline(ima,n);
	std::cin.get();
	getline(std::cin, ima);
	if (ima == "") {
		std::cout << "\n������� ������ ���!\n";
	}*/
	ima = a;
}
void abiturient::setotch(string a)
{
	otch = a;
}
void abiturient::setadres(string a)
{
	adres = a;
}
void abiturient::setozenki(int* a)
{
	sum=0;
	for (int i = 0; i < 5; i++)
	{
		this->marks[i] = a[i];
		sum += marks[i];
	}
}
int* abiturient::getozenki()
{
	return marks;
}
void abiturient::show()
{
	cout << "���: " << fam << " " << ima << " " << otch << endl;
}
void abiturient::setf(bool a)
{
	f = a;
}
bool abiturient::getf()
{
	return f;
}
int abiturient::getsum()
{
	return sum;
}


int main()
{    system("chcp 1251");
	setlocale(LC_ALL, "rus");
	int n,s=0;
	bool prNeyd=false;
	bool prPoly=false;

	cout << "������� ���-�� ������������: ";
	cin >> n;
	while (n < 0)
	{
		cout << "������ ������� �����������\n";
		cout << "������� ���-�� ������������: ";
		cin >> n;
	}
	abiturient* a = new abiturient[n];
	
	string fam, ima, otch, adres;
	int marks[5];
	for (int i = 0; i < n; i++)
	{
		cout << "������� ������ ��� " << i + 1 << "-�� �����������:\n";
		cout << "���: ";
		cin >> ima;
		a[i].setima(ima);
		cout << "�������: ";
		cin >> fam;
		a[i].setfam(fam);
		cout << "��������: ";
		cin >> otch;
		a[i].setotch(otch);

		cout << "������:";
		cin >> adres;
		a[i].setadres(adres);
		cout << "������� 5 ������:";
		for (int j = 0; j < 5; j++)
		{
			cin >> marks[j];
			while (marks[j] < 1)
			{
				cout << "������ ������� �����������\n";
				cin >> marks[j];
			}
		}
		a[i].setozenki(marks);
		cout << endl;
	}
	/*cout<<" �����������"<<endl;
	for(int i=0;i<n;i++)
	{
	a[i].show();
	}*/

	int zadb;
	cout << "������� �������� ����� ������: ";
	cin >> zadb;
	while (zadb < 1)
	{
		cout << "������ ������� �����������\n";
		cout << "������� �������� ����� ������: ";
		cin >> zadb;
	}

	int polypr;
	cout << "������� ������������� ����: ";
	cin >> polypr;
	while (polypr < 1)
	{
		cout << "������ ������� �����������\n";
		cout << "������� ������������� ����: ";
		cin >> polypr;
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
	cout << "������ ������������ � ���� ��������:"<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[i].getozenki()[j] < 5)
			{
				a[i].setf(false);
			}
		}
		if (a[i].getf ()== false)
		{
			a[i].show();
			prNeyd=true;
		}
		 
	}

	if(!prNeyd) cout<<"��� ����� �������������"<<endl;
	cout << "������ ������������, ����� ������ � ������� ������ �������� "<<endl;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i].getsum() < zadb)
		{
			a[i].show();
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (a[j].getsum() < a[j+1].getsum())
			{
				abiturient per;
				per = a[j];
				a[j] = a[j + 1];
				a[j + 1] = per;
			}
		}
	}
	

	cout << "������ N ������������ ������� ����� ������� ����:\n";
	for (int i = 0; i < N; i++)
	{
		a[i].show();
	}
	cout << "������ ������������ � ������������� ������:\n";
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < 5; j++)
		{ s+=a[i].getozenki()[j];}
		if(s==polypr){a[i].show() ;prPoly=true;}
		s=0;	
   }
	if (!prPoly) cout<<"����� ������������ ���"<<endl;
	system ("pause");
}
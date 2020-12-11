#include <io.h>
#include <fstream>
#include "Abiturient.h"

int initLength();
Abiturient* createArray(int);
void initFromConsole(int, Abiturient*);
void clearMemory(Abiturient*);

void InitFile(ofstream&, Abiturient*, int);
void AddToEndFile(ofstream&, Abiturient*, int);
void SystemFun();
void InitNameFile(char*);
int Menu();
template <typename stream>
void validStream(stream&);

void badMarks(Abiturient*, int);
void swapObjects(Abiturient&, Abiturient&);
void sumOfMarks(Abiturient*, int, int);
void abiturientsWithGoodMarks(Abiturient*, int, int);
void quickSort(int, Abiturient*);
void readFromFile(ifstream&, Abiturient*, int);

const int N = 256;

int main()
{
	try
	{
		char fileName[N] = "Abiturient.txt";
		enum { Init = 1, Create, Add, Read, Enter, BadMarks, Sum, GoodMarks, Exit };
		int n = initLength();
		Abiturient* abiturients = createArray(n);
		while (true)
		{
			int Key = Menu();
			if (Key == Exit)
			{
				clearMemory(abiturients);
				n = 0;
				return 0;
			}
			system("cls");
			switch (Key)
			{
			case Init:
			{
				InitNameFile(fileName);
				SystemFun();
				break;
			}
			case Create:
			{
				ofstream out(fileName);
				InitFile(out, abiturients, n);
				validStream(out);
				out.close();
				SystemFun();
				break;
			}
			case Add:
			{
				ofstream add(fileName, ios::app);
				AddToEndFile(add, abiturients, n);
				validStream(add);
				add.close();
				SystemFun();
				break;
			}
			case Read:
			{
				ifstream in(fileName);
				readFromFile(in, abiturients, n);
				break;
			}
			case Enter:
			{
				initFromConsole(n, abiturients);
				break;
			}
			case BadMarks:
			{
				badMarks(abiturients, n);
				break;
			}
			case Sum:
			{
				int marks;
				cout << "Enter compareble sum of marks: ";
				cin >> marks;
				sumOfMarks(abiturients, n, marks);
				break;
			}
			case GoodMarks:
			{
				int quontity;
				cout << "Enter qountity of abiturients with the most good marks: ";
				cin >> quontity;
				abiturientsWithGoodMarks(abiturients, n, quontity);
				break;
			}
			default:
				clearMemory(abiturients);
				n = 0;
				cout << "\nIncorrect input! Try again!";
				SystemFun();
			}
		}
	}
	catch (const std::ios_base::failure& ex)
	{
		cout << ex.what() << endl;
	}
	catch (const std::out_of_range& ex)
	{
		cout << ex.what() << endl;
	}
	catch (const std::invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}
}

int initLength()
{
	int length;
	cout << "Enter number of abiturients: ";
	cin >> length;
	return length;
}

Abiturient* createArray(int length)
{
	if (length < 1)
		throw std::invalid_argument("Number of abiturients must be more zero.");
	Abiturient* abiturients = new Abiturient[length];
	return abiturients;
}

void initFromConsole(int n, Abiturient* abiturients)
{
	if (abiturients == nullptr)
		throw std::invalid_argument("Pointer to null.");
	if (n < 1)
		throw std::invalid_argument("Length of array must be more zero.");
	cout << "Init abiturients: " << endl;
	for (int i = 0; i < n; i++)
		abiturients[i].enterAbiturient();
}

void clearMemory(Abiturient* abiturients)
{
	if (abiturients != nullptr)
		delete[] abiturients;
}

void InitFile(ofstream& streamOut, Abiturient* abiturients, int n)
{
	if (!streamOut)
		throw std::ios_base::failure("File is not open.");

	int bufSize = sizeof(Abiturient);
	int i = 0;
	while (i < n)
	{
		streamOut.write((char*)&abiturients[i], bufSize);
		i++;
	}
}

void AddToEndFile(ofstream& streamOut, Abiturient* abiturients, int n)
{
	if (!streamOut)
		throw std::ios_base::failure("File is not open.");

	int bufSize = sizeof(Abiturient);
	int i = 0;
	while (i < n)
	{
		streamOut.write((char*)&abiturients[i], bufSize);
		i++;
	}
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with list of abiturients:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - ADD AN ELEMENT TO AND OF FILE"
		"\n 4 - INITIALIZATION FROM FILE"
		"\n 5 - INITIALIZATION FROM CONSOLE"
		"\n 6 - DISPLAYING ABITURIENTS ABITURIENTS WITH BAD MARKS"
		"\n 7 - DISPLAYING ABITURIENTS ACCORDING TO SUM OF MARKS"
		"\n 8 - DISPLAYING ABITURIENTS WITH GOOD MARKS"
		"\n 9 - EXIT\n";
	cin >> k;
	return k;
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

template<typename stream>
void validStream(stream& s)
{
	if (!s)
		throw std::ios_base::failure("File isn't open.");
	if (!s.good())
		throw std::runtime_error("There is some error with file.");
	cout << "End of file: " << s.eof() << endl;
	cout << "Flags failbit, badbit or hardfail: " << s.fail() << endl;
	cout << "Flags badbit and hardfail: " << s.bad() << endl;
	cout << "Code of error: " << s.rdstate() << endl;
}

void readFromFile(ifstream& streamIn, Abiturient* abiturients, int n)
{
	if (!streamIn)
		throw std::ios_base::failure("File is not open.");
	int bufSize = sizeof(Abiturient);
	for (int i = 0; i < n; i++)
	{
		while (streamIn.read((char*)&abiturients[i], bufSize))
			abiturients[i].showAbiturient();
	}
}

void badMarks(Abiturient* abiturients, int n)
{
	for (int i = 0; i < n; i++)
		if (abiturients[i].getMathMark() < 4 || abiturients[i].getLanguageMark() < 4 || abiturients[i].getPhysicsMark() < 4)
			abiturients[i].showAbiturient();
}

void sumOfMarks(Abiturient* abiturients, int n, int sum)
{
	for (int i = 0; i < n; i++)
		if (abiturients[i].sumOfMarks() >= sum)
			abiturients[i].showAbiturient();
}

void abiturientsWithGoodMarks(Abiturient* abiturients, int n, int quontity)
{
	quickSort(n, abiturients);
	for (int i = 0; i < quontity; i++)
	{
		abiturients[i].showAbiturient();
	}
}

void quickSort(int size, Abiturient* abiturients)
{
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
			if (abiturients[j].sumOfMarks() < abiturients[min].sumOfMarks())
				swapObjects(abiturients[j], abiturients[min]);
	}
}

void swapObjects(Abiturient& obj1, Abiturient& obj2)
{
	Abiturient& tmp = obj1;
	obj1 = obj2;
	obj2 = tmp;
}
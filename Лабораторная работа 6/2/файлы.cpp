#include <iostream> 
#include <fstream> 
#define MAX 100 //Максимальное число элементов стека

using namespace std;

class Stack {
private:

 int data[MAX];

public:

    int n;

    Stack() { // Конструктор по умолчанию
        n = 0;
    }

    ~Stack() {} //Деструктор

    int top() { //Функция извлечения элемента из вершины стека
        if (n == 0) {
            cout << "Error! The stack is empty!\n";
            return -1;
        }
        return data[n - 1];
    }

    void push(int item) { //Функция вставки элемента в стек
        if (n < MAX)
            data[n++] = item;
        else
            cout << "Error! The stack is full!\n";
    }

    void pop() { //Функция удаления элемента из стека
        if (n == 0)
            cout << "Error! The stack is empty!\n";
        else
            n--;
    }

    int size() { //Функция определения размера стека
        return n;
    }
    friend istream& operator>>(istream& in, Stack& data) {
        int size;
        in >> size;
        if (size <= 0 || size>MAX) {
            throw exception("Некорректный размер");
        }
        for (int i = 0; i < size; i++) {
            in >> data.data[i];
        }
        return in;
    }
};

int main() 
{

    system("chcp 1251");
    setlocale(LC_ALL, "rus");

    int n, m;
    Stack s1, s2, s3;
   
    try {
        std::ifstream in;
        in.open("in.txt");
        if (!in.is_open()) {
            throw std::exception("Файл не открыт.\n");
        }
        std::ofstream out;
        out.open("result.txt");
        if (!out.is_open()) {
            throw std::exception("Файл не открыт.\n");
        }
       /* cout << "Введите размер первого массива:\n";
        cout << "n = ";*/
        in >> n; //ввод размера из файла
        int* val = new int[n];
        //cout << "Введите первый массив:\n";
        cout << "Первый массив:\n";
        out << "Первый массив:\n";
        for (int i = 0; i < n; i++) {             //Добавляем элементы во второй стек
            in >> val[i]; //ввод элементов из файла
            if (val[i] < val[i - 1]) {
                cout << "Последовательность не является неубывающей!";
                exit(0);
            }
            cout << val[i] << " ";
            out << val[i] << " ";
            s1.push(val[i]);
        }
        cout << "\n";
        out << "\n";

       /* 
        cout << "Введите размер второго массива:\n";
        cout << "m = ";*/
        in >> m;
        int* val2 = new int[m];
        //cout << "Введите второй массив:\n";
        cout << "Второй массив:\n";
        out << "Второй массив:\n";
        for (int i = 0; i < m; i++) {             //Добавляем элементы во второй стек
            in >> val2[i];
            if (val2[i] < val2[i - 1]) {
                cout << "Последовательность не является неубывающей!";
                exit(0);
            }
            cout << val2[i] << " ";
            out << val2[i] << " ";
            s2.push(val2[i]);

        }
        cout << "\n";
        out << "\n";



        cout << endl;

        //Слияние двух стеков в один
        while ((s1.size() > 0) || (s2.size() > 0)) {
            if ((s1.size() > 0) && (s2.size() > 0)) {
                if (s1.top() < s2.top()) {
                    s3.push(s2.top());
                    s2.pop();
                }
                else {
                    s3.push(s1.top());
                    s1.pop();
                }
            }
            else if (s1.size() > 0) {
                s3.push(s1.top());
                s1.pop();
            }
            else {
                s3.push(s2.top());
                s2.pop();
            }
        }

        cout << "Вывод программы:\n";
        out << "Вывод программы:\n"; //вывод результата в файл
        while (s3.size()) {
            cout << s3.top() << " "; //Вывод содержимого третьего стека на экран 
            out << s3.top() << " "; //Вывод содержимого третьего стека в файл
            s3.pop();
        }
        cout << endl;
    }
    catch (exception& e) {
        cout << e.what();
    }
    system("pause");
   
}
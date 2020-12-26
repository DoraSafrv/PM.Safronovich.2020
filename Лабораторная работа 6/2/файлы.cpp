#include <iostream> 
#include <fstream> 
#define MAX 100 //������������ ����� ��������� �����

using namespace std;

class Stack {
private:

 int data[MAX];

public:

    int n;

    Stack() { // ����������� �� ���������
        n = 0;
    }

    ~Stack() {} //����������

    int top() { //������� ���������� �������� �� ������� �����
        if (n == 0) {
            cout << "Error! The stack is empty!\n";
            return -1;
        }
        return data[n - 1];
    }

    void push(int item) { //������� ������� �������� � ����
        if (n < MAX)
            data[n++] = item;
        else
            cout << "Error! The stack is full!\n";
    }

    void pop() { //������� �������� �������� �� �����
        if (n == 0)
            cout << "Error! The stack is empty!\n";
        else
            n--;
    }

    int size() { //������� ����������� ������� �����
        return n;
    }
    friend istream& operator>>(istream& in, Stack& data) {
        int size;
        in >> size;
        if (size <= 0 || size>MAX) {
            throw exception("������������ ������");
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
            throw std::exception("���� �� ������.\n");
        }
        std::ofstream out;
        out.open("result.txt");
        if (!out.is_open()) {
            throw std::exception("���� �� ������.\n");
        }
       /* cout << "������� ������ ������� �������:\n";
        cout << "n = ";*/
        in >> n; //���� ������� �� �����
        int* val = new int[n];
        //cout << "������� ������ ������:\n";
        cout << "������ ������:\n";
        out << "������ ������:\n";
        for (int i = 0; i < n; i++) {             //��������� �������� �� ������ ����
            in >> val[i]; //���� ��������� �� �����
            if (val[i] < val[i - 1]) {
                cout << "������������������ �� �������� �����������!";
                exit(0);
            }
            cout << val[i] << " ";
            out << val[i] << " ";
            s1.push(val[i]);
        }
        cout << "\n";
        out << "\n";

       /* 
        cout << "������� ������ ������� �������:\n";
        cout << "m = ";*/
        in >> m;
        int* val2 = new int[m];
        //cout << "������� ������ ������:\n";
        cout << "������ ������:\n";
        out << "������ ������:\n";
        for (int i = 0; i < m; i++) {             //��������� �������� �� ������ ����
            in >> val2[i];
            if (val2[i] < val2[i - 1]) {
                cout << "������������������ �� �������� �����������!";
                exit(0);
            }
            cout << val2[i] << " ";
            out << val2[i] << " ";
            s2.push(val2[i]);

        }
        cout << "\n";
        out << "\n";



        cout << endl;

        //������� ���� ������ � ����
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

        cout << "����� ���������:\n";
        out << "����� ���������:\n"; //����� ���������� � ����
        while (s3.size()) {
            cout << s3.top() << " "; //����� ����������� �������� ����� �� ����� 
            out << s3.top() << " "; //����� ����������� �������� ����� � ����
            s3.pop();
        }
        cout << endl;
    }
    catch (exception& e) {
        cout << e.what();
    }
    system("pause");
   
}
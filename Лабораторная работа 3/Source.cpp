#include <stdlib.h>
#include <iostream>
#include "stack.h"

using namespace std;

void fun(stack s1, stack s2) {
    stack tmp1, tmp2;
    int counter1 = 0;
    int counter2 = 0;

    while (!s1.isempty()) {  // ��������� �������� �� s1 � tmp1
        tmp1.push(s1.pop());
        counter1++; // counter1 - ���-�� ��������� � s1
    }
    while (!s2.isempty()) {  // ��������� ������ �� s1 � tmp1
        tmp2.push(s2.pop());
        counter2++;  // counter2 - ���-�� ��������� � s2
    }
    while (!tmp1.isempty()) { // ��������� �������� ������� � s1
        s1.push(tmp1.pop());
    }
    while (!tmp2.isempty()) { // ��������� �������� ������� � s2
        s2.push(tmp2.pop());
    }
    cout << "Number of elements in the first stack: " << counter1 << endl;
    cout << "Number of elements in the second stack: " << counter2 << endl;

    //�������� ������� pop(), push(), isempty()
}

void fun2(stack a, stack b) {
    stack c;
    while (!a.isempty() || !b.isempty()) {  //���� ����������� �� �������, ����� ���� �� ������ ����� ������
        char tmp1, tmp2;
        tmp1 = a.top();  // tmp1 - ������� ������� ����� a
        tmp2 = b.top();  // tmp2 - ������� ������� ����� b
        if (tmp1 <= tmp2 && tmp1 != -1 && tmp2 != -1) { // ������������������ ��������� tmp1 � tmp2, �������� �� ������������� �������� � ����� 
            c.push(tmp1); // ���������� � ���� c �������� �� a (���������� ��� ������� tmp1 >= tmp2)
            a.pop();  // �������� �������� �������� �� a
        }
        else {
            c.push(tmp2); // ���������� � ���� c �������� �� a (���������� ��� ������� tmp1 < tmp2)
            b.pop();  // �������� �������� �������� �� b
        }
    }
    while (!c.isempty()) { // ����� ��������� ����� c
        cout << c.pop();
    }
}

int main() {
    stack s1, s2;
    char a; 
    cout << "Number of elements in 1 stack \n";
    int num1;
    cin >> num1;
    cout << "cin stack \n";
    for (int i = 0; i < num1; i++) {
        cin >> a;
        s1.push(a);
    }
    cout << "Number of elements in 2 stack \n";
    int num2;
    cin >> num2;
    cout << "cin stack \n";
    for (int i = 0; i < num2; i++) {
        cin >> a;
        s2.push(a);
    }
    fun(s1, s2);
    while (!s1.isempty()) {
        cout << s1.pop() << " ";
    }
    cout << endl;
    while (!s2.isempty()) {
        cout << s2.pop() << " ";
    }
    return 0;
}

#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h> // ��� assert()

template <class T> // ��� ������ ������ � T ������ ������������ (�������������) ���� ������
class MyArray
{
private:
    int m_length;
    T* m_data;

public:
    MyArray()
    {
        m_length = 0;
        m_data = nullptr;
    }

    MyArray(int length)
    {
        m_data = new T[length];
        m_length = length;
    }

    ~MyArray()
    {
        //delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;
        // ����������� �������� nullptr ��� m_data, ����� �� ������ �� �������� ������� ���������!
        m_data = nullptr;
        m_length = 0;
    }


    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // ����� ������� ������ �������� ������������� ���������, ��� �� ������� �� ���� ��������� �������
    int getLength(); // ���������� ����� � ������ ������ getLength() ����
};

template <typename T> // �����, ������������ ��� ���� ������, ��������� � ����������� ����������� ������� ������
int MyArray<T>::getLength() { return m_length; } // �������� ��������, ��� ������ - Array<T>, � �� ������ Array

#endif
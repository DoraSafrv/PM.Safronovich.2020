#pragma once

#include <iostream>

using namespace std;

const int LENGTH = 256;
const int MINMARK = 0;
const int MAXMARK = 10;

class Abiturient
{
public:
	int getHouse() const;
	int getFlat() const;
	int getMathMark() const;
	int getLanguageMark() const;
	int getPhysicsMark() const;
	string getCountry() const;
	string getRegion() const;
	string getArea() const;
	string getCity() const;
	string getStreet() const;

	Abiturient() :house(1), flat(1), mathMark(MINMARK), languageMark(MINMARK), physicsMark(MINMARK), name(Name()), country("Undefined"), region("Undefined"), area("Undefined"), city("Undefined"), street("Undefined")
	{
	}
	Abiturient(int, int, int, int, int, string, string, string, string, string, string, string, string);
	void showAbiturient() const;
	void enterAbiturient();
	int sumOfMarks();

private:
	int house, flat, mathMark, languageMark, physicsMark;
	string country, region, area, city, street;

	class Name {
	public:
		Name()
		{
			setFirstName("Noname");
			setLastName("Noname");
			setPatronymic("Noname");
		}

		Name(const Name& other)
		{
			setFirstName(other.firstName);
			setLastName(other.lastName);
			setPatronymic(other.patronymic);
		}

		Name(char* firstName, char* lastName, char* patronimic) {
			setFirstName(firstName);
			setLastName(lastName);
			setPatronymic(patronimic);
		}

		Name(string firstName, string lastName, string patronimic)
		{
			setFirstName(firstName);
			setLastName(lastName);
			setPatronymic(patronimic);
		}

		string getFirstName() const
		{
			return firstName;
		}

		string getLastName() const
		{
			return lastName;
		}

		string getPatronymic() const
		{
			return patronymic;
		}

		void showName() const
		{
			if (firstName.empty())
				throw std::invalid_argument("It's possible to show empty string.");
			if (lastName.empty())
				throw std::invalid_argument("It's possible to show empty string.");
			if (patronymic.empty())
				throw std::invalid_argument("It's possible to show empty string.");
			cout << "First name: " << getFirstName() << endl;
			cout << "Last name: " << getLastName() << endl;
			cout << "Patronimic: " << getPatronymic() << endl;
		}

		Name& operator=(const Name& other)
		{
			setFirstName(other.firstName);
			setLastName(other.lastName);
			setPatronymic(other.patronymic);
			return *this;
		}

	private:
		string firstName;
		string lastName;
		string patronymic;

		inline void setFirstName(string firstName)
		{
			if (firstName.length() == 0)
				throw std::invalid_argument("Length of string must be more zero.");
			this->firstName = firstName;
		}

		inline void setLastName(string lastName)
		{
			if (lastName.length() == 0)
				throw std::invalid_argument("Length of string must be more zero.");
			this->lastName = lastName;
		}

		inline void setPatronymic(string patronymic)
		{
			if (patronymic.length() == 0)
				throw std::invalid_argument("Length of string must be more zero.");
			this->patronymic = patronymic;
		}


	};
	Name name;
	inline void setHouse(int);
	inline void setFlat(int);
	inline void setMathMark(int);
	inline void setLanguageMark(int);
	inline void setPhysicsMark(int);
	inline void setCountry(string);
	inline void setRegion(string);
	inline void setArea(string);
	inline void setCity(string);
	inline void setStreet(string);
	void setMarks(int, int, int);
};

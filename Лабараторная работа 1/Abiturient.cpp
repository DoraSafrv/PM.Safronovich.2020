#include "Abiturient.h"

void Abiturient::showAbiturient() const
{
	name.showName();
	cout << "Country: " << getCountry() << endl;
	cout << "Region: " << getRegion() << endl;
	cout << "Area: " << getArea() << endl;
	cout << "City: " << getCity() << endl;
	cout << "Street: " << getStreet() << endl;
	cout << "House: " << getHouse() << endl;
	cout << "Flat: " << getFlat() << endl;
	cout << "Mathematics mark: " << getMathMark() << endl;
	cout << "Physics mark: " << getLanguageMark() << endl;
	cout << "Language mark: " << getPhysicsMark() << endl;
}

void Abiturient::enterAbiturient()
{
	string firstName, lastName, patronimic, country, region, area, city, street;
	int house, flat, mathMark, languageMark, physicsMark;
	double salary;
	cout << "Enter the abiturient's first name: ";
	cin >> firstName;
	cout << "Enter the abiturient's last name: ";
	cin >> lastName;
	cout << "Enter the worker's patronimic: ";
	cin >> patronimic;
	name = Name(firstName, lastName, patronimic);
	cout << "Enter the country: ";
	cin >> country;
	setCountry(country);
	cout << "Enter the region: ";
	cin >> region;
	setRegion(region);
	cout << "Enter the area: ";
	cin >> area;
	setArea(area);
	cout << "Enter the city: ";
	cin >> city;
	setCity(city);
	cout << "Enter the street: ";
	cin >> street;
	setStreet(street);

	cout << "Enter the number of house: ";
	cin >> house;
	setHouse(house);
	cout << "Enter the number of flat: ";
	cin >> flat;
	setFlat(flat);
	cout << "Enter the mathematical mark: ";
	cin >> mathMark;
	cout << "Enter the language mark: ";
	cin >> languageMark;
	cout << "Enter the physics mark: ";
	cin >> physicsMark;
	setMarks(mathMark, physicsMark, languageMark);
}

int Abiturient::sumOfMarks()
{
	if (physicsMark < MINMARK || physicsMark > MAXMARK)
		throw std::invalid_argument("Invalid physics mark.");
	if (mathMark < MINMARK || mathMark > MAXMARK)
		throw std::invalid_argument("Invalid mathematical mark.");
	if (languageMark < MINMARK || languageMark > MAXMARK)
		throw std::invalid_argument("Invalid language mark.");
	int sumOfMarks = (getMathMark() + getPhysicsMark() + getLanguageMark()) / 3;

	return sumOfMarks;
}

//getters
string Abiturient::getCountry() const
{
	return this->country;
}

string Abiturient::getRegion() const
{
	return this->region;
}

string Abiturient::getArea() const
{
	return this->area;
}

string Abiturient::getCity() const
{
	return this->city;
}

string Abiturient::getStreet() const
{
	return this->street;
}

int Abiturient::getHouse() const
{
	return this->house;
}

int Abiturient::getFlat() const
{
	return this->flat;
}

int Abiturient::getMathMark() const
{
	return this->mathMark;
}

int Abiturient::getLanguageMark() const
{
	return this->languageMark;
}

int Abiturient::getPhysicsMark() const
{
	return this->physicsMark;
}

//setters
inline void Abiturient::setHouse(int house)
{
	if (house < 1)
		throw std::invalid_argument("Invalid number of house.");
	this->house = house;
}

inline void Abiturient::setFlat(int flat)
{
	if (flat < 1)
		throw std::invalid_argument("Invalid number of flat.");
	this->flat = flat;
}

inline void Abiturient::setMathMark(int mathMark)
{
	if (mathMark < MINMARK || mathMark>MAXMARK)
		throw std::invalid_argument("Invalid mark.");
	this->mathMark = mathMark;
}

inline void Abiturient::setLanguageMark(int languageMark)
{
	if (languageMark < MINMARK || languageMark > MAXMARK)
		throw std::invalid_argument("Invalid mark.");
	this->languageMark = languageMark;
}

inline void Abiturient::setPhysicsMark(int physicsMark)
{
	if (physicsMark < MINMARK || physicsMark>MAXMARK)
		throw std::invalid_argument("Invalid mark.");
	this->physicsMark = physicsMark;
}

inline void Abiturient::setCountry(string country)
{
	if (country.length() == 0)
		throw std::invalid_argument("Length of string must be more zero.");
	this->country = country;
}

inline void Abiturient::setRegion(string region)
{
	if (region.length() == 0)
		throw std::invalid_argument("Length of string must be more zero.");
	this->region = region;
}

inline void Abiturient::setArea(string area)
{
	if (area.length() == 0)
		throw std::invalid_argument("Length of string must be more zero.");
	this->area = area;
}

inline void Abiturient::setCity(string city)
{
	if (city.length() == 0)
		throw std::invalid_argument("Length of string must be more zero.");
	this->city = city;
}

inline void Abiturient::setStreet(string street)
{
	if (street.length() == 0)
		throw std::invalid_argument("Length of string must be more zero.");
	this->street = street;
}

void Abiturient::setMarks(int mathMark, int languageMark, int physicsMark)
{
	setMathMark(mathMark);
	setPhysicsMark(physicsMark);
	setLanguageMark(languageMark);
}

Abiturient::Abiturient(int house, int flat, int mathMark, int languageMark, int physicsMark,
	string country, string region, string area, string city, string street,
	string firstName, string lastName, string patronimic)
{
	Name name(firstName, lastName, patronimic);
	setHouse(house);
	setFlat(flat);
	setMarks(mathMark, physicsMark, languageMark);
	setCountry(country);
	setRegion(region);
	setArea(area);
	setCity(city);
	setStreet(street);
}

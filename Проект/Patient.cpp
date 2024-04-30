#include "Patient.h"

Patient::Patient()
{
	_id = 0;
}

void Patient::Id(int id)
{
	_id = id;
}

void Patient::Name(const std::string& name)
{
	_name = name;
}

void Patient::Surname(const std::string& surname)
{
	_surname = surname;
}

void Patient::PhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Patient::Age(const std::string& age)
{
	_age = age;
}

void Patient::Address(const std::string& address)
{
	_address = address;
}

#pragma once

#include <string>

class Patient
{
private:
	int _id;
	std::string _name;
	std::string _surname;
	std::string _phoneNumber;
	std::string _age;
	std::string _address;

public:
	Patient();

	int Id() const { return _id; }
	const std::string& Name() const { return _name; }
	const std::string& Surname() const { return _surname; }
	const std::string& PhoneNumber() const { return _phoneNumber; }
	const std::string& Age() const { return _age; }
	const std::string& Address() const { return _address; }

	void Id(int id);
	void Name(const std::string& name);
	void Surname(const std::string& surname);
	void PhoneNumber(const std::string& phoneNumber);
	void Age(const std::string& age);
	void Address(const std::string& address);

	std::string GetName() const
	{
		return _name; 
	}

};


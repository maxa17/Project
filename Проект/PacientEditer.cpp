#include "PacientEditer.h"
#include <algorithm>
#include <iostream>

PacientEditer::PacientEditer(std::vector<Patient>& patients)
	: _patients(patients)
{
}

int PacientEditer::GetFreeId()
{
	int id = 1;
	while (true)
	{
		if (std::find_if(_patients.begin(), _patients.end(), [id](const Patient& patient) { return patient.Id() == id; }) == _patients.end())
		{
			return id;
		}
		++id;
	}
	return -1;
}

bool PacientEditer::AddPatient(Patient* patient)
{
	patient->Id(GetFreeId());
	_patients.push_back(*patient);
	return true;
}

bool PacientEditer::UpdateFullPatient(Patient* patient)
{
	for (int i = 0; i < _patients.size(); i++)
	{
		if (_patients[i].Id() == patient->Id())
		{
			_patients[i].Name(patient->Name());
			_patients[i].Surname(patient->Surname());
			_patients[i].PhoneNumber(patient->PhoneNumber());
			_patients[i].Age(patient->Age());
			_patients[i].Address(patient->Address());
			
			return true;
		}
	}
	return false;
}

bool PacientEditer::DeleteByIndex(int index)
{
	_patients.erase(_patients.begin() + index);
	return true;
	
}

bool PacientEditer::DeleteByName(const std::string& name)
{
	auto it = std::find_if(_patients.begin(), _patients.end(), [name](const Patient& obj) { return obj.Name() == name; });

	if (it != _patients.end())
	{
		_patients.erase(it);
		return true;
	}
	return false;
}

Patient PacientEditer::CreatePatientForm()
{
	Patient* art = new Patient();

	std::cout<< "Кирилиця не підтримується" <<std::endl;

	std::cout << "Ведіть Ім'я пацієнта : ";
	std::string name; std::getline(std::cin, name);

	std::cout << "Ведіть Призвіще пацієнта : ";
	std::string surname; std::getline(std::cin, surname);

	std::cout << "Ведіть номер телефону пацієнта : ";
	std::string phoneNumber; std::getline(std::cin, phoneNumber);


	std::cout << "Ведіть вік пацієнта : ";
	std::string age; std::getline(std::cin, age);

	std::cout << "Ведіть ардесу пацієнта : ";
	std::string address; std::getline(std::cin, address);


	return Patient();



}

void PacientEditer::ShowAllPacient()
{
	if (_patients.size() < 1)
	{
		std::cout << "Пацієнти Відсутні" << std::endl;
	}
	for (int i = 1; i < _patients.size() + 1; i++)
	{
		std::cout <<i<<". "<< _patients[i - 1].Name() << "" << std::endl;
	}
}

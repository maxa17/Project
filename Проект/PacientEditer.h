#pragma once
#include <vector>
#include <string>
#include "Patient.h"
class PacientEditer
{
private:
	std::vector<Patient>& _patients;
public:
	PacientEditer(std::vector<Patient>& patients);
	int GetFreeId();
	bool AddPatient(Patient* patient);

	bool UpdateFullPatient(Patient* patient);

	bool DeleteByIndex(int index);
	bool DeleteByName(const std::string& name);


	Patient CreatePatientForm();


	void ShowAllPacient();

	Patient* GetPatientByName(const std::string& name)
	{
		for (auto& patient : _patients)
		{
			if (patient.GetName() == name)
			{
				return &patient;
			}
		}
		return nullptr; // повернути nullptr, якщо пацієнт з таким ім'ям не знайдений
	}

};

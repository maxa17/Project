#pragma once

#include "Patient.h"
#include "CsvPatient.h"

#include <string>
#include <filesystem>
#include <vector>
#include <iostream>
#include <fstream>

class Database
{
private:
	std::filesystem::path _filePatientPath;
	CsvPatient _csvPatient;


	bool CreateFolderIfNotExists(const std::string&);
	bool CreatePatientsDataFile(const std::string&);
public:
	Database(const std::string&);

	void SavePatient(std::vector<Patient> patient);
	std::vector<Patient> LoadPatient();

	
};


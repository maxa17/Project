#pragma once

#include "Patient.h"

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <Windows.h>

class CsvPatient
{
private:
	std::string _filePath;
public:
	CsvPatient();
	CsvPatient(std::string filePath);
	std::vector<Patient> ReadData() const;
	void WriteData(const std::vector<Patient>& patients) const;


	
};  


	


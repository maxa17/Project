#include "CsvPatient.h"

CsvPatient::CsvPatient()
{
}

CsvPatient::CsvPatient(std::string filePath)
{
	_filePath = filePath;
}

std::vector<Patient> CsvPatient::ReadData() const
{
    std::vector<Patient> patients;
    std::ifstream csvFile(_filePath);

    if (csvFile.is_open()) {
        std::string line;
        
        std::getline(csvFile, line);

        while (std::getline(csvFile, line)) {
            Patient patient;
            std::stringstream ss(line);

            
            std::string field;
            int index = 0;
            while (std::getline(ss, field, '|'))
            {
                switch (index)
                {
                case 0:
                    patient.Id(std::stoi(field));
                    break;
                case 1:
                    patient.Name(field);
                    break;
                case 2:
                    patient.Surname(field);
                    break;
                case 3:
                    patient.PhoneNumber(field);
                    break;
                case 4:
                    patient.Age(field);
                    break;
                case 5:
                    patient.Address(field);
                    break;
                
                default:
                    
                    std::cerr << "Unknown field: " << field << std::endl;
                    break;
                }
                index++;
            }

            patients.push_back(patient);
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV file could not be opened: " << _filePath << std::endl;
    }

    return patients;
}

void CsvPatient::WriteData(const std::vector<Patient>& patients) const
{
    std::ofstream csvFile(_filePath);

    if (csvFile.is_open()) {

        csvFile << "id | name | surname | phoneNumber | age | address\n";
        for (const auto& patient : patients) {
            csvFile << patient.Id() << '|'
                << patient.Name() << '|'
                << patient.Surname() << '|'
                << patient.PhoneNumber() << '|'
                << patient.Age() << '|'
                << patient.Address() << '\n';
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "CSV file could not be opened for writing: " << _filePath << std::endl;
    }
}





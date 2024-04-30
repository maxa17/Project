#include "Database.h"
#include "CsvPatient.h"
#include <filesystem>
#include <cstdlib>
#include <fstream>



bool Database::CreateFolderIfNotExists(const std::string& folderPath)
{
    {
        std::filesystem::path path(folderPath);

        if (!std::filesystem::exists(path))
        {
            try
            {
                
                std::filesystem::create_directory(path);
                return true;
            }
            catch (const std::filesystem::filesystem_error& e)
            {
                std::cerr << "Error creating a folder: " << e.what() << std::endl;
                return false;
            }
        }
        else
        {
            return true;
        }
    }
}



bool Database::CreatePatientsDataFile(const std::string& folderPath)
{
    std::filesystem::path path(folderPath);

    
    std::filesystem::path patientsDataFilePath(path / "PatientsData.txt");

    
    try
    {
        if (!std::filesystem::exists(patientsDataFilePath))
        {
            std::ofstream patientsDataFile(patientsDataFilePath);
            if (!patientsDataFile.is_open())
            {
                std::cerr << "The file PatientsData.txt could not be opened for writing." << std::endl;
                return false;
            }

            patientsDataFile.close();
        }
        return true;
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Error creating PatientsData.txt file: " << e.what() << std::endl;
        return false;
    }
}

Database::Database(const std::string& pathToDb)
{
    CreateFolderIfNotExists(pathToDb);
    CreatePatientsDataFile(pathToDb);

    _filePatientPath = std::filesystem::path(pathToDb + "/PatientsData.txt");
    _csvPatient = CsvPatient(_filePatientPath.string());

}

void Database::SavePatient(std::vector<Patient> patients)
{
    _csvPatient.WriteData(patients);
}

std::vector<Patient> Database::LoadPatient()
{
    return _csvPatient.ReadData();
}





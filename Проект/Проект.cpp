#include "Database.h"
#include "Patient.h"
#include "PacientEditer.h"
#include "CsvPatient.h"

#include <iostream>
#include <vector>
#include <Windows.h> 
#include <conio.h>
#include <locale>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Database* database = new Database("C:\\.PatientDB");
    std::vector<Patient>patients=database->LoadPatient();
    
    while (true)
    {
        
        // Меню вибора пацієнта або лікаря 
        std::cout << "Виберіть користувача: \n1 - Лікар \n2 - Пацієнт  \n3 - Вихід " << std::endl;
        std::string choiceRole; std::getline(std::cin, choiceRole);

        if (choiceRole == "1") // Вибір Лікаря
        {
            while (true)
            {
                //system("cls");
                // Меню лікаря
                std::cout << "Меню Лікаря: \n1 - База всіх пацієнтів  \n2 - Додати пацієнта \n3 - Вихід " << std::endl;
                std::string choiceDoctor; std::getline(std::cin, choiceDoctor);
                if (choiceDoctor == "1") // База всіх пацієнтів
                {
                    while (true)
                    {
                        //system("cls");
                        // База пацієнтів 
                        std::cout << "База пацієнтів: \n1 - Переглянути всіх пацієнтів \n2 - Вибрати пацієнта \n3 - Вихід " << std::endl;
                        std::string choicePatientDatabase; std::getline(std::cin, choicePatientDatabase);
                        if (choicePatientDatabase == "1") // Переглянути всіх пацієнтів
                        {
                            PacientEditer editor(patients);
                            editor.ShowAllPacient();
                        }
                        else if (choicePatientDatabase == "2") // Вибрати пацієнта
                        {
                            std::cout << "Введіть ім'я пацієнта: ";
                            std::string patientName; std::getline(std::cin, patientName);
                            PacientEditer editor(patients);
                            Patient* patient = editor.GetPatientByName(patientName);
                            if (patient != nullptr)
                            {
                                std::cout << "Ім'я: " << patient->Name() << "\n";
                                std::cout << "Прізвище: " << patient->Surname() << "\n";
                                std::cout << "Номер телефону: " << patient->PhoneNumber() << "\n";
                                std::cout << "Вік: " << patient->Age() << "\n";
                                std::cout << "Адреса: " << patient->Address() << "\n";
                            }
                            else
                            {
                                std::cout << "Пацієнт не знайдений.\n";
                            }
                        }
                        else if (choicePatientDatabase == "3") // Вихід 
                        {
                            system("cls");
                            break;
                        }
                        else // Не вірне число 
                        {
                            std::cout << "Введено невірне число" << std::endl;
                        }

                    }


                }

                if (choiceDoctor == "2") // Додати пацієнта
                {
                    

                    PacientEditer editor(patients);
                    Patient newPatient = editor.CreatePatientForm();
                    editor.AddPatient(&newPatient);
                    database->SavePatient(patients);
                    std::cout << "Данні збережено"<<std::endl;

                }




                else if (choiceDoctor == "3") // Вихід 
                {
                    system("cls");
                    break;
                }
                else // Не вірне число 
                {
                    std::cout << "Введено невірне число" << std::endl;
                }
            }
        }
        else if (choiceRole == "2") // Вибір пацієнта
        {
            system("cls");
            std::cout << "Меню Пацієнта: \n1 - Переглянути мої дані \n2 - Змінити мої дані \n3 - Вихід " << std::endl;
            std::string choicePatient; std::getline(std::cin, choicePatient);
            if (choicePatient == "1") // Переглянути мої дані
            {
                std::cout << "Введіть ім'я пацієнта: ";
                std::string patientName; std::getline(std::cin, patientName);
                PacientEditer editor(patients);
                Patient* patient = editor.GetPatientByName(patientName);
                if (patient != nullptr)
                {
                    std::cout << "Ім'я: " << patient->Name() << "\n";
                    std::cout << "Прізвище: " << patient->Surname() << "\n";
                    std::cout << "Номер телефону: " << patient->PhoneNumber() << "\n";
                    std::cout << "Вік: " << patient->Age() << "\n";
                    std::cout << "Адреса: " << patient->Address() << "\n";
                }
                else
                {
                    std::cout << "Пацієнт не знайдений.\n";
                }
            }
            else if (choicePatient == "2") // Змінити мої дані
            {
                std::cout << "Введіть ім'я пацієнта: ";
                std::string patientName; std::getline(std::cin, patientName);
                PacientEditer editor(patients);
                Patient* patient = editor.GetPatientByName(patientName);
                if (patient != nullptr)
                {
                    Patient updatedPatient = editor.CreatePatientForm();
                    editor.UpdateFullPatient(&updatedPatient);
                }
                else
                {
                    std::cout << "Пацієнт не знайдений.\n";
                }
            }
            else if (choicePatient == "3") // Вихід 
            {
                system("cls");
                break;
            }
            else // Не вірне число 
            {
                std::cout << "Введено невірне число" << std::endl;
            }
        }
        else if (choiceRole == "3") // Вихід 
        {
            system("cls");
            break;
        }
        else // Не вірне число 
        {
            std::cout << "Введено невірне число" << std::endl;
        }
    }


    database->SavePatient(patients);
    std::cout << "Данні збережено";
}



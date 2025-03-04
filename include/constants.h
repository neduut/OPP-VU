#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "mylib.h"

// user prompts
const string ENTER_FIRST_NAME = "Įveskite vardą: ";
const string ENTER_LAST_NAME = "Įveskite pavardę: "; 
const string ENTER_MARK = "Įveskite namų darbų pažymį (norint sustoti, įveskite -1): "; 
const string ENTER_MARK_IN_MIXED = "Įveskite namų darbų pažymį: ";
const string ENTER_EXAM_MARK = "Įveskite egzamino pažymį: ";
const string ENTER_GROUP_TYPE = "Pasirinkite grupavimo tipą (1 - vidurkis / 2 - mediana): ";
const string ENTER_SORT_TYPE = "Pasirinkite, pagal ką rūšiuoti studentus (1 - vardą / 2 - pavardę / 3 - galutinį balą (vid.) / 4 - galutinį balą (med.)): ";
const string ENTER_PRINT_TYPE = "Pasirinkite, kur išvesti duomenis (1 - ekraną / 2 - failą): ";
const string ENTER_MARKS_COUNT = "Įveskite namų darbų pažymių skaičių: ";
const string ADD_ANOTHER_MARK = "Ar norite įvesti dar vieną namų darbą? (taip/ne): ";
const string ADD_ANOTHER_STUDENT = "Ar norite įvesti dar vieną studentą? (taip/ne): ";

constexpr char MENU_TEXT[] = 
    "\nPasirinkite, ką norite daryti:\n"
    "1 - Įvesti viską rankiniu būdu\n"
    "2 - Generuoti atsitiktinius pažymius (vardus įvesti ranka)\n"
    "3 - Generuoti atsitiktinius vardus ir pažymius\n"
    "4 - Skaityti iš failo\n"
    "5 - Užbaigti programą\n";

constexpr char ENTER_FILE_SIZE[] = 
    "\nPasirinkite, kokio dydžio failą norite atidaryti:\n"
    "1 - 1 000\n"
    "2 - 10 000\n"
    "3 - 100 000\n"
    "4 - 1 000 000\n"
    "5 - 10 000 000\n";

// errors
const string INVALID_FIRST_NAME_ERROR = "Klaida: įvestas netinkamas vardas! "; 
const string INVALID_LAST_NAME_ERROR = "Klaida: įvesta netinkama pavardė! "; 
const string INVALID_MARK_ERROR = "Klaida: pažymys turi būti sveikasis skaičius nuo 1 iki 10! "; 
const string INVALID_EXAM_MARK_ERROR = "Klaida: egzamino pažymys turi būti sveikasis skaičius nuo 1 iki 10! "; 
const string INVALID_MARKS_COUNT_ERROR = "Klaida: pažymių skaičius turi būti sveikasis skaičius ir mažesnis nei 10! ";
const string INVALID_MENU_CHOICE = "Klaida: netinkamas meniu pasirinkimas! ";
const string INVALID_CHOICE = "Klaida: netinkamas pasirinkimas! ";
const string INVALID_SIZE_ERROR = "Klaida: dydis turi būti sveikasis skaičius! ";
const string INVALID_MARKS_COUNT = "Klaida: turite įvesti bent vieną pažymį! ";
const string INVALID_OUTPUT_TYPE_ERROR = "Klaida: netinkamas išvedimo tipas! ";
const string FILE_OPEN_ERROR = "Klaida: nepavyko atidaryti failo! ";
const string EMPTY_ARRAY_ERROR = "Klaida: pažymių masyvas tuščias! ";
const string INVALID_GROUP_TYPE = "Klaida: netinkamas grupavimo tipas! ";
const string INVALID_FILE_SIZE = "Klaida: netinkamas failo dydis! ";

// success 
const string FILE_READ_SUCCESS = "Duomenys nuskaityti sėkmingai! ";
const string FILE_WRITE_SUCCESS = "Duomenys įrašyti sėkmingai! ";

// menu choice
const string MENU_CHOICE_1 = "1 - Įvesti studentų duomenis";
const string MENU_CHOICE_2 = "2 - Generuoti atsitiktinius pažymius";
const string MENU_CHOICE_3 = "3 - Generuoti atsitiktinius vardus ir pažymius";
const string MENU_CHOICE_4 = "4 - Užbaigti programą";


#endif
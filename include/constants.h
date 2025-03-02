#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "mylib.h"

// user prompts
const string ENTER_FIRST_NAME = "Iveskite varda: ";
const string ENTER_LAST_NAME = "Iveskite pavarde: "; 
const string ENTER_MARK = "Iveskite namu darbu pazymi (norint sustoti iveskite -1): "; 
const string ENTER_MARK_IN_MIXED = "Iveskite namu darbu pazymi: ";
const string ENTER_EXAM_MARK = "Iveskite egzamino pazymi: ";
const string ENTER_SORT_TYPE = "Pasirinkite pagal ka rusiuoti studentus (v-varda /p-pavarde /g-galutini bala): ";
const string ENTER_OUTPUT_TYPE = "Pasirinkite i kur isvesti duomenis (e-ekrana /f-faila): ";
const string ENTER_MARKS_COUNT = "Iveskite namu darbu pazymiu skaiciu: ";
const string ADD_ANOTHER_MARK = "Ar norite ivesti dar viena namu darba? (taip/ne): ";
const string ADD_ANOTHER_STUDENT = "Ar norite ivesti dar viena studenta? (taip/ne): ";
constexpr char MENU_TEXT[] = 
    "\nPasirinkite ka norite daryti:\n"
    "1 - Ivesti viska rankiniu budu\n"
    "2 - Generuoti atsitiktinius pazymius (vardus ivesti ranka)\n"
    "3 - Generuoti atsitiktinius vardus ir pazymius\n"
    "4 - Skaityti is failo\n"
    "5 - Uzbaigti programa\n";
const string ENTER_GROUP_TYPE = "Pasirinkite grupavimo tipa (v-vidurkis / m-mediana): ";

// errors
const string INVALID_FIRST_NAME_ERROR = "Klaida: ivestas netinkamas vardas! "; 
const string INVALID_LAST_NAME_ERROR = "Klaida: ivesta netinkama pavarde! "; 
const string INVALID_MARK_ERROR = "Klaida: pazymys turi buti sveikasis skaicius nuo 1 iki 10! "; 
const string INVALID_EXAM_MARK_ERROR = "Klaida: egzamino pazymys turi buti sveikasis skaicius nuo 1 iki 10! "; 
const string INVALID_MARKS_COUNT_ERROR = "Klaida: pazymiu skaicius turi buti sveikasis skaicius ir mazesnis nei 10! ";
const string INVALID_MENU_CHOICE = "Klaida: netinkamas menu pasirinkimas ! ";
const string INVALID_CHOICE = "Klaida: netinkamas pasirinkimas! ";
const string INVALID_SIZE_ERROR = "Klaida: dydis turi buti sveikasis skaicius! ";
const string INVALID_MARKS_COUNT = "Klaida: turite ivesti bent viena pazymi! ";
const string INVALID_OUTPUT_TYPE_ERROR = "Klaida: netinkamas isvedimo tipas! ";
const string FILE_OPEN_ERROR = "Klaida: nepavyko atidaryti failo! ";
const string EMPTY_ARRAY_ERROR = "Klaida: pazymiu masyvas tuscias! ";

// success 
const string FILE_READ_SUCCESS = "Duomenys nuskaityti sekmingai! ";
const string FILE_WRITE_SUCCESS = "Duomenys irasyti sekmingai! ";

// menu choice
const string MENU_CHOICE_1 = "1 - Ivesti studentu duomenis";
const string MENU_CHOICE_2 = "2 - Generuoti atsitiktinius pazymius";
const string MENU_CHOICE_3 = "3 - Generuoti atsisitiktinius vardus ir pazymius";
const string MENU_CHOICE_4 = "4 - Uzbaigti programa";


#endif
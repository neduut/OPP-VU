#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "mylib.h"

// user prompts
const string ENTER_FIRST_NAME = "Iveskite varda (norint sustoti iveskite -1): ";
const string ENTER_LAST_NAME = "Iveskite pavarde: "; 
const string ENTER_MARK = "Iveskite namu darbu pazymi (norint sustoti iveskite -1): "; 
const string ENTER_EXAM_MARK = "Iveskite egzamino pazymi: ";
const string ENTER_FINAL_TYPE = "Pasirinkite galutinio pazymio tipa (v-vidurkis / m-mediana): ";
const string ENTER_MARKS_COUNT = "Iveskite namu darbu pazymiu skaiciu: ";

// errors
const string INVALID_FIRST_NAME_ERROR = "Klaida: ivestas netinkamas vardas! "; 
const string INVALID_LAST_NAME_ERROR = "Klaida: ivesta netinkama pavarde! "; 
const string INVALID_MARK_ERROR = "Klaida: pazymys turi buti sveikasis skaicius nuo 1 iki 10! "; 
const string INVALID_EXAM_MARK_ERROR = "Klaida: egzamino pazymys turi buti sveikasis skaicius nuo 1 iki 10! "; 
const string INVALID_FINAL_TYPE_ERROR = "Klaida: ivestas netinkamas galutinio pazymio tipas! ";
const string INVALID_MARKS_COUNT_ERROR = "Klaida: pazymiu skaicius turi buti sveikasis skaicius ir mazesnis nei 10! ";

const int MAX_MARKS = 10;

#endif
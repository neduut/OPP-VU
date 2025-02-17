#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "mylib.h"

// user prompts
const string ENTER_FIRST_NAME = "Iveskite varda (norint sustoti iveskite -1): ";
const string ENTER_LAST_NAME = "Iveskite pavarde: "; 
const string ENTER_MARK = "Iveskite namu darbu pazymi (norint sustoti iveskite -1): "; 

// errors
const string INVALID_FIRST_NAME_ERROR = "Klaida: ivestas netinkamas vardas! "; 
const string INVALID_LAST_NAME_ERROR = "Klaida: ivesta netinkama pavarde! "; 
const string INVALID_MARK_ERROR = "Klaida: pazymys turi buti sveikasis skaicius nuo 1 iki 10! "; 
const string INVALID_EXAM_MARK_ERROR = "Klaida: egzamino pazymys turi buti sveikasis skaicius nuo 1 iki 10! "; 

// MENU CHOICES BEGIN
const string MENU_CHOICE_1 = "1 - Ivesti studentu duomenis";
const string MENU_CHOICE_2 = "2 - Generuoti atsitiktinius pazymius";
const string MENU_CHOICE_3 = "3 - Generuoti atsisitiktinius vardus ir pazymius";
const string MENU_CHOICE_4 = "4 - Uzbaigti programa";

#endif
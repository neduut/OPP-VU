#ifndef MESSAGES_H
#define MESSAGES_H
#include "common.h"

//user prompts
const string ENTER_FIRST_NAME = "Iveskite varda: ";
const string ENTER_LAST_NAME = "Iveskite pavarde: ";
const string ENTER_MARK = "Iveskite namu darbu pazymi (pazymius veskite per space klavisa, norint sustoti spauskite enter): ";
const string ENTER_EXAM_MARK = "Iveskite egzamino pazymi: ";

//error 
const string INVALID_FIRST_NAME_ERROR = "Ivestas netinkamas vardas";
const string INVALID_LAST_NAME_ERROR = "Ivesta netinkama pavarde";
const string INVALID_MARK_ERROR = "Pazymys turi buti sveikasis skaicius nuo 1 iki 10";
const string INVALID_EXAM_MARK_ERROR = "Egzamino pazymys turi buti sveikasis skaicius nuo 1 iki 10";

#endif
#ifndef UTILS_H
#define UTILS_H

#include "mylib.h"
#include "constants.h"

bool isNameValid(string name);
bool isMarkValid(string mark);
bool isCountValid(string count);
bool isMenuChoiceValid(string choice);
bool isChoiceValid(string choice);

string getRandomFirstName();
string getRandomLastName();
int getRandomMark();

#endif
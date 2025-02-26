#ifndef UTILS_H
#define UTILS_H

#include "mylib.h"
#include "constants.h"

// requests
string getFinalType();
string getMenuChoice();
string getFirstName(char menuChoice);
string getLastName(char menuChoice);
int getExamMark(char menuChoice);
vector<int> getHomeworkMarks(char menuChoice);
string getPrintType();
string getSortType();

// validations
bool isNameValid(string name);
bool isMarkValid(string mark);
bool isCountValid(string count);
bool isMenuChoiceValid(string choice);
bool isChoiceValid(string choice);
bool isSizeValid(string size);
bool isFinalTypeValid(string finalType);
bool isFinalPrintValid(string printType);

// random generators
string getRandomFirstName();
string getRandomLastName();
int getRandomMark();

#endif
#ifndef UTILS2_H
#define UTILS2_H

#include "mylib2.h"

// requests
string getYesNo();
int getSortType();
int getGroupType();
int getPrintType();
int getMenuChoice();
int getProgramMenuChoice();
int getTestMenuChoice();
string getFirstName(char menuChoice);
string getLastName(char menuChoice);
int getExamMark(char menuChoice);
list<int> getHomeworkMarks(char menuChoice);
int getFileSize();

// validations
bool isNameValid(string name);
bool isMarkValid(string mark);
bool isChoiceValid(string choice);

// random generators
string getRandomFirstName();
string getRandomLastName();
int getRandomMark();

#endif
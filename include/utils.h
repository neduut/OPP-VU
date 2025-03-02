#ifndef UTILS_H
#define UTILS_H

#include "mylib.h"

// requests
string getSortType();
string getGroupType();
string getOutputType();
string getMenuChoice();
string getFirstName(char menuChoice);
string getLastName(char menuChoice);
int getExamMark(char menuChoice);
vector<int> getHomeworkMarks(char menuChoice);
int getFileSize();

// validations
bool isNameValid(string name);
bool isMarkValid(string mark);
bool isCountValid(string count);
bool isMenuChoiceValid(string choice);
bool isChoiceValid(string choice);
bool isSizeValid(string size);
bool isOutputTypeValid(string printType);
bool isGroupTypeValid(string groupType);
bool isFileSizeValid(int size);

// random generators
string getRandomFirstName();
string getRandomLastName();
int getRandomMark();

#endif
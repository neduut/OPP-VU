#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "mylib.h"

struct Student {
    string firstName;
    string lastName;
    vector<int> marks;
    int examMark;
    double avgFinal;
    double medianFinal;
};

void handleMenu(vector<Student>& students);
void readInput(vector<Student>& students, char menuChoice);
void readFromFile(vector<Student>& students);
double averageFinalMark(const vector<int>& marks, int examMark);
double medianFinalMark(const vector<int>& marks, int examMark);
void sortStudents(vector<Student>& students, char sortType);
void groupStudents(vector<Student>& students, char groupType);
void printToConsole(vector<Student>& students);
void printToFile(vector<Student>& students, const string& fileName);

#endif  
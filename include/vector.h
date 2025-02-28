#ifndef VECTOR_H
#define VECTOR_H

#include "mylib.h"

struct Student {
    string firstName;
    string lastName;
    vector<int> marks;
    int examMark;
    double finalMark;
};

void handleMenu(vector<Student>& students, const char& finalType);
void readInput(vector<Student>& students, char menuChoice, char finalType);
void readFromFile(vector<Student>& students, char finalType);
double averageFinalMark(const vector<int>& marks, int examMark);
double medianFinalMark(const vector<int>& marks, int examMark);
void sortStudents(vector<Student>& students, char sortType);
void output(vector<Student>& students, char finalType, char printType);

#endif  
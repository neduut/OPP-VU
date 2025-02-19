#ifndef VESTOR_H
#define VECTOR_H

#include "mylib.h"
#include "constants.h"
#include "validations.h"

struct Student {
    string firstName;
    string lastName;
    vector<int> marks;
    int examMark;
};

void readInput(vector<Student>& students);
double averageFinalMark(vector<Student>& students);
double medianFinalMark(vector<Student>& students);
void output(vector<Student>& students);

#endif  
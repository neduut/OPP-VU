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
    double finalMarkAverage;
    double finalMarkMedian;
};

void readInput(vector<Student>& students);
void averageFinalMark(vector<Student>& students);
void medianFinalMark(vector<Student>& students);
void output(vector<Student>& students);

#endif  
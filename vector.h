#ifndef VESTOR_H
#define VECTOR_H

#include "mylib.h"
#include "constants.h"
#include "utils.h"

struct StudentVector {
    string firstName;
    string lastName;
    vector<int> marks;
    int examMark;
};

void readInput(vector<StudentVector>& students, string choice);
double averageFinalMark(const StudentVector& student);
double medianFinalMark(const StudentVector& student);
void output(vector<StudentVector>& students);

#endif  
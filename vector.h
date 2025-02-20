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

void readInput(vector<StudentVector>& students);
double averageFinalMark(vector<StudentVector>& students);
double medianFinalMark(vector<StudentVector>& students);
void output(vector<StudentVector>& students);

#endif  
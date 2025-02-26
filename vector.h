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
    double finalMark; 
};

void readInput(vector<StudentVector>& students, string menuChoice, string finalType);
void readFromFile(vector<StudentVector>& students, string finalType);
double averageFinalMark(const vector<int>& marks, int examMark);
double medianFinalMark(const vector<int> marks, int examMark);
void output(vector<StudentVector>& students, string finalType, string printType);

#endif  
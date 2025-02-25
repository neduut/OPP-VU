#ifndef MIXED_H
#define MIXED_H
#include "constants.h"
#include "mylib.h"
#include "utils.h"

struct StudentMixed {
    string firstName, lastName; 
    int *marks;
    int marksCount;
    int examMark;    
};

void readInput(vector<StudentMixed>& students, string menuChoice);
double averageFinalMark(const StudentMixed& student);
double medianFinalMark(const StudentMixed& student);
void output(vector<StudentMixed>& students, string finalType);

#endif 


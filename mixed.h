#ifndef MIXED_H
#define MIXED_H
#include "constants.h"
#include "mylib.h"
#include "utils.h"

struct StudentMixed {
    string firstName;   
    string lastName;    
    int *marks = nullptr;
    int marksCount = 0;  
    int examMark = 0;      
};

/*
struct StudentMixed {
    string firstName;
    string lastName;
    int* marks;
    int marksCount;
    int marksCapacity;
    int examMark;

    StudentMixed() {
        marks = new int[1]();
        marksCount = 0;
        marksCapacity = 1;
        examMark = 0;
    }

    ~StudentMixed() {
        delete[] marks;
    }
};*/

void readInput(vector<StudentMixed>& students);
double averageFinalMark(const StudentMixed& student);
double medianFinalMark(const StudentMixed& student);
void output(vector<StudentMixed>& students);

#endif 


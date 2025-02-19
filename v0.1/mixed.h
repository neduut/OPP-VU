
#ifndef MIXED_H
#define MIXED_H
#include "constants.h"
#include "mylib.h"
#include <validations.h>

//#define MAX_NAME_LENGTH 20  ??

//studentu struktura vektorius, pazymiu - c masyvas
struct Student {
    string firstName;
    string lastName;
    //vector<int> marks; padaryt c dinamini masyva. int* marks ??
    int examMark;
    double finalMarkAverage;
    double finalMarkMedian;
};

//void readInput(vector<Student>& students);
//void averageFinalMark(vector<Student>& students);
//void medianFinalMark(vector<Student>& students);
//void output(vector<Student>& students);

#endif 

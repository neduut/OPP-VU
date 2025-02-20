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

//failed dynamic c array implementation
/*struct StudentMixed {
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

/*
//second try
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

    void addMark(int mark) {
        if (marksCount == marksCapacity) {
            marksCapacity *= 2;  
            int* newMarks = new int[marksCapacity];
            
            for (int i = 0; i < marksCount; i++) {
                newMarks[i] = marks[i];
            }

            delete[] marks;
            marks = newMarks;
        }

        marks[marksCount] = mark;
        marksCount++;  
    }

    ~StudentMixed() {
        delete[] marks; 
    }
};*/


void readInput(vector<StudentMixed>& students, string choice);
double averageFinalMark(const StudentMixed& student);
double medianFinalMark(const StudentMixed& student);
void output(vector<StudentMixed>& students);
// failed 3rd time function void readInput(vector<StudentMixed>& students);

#endif 


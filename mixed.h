#ifndef MIXED_H
#define MIXED_H
#include "constants.h"
#include "mylib.h"
#include "utils.h"

struct StudentMixed {
    string firstName;   
    string lastName;    
    int marks[MAX_MARKS] = {0};
    int marksCount = 0;  
    int examMark = 0;      
};

/*struct StudentMixed {
    string firstName;
    string lastName;
    int* marks;
    int marksCount = 0;
    int marksCapacity = INITIAL_ARRAY_SIZE;
    int examMark;

    StudentMixed(const string& fName, const string& lName, int exam)
        : firstName(fName), lastName(lName), examMark(exam) {
        marks = new int[marksCapacity]; 
    }

    ~StudentMixed() {
        delete[] marks;
    }

    void expandArray() {
        int oldSize = marksCapacity;
        marksCapacity *= 2;
        int* newArray = new int[marksCapacity];

        for (int i = 0; i < oldSize; i++) {
            newArray[i] = marks[i];
        }

        delete[] marks;
        marks = newArray;
    }

    void addMark(int paz) {
        if (marksCount == marksCapacity) {
            expandArray(); 
        }
        marks[marksCount++] = paz;
    }
};*/

void readInput(vector<StudentMixed>& students);
double averageFinalMark(vector<StudentMixed>& students);
double medianFinalMark(vector<StudentMixed>& students);
void output(vector<StudentMixed>& students);

#endif 


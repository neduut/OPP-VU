// used vector for students and dynamic c array for marks
#ifndef MIXED_H
#define MIXED_H
#include "constants.h"
#include "mylib.h"
#include <validations.h>

struct Student {
    string firstName;
    string lastName;
    int* marks;
    int marksCount;
    int marksCapacity;
    int examMark;

    // constructor
    Student(std::string fName, std::string lName, int exam)
        : firstName(fName), lastName(lName), marksCount(0), marksCapacity(2), examMark(exam) {
        marks = new int[marksCapacity]; // initial size
    }

    ~Student() {
        delete[] marks;
    }

    void addMark(int paz) {
        if (marksCount == marksCapacity) {
            resize(marksCapacity * 2);
        }
        marks[marksCount++] = paz;
    }

    void resize(int new_capacity) {
        int* temp = new int[new_capacity];
        for (int i = 0; i < marksCount; i++) {
            temp[i] = marks[i];
        }
        delete[] marks;
        marks = temp;
        marksCapacity = new_capacity;
    }
};

void readInput(vector<Student>& students);
//void averageFinalMark(vector<Student>& students);
//void medianFinalMark(vector<Student>& students);
//void output(vector<Student>& students);

#endif 

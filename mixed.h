// used vector for students and dynamic c array for marks
#ifndef MIXED_H
#define MIXED_H
#include "constants.h"
#include "mylib.h"
#include "validations.h"

/*struct StudentMixed {
    string firstName;
    string lastName;
    int* marks;
    int marksCount;
    int marksCapacity;
    int examMark;

    // constructor
    StudentMixed(std::string fName, std::string lName, int exam)
        : firstName(fName), lastName(lName), marksCount(0), marksCapacity(2), examMark(exam) {
        marks = new int[marksCapacity]; // initial size
    }

    ~StudentMixed() {
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
};*/

struct StudentMixed {
    string firstName;
    string lastName;
    int* marks;
    int marksCount;
    int marksCapacity;
    int examMark;

    // constructor
    StudentMixed(const string& fName, const string& lName, int exam)
        : firstName(fName), lastName(lName), marksCount(0), marksCapacity(2), examMark(exam) {
        marks = new int[marksCapacity]; // intial size
    }

    // copy constructor
    StudentMixed(const StudentMixed& other)
        : firstName(other.firstName), lastName(other.lastName),
          marksCount(other.marksCount), marksCapacity(other.marksCapacity), examMark(other.examMark) {
        marks = new int[marksCapacity]; // new array
        for (int i = 0; i < marksCount; i++) {
            marks[i] = other.marks[i]; // copy data
        }
    }

    // move constructor
    StudentMixed(StudentMixed&& other) noexcept
        : firstName(move(other.firstName)), lastName(move(other.lastName)),
          marks(other.marks), marksCount(other.marksCount),
          marksCapacity(other.marksCapacity), examMark(other.examMark) {
        other.marks = nullptr; // reset
        other.marksCount = 0;
        other.marksCapacity = 0;
    }

    // copy assignment operator
    StudentMixed& operator=(const StudentMixed& other) {
        if (this == &other) return *this; // check for self-assignment

        delete[] marks; // free old array

        firstName = other.firstName;
        lastName = other.lastName;
        examMark = other.examMark;
        marksCount = other.marksCount;
        marksCapacity = other.marksCapacity;

        marks = new int[marksCapacity]; // new array
        for (int i = 0; i < marksCount; i++) {
            marks[i] = other.marks[i]; // copy data
        }

        return *this;
    }

    // move assignment operator
    StudentMixed& operator=(StudentMixed&& other) noexcept {
        if (this == &other) return *this;

        delete[] marks; // free old array

        firstName = move(other.firstName);
        lastName = move(other.lastName);
        examMark = other.examMark;
        marksCount = other.marksCount;
        marksCapacity = other.marksCapacity;
        marks = other.marks;

        other.marks = nullptr;
        other.marksCount = 0;
        other.marksCapacity = 0;

        return *this;
    }

    ~StudentMixed() {
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


void readInput(vector<StudentMixed>& students);
double averageFinalMark(vector<StudentMixed>& students);
double medianFinalMark(vector<StudentMixed>& students);
void output(vector<StudentMixed>& students);

#endif 

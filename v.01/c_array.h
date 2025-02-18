
#ifndef C_ARRAY_H
#define C_ARRAY_H
#include "constants.h"
#include "mylib.h"

#define MAX_NAME_LENGTH 20  

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int *marks;  
    int numMarks;
    int examMark;
} Student;

void addStudent(Student **students, int *studentCount);
void printResults(Student *students, int studentCount);
void freeMemory(Student *students, int studentCount);

#endif 

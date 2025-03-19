#ifndef FUNCTIONS1_H
#define FUNCTIONS1_H

#include "mylib1.h"

struct Student {
    string firstName;
    string lastName;
    deque<int> marks;
    int examMark;
    double avgFinal;
    double medianFinal;
};

void handleProgramMenu(deque<Student>& students);
void handleTestMenu();
void generateFile(int size);
void readInput(deque<Student>& students, char menuChoice);
void readFromFile(deque<Student>& students, int fileSize);       
double averageFinalMark(const deque<int>& marks, int examMark);
double medianFinalMark(const deque<int>& marks, int examMark);
void sortStudents(deque<Student>& students, char sortType);
void groupStudents1(deque<Student>& students, deque<Student>& kietiakai, deque<Student>& vargsiukai, char groupType);
void groupStudents2(deque<Student>& students, deque<Student>& kietiakai, deque<Student>& vargsiukai, char groupType);
void printToConsole(deque<Student>& kietiakai, deque<Student>& vargsiukai);
void printToFile(deque<Student>& students, const string& fileName);
void fileGenTest(int size, const string& fileName);
void programTest(int size, const string& fileName);
void dequeTest(int size, const string& fileName);
void strategies(int size, const string& fileName, int strategy);

#endif

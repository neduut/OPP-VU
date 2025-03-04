#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "mylib.h"

struct Student {
    string firstName;
    string lastName;
    vector<int> marks;
    int examMark;
    double avgFinal;
    double medianFinal;
};

void handleMenu(vector<Student>& students);
void generateFile(int size);
void readInput(vector<Student>& students, char menuChoice);
void readFromFile(vector<Student>& students, int fileSize);       
double averageFinalMark(const vector<int>& marks, int examMark);
double medianFinalMark(const vector<int>& marks, int examMark);
void sortStudents(vector<Student>& students, char sortType);
void groupStudents(vector<Student>& students, vector<Student>& kietiakai, vector<Student>& vargsiukai, char groupType);
void printToConsole(vector<Student>& kietiakai, vector<Student>& vargsiukai);
void printToFile(vector<Student>& students, const string& fileName);
void run_speed_test_1(int size, const std::string& fileName);
void run_speed_test_2(int size, const std::string& fileName);

#endif  
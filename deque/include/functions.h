#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "mylib.h"
#include <deque>

struct Student {
    std::string firstName;
    std::string lastName;
    std::deque<int> marks;
    int examMark;
    double avgFinal;
    double medianFinal;
};

void handleProgramMenu(std::deque<Student>& students);
void handleTestMenu();
void generateFile(int size);
void readInput(std::deque<Student>& students, char menuChoice);
void readFromFile(std::deque<Student>& students, int fileSize);       
double averageFinalMark(const std::deque<int>& marks, int examMark);
double medianFinalMark(const std::deque<int>& marks, int examMark);
void sortStudents(std::deque<Student>& students, char sortType);
void groupStudents1(std::deque<Student>& students, std::deque<Student>& kietiakai, std::deque<Student>& vargsiukai, char groupType);
void groupStudents2(std::deque<Student>& students, std::deque<Student>& kietiakai, std::deque<Student>& vargsiukai, char groupType);
void printToConsole(std::deque<Student>& kietiakai, std::deque<Student>& vargsiukai);
void printToFile(std::deque<Student>& students, const std::string& fileName);
void fileGenTest(int size, const std::string& fileName);
void programTest(int size, const std::string& fileName);
void dequeTest(int size, const std::string& fileName);
void strategies(int size, const std::string& fileName, int strategy);

#endif

#ifndef FUNCTIONSLIST2_H
#define FUNCTIONSLIST2_H

#include "mylib2.h"

struct Student {
    std::string firstName;
    std::string lastName;
    std::list<int> marks;
    int examMark;
    double avgFinal;
    double medianFinal;
};

void handleProgramMenu(std::list<Student>& students);
void handleTestMenu();
void generateFile(int size);
void readInput(std::list<Student>& students, char menuChoice);
void readFromFile(std::list<Student>& students, int fileSize);       
double averageFinalMark(const std::list<int>& marks, int examMark);
double medianFinalMark(const std::list<int>& marks, int examMark);
void sortStudents(std::list<Student>& students, char sortType);
void groupStudents1(std::list<Student>& students, std::list<Student>& kietiakai, std::list<Student>& vargsiukai, char groupType);
void groupStudents2(std::list<Student>& students, std::list<Student>& kietiakai, std::list<Student>& vargsiukai, char groupType);
void printToConsole(std::list<Student>& kietiakai, std::list<Student>& vargsiukai);
void printToFile(std::list<Student>& students, const std::string& fileName);
void fileGenTest(int size, const std::string& fileName);
void programTest(int size, const std::string& fileName);
void listTest(int size, const std::string& fileName);
void strategies(int size, const std::string& fileName, int strategy);

#endif

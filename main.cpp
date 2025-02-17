#include "main.h"
#include "functions.h"

int main() {
    vector<Student> students;

    readInput(students);
    averageFinalMark(students);
    medianFinalMark(students);
    output(students);

    return 0;
}


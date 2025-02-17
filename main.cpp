#include "main.h"
#include "functions.h"

int main() {
    vector<Student> students;

    readInput(students);
    calculateFinalMark(students);
    output(students);

    return 0;
}


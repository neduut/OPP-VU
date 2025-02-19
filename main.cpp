#include "main.h"

int main() {
    vector<Student> students;

    readInput(students);

    //if students vector is not empty, calculate final marks and output them
    if(!students.empty()){
        output(students);
    }

    return 0;
}

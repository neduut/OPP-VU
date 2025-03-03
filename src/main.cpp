#include "mylib.h"
#include "utils.h"
#include "functions.h"
#include "timeMeasurement.h"
#include <windows.h>
   
int main() {

    // enable lithuanian characters in console
    SetConsoleOutputCP(65001);

    generateFile(10000);

    vector<Student> students;
    handleMenu(students);

    return 0;
}

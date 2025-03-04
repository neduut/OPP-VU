#include "mylib.h"
#include "utils.h"
#include "functions.h"
#include "timeMeasurement.h"
#include <windows.h>
   
int main() {

    // enable lithuanian characters in console
    SetConsoleOutputCP(65001);

    vector<Student> students;

    run_speed_test_1(10000);
    run_speed_test_2(10000);

    //handleMenu(students);

    return 0;
}

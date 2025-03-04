#include "mylib.h"
#include "utils.h"
#include "functions.h"
#include "timeMeasurement.h"
#include <windows.h>
   
int main() {

    // enable lithuanian characters in console
    SetConsoleOutputCP(65001);

    //run_speed_test_1(10000);
    //run_speed_test_2(10000);
    // sita idet i tas funkcijas laiko matavimo generateFile(10000);

    vector<Student> students;
    handleMenu(students);

    return 0;
}

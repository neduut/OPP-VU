#include "mylib.h"
#include "utils.h"
#include "functions.h"
#include <windows.h>
   
int main() {

    // enable lithuanian characters in console
    SetConsoleOutputCP(65001);

    vector<Student> students;

    run_speed_test_1(1000, "assets/runTimeResults.txt");
    run_speed_test_2(1000, "assets/runTimeResults.txt");

    //handleMenu(students);

    return 0;
}

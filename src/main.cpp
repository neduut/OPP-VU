#include "mylib.h"
#include "utils.h"
#include "functions.h"
#include <windows.h>
   
int main() {

    // enable lithuanian characters in console
    SetConsoleOutputCP(65001);

    vector<Student> students;

    // pirma susikurt faila, tada ji uzarchivuot
    speedTest1(10000000, "assets/runTimeResults.txt");
    // paskui atlikti 5 testus su tuo paciu failu
    speedTest2(10000000, "assets/runTimeResults.txt");

    handleMenu(students); 

    return 0;
}

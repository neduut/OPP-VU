#include "mylib2.h"
#include "utils2.h"
#include "functions2.h"
#include <windows.h>

int main() {

    // enable lithuanian characters in console
    SetConsoleOutputCP(65001);

    list<Student> students;

    // ar testavimas ar programa
    int choice = getMenuChoice();

    if (choice == 1) {
        handleProgramMenu(students);
    } else if (choice == 2) {
        handleTestMenu();
    } else {
        cout << "Kaip sau nori.\n";
    }

    return 0;
}


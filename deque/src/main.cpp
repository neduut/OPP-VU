#include "mylib1.h"
#include "utils1.h"
#include "functions1.h"
#include <windows.h>

int main() {

    // enable lithuanian characters in console
    SetConsoleOutputCP(65001);

    deque<Student> students;

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


#include "main.h"

int main() {
    
    #define USE_VECTOR 

    #ifdef USE_VECTOR
        std::vector<StudentVector> students;
    #else
        std::vector<StudentMixed> students;
    #endif
    
    string finalType;
    while (true) {
        cout << ENTER_FINAL_TYPE;
        cin >> finalType;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        if (isFinalTypeValid(finalType)) {
            break; 
        }
        cout << INVALID_FINAL_TYPE_ERROR;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        string menuChoice;
        while (true) {
            cout << MENU_TEXT;
            cin >> menuChoice;
            if (isMenuChoiceValid(menuChoice)) break;
            cout << INVALID_MENU_CHOICE;
            cin.clear();    
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (menuChoice == "4") {
            // if students vector is not empty, calculate and output final marks
            if (!students.empty()) {
                output(students, finalType);
            }
            break;
        }

        readInput(students, menuChoice);
    }

    return 0;
}

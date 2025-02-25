    #include "main.h"

    #ifdef USE_VECTOR
    vector<StudentVector> students;
    #else
    vector<StudentMixed> students;
    #endif

    int main() {
        string finalType;
        while (true) {
            cout << ENTER_FINAL_TYPE;
            cin >> finalType;
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

            if (menuChoice == "5") {
                // if students vector is not empty, calculate and output final marks
                if (!students.empty()) {
                    output(students, finalType);
                }
                break;
            }
            else if  (menuChoice == "4") readFromFile(students);
            else readInput(students, menuChoice);
        }

        return 0;
    }

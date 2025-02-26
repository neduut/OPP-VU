    #include "main.h"

    // i ekrana su buferiu, i ostringstreama su reserve ir suskaiciuot eilutes

    int main() {
        //ar geriau ji definint ar palikt cia maine
        vector<StudentVector> students;

        // median or average
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

        // print to screen or file
        string printType;
        while (true) {
            cout << ENTER_PRINT_TYPE;
            cin >> printType;
            if (isFinalPrintValid(printType)) {
                break;  
            }
            cout << INVALID_PRINT_TYPE_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // main menu
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
                    //pabandyt idet ta shrink_to_fit
                    output(students, finalType, printType);
                }
                break;
            }
            else if  (menuChoice == "4") readFromFile(students, finalType);
            else readInput(students, menuChoice, finalType);
        }

        return 0;
    }

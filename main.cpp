#include "main.h"

int main() {
    
    #define USE_VECTOR 

    #ifdef USE_VECTOR
        std::vector<StudentVector> students;
    #else
        std::vector<StudentMixed> students;
    #endif

    while (true) {
        cout << "\n1 - Ivesti viska rankiniu budu" << endl;
        cout << "2 - Generuoti atsitiktinius pazymius (vardus ivesti ranka)" << endl;
        cout << "3 - Generuoti atsitiktinius vardus ir pazymius" << endl;
        cout << "4 - Uzdaryti programa" << endl;
        
        string choice;
        cin >> choice;

        if(!isMenuChoiceValid(choice)){
            cout << INVALID_MENU_CHOICE;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == "4"){
            //if students vector is not empty, calculate final marks and output them
            if(!students.empty()){
             output(students);
            }
            break;
        }
        readInput(students, choice);
    }
    return 0;
}

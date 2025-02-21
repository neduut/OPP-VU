#include "main.h"

int main() {
    
    //version for vector.cpp
    //vector<StudentVector> students;

    //version for mixed.cpp
    vector<StudentMixed> students;

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


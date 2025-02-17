#include "main.h"


//user prompts

void ENTER_FIRST_NAME() { cout << "Iveskite varda (norint sustoti iveskite -1): "; }
void ENTER_LAST_NAME() { cout <<  "Iveskite pavarde: "; }
void ENTER_MARK() { cout <<  "Iveskite namu darbu pazymi (norint sustoti iveskite -1): "; }


//errors

void INVALID_FIRST_NAME_ERROR() { cout <<  "Ivestas netinkamas vardas"; }
void INVALID_LAST_NAME_ERROR() { cout <<  "Ivesta netinkama pavarde"; }
void INVALID_MARK_ERROR() { cout <<  "Pazymys turi buti sveikasis skaicius nuo 1 iki 10"; }
void INVALID_EXAM_MARK_ERROR() { cout <<  "Egzamino pazymys turi buti sveikasis skaicius nuo 1 iki 10"; }


//checks
//bool isNameValid(string name)
//bool isMarkValid(string mark)


//program functions

void readInput(vector<Student>& students){
    while(true){
        ENTER_FIRST_NAME();
        string firstName;
        cin >> firstName;
        if(firstName == "-1") break;
        /*if (!isNameValid(firstName)){
            INVALID_FIRST_NAME_ERROR();
            continue;
        }*/

        ENTER_LAST_NAME();
        string lastName;
        cin >> lastName;
        /*if(!isNameValid(lastName)){
            INVALID_LAST_NAME_ERROR();
            continue;
        }*/

        vector<int> marks;
        string tempMark;
        while (true) {
            ENTER_MARK();
            cin >> tempMark;
            if (tempMark == "-1") break;
            /*if(!isMarkValid(tempMark)){
                INVALID_MARK_ERROR();
                continue;
            }*/
        int mark = stoi(tempMark);
        marks.push_back(mark);
        }

        students.push_back({firstName, lastName, marks});
    }

};

//calculateFinalMark(vector<Student>& students);
//output(vector<Student>& students);


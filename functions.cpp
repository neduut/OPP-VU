#include "main.h"
#include "functions.h"

// user prompts
void ENTER_FIRST_NAME() { cout << "Iveskite varda (norint sustoti iveskite -1): "; }
void ENTER_LAST_NAME() { cout << "Iveskite pavarde: "; }
void ENTER_MARK() { cout << "Iveskite namu darbu pazymi (norint sustoti iveskite -1): "; }

// errors
void INVALID_FIRST_NAME_ERROR() { cout << "Klaida: ivestas netinkamas vardas! "; }
void INVALID_LAST_NAME_ERROR() { cout << "Klaida: ivesta netinkama pavarde! "; }
void INVALID_MARK_ERROR() { cout << "Klaida: pazymys turi buti sveikasis skaicius nuo 1 iki 10! "; }
void INVALID_EXAM_MARK_ERROR() { cout << "Klaida: egzamino pazymys turi buti sveikasis skaicius nuo 1 iki 10! "; }

// checks
bool isNameValid(string name) {
    for (char c : name) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool isMarkValid(string mark) {
    for (char c : mark) {
        if (!isdigit(c)) return false;
    }
    int markInt = stoi(mark);
    if (markInt < 1 || markInt > 10) return false;
    return true;
}

// program functions
void readInput(vector<Student>& students) {
    while (true) {
        ENTER_FIRST_NAME();
        string firstName;
        cin >> firstName;
        if (firstName == "-1") break;
        if (!isNameValid(firstName)) {
            INVALID_FIRST_NAME_ERROR();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        string lastName;
        while (true) {
            ENTER_LAST_NAME();
            cin >> lastName;
            if (isNameValid(lastName)) break;
            INVALID_LAST_NAME_ERROR();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<int> marks;
        string tempMark;
        while (true) {
            ENTER_MARK();
            cin >> tempMark;
            if (tempMark == "-1") break;
            if (!isMarkValid(tempMark)) {
                INVALID_MARK_ERROR();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            marks.push_back(stoi(tempMark));
        }

        while (true) {
            cout << "Iveskite egzamino pazymi: ";
            cin >> tempMark;
            if (!isMarkValid(tempMark)) {
                INVALID_EXAM_MARK_ERROR();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        int examMark = stoi(tempMark);

        students.push_back(Student{firstName, lastName, marks, examMark});
    }
}

void calculateFinalMark(vector<Student>& students)
{
    for (Student& student : students) {
        double sum = 0;
        for (int mark : student.marks) {
            sum += mark;
        }
        sum += student.examMark;
        student.finalMark = sum / (double(student.marks.size()+1));
    }
};

void output(vector<Student>& students)
{
    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Vid.)" << endl; 
    cout << "----------------------------------------------" << endl;
    for (Student student : students) {
        cout << left << setw(15) << student.firstName << setw(15) << student.lastName << fixed << setprecision(2) << student.finalMark << endl;
    }
};


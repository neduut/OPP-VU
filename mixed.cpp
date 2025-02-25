#include "mixed.h"

void readInput(vector<StudentMixed>& students, string menuChoice) {
    string choice;
    do {
        StudentMixed tempStudent;
        tempStudent.marks = nullptr;
        tempStudent.marksCount = 0;

        // first and last name
        string firstName;
        string lastName;
        if (menuChoice == "1" || menuChoice == "2") {
            cout << ENTER_FIRST_NAME;
            cin >> firstName;
            if (!isNameValid(firstName)) {
                cout << INVALID_FIRST_NAME_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            while (true) {
                cout << ENTER_LAST_NAME;
                cin >> lastName;
                if (isNameValid(lastName)) break;
                cout << INVALID_LAST_NAME_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            firstName = getRandomFirstName();
            lastName = getRandomLastName();
            cout << "Studentas: " << firstName << " " << lastName << endl;
        }

        tempStudent.firstName = firstName;
        tempStudent.lastName = lastName;

        // homework marks
        if (menuChoice == "1") {
            string tempMark;
            do {
                cout << ENTER_MARK_IN_MIXED;
                cin >> tempMark;
                if (!isMarkValid(tempMark)) {
                    cout << INVALID_MARK_ERROR;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                int mark = stoi(tempMark);
                
                int* newMarks = new int[tempStudent.marksCount + 1];
                for (int i = 0; i < tempStudent.marksCount; ++i) {
                    newMarks[i] = tempStudent.marks[i];
                }
                newMarks[tempStudent.marksCount] = mark;
                delete[] tempStudent.marks;
                tempStudent.marks = newMarks;
                tempStudent.marksCount++;
                
                while (true) {
                    cout << ADD_ANOTHER_MARK << endl;
                    cin >> choice;
                    if (isChoiceValid(choice)) break;
                    cout << INVALID_CHOICE;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            } while (choice == "taip");
        } else {
            tempStudent.marksCount = getRandomNumber();
            tempStudent.marks = new int[tempStudent.marksCount];
            for (int i = 0; i < tempStudent.marksCount; i++) {
                tempStudent.marks[i] = getRandomMark();
                cout << "Mark " << i + 1 << ": " << tempStudent.marks[i] << endl;
            }
        }

        // read exam mark
        int examMark;
        string tempExamMark;
        if (menuChoice == "1") {
            while (true) {
                cout << ENTER_EXAM_MARK;
                cin >> tempExamMark;
                if (!isMarkValid(tempExamMark)) {
                    cout << INVALID_EXAM_MARK_ERROR;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                examMark = stoi(tempExamMark);
                break;
            }
        } else {
            examMark = getRandomMark();
            cout << "Egzamino pazymys: " << examMark << endl;
        }

        tempStudent.examMark = examMark;
        students.push_back(tempStudent);

        while (true) {
            cout << ADD_ANOTHER_STUDENT << endl;
            cin >> choice;
            if (isChoiceValid(choice)) break;
            cout << INVALID_CHOICE;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice == "taip");
}

double averageFinalMark(const StudentMixed& student) {
    double sum = 0;
    for (int i = 0; i < student.marksCount; i++) {
        int mark = student.marks[i];
        sum += mark;
    }
    double average = sum / student.marksCount;
    return 0.4 * average + 0.6 * student.examMark;
}

double medianFinalMark(const StudentMixed& student) {
    vector<int> marks(student.marks, student.marks + student.marksCount);
    sort(marks.begin(), marks.end());
    double median;
    if (marks.size() % 2 == 0) {
        median = (marks[marks.size() / 2 - 1] + marks[marks.size() / 2]) / 2.0;
    } else {
        median = marks[marks.size() / 2];
    }
    return 0.4 * median + 0.6 * student.examMark;
}

void output(vector<StudentMixed>& students, string finalType) {
    if(finalType == "v") {
        cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl; 
        cout << "--------------------------------------------------" << endl;
        for (StudentMixed student : students) {
            double average = averageFinalMark(student);
            cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << average << endl;
        }
    } else {
        cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Med.)" << endl; 
        cout << "--------------------------------------------------" << endl;
        for (StudentMixed student : students) {
            double median = medianFinalMark(student);
            cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << median << endl;
        }
    }
}
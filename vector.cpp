#include "vector.h"

void readInput(vector<StudentVector>& students) {
    while (true) {
        // read first name
        cout << ENTER_FIRST_NAME;
        string firstName;
        cin >> firstName;
        if (firstName == "-1") break;
        if (!isNameValid(firstName)) {
            cout << INVALID_FIRST_NAME_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // read last name
        string lastName;
        while (true) {
            cout << ENTER_LAST_NAME;
            cin >> lastName;
            if (isNameValid(lastName)) break;
            cout << INVALID_LAST_NAME_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // read homework marks
        vector<int> marks;
        string tempMark;
        while (true) {
            cout << ENTER_MARK;
            cin >> tempMark;
            if (tempMark == "-1") break;
            if (!isMarkValid(tempMark)) {
                cout << INVALID_MARK_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            marks.push_back(stoi(tempMark));
        }

        // read exam mark
        while (true) {
            cout << ENTER_EXAM_MARK;
            cin >> tempMark;
            if (!isMarkValid(tempMark)) {
                cout << INVALID_EXAM_MARK_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        int examMark = stoi(tempMark);

        students.push_back(StudentVector{firstName, lastName, marks, examMark});
    }
}

double averageFinalMark(const StudentVector& student)
{
    double sum = 0;
    for (int mark : student.marks) {
        sum += mark;
    }
    double average = sum / student.marks.size();
    return 0.4 * average + 0.6 * student.examMark;
}

double medianFinalMark(const StudentVector& student)
{
    vector<int> marks = student.marks;
    sort(marks.begin(), marks.end());
    double median;
    if (marks.size() % 2 == 0) {
        median = (marks[marks.size() / 2 - 1] + marks[marks.size() / 2]) / 2.0;
    } else {
        median = marks[marks.size() / 2];
    }
    return 0.4 * median + 0.6 * student.examMark;
}

void output(vector<StudentVector>& students)
{
    while(true){
        string finalType;
        cout << ENTER_FINAL_TYPE;
        cin >> finalType;
    
        if(finalType == "v") {
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl; 
            cout << "--------------------------------------------------" << endl;
            for (StudentVector student : students) {
                double average = averageFinalMark(student);
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << average << endl;
            }
            break;
        } else if (finalType == "m") {
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Med.)" << endl; 
            cout << "--------------------------------------------------" << endl;
            for (StudentVector student : students) {
                double median = medianFinalMark(student);
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << median << endl;
            }
            break;
        }
        else {
            cout << INVALID_FINAL_TYPE_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
}

#include "vector.h"

int main() {
    vector<Student> students;

    readInput(students);

    //if students vector is not empty, calculate final marks and output them
    if(!students.empty()){
        output(students);
    }

    return 0;
}

void readInput(vector<Student>& students) {
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

        students.push_back(Student{firstName, lastName, marks, examMark});
    }
}

double averageFinalMark(vector<Student>& students)
{
    double result = 0.0;
    for (Student& student : students) {
        double sum = 0;
        for (int mark : student.marks) {
            sum += mark;
        }
        sum += student.examMark;
        result = sum / (double(student.marks.size()+1));
    }
    return result;
}

double medianFinalMark(vector<Student>& students)
{
    double result = 0.0;
    for (Student& student : students) {
        vector<int> marks = student.marks;
        marks.push_back(student.examMark);
        sort(marks.begin(), marks.end());
        if (marks.size() % 2 == 0) {
            result = (marks[marks.size() / 2 - 1] + marks[marks.size() / 2]) / 2.0;
        } else {
            result = marks[marks.size() / 2];
        }
    }
    return result;
}

void output(vector<Student>& students)
{
    while(true){
        string finalType;
        cout << ENTER_FINAL_TYPE;
        cin >> finalType;
    
        if(finalType == "v") {
            double average = averageFinalMark(students);
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl; 
            cout << "---------------------------------------------------------------------" << endl;
            for (Student student : students) {
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << average << endl;
            }
        } else if (finalType == "m") {
            double median = medianFinalMark(students);
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Med.)" << endl; 
            cout << "---------------------------------------------------------------------" << endl;
            for (Student student : students) {
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << median << endl;
            }
        }
        else {
            cout << INVALID_FINAL_TYPE_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
}

// used vector for students and dynamic c array for marks
#include "mixed.h"

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

        Student student(firstName, lastName, 0);

        // read homework marks
        while (true) {
            string tempMark;
            cout << ENTER_MARK;
            cin >> tempMark;
            if (tempMark == "-1") break;
            if (!isMarkValid(tempMark)) {
                cout << INVALID_MARK_ERROR;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            int paz = stoi(tempMark);
            student.addMark(paz);
        }
        
        // read exam mark
        string tempMark;
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
        students.push_back(student);
    }
}

/*void averageFinalMark(vector<Student>& students)
{
    for (Student& student : students) {
        double sum = 0;
        for (int mark : student.marks) {
            sum += mark;
        }
        sum += student.examMark;
        student.finalMarkAverage = sum / (double(student.marks.size()+1));
    }
}*/

/*void medianFinalMark(vector<Student>& students)
{
    for (Student& student : students) {
        vector<int> marks = student.marks;
        marks.push_back(student.examMark);
        sort(marks.begin(), marks.end());
        if (marks.size() % 2 == 0) {
            student.finalMarkMedian = (marks[marks.size() / 2 - 1] + marks[marks.size() / 2]) / 2.0;
        } else {
            student.finalMarkMedian = marks[marks.size() / 2];
        }
    }
}*/

/*void output(vector<Student>& students)
{

    //perrasyt kaip paprasta statini masyva

    while(true){
        string finalType;
        cout << ENTER_FINAL_TYPE;
        cin >> finalType;
    
        if(finalType == "v") {
            averageFinalMark(students);
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl; 
            cout << "---------------------------------------------------------------------" << endl;
            for (Student student : students) {
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << student.finalMarkAverage << endl;
            }
        } else if (finalType == "m") {
            medianFinalMark(students);
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Med.)" << endl; 
            cout << "---------------------------------------------------------------------" << endl;
            for (Student student : students) {
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << student.finalMarkMedian << endl;
            }
        }
        else {
            cout << INVALID_FINAL_TYPE_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
}*/



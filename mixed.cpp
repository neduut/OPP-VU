#include "mixed.h"

void readInput(vector<StudentMixed>& students) {
    while (true) {
        // name input
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

        // last name input
        string lastName;
        while (true) {
            cout << ENTER_LAST_NAME;
            cin >> lastName;
            if (isNameValid(lastName)) break;
            cout << INVALID_LAST_NAME_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        StudentMixed student;
        student.firstName = firstName;
        student.lastName = lastName;

        // homework marks
        /*while (true) {
            string tempMark;
            cout << ENTER_MARK;
            cin >> tempMark;
            if (tempMark == "-1") break;
            if (!isMarkValid(tempMark)) {
                cout << INVALID_MARK_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            student.addMark(stoi(tempMark));
        }*/

        // homework marks count
        string numMarksStr;
        int numMarks;
        while (true) {
            cout << ENTER_MARKS_COUNT;
            cin >> numMarksStr;
            if (!isCountValid(numMarksStr)) {
                cout << INVALID_MARKS_COUNT_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            numMarks = stoi(numMarksStr);
            break;
        }

        student.marksCount = numMarks;

        // homework marks 
        for (int i = 0; i < numMarks; i++) {
            while (true) {
                string tempMark;
                cout << "Pazymys " << (i + 1) << ": ";
                cin >> tempMark;

                if (!isMarkValid(tempMark)) {
                    cout << INVALID_MARK_ERROR;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                student.marks[i] = stoi(tempMark);
                break;
            }
        }

        // exam mark
        string tempExamMark;
        while (true) {
            cout << ENTER_EXAM_MARK;
            cin >> tempExamMark;
            if (!isMarkValid(tempExamMark)) {
                cout << INVALID_EXAM_MARK_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            student.examMark = stoi(tempExamMark);
            break;
        }

        students.push_back(student);
    }
}

double averageFinalMark(vector<StudentMixed>& students){
    double average = 0.0;
    for (StudentMixed& student : students) {
        double sum = 0;
        for (int i = 0; i < student.marksCount; i++) {
            sum += student.marks[i];
        }
        average = sum / (double(student.marksCount + 1));
        average = 0.4 * average + 0.6 * student.examMark;
    }
    return average;
}

double medianFinalMark(vector<StudentMixed>& students){
    double median = 0.0;
    double finalMark = 0.0;
    for (StudentMixed& student : students) {
        vector<int> tempMarks;
        for (int i = 0; i < student.marksCount; i++) {
            tempMarks.push_back(student.marks[i]);  
        }
        sort(tempMarks.begin(), tempMarks.end());

        size_t size = tempMarks.size();
        if (size % 2 == 0) {
            median = (tempMarks[size / 2 - 1] + tempMarks[size / 2]) / 2.0;
        } else {
            median = tempMarks[size / 2];
        }
        return 0.4 * median + 0.6 * student.examMark;
    }
}

void output(vector<StudentMixed>& students)
{
    while(true) {
        string finalType;
        cout << ENTER_FINAL_TYPE;
        cin >> finalType;
    
        if (finalType == "v") { 
            double average = averageFinalMark(students);
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl; 
            cout << "--------------------------------------------------" << endl;
            for (StudentMixed& student : students) {
                cout << left << setw(17) << student.lastName 
                     << setw(17) << student.firstName 
                     << setw(19) << fixed << setprecision(2) << average << endl;
            }
            break;
        } 
        else if (finalType == "m") {
            double median = medianFinalMark(students);  
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Med.)" << endl; 
            cout << "--------------------------------------------------" << endl;
            for (StudentMixed& student : students) {
                cout << left << setw(17) << student.lastName 
                     << setw(17) << student.firstName 
                     << setw(19) << fixed << setprecision(2) << median << endl;
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




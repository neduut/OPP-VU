#include "mixed.h"

/*void readInput(vector<StudentMixed>& students) {
    int size = 0;
    int capacity = 1;
    StudentMixed* student = new StudentMixed[capacity];

    while(true) {
        if (size == capacity) {
            capacity ++;
            StudentMixed* temp = new StudentMixed[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = student[i];
                }
            delete[] student;
            student = temp;
        }

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

        student[size].firstName = firstName;
        student[size].lastName = lastName;

        // homework marks
        int index = 0;
        while (true) {
            string tempMark;
            cout << ENTER_MARK;
            cin >> tempMark;

            if (tempMark == "-1") break;
            if (!isMarkValid(tempMark)) {
                cout << INVALID_MARK_ERROR << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            // if there is no space in the array, increase the size
            if (index == student[size].marksCapacity) {
                student[size].marksCapacity++;
                int* newMarks = new int[student[size].marksCapacity];
                // copy old array to new array
                for (int i = 0; i < index; i++) {
                    newMarks[i] = student[size].marks[i];
                }
                // free old array and assign new array to the pointer
                delete[] student[size].marks;
                student[size].marks = newMarks;
            }
            // add mark to the array
            
            student[size].marks[index] = stoi(tempMark);
            index++;

        }

        student[size].marksCount = index;

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
            student[size].examMark = stoi(tempExamMark);
            break;
        }
        size++;
    }

    for (int i = 0; i < size; i++) {
        students.push_back(student[i]);
    }

    delete[] student;
}*/

void readInput(vector<StudentMixed>& students) {
    string firstName;
    string lastName;
    while (true) {
        // first name
        cout << ENTER_FIRST_NAME;
        
        cin >> firstName;
        if (firstName == "-1") break;
        if (!isNameValid(firstName)) {
            cout << INVALID_FIRST_NAME_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // last name
        while (true) {
            cout << ENTER_LAST_NAME;
            cin >> lastName;
            if (isNameValid(lastName)) break;
            cout << INVALID_LAST_NAME_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // homework marks
        int size;
        cout << "Iveskite pazymiu kieki: " << endl;
        cin >> size;
        int* marks2 = new int[size];
        string tempMark;
        for (int i = 0; i < size; i++) {
                cout << ENTER_MARK;
                cin >> tempMark;
                if (!isMarkValid(tempMark)) {
                    cout << INVALID_MARK_ERROR;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                marks2[i] = stoi(tempMark);
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
        
        students.push_back({firstName, lastName, marks2, size, examMark});
    }
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

void output(vector<StudentMixed>& students)
{
    while(true){
        string finalType;
        cout << ENTER_FINAL_TYPE;
        cin >> finalType;
    
        if(finalType == "v") {
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl; 
            cout << "--------------------------------------------------" << endl;
            for (StudentMixed student : students) {
                double average = averageFinalMark(student);
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << average << endl;
            }
            break;
        } else if (finalType == "m") {
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Med.)" << endl; 
            cout << "--------------------------------------------------" << endl;
            for (StudentMixed student : students) {
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
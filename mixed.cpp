#include "mixed.h"

void readInput(vector<StudentMixed>& students, string choice) {
    while (true) {
        if (choice == "3" && students.size() > 0) {
            cout << "Ar norite ivesti studenta? (taip/ne)" << endl;
            string choice;
            cin >> choice;
            if (choice == "ne") break;
            if (!isChoiceValid(choice)) {
                cout << INVALID_CHOICE;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            choice = "1";
        }

        // first name
        string firstName;
        string lastName;
        if (choice == "1" || choice == "2") {
            cout << ENTER_FIRST_NAME;
            cin >> firstName;
            if (firstName == "-1") break;
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

        // homework marks
        int size;
        cout << "Iveskite pazymiu kieki: " << endl;
        cin >> size;
        int* marks2 = new int[size];
        if (choice == "1") {
            string tempMark;
            for (int i = 0; i < size; i++) {
                cout << ENTER_MARK;
                cin >> tempMark;
                if (!isMarkValid(tempMark)) {
                    cout << INVALID_MARK_ERROR;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    i--; // retry the current mark
                    continue;
                }
                marks2[i] = stoi(tempMark);
            }
        } else {
            for (int i = 0; i < size; i++) {
                marks2[i] = getRandomMark();
                cout << "Pazymys: " << marks2[i] << endl;
            }
        }

        // read exam mark
        int examMark;
        string tempMark;
        if (choice == "1") {
            while (true) {
                cout << ENTER_EXAM_MARK;
                cin >> tempMark;
                if (!isMarkValid(tempMark)) {
                    cout << INVALID_EXAM_MARK_ERROR;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                examMark = stoi(tempMark);
                break;
            }
        } else {
            examMark = getRandomMark();
            cout << "Egzamino pazymys: " << examMark << endl;
        }

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

void output(vector<StudentMixed>& students) {
    while (true) {
        string finalType;
        cout << ENTER_FINAL_TYPE;
        cin >> finalType;

        if (finalType == "v") {
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
        } else {
            cout << INVALID_FINAL_TYPE_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
}

//failed dynamic array implementation
/*void readInput(vector<StudentMixed>& students) {
    int size = 0;
    int capacity = 1;
    StudentMixed* student = new StudentMixed[capacity];

    while (true) {
        if (size == capacity) {
            capacity++;
            StudentMixed* temp = new StudentMixed[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = student[i];
            }
            delete[] student;
            student = temp;
        }

        student[size].marksCapacity = 1;
        student[size].marks = new int[student[size].marksCapacity];

        // First name input
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

        // Last name input
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

        // Homework marks input
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

            // Dynamic array resize
            if (index == student[size].marksCapacity) {
                student[size].marksCapacity *= 2; // Dvigubiname vietą, kad būtų efektyviau
                int* newMarks = new int[student[size].marksCapacity];

                for (int i = 0; i < index; i++) {
                    newMarks[i] = student[size].marks[i];
                }

                delete[] student[size].marks;
                student[size].marks = newMarks;
            }

            student[size].marks[index] = stoi(tempMark);
            index++;
        }

        student[size].marksCount = index;

        // Exam mark input
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

    for (int i = 0; i < size; i++) {
        delete[] student[i].marks;
    }
    delete[] student;
}
*/

//second failed try
/*void readInput(vector<StudentMixed>& students) {
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

        // Homework marks
        int* marks2 = nullptr; 
        int marksCount = 0;
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

            int* tempMarks = new int[marksCount + 1];
            for (int i = 0; i < marksCount; i++) {
                tempMarks[i] = marks2[i];
            }
            tempMarks[marksCount] = stoi(tempMark);

            delete[] marks2;
            marks2 = tempMarks;
            marksCount++;
        }

        // Exam mark
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

        students.push_back({firstName, lastName, marks2, marksCount, examMark});
    }
}*/

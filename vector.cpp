#include "vector.h"

void readInput(vector<StudentVector>& students, string menuChoice) {
    string choice;
    do {
        // first and last name
        string firstName;
        string lastName;

        if (menuChoice == "1" || menuChoice == "2") {
            while (true) {
                cout << ENTER_FIRST_NAME;
                cin >> firstName;
                if (isNameValid(firstName)) break;
                cout << INVALID_FIRST_NAME_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            while (true) {
                cout << ENTER_LAST_NAME;
                cin >> lastName;
                if (isNameValid(lastName)) break;
                cout << INVALID_LAST_NAME_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } 
        else {  
            firstName = getRandomFirstName();
            lastName = getRandomLastName();
            cout << "Studentas: " << firstName << " " << lastName << endl;
        }

        // homework marks
        vector<int> marks;
        if (menuChoice == "1") {
            string tempMark;
            while (true) {
                cout << ENTER_MARK;
                cin >> tempMark;

                if (tempMark == "-1" && marks.empty()) {  
                    cout << INVALID_MARKS_COUNT;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                } 
                else if (tempMark == "-1") break;

                if (!isMarkValid(tempMark)) {
                    cout << INVALID_MARK_ERROR;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                marks.push_back(stoi(tempMark));
            }
        } 
        else {
            int number = getRandomNumber();
            for (int i = 0; i < number; i++) {
                marks.push_back(getRandomMark());
                cout << "Pazymys " << i + 1 << ": " << marks[i] << endl;
            }
        }

        // read exam mark
        int examMark;
        string tempMark;
        if (menuChoice == "1") {
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
        } 
        else {
            examMark = getRandomMark();
            cout << "Egzamino pazymys: " << examMark << endl;
        }       

        students.push_back(StudentVector{firstName, lastName, marks, examMark});

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

void output(vector<StudentVector>& students, string finalType)
{
    while(true){
        if(finalType == "v") {
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.)" << endl; 
            cout << "--------------------------------------------------" << endl;
            for (StudentVector student : students) {
                double average = averageFinalMark(student);
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << average << endl;
            }
            break;
        } else{
            cout << left << setw(17) << "Pavarde" << setw(17) << "Vardas" << setw(17) << "Galutinis (Med.)" << endl; 
            cout << "--------------------------------------------------" << endl;
            for (StudentVector student : students) {
                double median = medianFinalMark(student);
                cout << left << setw(17) << student.firstName << setw(17) << student.lastName << setw(19) << fixed << setprecision(2) << median << endl;
            }
            break;
        }
    }
}

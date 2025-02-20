#include "vector.h"

void readInput(vector<StudentVector>& students, string choice) {
    while (true) {

        if(choice == "3" && students.size() > 0){
            cout << "Ar norite ivesti studenta? (taip/ne)" << endl;
            string choice;
            cin >> choice;
            if(choice == "ne") break;
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
        if(choice == "1" || choice == "2"){
            cout << ENTER_FIRST_NAME;
            firstName;
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

        }
        else{
            firstName = getRandomFirstName();
            lastName = getRandomLastName();
            cout << "Studentas: " << firstName << " " << lastName << endl;
        }

        // homework marks
        vector<int> marks;
        if(choice == "1"){
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
        }
        else{
            int mark = getRandomMark();
            marks.push_back(mark);
            cout << "Pazymys: " << mark << endl;
            while(true){
                cout << "Ar norite ivesti dar viena pazymi? (taip/ne)" << endl;
                string choice;
                cin >> choice;
                if(choice == "ne") break;
                if (!isChoiceValid(choice)) {
                    cout << INVALID_CHOICE;
                    cin.clear();    
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                int mark = getRandomMark();
                cout << "Pazymys: " << mark << endl;
                marks.push_back(mark);
            }
        }

        // read exam mark
        int examMark;
        string tempMark;
        if(choice == "1"){
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
        else{
            examMark = getRandomMark();
            cout << "Egzamino pazymys: " << examMark << endl;
        }       

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

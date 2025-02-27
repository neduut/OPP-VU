#include "vector.h"

void handleMenu(vector<Student>& students, const char& finalType) {
    while (true) {
        char menuChoice = getMenuChoice()[0];

        if (menuChoice == '5') {
            // If students vector is not empty, calculate and output final marks
            if (!students.empty()) {
                char sortType = getSortType()[0];
                char printType = getPrintType()[0];
                sortStudents(students, sortType);
        
                TimeMeasurement finalMarks("Rezultatu isvedimas");
                finalMarks.start();
                output(students, finalType, printType);
                finalMarks.stop();
            }
            break;
        }
        else if (menuChoice == '4') {
            TimeMeasurement fileRead("Failo nuskaitymas");
            fileRead.start();
            readFromFile(students, finalType);
            fileRead.stop();
        }
        else readInput(students, menuChoice, finalType);
    }
}

void readInput(vector<Student>& students, char menuChoice, char finalType) {
    students.reserve(10000);

    string choice;
    do {
        // first and last name
        string firstName = getFirstName(menuChoice);
        string lastName = getLastName(menuChoice);

        // homework marks
        vector<int> marks = getHomeworkMarks(menuChoice);

        // exam mark
        int examMark = getExamMark(menuChoice);     

        // final mark
        double finalMark = (finalType == 'v') ? averageFinalMark(marks, examMark) 
                                              : medianFinalMark(marks, examMark);

        students.push_back({firstName, lastName, marks, examMark, finalMark});

        while (true) {
            cout << ADD_ANOTHER_STUDENT << endl;
            cin >> choice;
            if (isChoiceValid(choice)) break;
            cout << INVALID_CHOICE;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice == "taip"); 

    students.shrink_to_fit();
}

void readFromFile(vector<Student>& students, char finalType) {
    students.reserve(1000000);

    ifstream file("studentai1000000.txt");
    if (!file) {
        cout << FILE_OPEN_ERROR << endl;
        return;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        istringstream stream(line);
        string firstName, lastName;
        stream >> firstName >> lastName;
        vector<int> marks;
        int mark;
        while (stream >> mark) {
            marks.push_back(mark);
        }
        int examMark = marks.back();
        marks.pop_back();

        double finalMark = (finalType == 'v') ? averageFinalMark(marks, examMark) 
                                              : medianFinalMark(marks, examMark);

        students.push_back({firstName, lastName, marks, examMark, finalMark});
    }

    cout << FILE_READ_SUCCESS << endl;
    file.close();
    students.shrink_to_fit();
}

double averageFinalMark(const vector<int>& marks, int examMark){
    double sum = 0;
    for (int mark : marks) {
        sum += mark;
    }
    double average = sum / marks.size();
    return 0.4 * average + 0.6 * examMark;
}

double medianFinalMark(const vector<int>& marks, int examMark){
    vector<int> sortedMarks = marks;
    sort(sortedMarks.begin(), sortedMarks.end());
    double median;
    if (sortedMarks.size() % 2 == 0) {
        median = (sortedMarks[sortedMarks.size() / 2 - 1] + sortedMarks[sortedMarks.size() / 2]) / 2.0;
    } else {
        median = sortedMarks[sortedMarks.size() / 2];
    }
    return 0.4 * median + 0.6 * examMark;
}

void sortStudents(vector<Student>& students, char sortType) {
    if (sortType == 'v') {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.firstName < b.firstName;
        });
    } else if (sortType == 'p') {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.lastName < b.lastName;
        });
    }
    else {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.finalMark > b.finalMark;
        });
    }
}

void output(vector<Student>& students, char finalType, char printType) {
    if (printType == 'e') {  
        string type = (finalType == 'v') ? "Vid." : "Med."; 

        cout << left << setw(17) << "Vardas"
             << setw(17) << "Pavarde"
             << setw(17) << type << endl; 
        cout << string(38, '-') << endl; 

        for (const auto& student : students) { 
            cout << left << setw(17) << student.firstName 
                 << setw(17) << student.lastName 
                 << setw(19) << fixed << setprecision(2) 
                 << student.finalMark << endl;
        }
    } else 
    {
        vector<string> lines; // Vector to store all lines before writing
        lines.reserve(students.size() + 2); // Reserve space for efficiency
    
        // Add the header
        ostringstream header;
        string type = (finalType == 'v') ? "Vid." : "Med.";
        header << left << setw(17) << "Vardas"
               << setw(17) << "Pavarde"
               << setw(17) << type << endl
               << string(38, '-') << endl;
        lines.push_back(header.str());
    
        // Collect student data into the vector
        for (const auto& student : students) {
            ostringstream ss;
            ss << left << setw(17) << student.firstName
               << setw(17) << student.lastName
               << setw(19) << fixed << setprecision(2)
               << student.finalMark << endl;
            lines.push_back(ss.str());
        }
    
        ofstream file("rezultatai.txt");
        if (!file) {
            cerr << FILE_OPEN_ERROR << endl;
            return;
        }
    
        // Write all lines to the file in one operation
        for (const auto& line : lines) {
            file.write(line.c_str(), line.size());
        }
    
        file.close();
        cout << FILE_WRITE_SUCCESS << endl;
    }
    
}

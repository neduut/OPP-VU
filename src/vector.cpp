#include "vector.h"
#include "utils.h"
#include "timeMeasurement.h"
#include "constants.h"

void handleMenu(vector<Student>& students, const char& finalType) {
    while (true) {
        char menuChoice = getMenuChoice()[0];

        if (menuChoice == '5') {
            // If students vector is not empty, calculate and output final marks
            if (!students.empty()) {
                char sortType = getSortType()[0];
                char printType = getPrintType()[0];
                cout << endl;
                sortStudents(students, sortType);
                output(students, finalType, printType);
            }
            break;
        }
        else if (menuChoice == '4') {
            readFromFile(students, finalType);
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
    try {
        students.reserve(1000000);

        ifstream file("assets/studetnai10000.txt");
        if (!file) {
            throw std::runtime_error(FILE_OPEN_ERROR);
        }
        //file.exceptions(ifstream::failbit | ifstream::badbit);// automatically throws exceptions on fail

        TimeMeasurement fileRead("Failo nuskaitymas");
        fileRead.start();

        file.ignore(numeric_limits<streamsize>::max(), '\n'); // skip the first line

        string line;
        while (getline(file, line)) {
            istringstream stream(line);
            string firstName, lastName;
            stream >> firstName >> lastName;
            
            vector<int> marks;
            int mark;
            while (stream >> mark) {
                marks.push_back(mark);
            }

            if (marks.empty()) throw std::runtime_error(EMPTY_ARRAY_ERROR);
            int examMark = marks.back();
            marks.pop_back();

            double finalMark = (finalType == 'v') ? averageFinalMark(marks, examMark) 
                                                  : medianFinalMark(marks, examMark);

            students.push_back({firstName, lastName, marks, examMark, finalMark});
        }

        file.close();
        fileRead.stop();
        cout << FILE_READ_SUCCESS << endl;
        students.shrink_to_fit();

    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
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
    try {
        if (sortType == 'v') {
            stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.firstName < b.firstName;
            });
        } else if (sortType == 'p') {
            stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.lastName < b.lastName;
            });
        } else {
            stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.finalMark > b.finalMark;
            });
        }
    } catch (const std::exception& e) {
        cerr << "Klaida rikiuojant: " << e.what() << endl;
    }
}

void output(vector<Student>& students, char finalType, char printType) {
    try {
        if (printType == 'e') {  
            string type = (finalType == 'v') ? "Vid." : "Med."; 

            cout << left << setw(17) << "Vardas"
                 << setw(17) << "Pavarde"
                 << setw(17) << type << '\n'; 
            cout << string(38, '-') << '\n'; 

            for (const auto& student : students) { 
                cout << left << setw(17) << student.firstName 
                     << setw(17) << student.lastName 
                     << setw(19) << fixed << setprecision(2) 
                     << student.finalMark << '\n';
            }
        } else {
            ofstream file("assets/rezultatai.txt");
            if (!file) {
                throw std::runtime_error(FILE_OPEN_ERROR);
            }
            //file.exceptions(ofstream::failbit | ofstream::badbit);// automatically throws exceptions on fail
        
            TimeMeasurement finalMarks("Rezultatu isvedimas");
            finalMarks.start();

            vector<string> lines; // vector to store all lines before writing
            lines.reserve(students.size() + 2); // reserve space for efficiency. +2 for header and separator
        
            // add the header
            ostringstream header;
            string type = (finalType == 'v') ? "Vid." : "Med.";
            header << left << setw(17) << "Vardas"
                   << setw(17) << "Pavarde"
                   << setw(17) << type << '\n'
                   << string(38, '-') << '\n';
            lines.push_back(header.str());
        
            // collect student data into the vector
            for (const auto& student : students) {
                ostringstream ss;
                ss << left << setw(17) << student.firstName
                   << setw(17) << student.lastName
                   << setw(19) << fixed << setprecision(2)
                   << student.finalMark << '\n';
                lines.push_back(ss.str());
            }

            // write all lines to the file in one operation
            for (const auto& line : lines) {
                file.write(line.c_str(), line.size());
            }

            file.close();
            finalMarks.stop();
            cout << FILE_WRITE_SUCCESS << endl;
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
    }
}


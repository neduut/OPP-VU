#include "functions.h"
#include "utils.h"
#include "timeMeasurement.h"
#include "constants.h"

void handleMenu(vector<Student>& students) {
    while (true) {
        int menuChoice = getMenuChoice();

        if (menuChoice == 5) {
            if (!students.empty()) {
                cout << endl;

                int groupType = getGroupType();  // by average or median?
                int sortType = getSortType();    // by first name, last name or final mark?
                int outputType = getPrintType(); // to console or to file?

                // KAZKAS CIA NE TAIP SU VEKTORIUM !!!!!!!!!!!!!!
                vector<Student> kietiakai;
                vector<Student> vargsiukai;

                // separate students into 2 groups
                groupStudents(students, kietiakai, vargsiukai, groupType);

                // sort students
                sortStudents(kietiakai, sortType);
                sortStudents(vargsiukai, sortType);

                if (outputType == 1) {
                    printToConsole(kietiakai, vargsiukai);
                } else {
                    printToFile(kietiakai, "kietiakuRezultatai.txt");
                    printToFile(vargsiukai, "vargsiukuRezultatai.txt");
                }
            }
            break;
        }
        else if (menuChoice == 4) {
            readFromFile(students);
        }
        else {
            readInput(students, menuChoice);
        }
    }
}

void readInput(vector<Student>& students, char menuChoice) {
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
        double avgFinal = averageFinalMark(marks, examMark);
        double medianFinal = medianFinalMark(marks, examMark);

        students.push_back({firstName, lastName, marks, examMark, avgFinal, medianFinal});

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

void readFromFile(vector<Student>& students) {
    try {
        int fileSize = getFileSize();
        students.reserve(fileSize); 
        
        ifstream file("assets/studentai" + to_string(fileSize) + ".txt");
        if (!file) {
            throw std::runtime_error(FILE_OPEN_ERROR);
        }
        //file.exceptions(ifstream::failbit | ifstream::badbit);// automatically throws exceptions on fail

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

        // final mark
        double avgFinal = averageFinalMark(marks, examMark);
        double medianFinal = medianFinalMark(marks, examMark);

        students.push_back({firstName, lastName, marks, examMark, avgFinal, medianFinal});
        }

        file.close();
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
        if (sortType == 1) {
            stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.firstName < b.firstName;
            });
        } else if (sortType == 2) {
            stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.lastName < b.lastName;
            });
        } else if (sortType == 3) { 
            stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.avgFinal < b.avgFinal;
            });
        } else {
            stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.medianFinal < b.medianFinal;
            });
        }
    } catch (const std::exception& e) {
        cerr << "Klaida rikiuojant: " << e.what() << endl;
    }
}

void groupStudents(vector<Student>& students, vector<Student>& kietiakai, vector<Student>& vargsiukai, char groupType) {
    try {
        if (groupType == 1) {
            for (const auto& student : students) {
                if (student.avgFinal >= 5) {
                    kietiakai.push_back(student);
                } else {
                    vargsiukai.push_back(student);
                }
            }
        } else {
            for (const auto& student : students) {
                if (student.medianFinal >= 5) {
                    kietiakai.push_back(student);
                } else {
                    vargsiukai.push_back(student);
                }
            }
        }
    } catch (const std::exception& e) {
        cerr << "Klaida grupuojant: " << e.what() << endl;
    }
}

void printToConsole(vector<Student>& kietiakai, vector<Student>& vargsiukai) {
    cout << left << setw(17) << "Vardas"
         << setw(17) << "Pavarde"
         << setw(19) << "Galutinis (Vid.)"
         << setw(19) << "Galutinis (Med.)" << '\n'; 
    cout << string(70, '-') << '\n'; 

    cout << "Kietiakai: " << endl;
    for (const auto& student : kietiakai) { 
        cout << left << setw(17) << student.firstName 
             << setw(17) << student.lastName 
             << setw(19) << fixed << setprecision(2) 
             << student.avgFinal  
             << setw(19) << fixed << setprecision(2) 
             << student.medianFinal 
             << '\n';
    }
    cout << "Vargsiukai: " << endl;
    for (const auto& student : vargsiukai) { 
        cout << left << setw(17) << student.firstName 
             << setw(17) << student.lastName 
             << setw(19) << fixed << setprecision(2) 
             << student.avgFinal  
             << setw(19) << fixed << setprecision(2) 
             << student.medianFinal 
             << '\n';
    }
}

void printToFile(vector<Student>& students, const string& fileName) {
    try {
        ofstream file("assets/" + fileName);
        if (!file) {
            throw std::runtime_error(FILE_OPEN_ERROR);
        }
        
        // file.exceptions(ofstream::failbit | ofstream::badbit); // automatically throws exceptions on fail

        vector<string> lines; // vector to store all lines before writing
        lines.reserve(students.size() + 2); // reserve space for efficiency, +2 for header and separator
        
        // add the header
        ostringstream header;
        header << left << setw(15) << "Vardas"
               << setw(15) << "Pavarde"
               << setw(20) << "Galutinis (Vid.)"
               << setw(20) << "Galutinis (Med.)" << '\n'
               << string(66, '-') << '\n'; 
        lines.push_back(header.str());
        
        // collect student data into the vector
        for (const auto& student : students) {
            ostringstream ss;
            ss << left << setw(15) << student.firstName
               << setw(15) << student.lastName
               << setw(20) << fixed << setprecision(2) << student.avgFinal
               << setw(20) << fixed << setprecision(2) << student.medianFinal
               << '\n';
            lines.push_back(ss.str());
        }

        // write all lines to the file in one operation
        for (const auto& line : lines) {
            file.write(line.c_str(), line.size());
        }

        file.close();
        cout << FILE_WRITE_SUCCESS << endl;

    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

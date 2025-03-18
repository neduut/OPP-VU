#include "functions.h"
#include "utils.h"
#include "constants.h"
#include "timeMeasurement.h"

void handleProgramMenu(vector<Student>& students) {
    while (true) {
        int menuChoice = getProgramMenuChoice();

        if (menuChoice == 5) {
            if (!students.empty()) {
                cout << endl;

                int groupType = getGroupType();  // by average or median?
                int sortType = getSortType();    // by first name, last name or final mark?
                int outputType = getPrintType(); // to console or to file?

                vector<Student> kietiakai;
                vector<Student> vargsiukai;

                // separate students into 2 groups
                groupStudents1(students, kietiakai, vargsiukai, groupType);

                students.clear(); // clear students vector
                kietiakai.shrink_to_fit();
                vargsiukai.shrink_to_fit();

                // sort students
                sortStudents(kietiakai, sortType);
                sortStudents(vargsiukai, sortType);

                // if output type is 1, print to console, if 2, print to file
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
            int fileSize = getFileSize();
            readFromFile(students, fileSize);
        }
        else {
            readInput(students, menuChoice);
        }
    }
}

void handleTestMenu() {
    while (true) {
        int testMenuChoice = getTestMenuChoice();

        if (testMenuChoice == 0) {
            break;
        }
        else if (testMenuChoice == 1) {
            int fileSize = getFileSize();
            speedTest(fileSize, "assets/runTimeResults.txt");
        }
        else if (testMenuChoice == 2) {
            int fileSize = getFileSize();
            strategies(fileSize, "assets/runTimeResults.txt", 1);
        }
        else if (testMenuChoice == 3) {
            int fileSize = getFileSize();
            strategies(fileSize, "assets/runTimeResults.txt", 2);
        }
        /*else if (testMenuChoice == 4) {
            int fileSize = getFileSize();
            srategy3(fileSize, "assets/runTimeResults.txt", 3);
        }*/
    }
}

void generateFile(int size) {
    try {
        string fileName = "assets/studentai" + to_string(size) + ".txt";
        ofstream file(fileName);
        if (!file) {
            throw std::runtime_error(FILE_OPEN_ERROR);
        }

        vector<string> lines;
        lines.reserve(size + 1); // Reserve space for size + 1 (header)

        // Add header
        ostringstream header;
        header << left << setw(15) << "Vardas"
               << setw(15) << "Pavardė";
        for (int j = 1; j <= 5; ++j) {  
            header << setw(8) << "ND" + to_string(j);
        }
        header << setw(10) << "Egzaminas" << '\n';
        lines.push_back(header.str());

        // Generate student data
        for (int i = 0; i < size; ++i) {
            ostringstream ss;
            ss << left << setw(15) << "Vardas" + to_string(i + 1)
               << setw(15) << "Pavardė" + to_string(i + 1);
            for (int j = 0; j < 5; ++j) {  
                ss << setw(8) << getRandomMark();  
            }
            ss << setw(10) << getRandomMark() << '\n';  // Add exam mark
            lines.push_back(ss.str());
        }

        // Write all lines to the file in one operation
        for (const auto& line : lines) {
            file.write(line.c_str(), line.size());
        }

        file.close();
        cout << FILE_WRITE_SUCCESS << fileName << endl;

    } catch (const std::exception& e) { 
        cerr << "Error: " << e.what() << endl;
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

        cout << ADD_ANOTHER_STUDENT << endl;
        choice = getYesNo();

    } while (choice == "taip"); 

    students.shrink_to_fit();
}

void readFromFile(vector<Student>& students, int fileSize) {
    try {
        students.reserve(fileSize); 
        
        ifstream file("assets/studentai" + to_string(fileSize) + ".txt");
        if (!file) {
            throw std::runtime_error(FILE_OPEN_ERROR);
        }

        file.ignore(numeric_limits<streamsize>::max(), '\n'); // skip the first line

        string firstName, lastName, line;
        while (getline(file, line)) {
            istringstream stream(line);
            stream >> firstName >> lastName;
            
            vector<int> marks;
            marks.reserve(6); 
            
            int mark;
            while (stream >> mark) {
                marks.push_back(mark);
            }

            if (marks.empty()) throw std::runtime_error(EMPTY_ARRAY_ERROR);
            
            int examMark = marks.back();
            marks.pop_back();
            
            double avgFinal = averageFinalMark(marks, examMark);
            double medianFinal = medianFinalMark(marks, examMark);
            
            students.emplace_back(Student{std::move(firstName), std::move(lastName), std::move(marks), examMark, avgFinal, medianFinal});
        }

        file.close();
        students.shrink_to_fit();
        cout << FILE_READ_SUCCESS << endl;

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
    // if sortType is 1, sort by first name
    if (sortType == 1) {
        stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.firstName < b.firstName;
        });
    // if sortType is 2, sort by last name
    } else if (sortType == 2) {
        stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.lastName < b.lastName;
        });
    // if sortType is 3, sort by average final mark
    } else if (sortType == 3) { 
        stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.avgFinal < b.avgFinal;
        });
    // if sortType is 4, sort by median final mark
    } else {
        stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.medianFinal < b.medianFinal;
        });
    }
}

void groupStudents1(vector<Student>& students, vector<Student>& kietiakai, vector<Student>& vargsiukai, char groupType) {
    for (const auto& student : students) {
        double finalMark = (groupType == 1) ? student.avgFinal : student.medianFinal;
        
        if (finalMark >= 5) {
            kietiakai.push_back(student);
        } else {
            vargsiukai.push_back(student);
        }
    }
}

void groupStudents2(vector<Student>& students, vector<Student>& kietiakai, vector<Student>& vargsiukai, char groupType) {
    for (auto it = students.begin(); it != students.end();) {
        double finalMark = (groupType == 1) ? it->avgFinal : it->medianFinal;

        if (finalMark < 5) {
            vargsiukai.push_back(*it);
            it = students.erase(it);  
        } else {
            ++it;  
        }
    }
    kietiakai.insert(kietiakai.end(), students.begin(), students.end());
    students.clear(); 
}

void printToConsole(vector<Student>& kietiakai, vector<Student>& vargsiukai) {
    cout << left << setw(17) << "Vardas"
         << setw(17) << "Pavarde"
         << setw(23) << "Galutinis (Vid.)"
         << setw(23) << "Galutinis (Med.)" << '\n'; 
    cout << string(80, '-') << '\n'; 

    cout << "Kietiakai: " << endl;
    for (const auto& student : kietiakai) { 
        cout << left << setw(17) << student.firstName 
             << setw(17) << student.lastName 
             << setw(23) << fixed << setprecision(2) 
             << student.avgFinal  
             << setw(23) << fixed << setprecision(2) 
             << student.medianFinal 
             << '\n';
    }
    cout << "Vargsiukai: " << endl;
    for (const auto& student : vargsiukai) { 
        cout << left << setw(17) << student.firstName 
             << setw(17) << student.lastName 
             << setw(23) << fixed << setprecision(2) 
             << student.avgFinal  
             << setw(23) << fixed << setprecision(2) 
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

        vector<string> lines;
        lines.reserve(students.size() + 2);

        ostringstream header;
        header << left << setw(15) << "Vardas"
               << setw(20) << "Pavarde"
               << setw(17) << "Galutinis (Vid.)" << '\n'
               << string(60, '-') << '\n';
        lines.push_back(header.str());

        for (const auto& student : students) {
            ostringstream ss;
            ss << setw(15) << left << student.firstName
               << setw(20) << student.lastName
               << setw(17) << fixed << setprecision(2) << student.avgFinal << '\n';
            lines.push_back(ss.str());
        }

        for (const auto& line : lines) {
            file.write(line.c_str(), line.size());
        }

        file.close();
        cout << "Rezultatai issaugoti faile: " << fileName << "\n";

    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void speedTest(int size, const std::string& fileName) {
    std::ofstream runTimeResults(fileName, std::ios::app); // open file in append mode

    if (runTimeResults.is_open()) {
        runTimeResults << "Vektorius\n";
        runTimeResults << "Failas: studentai" << size << ".txt\n";

        vector<Student> students;

        TimeMeasurement readTime("Duomenų nuskaitymas iš failo");
        readTime.start();
        readFromFile(students, size);
        readTime.stop(runTimeResults); 

        int sortType = getSortType(); 
        TimeMeasurement printTime("Studentų rikiavimas didėjimo tvarka");
        printTime.start();
        sortStudents(students, sortType);
        printTime.stop(runTimeResults);  

        vector<Student> kietiakai;
        vector<Student> vargsiukai;

        TimeMeasurement groupingTime("Studentų rūšiavimas į dvi grupes");
        groupingTime.start();
        groupStudents1(students, kietiakai, vargsiukai, 1);
        groupingTime.stop(runTimeResults); 

        students.clear(); 
        kietiakai.shrink_to_fit();
        vargsiukai.shrink_to_fit();

        runTimeResults << "\n";

        runTimeResults.close(); 
    } else {
        std::cerr << FILE_OPEN_ERROR << std::endl;
    }
    cout << "\nLaiko tyrimo rezultatai įrašyti į failą: " << fileName << "\n" << endl;
}

void strategies(int size, const std::string& fileName, int strategy) {
    std::ofstream runTimeResults(fileName, std::ios::app); 

    if (runTimeResults.is_open()) {
        runTimeResults << "Vektorius\n";
        runTimeResults << "Failas: studentai" << size << ".txt\n";
        TimeMeasurement groupingTime("Studentų rūšiavimas į dvi grupes (strategija 1)");

        vector<Student> students;
        vector<Student> kietiakai;
        vector<Student> vargsiukai;

        if (strategy == 1) {
            groupingTime.start();
            groupStudents1(students, kietiakai, vargsiukai, 1);
            groupingTime.stop(runTimeResults); 
        } else if (strategy == 2) {
            groupingTime.start();
            groupStudents2(students, kietiakai, vargsiukai, 1);
            groupingTime.stop(runTimeResults); 
        } /*else {
            groupingTime.start();
            groupStudents3(students, kietiakai, vargsiukai, 1);
            groupingTime.stop(runTimeResults); 
        }*/

        /*students.clear(); 
        kietiakai.shrink_to_fit();
        vargsiukai.shrink_to_fit();*/

        runTimeResults << "\n";

        runTimeResults.close(); 
    } else {
        std::cerr << FILE_OPEN_ERROR << std::endl;
    }
    cout << "\nLaiko tyrimo rezultatai įrašyti į failą: " << fileName << "\n" << endl;
}


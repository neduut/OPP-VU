#include "utils.h"
#include "constants.h"

static std::random_device rd;

// requests
int getSortType() {
    string sortType;
    while (true) {
        cout << ENTER_SORT_TYPE;
        cin >> sortType;
        if (stoi(sortType) >= 1 && stoi(sortType) <= 4) break;
        cout << INVALID_CHOICE;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return stoi(sortType);
}

int getPrintType() {
    string printType;
    while (true) {
        cout << ENTER_PRINT_TYPE;
        cin >> printType;
        if (stoi(printType) == 1 || stoi(printType) == 2) break;
        cout << INVALID_OUTPUT_TYPE_ERROR;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return stoi(printType);
}

int getMenuChoice() {
    string choice;
    while (true) {
        cout << MENU_TEXT;
        cin >> choice;
        if (stoi(choice) >= 1 && stoi(choice) <= 5) break;
        cout << INVALID_CHOICE;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return stoi(choice);
}

string getFirstName(char menuChoice) {
    string firstName;
    if (menuChoice == '1' || menuChoice == '2') {
        while (true) {
            cout << ENTER_FIRST_NAME;
            cin >> firstName;
            if (isNameValid(firstName)) break;
            cout << INVALID_FIRST_NAME_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } else {  
        firstName = getRandomFirstName();
        cout << "Studentas: " << firstName;
    }
    return firstName;
}

string getLastName(char menuChoice) {
    string lastName;
    
    if (menuChoice == '1' || menuChoice == '2') {
        while (true) {
            cout << ENTER_LAST_NAME;
            cin >> lastName;
            if (isNameValid(lastName)) break;
            cout << INVALID_LAST_NAME_ERROR;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } else {  
        lastName = getRandomLastName();
        cout << " " << lastName << endl;
    }
    return lastName;
}

int getExamMark(char menuChoice) {
    string tempMark;
    int examMark;
    if (menuChoice == '1') {
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
    return examMark;
}

vector<int> getHomeworkMarks(char menuChoice) {
    vector<int> marks;
    if (menuChoice == '1') {
        string tempMark;
        while (true) {
            cout << ENTER_MARK;
            cin >> tempMark;

            if (tempMark == "-1" && marks.empty()) {  
                cout << INVALID_MARKS_COUNT;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            } else if (tempMark == "-1") break;

            if (!isMarkValid(tempMark)) {
                cout << INVALID_MARK_ERROR;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            marks.push_back(stoi(tempMark));
        }
    } else {
        for (int i = 0; i < 6; i++) {
            marks.push_back(getRandomMark());
            cout << "Pazymys " << i + 1 << ": " << marks[i] << endl;
        }
    }
    return marks;
}

int getGroupType() {
    string groupType;
    while (true) {
        cout << ENTER_GROUP_TYPE;
        cin >> groupType;
        if (groupType == "1" || groupType == "2") break;
        cout << INVALID_GROUP_TYPE;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return stoi(groupType);
}

int getFileSize() {
    string size;
    while (true) {
        cout << ENTER_FILE_SIZE;
        cin >> size;
        if (stoi(size) >= 1 && stoi(size) <= 5) break;
        cout << INVALID_FILE_SIZE;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int sizeInt = stoi(size); 

    switch (sizeInt) {
        case 1: return 1000;
        case 2: return 10000;
        case 3: return 100000;
        case 4: return 1000000;
        case 5: return 10000000;
        default: return 0;
    }
}

// validations
bool isNameValid(string name) {
    for (char c : name) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool isMarkValid(string mark) {
    for (char c : mark) {
        if (!isdigit(c)) return false;
    }
    int markInt = stoi(mark);
    if (markInt < 1 || markInt > 10) return false;
    return true;
}

bool isChoiceValid(string choice) {
    if (choice != "taip" && choice != "ne") return false;
    return true;
}

// random generators
void generateFile(int size) {
    try {
        string fileName = "assets/studentai" + to_string(size) + ".txt";
        ofstream file(fileName);
        if (!file) {
            throw std::runtime_error(FILE_OPEN_ERROR);
        }

        vector<string> lines;
        lines.reserve(size + 1); //+1 for header

        ostringstream header;
        header << left << setw(15) << "Vardas"
               << setw(15) << "Pavardė";
        for (int j = 1; j <= 10; j++) {
            header << setw(8) << "ND" + to_string(j);
        }
        header << setw(10) << "Egzaminas" << '\n';
        lines.push_back(header.str());

        for (int i = 0; i < size; i++) {
            ostringstream ss;
            ss << left << setw(15) << "Vardas" + to_string(i + 1)
               << setw(15) << "Pavardė" + to_string(i + 1);
            for (int j = 0; j < 10; j++) {
                ss << setw(8) << getRandomMark();
            }
            ss << setw(10) << getRandomMark() << '\n';
            lines.push_back(ss.str());
        }

        // write all lines to the file in one operation
        for (const auto& line : lines) {
            file.write(line.c_str(), line.size());
        }

        file.close();
        cout << FILE_WRITE_SUCCESS << endl;

    } catch (const std::exception& e) { 
        cerr << "Klaida: " << e.what() << endl;
    }
}

string getRandomFirstName() {
    string names[] = {"Jonas", "Petras", "Mantas", "Dovydas", "Karolis", "Tomas", "Justinas", "Rokas", "Marius", "Aurimas"};
    return names[rand() % 10];
}

string getRandomLastName() {
    string surnames[] = {"Jonaitis", "Petraitis", "Kazlauskas", "Dargis", "Jankauskas", "Zujus", "Adomaitis", "Bagdonas", "Vasiliauskas", "Butkus"};
    return surnames[rand() % 10];
}

int getRandomMark() {
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> mark(1, 10);
    return mark(mt);
}

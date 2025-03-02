#include "utils.h"
#include "constants.h"

static std::random_device rd;

// requests
string getSortType() {
    string sortType;
    while (true) {
        cout << ENTER_SORT_TYPE;
        cin >> sortType;
        if (sortType == "v" || sortType == "p" || sortType == "g") break;
        cout << INVALID_CHOICE;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return sortType;
}

string getOutputType() {
    string outputType;
    while (true) {
        cout << ENTER_OUTPUT_TYPE;
        cin >> outputType;
        if (isOutputTypeValid(outputType)) break;
        cout << INVALID_OUTPUT_TYPE_ERROR;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return outputType;
}

string getMenuChoice() {
    string choice;
    while (true) {
        cout << MENU_TEXT;
        cin >> choice;
        if (isMenuChoiceValid(choice)) break;
        cout << INVALID_CHOICE;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
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
        for (int i = 0; i < 10; i++) {
            marks.push_back(getRandomMark());
            cout << "Pazymys " << i + 1 << ": " << marks[i] << endl;
        }
    }
    return marks;
}

string getGroupType() {
    string groupType;
    while (true) {
        cout << ENTER_GROUP_TYPE;
        cin >> groupType;
        if (isGroupTypeValid(groupType)) break;
        cout << INVALID_CHOICE;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return groupType;
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

bool isCountValid(string count) {
    for (char c : count) {
        if (!isdigit(c)) return false;
    }
    int countInt = stoi(count);
    if (countInt < 1) return false;
    return true;
}

bool isMenuChoiceValid(string choice) {
    for (char c : choice) {
        if (!isdigit(c)) return false;
    }
    int choiceInt = stoi(choice);
    if (choiceInt < 1 || choiceInt > 5) return false;
    return true;
}

bool isChoiceValid(string choice) {
    if (choice != "taip" && choice != "ne") return false;
    return true;
}

bool isSizeValid(string size) {
    for (char c : size) {
        if (!isdigit(c)) return false;
    }
    int sizeInt = stoi(size);
    if (sizeInt < 1) return false;
    return true;
}

bool isOutputTypeValid(string outputType) {
    if (outputType != "e" && outputType != "f") return false;
    return true;
}

bool isGroupTypeValid(string groupType) {
    if (groupType != "v" && groupType != "m") return false;
    return true;
}

// random generators
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

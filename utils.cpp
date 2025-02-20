#include "utils.h"

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
    if (choiceInt < 1 || choiceInt > 4) return false;
    return true;
}

bool isChoiceValid(string choice) {
    if (choice != "taip" && choice != "ne") return false;
    return true;
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
    return rand() % 10 + 1;
}
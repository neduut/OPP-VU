#include "TimeMeasurement.h"
#include "functions.h"

using namespace std::chrono;

// Constructor with a name
TimeMeasurement::TimeMeasurement(const std::string& name) {
    actionName = name;
}

// Start measurement
void TimeMeasurement::start() {
    startTime = high_resolution_clock::now();
}

// Stop measurement and display the time
void TimeMeasurement::stop() {
    endTime = high_resolution_clock::now();
    std::cout << "---> " << actionName << " took: " << getTimeDifference() << " s\n";
}

// Returns the time difference (ms)
double TimeMeasurement::getTimeDifference() {
    return duration<double>(endTime - startTime).count();
}

void run_speed_test_1(int size) {
    TimeMeasurement genTime("Failo generavimas");

    genTime.start();
    generateFile(size);
    genTime.stop();
}

void run_speed_test_2(int size) {
    TimeMeasurement programTime("Visos programos veikimo laikas");
    programTime.start();

    vector<Student> students;

    TimeMeasurement readTime("Duomenų nuskaitymas iš failo: ");
    readTime.start();
    readFromFile(students, size);
    readTime.stop();

    vector<Student> kietiakai;
    vector<Student> vargsiukai;

    TimeMeasurement groupingTime("Studentų rūšiavimas į dvi grupes: ");
    groupingTime.start();
    groupStudents(students, kietiakai, vargsiukai, 1);
    groupingTime.stop();

    TimeMeasurement printTime("Duomenų išvedimas į 2 failus: ");
    printTime.start();
    printToFile(kietiakai, "kietiakai.txt");
    printToFile(vargsiukai, "vargsiukai.txt");
    printTime.stop();

    programTime.stop();
 }

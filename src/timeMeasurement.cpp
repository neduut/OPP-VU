#include "TimeMeasurement.h"

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

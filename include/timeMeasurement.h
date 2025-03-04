#ifndef TIME_MEASUREMENT_H
#define TIME_MEASUREMENT_H

#include <chrono>
#include <iostream>

class TimeMeasurement {
private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
    std::string actionName;

public:
    // Constructor with an action name
    TimeMeasurement(const std::string& name);

    // Start measurement
    void start();

    // Stop measurement and display the time
    void stop();

    // Get time difference (ms)
    double getTimeDifference();
};

// void run_speed_test_1(int size);
// void run_speed_test_2(int size);

#endif

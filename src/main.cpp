#include "mylib.h"
#include "constants.h"
#include "utils.h"
#include "vector.h"
#include "timeMeasurement.h"
   
    int main() {

        TimeMeasurement program("Bendras programos vykdymas");
        program.start();

        vector<Student> students;
        char finalType = getFinalType()[0]; // average or median
        handleMenu(students, finalType);

        program.stop();

        return 0;
    }

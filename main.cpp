    #include "main.h"
   
    int main() {

        TimeMeasurement program("Bendras programos vykdymas");
        program.start();

        vector<Student> students;
        char finalType = getFinalType()[0]; // average or median
        handleMenu(students, finalType);

        program.stop();

        return 0;
    }

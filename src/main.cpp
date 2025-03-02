#include "mylib.h"
#include "utils.h"
#include "functions.h"
#include "timeMeasurement.h"
   
int main() {

    // settings to enable lithuanian characters
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stderr), _O_U8TEXT);

    TimeMeasurement program("Bendras programos vykdymas");
    program.start();

    vector<Student> students;
    handleMenu(students, sortType, printType);

    program.stop();

    return 0;
}

    #include "main.h"

    /*TO DOO
    1. i ekrana su buferiu, i ostringstreama su reserve ir suskaiciuot eilutes
    2. vietoj situ visu patikrinimu gal padaryt kaip paskaitoj sake su tuo auto (pasitikslint)
    */
   
    int main() {

        TimeMeasurement program("Bendras programos vykdymas");
        program.start();

        vector<Student> students;
        char finalType = getFinalType()[0]; // average or median
        handleMenu(students, finalType);

        program.stop();

        return 0;
    }

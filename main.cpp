    #include "main.h"

    /*TO DOO
    1. i ekrana su buferiu, i ostringstreama su reserve ir suskaiciuot eilutes
    2. vietoj situ visu patikrinimu gal padaryt kaip paskaitoj sake su tuo auto (pasitikslint)
    */
   
    int main() {

        vector<Student> students;
        char finalType = getFinalType()[0]; // average or median
        handleMenu(students, finalType);

        return 0;
    }

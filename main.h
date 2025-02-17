#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <limits>
#include <ios>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;


struct Student {
    string firstName;
    string lastName;
    vector<int> marks;
    int examMark;
    double finalMark;
};

#endif
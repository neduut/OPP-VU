#ifndef MAIN_H
#define MAIN_H

#include "mylib.h"
#include "constants.h"
#include "utils.h"

//#define USE_VECTOR

#ifdef USE_VECTOR
    #include "vector.h"
#else
    #include "mixed.h"
#endif

#endif // MAIN_H
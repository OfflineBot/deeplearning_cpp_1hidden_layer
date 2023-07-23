#ifndef MATRIX_H
#define MATRIX_H

#include "../types/vec.hpp"

typedef struct
{
    vec2<float> w1;
    vec1<float> b1;
    vec2<float> w2;
    vec1<float> b2; 
} Matrix;

#endif
#ifndef NORM_H
#define NORM_H

#include "../types/vec.hpp"

typedef struct {
    vec2<float> x;
    vec1<float> x_mean;
    vec1<float> x_std;
    vec2<float> x_norm;
    vec2<float> y;
    vec1<float> y_mean;
    vec1<float> y_std;
    vec2<float> y_norm;
} Normalize;

typedef struct {
    vec1<float> x_mean;
    vec1<float> x_std;
    vec1<float> y_mean;
    vec1<float> y_std;
} OutputNorm;

#endif
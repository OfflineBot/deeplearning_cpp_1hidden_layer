#ifndef ZERO_MATRIX_H
#define ZERO_MATRIX_H

#include "../types/vec.hpp"

vec2<float> zero_matrix(int rows, int cols) {
    vec2<float> result;

    vec1<float> array_slice;
    for (int col = 0; col < cols; col++) 
        array_slice.push_back(0.0);

    for (int row = 0; row < rows; row++)
        result.push_back(array_slice);

    return result;
}

#endif
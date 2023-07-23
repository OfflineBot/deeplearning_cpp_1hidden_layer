#ifndef DOT_H
#define DOT_H

#include <iostream>   
#include "../types/vec.hpp"
#include "../matrix/zero_matrix.hpp"

vec2<float> dot(vec2<float> array1, vec2<float> array2) {
    int rows = array1.size();
    int cols = array1[0].size();

    int array2_size = array2.size();
    int array2_i_size = array2[0].size();
    
    vec2<float> result = zero_matrix(rows, array2_i_size);
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            for (int i = 0; i < array2_i_size; i++) {
                result[row][i] += array1[row][col] * array2[col][i];
            }
        }
    }

    return result;
}

#endif
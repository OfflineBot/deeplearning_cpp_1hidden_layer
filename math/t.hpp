#ifndef T_H
#define	T_H

#include "../types/vec.hpp"

vec2<float> t(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();

    vec2<float> result;
    for (int col = 0; col < cols; col++) {
        vec1<float> array_slice;
        for (int row = 0; row < rows; row++) {
            array_slice.push_back(array[row][col]);
        }
        result.push_back(array_slice);
    }
    return result;
}

#endif
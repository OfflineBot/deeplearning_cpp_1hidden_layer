#ifndef SUM_H
#define SUM_H

#include "../types/vec.hpp"

vec1<float> sum(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();
    vec1<float> result;

    for (int col = 0; col < cols; col++) {
        float item = 0;
        for (int row = 0; row < rows; row++) {
            item += array[row][col];
        }
        result.push_back(item);
    }

    return result;
}

#endif
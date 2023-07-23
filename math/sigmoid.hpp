#ifndef SIGMOID_H
#define SIGMOID_H

#include <cmath>
#include "../types/vec.hpp"

vec2<float> sigmoid(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();
    vec2<float> result;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float value = 1.0 / (1.0 + exp(-array[row][col]));
            array_slice.push_back(value);
        }
        result.push_back(array_slice);
    }

    return result;
}

vec2<float> deriv_sigmoid(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();

    vec2<float> sig = sigmoid(array);
    vec2<float> result; 

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float value = 1.0 - sig[row][col];
            array_slice.push_back(value);
        }
        result.push_back(array_slice);
    }

    return result;
}

#endif
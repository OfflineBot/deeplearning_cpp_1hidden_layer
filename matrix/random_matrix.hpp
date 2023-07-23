#ifndef RANDOM_MATRIX_H
#define RANDOM_MATRIX_H

#include <random>

#include "../types/vec.hpp"

vec1<float> matrix_rand(int cols) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<float> distr(-1.0, 1.0);

    vec1<float> result;

    for (int i = 0; i < cols; i++) {
        result.push_back(distr(generator));
    }

    return result;
}

vec2<float> matrix_rand(int rows, int cols) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<float> distr(-1.0, 1.0);

    vec2<float> result;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            array_slice.push_back(distr(generator));
        }
        result.push_back(array_slice);
    }

    return result;
}

vec3<float> matrix_rand(int items, int rows, int cols) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<float> distr(-1.0, 1.0);

    vec3<float> result;

    for (int item = 0; item < items; item++) {
        vec2<float> array_slice;
        for (int row = 0; row < rows; row++) {
            vec1<float> array_slice1;
            for (int col = 0; col < cols; col++) {
                array_slice1.push_back(distr(generator));
            }
            array_slice.push_back(array_slice1);
        }
        result.push_back(array_slice);
    }

    return result;
}

#endif
#ifndef TESTING_H
#define TESTING_H

#include <iostream>

#include "types/vec_import.hpp"
#include "math/dot.hpp"
#include "math/t.hpp"
#include "math/sum.hpp"


void println(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%f, ", array[row][col]);
        }
        printf("\n");
    }
}

void println(vec1<float> array) {
    int rows = array.size();

    for (int row = 0; row < rows; row++) {
        printf("%f, ", array[row]);
    }
    printf("\n");
}


int test() {
    vec2<float> input_arr = {
        {1.0, 1.0},
        {0.0, 0.0},
        {1.0, 0.0},
        {0.0, 1.0},
    };
    vec2<float> output_arr = {
        {1.0},
        {0.0},
        {0.5},
        {0.5},
    };
    DeepLearning dl;

    Normalize norm = dl.normalize(input_arr, output_arr);

    Matrix matrix = dl.init_matrix(2, 10, 1, 5);

    TrainingData data = dl.train(40, 0.001, matrix, norm);

    printf("enddata: w1:\n");
    println(data.matrix.w1);
    return 0;
}

#endif
#ifndef UPDATE_MATRIX_H
#define UPDATE_MATRIX_H

#include <iostream>

#include "../network.hpp"
#include "../types/vec_import.hpp"
#include "../math/all_math_import.hpp"

Matrix DeepLearning::update_matrix(Matrix matrix, Normalize norm, ZAStorage za_storage, DeltaStorage delta_storage, float learning_rate) {
    matrix.w1 = matrix.w1 - dot(t(norm.x_norm), delta_storage.delta1) * learning_rate;
    matrix.b1 = matrix.b1 - sum(delta_storage.delta1) * learning_rate;
    matrix.w2 = matrix.w2 - dot(t(za_storage.a1), delta_storage.delta2) * learning_rate;
    matrix.b2 = matrix.b2 - sum(delta_storage.delta2) * learning_rate;

    return matrix;
}

#endif
#ifndef PROPAGATION_H
#define PROPAGATION_H

#include <iostream>
#include "../network.hpp"
#include "../types/vec_import.hpp"
#include "../math/all_math_import.hpp"
#include "../testing.hpp"

ZAStorage DeepLearning::forward(Matrix matrix, Normalize norm) {


    vec2<float> z1 = dot(norm.x_norm, matrix.w1) + matrix.b1;
    vec2<float> a1 = sigmoid(z1);
    vec2<float> z2 = dot(a1, matrix.w2) + matrix.b2;

    return ZAStorage {
        z1,
        a1,
        z2,
    };
}

DeltaStorage DeepLearning::backward(Matrix matrix, Normalize norm, ZAStorage za_storage) {

    vec2<float> delta2 = za_storage.z2 - norm.y_norm * deriv_sigmoid(za_storage.z2);
    vec2<float> delta1 = dot(delta2, t(matrix.w2)) * deriv_sigmoid(za_storage.z1);
    
    return DeltaStorage {
        delta2,
        delta1,
    };
}

#endif
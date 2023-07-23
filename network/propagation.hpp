#ifndef PROPAGATION_H
#define PROPAGATION_H

#include "../network.hpp"
#include "../types/vec_import.hpp"
#include "../math/all_math_import.hpp"

ZAStorage DeepLearning::forward(Matrix matrix, Normalize norm) {
    int layers = matrix.b.size();

    printf("z1\n");
    vec2<float> z1 = dot(norm.x_norm, matrix.w1) + matrix.b1;
    printf("finished z1\n");
    vec2<float> a1 = sigmoid(z1);

    vec2<float> last_a = a1;
    vec3<float> z;
    vec3<float> a;

    for (int i = 0; i < layers; i++) {
        printf("z%i\n", i);
        vec2<float> my_z = dot(last_a, matrix.w[i]) + matrix.b[i];
        vec2<float> my_a = sigmoid(my_z);
        z.push_back(my_z);
        a.push_back(my_a);
        last_a = my_a;
    }
    printf("z2");
    vec2<float> z2 = dot(last_a, matrix.w2) + matrix.b2;

    return ZAStorage {
        z1,
        a1,
        z, 
        a,
        z2,
    };
}

DeltaStorage DeepLearning::backward(Matrix matrix, Normalize norm, ZAStorage za_storage) {
    int layers = matrix.b.size();

    vec2<float> delta2 = za_storage.z2 - norm.y_norm * deriv_sigmoid(za_storage.z2);
    vec3<float> delta;
    vec2<float> last_delta = delta2;

    for (int i = 0; i < layers; i++) {
        vec2<float> my_delta = dot(last_delta, t(matrix.w[layers + 1 - i])) * deriv_sigmoid(za_storage.z[layers - i]);
        delta.push_back(my_delta);
        last_delta = my_delta;
    }

    vec2<float> delta1 = dot(last_delta, t(matrix.w[0])) * deriv_sigmoid(za_storage.z1);

    return DeltaStorage {
        delta2,
        delta,
        delta1,
    };
}

#endif
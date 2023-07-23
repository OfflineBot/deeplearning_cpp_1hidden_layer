#include "../network.hpp"
#include "../matrix/random_matrix.hpp"

Matrix DeepLearning::init_matrix(int input_layer_size, int hidden_layer_size, int output_layer_size, int hidden_layer) {
    vec2<float> w1 = matrix_rand(input_layer_size, hidden_layer_size);
    vec1<float> b1 = matrix_rand(hidden_layer_size);
    vec3<float> w = matrix_rand(hidden_layer, hidden_layer_size, hidden_layer_size);
    vec2<float> b = matrix_rand(hidden_layer, hidden_layer_size);
    vec2<float> w2 = matrix_rand(hidden_layer_size, output_layer_size);
    vec1<float> b2 = matrix_rand(output_layer_size);

    return Matrix {
        w1,
        b1,
        w, 
        b,
        w2,
        b2,
    };
}
#ifndef NETWORK_H
#define NETWORK_H

#include "structs/all_structs.hpp"
#include "types/vec_import.hpp"

class DeepLearning {
private:
    ZAStorage forward(Matrix matrix, Normalize norm);
    DeltaStorage backward(Matrix matrix, Normalize norm, ZAStorage za_storage);
    Matrix update_matrix(Matrix matrix, Normalize norm, ZAStorage za_storage, DeltaStorage delta_storage, float learning_rate);

public:
    Normalize normalize(vec2<float> input_data, vec2<float> output_data);
    Matrix init_matrix(int input_layer_size, int hidden_layer_size, int output_layer_size, int hidden_layers);
    TrainingData train(int iterations, float learning_rate, Matrix matrix, Normalize norm);
};

#endif
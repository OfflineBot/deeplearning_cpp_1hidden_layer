#include "../network.hpp"
#include "propagation.hpp"
#include "update_matrix.hpp"

TrainingData DeepLearning::train(int iterations, float learning_rate, Matrix matrix, Normalize norm) {
    for (int i = 0; i <= iterations; i++) {

        if (i % 1000 == 0.0)
            printf("%f%%\n", round(static_cast<float>(i) / static_cast<float>(iterations) * 100.0));

        ZAStorage za_storage = forward(matrix, norm);
        DeltaStorage delta_storage = backward(matrix, norm, za_storage);
        Matrix matrix1 = update_matrix(matrix, norm, za_storage, delta_storage, learning_rate);

    }

    OutputNorm out_norm = OutputNorm {
        norm.x_mean,
        norm.x_std,
        norm.y_mean,
        norm.y_std,
    };
    return TrainingData {
        matrix,
        out_norm,
    };
}
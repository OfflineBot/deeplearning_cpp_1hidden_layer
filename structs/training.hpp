#ifndef TRAINING_H
#define TRAINING_H

#include "../types/vec.hpp"
#include "norm.hpp"

typedef struct {
    Matrix matrix;
    OutputNorm norm;
} TrainingData;

#endif
#ifndef STORAGES_H
#define STORAGES_H

#include "../types/vec.hpp"

typedef struct {
    vec2<float> z1;
    vec2<float> a1;
    vec2<float> z2;
} ZAStorage;

typedef struct {
    vec2<float> delta2;
    vec2<float> delta1;
} DeltaStorage;

#endif
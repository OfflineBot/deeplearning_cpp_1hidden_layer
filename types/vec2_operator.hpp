#ifndef VEC2_OPERATOR_H
#define VEC2_OPERATOR_H

#include <iostream>
#include "vec.hpp"

// basic operations
inline vec2<float> operator+(vec2<float> array1, vec2<float> array2) {
    int rows = array1.size();
    int cols = array1[0].size();

    int array2_size = array2.size();
    int array2_i_size = array2[0].size();

    if (rows != array2_size || cols != array2_i_size)
        throw std::runtime_error("Vec2 + Vec2 does not have compatible shapes!");
    
    vec2<float> result;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = array1[row][col] + array2[row][col];
            array_slice.push_back(item);
        }
        result.push_back(array_slice);
    }

    return result;
}

inline vec2<float> operator-(vec2<float> array1, vec2<float> array2) {
    int rows = array1.size();
    int cols = array1[0].size();

    int array2_size = array2.size();
    int array2_i_size = array2[0].size();

    if (rows != array2_size || cols != array2_i_size)
        throw std::runtime_error("Vec2 - Vec2 does not have compatible shapes!");
    
    vec2<float> result;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = array1[row][col] - array2[row][col];
            array_slice.push_back(item);
        }
        result.push_back(array_slice);
    }

    return result;
}

inline vec2<float> operator*(vec2<float> array1, vec2<float> array2) {
    int rows = array1.size();
    int cols = array1[0].size();

    int array2_size = array2.size();
    int array2_i_size = array2[0].size();

    if (rows != array2_size || cols != array2_i_size) {
        printf("(%i, %i) (%i, %i)\n", rows, cols, array2_size, array2_i_size);
        //throw std::runtime_error("Vec2 * Vec2 not compatible!");
    }
    
    vec2<float> result;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = array1[row][col] * array2[row][col];
            array_slice.push_back(item);
        }
        result.push_back(array_slice);
    }

    return result;
}

inline vec2<float> operator/(vec2<float> array1, vec2<float> array2) {
    int rows = array1.size();
    int cols = array1[0].size();

    int array2_size = array2.size();
    int array2_i_size = array2[0].size();

    if (rows != array2_size || cols != array2_i_size)
        throw std::runtime_error("Vec2 / Vec2 does not have compatible shapes!");
    
    vec2<float> result;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = array1[row][col] / array2[row][col];
            array_slice.push_back(item);
        }
        result.push_back(array_slice);
    }

    return result;
}


// single multiply
inline vec2<float> operator*(vec2<float> array1, float multi_item) {
    int rows = array1.size();
    int cols = array1[0].size();

    
    vec2<float> result;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = array1[row][col] * multi_item;
            array_slice.push_back(item);
        }
        result.push_back(array_slice);
    }

    return result;
}


inline vec2<float> operator+(vec2<float> array1, vec1<float> array2) {
    int rows = array1.size();
    int cols = array1[0].size();


    //if (cols != array2_size)
    //    throw std::runtime_error("Matrices dont match!");

    vec2<float> result;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float value = array1[row][col] + array2[col];
            array_slice.push_back(value);
        }
        result.push_back(array_slice);
    }

    return result;
}

#endif
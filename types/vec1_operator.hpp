#ifndef VEC1_OPERATOR_H
#define VEC1_OPERATOR_H

#include <iostream>
#include "vec.hpp"


// basic operations
inline vec1<float> operator+(vec1<float> array1, vec1<float> array2) {
    int rows = array1.size();
    int array2_size = array2.size();
    if (rows != array2_size) 
        throw std::runtime_error("Vec1 + Vec1 are not compatible!"); 
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] + array2[row];
        result.push_back(item);
    }
    return result;
}

inline vec1<float> operator-(vec1<float> array1, vec1<float> array2) {
    int rows = array1.size();
    int array2_size = array2.size();
    if (rows != array2_size) 
        throw std::runtime_error("Vec1 - Vec1 are not compatible!"); 
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] - array2[row];
        result.push_back(item);
    }
    return result;
}

inline vec1<float> operator*(vec1<float> array1, vec1<float> array2) {
    int rows = array1.size();
    int array2_size = array2.size();
    if (rows != array2_size) 
        throw std::runtime_error("Vec1 * Vec1 are not compatible!"); 
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] * array2[row];
        result.push_back(item);
    }
    return result;
}

inline vec1<float> operator/(vec1<float> array1, vec1<float> array2) {
    int rows = array1.size();
    int array2_size = array2.size();
    if (rows != array2_size) 
        throw std::runtime_error("Vec1 / Vec1 are not compatible!"); 
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] / array2[row];
        result.push_back(item);
    }
    return result;
}


// multiply with one value
inline vec1<float> operator*(vec1<float> array1, float multi_item) {
    int rows = array1.size();
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] + multi_item;
        result.push_back(item);
    }
    return result;
}

#endif
#include "../network.hpp"


vec1<float> mean_axis0(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();

    vec1<float> my_mean(cols, 0.0f);

    for (int col = 0; col < cols; col++) {
        for (int row = 0; row < rows; row++) {
            my_mean[col] += array[row][col];
        }
        my_mean[col] /= rows;
    }

    return my_mean;
}

vec1<float> std_axis0(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();

    vec1<float> my_std;
    vec1<float> my_mean = mean_axis0(array);

    for (int col = 0; col < cols; col++) {
        float current_num = 0;
        for (int row = 0; row < rows; row++) {
            float power = pow(array[row][col] - my_mean[col], 2.0);
            current_num += power;
        }
        float final_num = sqrt(current_num / rows);
        if (final_num == 0.0f) {
            final_num = 1e-6;
        }
        my_std.push_back(final_num);
    }
    return my_std;
}

vec2<float> norm(vec2<float> array, vec1<float> input_mean, vec1<float> input_std) {
    vec2<float> my_norm;

    int rows = array.size();
    int cols = array[0].size();

    for (int row = 0; row < rows; row++) {
        vec1<float> values;
        for (int col = 0; col < cols; col++) {
            float value = ((array[row][col] - input_mean[col])) / input_std[col];
            values.push_back(value);
        }
        my_norm.push_back(values);
    }
    return my_norm;
}


Normalize DeepLearning::normalize(vec2<float> input_data, vec2<float> output_data) {

    vec1<float> x_mean = mean_axis0(input_data);
    vec1<float> x_std = std_axis0(input_data);
    vec2<float> x_norm = norm(input_data, x_mean, x_std);

    vec1<float> y_mean = mean_axis0(output_data);
    vec1<float> y_std = std_axis0(output_data);
    vec2<float> y_norm = norm(output_data, y_mean, y_std);

    return Normalize {
        input_data,
        x_mean,
        x_std,
        x_norm,
        output_data,
        y_mean,
        y_std,
        y_norm,
    };
}


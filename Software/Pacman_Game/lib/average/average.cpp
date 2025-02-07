#include "average.h"

float average(const std::vector<float>& values){
    // If list is empty, return 0
    if (values.size() == 0){
        return 0;
    }

    float sum = 0;
    for (auto value : values){
        sum += value;
    }
    return sum / values.size();
}
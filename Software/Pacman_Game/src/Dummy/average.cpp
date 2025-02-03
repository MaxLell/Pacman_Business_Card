#include "average.h"

float average(std::vector<float>  &v) {
    float sum = 0;
    for (float &i : v) {
        sum += i;
    }
    return sum / v.size();
}
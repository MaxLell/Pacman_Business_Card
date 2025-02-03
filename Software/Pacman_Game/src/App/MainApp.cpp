#include <iostream>
#include <vector>

#include "average.h"

int main() {
    std::vector<float> v = {1, 2, 3, 4, 5};
    float result = average(v);
    std::cout << "The average is: " << result << std::endl;
    return 0;
}
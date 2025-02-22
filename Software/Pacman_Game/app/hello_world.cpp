#include <iostream>
#include "average.h"
#include <vector>

int main()
{
	// run the average function (input is a vector of floats) and print the result
	std::vector<float> v = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	std::cout << "Average: " << average(v) << std::endl;
	std::cout << "Hello World " << std::endl;
	return EXIT_SUCCESS;
}
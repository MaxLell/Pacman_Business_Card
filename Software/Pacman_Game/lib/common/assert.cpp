#include "assert.h"
#include <iostream>
#include <cstdlib>

void assert_failed(const char* condition, const char* function, const char* file, int line)
{
    std::cerr << "Assertion failed: (" << condition << "), function " << function
              << ", file " << file << ", line " << line << "." << std::endl;
    std::abort();
}
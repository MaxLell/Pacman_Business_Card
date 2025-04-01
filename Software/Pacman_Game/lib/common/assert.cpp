#include "assert.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>


void assert_failed(const char* condition, const char* function, const char* file, int line)
{
    #ifndef TESTING
    std::cerr << "\n\n"
              << "┌────────────────────────────────────────────────────────┐\n"
              << "│                                                        │\n"
              << "│                     ASSERT FAILED                      │\n"
              << "│                                                        │\n"
              << "└────────────────────────────────────────────────────────┘\n\n"
              << "----> Condition: (" << condition << ")\n\n"
              << "----> File: " << file << ":"<< line << "\n"
              << std::endl;

    std::abort();
    #else
    throw std::runtime_error("ASSERT triggered");
    #endif
}

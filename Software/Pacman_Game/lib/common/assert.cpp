#include "assert.h"
#include <iostream>
#include <cstdlib>

void assert_failed(const char* condition, const char* function, const char* file, int line)
{
    std::cerr << "\n\n"
              << "┌────────────────────────────────────────────────────────┐\n"
              << "│                                                        │\n"
              << "│                     ASSERT FAILED                      │\n"
              << "│                                                        │\n"
              << "└────────────────────────────────────────────────────────┘\n\n"
              << "----> Condition: (" << condition << ")\n\n"
              << "----> File: " << file << ", Line: " << line << "\n"
              << std::endl;

    std::abort();
}
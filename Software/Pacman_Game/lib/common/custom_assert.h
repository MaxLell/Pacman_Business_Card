#pragma once

void assert_failed(const char *condition, const char *file, int line);

#define ASSERT(condition)                                                \
    do                                                                   \
    {                                                                    \
        if (!(condition))                                                \
        {                                                                \
            assert_failed(#condition, __FILE__, __LINE__); \
        }                                                                \
    } while (false)
